#include "CircleCollide2D.h"

namespace parabellum {

void CircleCollide2D::Update(float dt)
{
    //
}

bool CircleCollide2D::checkCollision(ColliderComponent& other)
{
    //check circle to circle collision
    float distance = (owner->m_transform.position - other.owner->m_transform.position).length();
    auto collider = dynamic_cast<CircleCollide2D*>(&other);
    if (collider) {
        float radii = radius + collider->radius;
        if (distance <= radii) return true;


    }
    
    //float distance = vec2{ actorA->m_transform.position - actorB->m_transform.position }.length();
    // if your distance is less than or equal to the SUM of both of the actor's radius
    //if (distance <= actorA->getRadius() + actorB->getRadius()) {
    
    return false;
}
}
