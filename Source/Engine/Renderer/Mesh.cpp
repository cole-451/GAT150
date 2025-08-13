#include "Mesh.h"
#include "Renderer.h"
#include "Core/File.h"





namespace parabellum {
	bool Mesh::Load(const std::string& filename)
	{
		std::string buffer;

		if (!parabellum::File::ReadTextFile(filename, buffer)) {
			Logger::Error("cant read your file lil bro");
		}
		std::stringstream stream(buffer);

		stream >> m_color;
		vec2 point;

		while (stream >> point) {
			m_points.push_back(point);
		}
		return true;
	}
	void Mesh::Draw(class Renderer& renderer, const vec2 position, float rotation, float scale) {

		renderer.setColor(m_color.r, m_color.g, m_color.b);

		if (m_points.empty()) {
			return;
		}

		for (int i = 0; i < m_points.size() - 1; i++) {
			vec2 p1 = (m_points[i].Rotate(math::degrees_to_radius(rotation)) *scale) + position;
			vec2 p2 = (m_points[i + 1].Rotate(math::degrees_to_radius(rotation)) * scale) + position;
			renderer.drawline(p1.x, p1.y, p2.x, p2.y);
		}
	}
	void Mesh::Draw(Renderer& renderer, const Transform& transform)
	{
		Draw(renderer, transform.position, transform.rotation, transform.scale);
	}
	void Mesh::calculateRadius()
	{
		m_radius = 0;

		for (auto& point : m_points) {
			float length = point.length();
			if (length > m_radius) {
				m_radius = length;
			}
		}
	}
}