//
// Created by Andrii on 06.04.23.
//

#ifndef PROJECT_GODS_PHYSICSENTITY_H
#define PROJECT_GODS_PHYSICSENTITY_H

#include "box2d/box2d.h"
#include "raylib.h"

class PhysicsEntity
{

protected:
  b2Body *_body = nullptr;

public:
  PhysicsEntity(b2World *world, b2BodyType bodyType, const Vector2 &position)
  {
    // Create the Box2D body definition
    b2BodyDef bodyDef;
    bodyDef.type = bodyType;
    bodyDef.position.Set(position.x / 100.0f, position.y / 100.0f);// Convert from pixels to meters
    _body = world->CreateBody(&bodyDef);
  }

  [[nodiscard]] b2Body *GetBody() const { return _body; }

  Vector2 UpdatePosition()
  {
    Vector2 new_pos;
    // Update the Raylib shape position based on the Box2D body position
    const b2Vec2 &phys_position = _body->GetPosition();
    new_pos.x = phys_position.x * 100.0f;// Convert from meters to pixels
    new_pos.y = phys_position.y * 100.0f;
    return new_pos;
  }
};

#endif// PROJECT_GODS_PHYSICSENTITY_H