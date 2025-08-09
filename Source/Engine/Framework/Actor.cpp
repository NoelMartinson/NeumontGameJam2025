#include "Actor.h"
#include "Renderer/Renderer.h"

namespace whermst{


	void Actor::Update(float dt)
	{
		
	}

	void Actor::Draw(Renderer& renderer)
	{
		
		renderer.DrawTexture(_texture.get(), transform.position.x, transform.position.y, transform.rotation, transform.scale);
	}

	/// <summary>
	/// Returns the effective radius of the actor based on its texture size, scale, and a scaling factor.
	/// </summary>
	/// <returns>The computed radius of the actor. Returns 0 if the actor has no texture.</returns>
	float Actor::GetRadius( float scale)
	{
		return (_texture) ? (_texture->GetSize(scale).Length() * 0.5f) * transform.scale * 0.8f : 0;
	}
}