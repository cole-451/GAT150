#pragma once
namespace parabellum {
	class Texture;
	class TextureAnimation : public Resource {
	public:
		TextureAnimation() = default;
		~TextureAnimation() = default;
		bool Load(const std::string& filename, class Renderer& renderer);
		vec2 GetSize() const;
		rect GetFrameRect(int frame) const;
		int GetTotalFrames() const { return m_totalFrames; }
		float GetFPS() const { return m_framesPerSecond; }
		bool IsValidFrame(int frame) const { return frame >= 0 && frame < m_totalFrames; }
		bool IsLooping() const { return m_loop; }
		res_t<Texture> GetTexture() { return m_texture; }
	private:
		int m_columns = 0; //The number of horizontal sub images in the image
		int m_rows = 0; //The number of vertical sub images in the image
		int m_startFrame = 0; // The start frame
		int m_totalFrames = 0; //The number of frames in the animation
		float m_framesPerSecond = 0; // Frames per second (usually 10-15 frames per second)
		bool m_loop = true; //Whether the animations should loop
		res_t<Texture> m_texture;
	};
}