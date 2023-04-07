//
// Created by Andrii on 06.04.23.
//

#ifndef PROJECT_GODS_PLAYER_H
#define PROJECT_GODS_PLAYER_H

#include "Entity.h"
#include "PhysicsEntity.h"
#include "TexturedEntity.h"
#include "box2d/box2d.h"
#include "raylib.h"


class Player
  : public TexturedEntity
  , public PhysicsEntity
{

public:
  Player(b2World *world, const Vector2 &position, const Vector2 &size, Texture2D texture, Rectangle source)
    : TexturedEntity(texture, source), PhysicsEntity(world, b2_dynamicBody, position, size)
  {
    b2PolygonShape box;
    box.SetAsBox(size.x / (2.0f * PHYSICS_SCALE), size.y / (2.0f * PHYSICS_SCALE));

    // Create the Box2D fixture definition
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &box;
    fixtureDef.density = 1.0f;
    fixtureDef.friction = 0.1f;
    fixtureDef.restitution = 0.0f;
    _body->CreateFixture(&fixtureDef);

    _body->SetSleepingAllowed(false);

    _position = position;
    _size = size;
  }

  void Update([[maybe_unused]] float delta) override
  {
    // Apply input forces to the Box2D body
    b2Vec2 move(0.0f, 0.0f);
    if (IsKeyDown(KEY_LEFT)) { move.x += 5.0f; }
    if (IsKeyDown(KEY_RIGHT)) { move.x -= 5.0f; }

    _body->ApplyForceToCenter({ move.x, move.y }, true);
    if (IsKeyDown(KEY_UP)) _body->ApplyLinearImpulseToCenter({ 0, 1.0f * _body->GetMass() }, true);

    _position = UpdatePosition();
  }
};


#endif// PROJECT_GODS_PLAYER_H
