#include "MeshRenderer.h"

namespace parabellum {
 FACTORY_REGISTER(MeshRenderer) 

	void parabellum::MeshRenderer::Update(float dt)
	{
		//
	}

	void MeshRenderer::draw(Renderer& renderer) {

		auto mesh = Resources().Get<Mesh>(meshName);
		if (mesh) {
			mesh->Draw(renderer, owner->m_transform);
		}
	}

}
