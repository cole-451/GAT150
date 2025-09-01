#include "EnginePCH.h"
#include "SpriteRenderer.h"
#include "Renderer/Renderer.h"
#include "Engine.h"

namespace parabellum {

	FACTORY_REGISTER(SpriteRenderer);
	void SpriteRenderer::Start()
	{
		if (!texture && !textureName.empty()) {
		texture = Resources().Get<Texture>(textureName, getEngine().getRenderer());
		}

	}
	void SpriteRenderer::Update(float dt)
	{
		//
	}

	void SpriteRenderer::draw(Renderer& renderer)
	{
		if (texture) {
			if (textureRect.w > 0 && textureRect.h > 0) {
				renderer.DrawTexture(*texture, textureRect, owner->m_transform.position.x, owner->m_transform.position.y, owner->m_transform.rotation, owner->m_transform.scale);

			}
			else {
				renderer.DrawTexture(*texture, owner->m_transform.position.x, owner->m_transform.position.y, owner->m_transform.rotation, owner->m_transform.scale);

			}

		}

	}
	void SpriteRenderer::Read(const json::value_t& value)
	{
		Object::Read(value);
		Component::Read(value);
		JSON_READ(value, textureName);
	}
}
