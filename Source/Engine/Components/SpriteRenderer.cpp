#include "EnginePCH.h"
#include "SpriteRenderer.h"
#include "Renderer/Renderer.h"

namespace parabellum {

void SpriteRenderer::Update(float dt)
{
	//
}

void SpriteRenderer::draw(Renderer& renderer)
{
	renderer.DrawTexture(Resources().Get<Texture>(textureName, renderer).get(), owner->m_transform.position.x, owner->m_transform.position.y, owner->m_transform.rotation, owner->m_transform.scale);
}
}
