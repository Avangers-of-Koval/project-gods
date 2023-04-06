//
// Created by Andrii on 06.04.23.
//

#ifndef PROJECT_GODS_DEBUGOBJECT_H
#define PROJECT_GODS_DEBUGOBJECT_H

#include "Entity.h"
#include "PhysicsEntity.h"

class DebugObject
  : public PhysicsEntity
  , public Entity
{
public:
  DebugObject(b2World *world, const Vector2 &position, const Vector2 &size)
    : PhysicsEntity(world, b2_staticBody, position)
  {
    b2PolygonShape box;
    box.SetAsBox(size.x / 2.0f, size.y / 2.0f);

    // Create the Box2D fixture definition
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &box;
    fixtureDef.density = 1.0f;
    fixtureDef.friction = 0.3f;
    _body->CreateFixture(&fixtureDef);

    _position = position;
    _size = size;
  }

  void Draw() override
  {
    DrawRectangle(static_cast<int>(_position.x),
      static_cast<int>(_position.y),
      static_cast<int>(_size.x),
      static_cast<int>(_size.y),
      GREEN);
  }

  void Update([[maybe_unused]] float delta) override { _position = UpdatePosition(); }
};


#endif// PROJECT_GODS_DEBUGOBJECT_H
