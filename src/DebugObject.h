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
    : PhysicsEntity(world, b2_staticBody, position, size)
  {
    b2PolygonShape box;
    box.SetAsBox(size.x / (2.0f * PHYSICS_SCALE), size.y / (2.0f * PHYSICS_SCALE));

    _body->CreateFixture(&box, 1.0f);

    _position = position;
    _size = size;
  }

  void Draw() override { DrawRectanglePro({ 0, 0, _size.x, _size.y }, { _position.x, _position.y }, _rotation, GREEN); }

  void Update([[maybe_unused]] float delta) override { _position = UpdatePosition(); }
};


#endif// PROJECT_GODS_DEBUGOBJECT_H
