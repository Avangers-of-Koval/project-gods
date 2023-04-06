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
    : TexturedEntity(texture, source), PhysicsEntity(world, b2_dynamicBody, position)
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
  }

  void Update([[maybe_unused]] float delta) override
  {
    // Apply input forces to the Box2D body
    b2Vec2 force(0.0f, 0.0f);
    if (IsKeyDown(KEY_LEFT)) { force.x -= 10.0f; }
    if (IsKeyDown(KEY_RIGHT)) { force.x += 10.0f; }
    _body->ApplyForceToCenter(force, true);

    if (IsKeyDown(KEY_UP)) _body->ApplyLinearImpulse({ 0, sqrt(2 * 9.81f * 10) }, _body->GetWorldCenter(), true);

    _position = UpdatePosition();
  }
};


#endif// PROJECT_GODS_PLAYER_H
