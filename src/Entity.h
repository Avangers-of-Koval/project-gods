//
// Created by Andrii on 06.04.23.
//

#ifndef PROJECT_GODS_ENTITY_H
#define PROJECT_GODS_ENTITY_H

#include "box2d/box2d.h"
#include "raylib.h"

class Entity
{
protected:
  Vector2 _position{};
  Vector2 _size = { 10, 10 };
  float _rotation = 0;

public:
  virtual ~Entity() = default;
  virtual void Draw() { DrawRectanglePro({ 0, 0, _size.x, _size.y }, { _position.x, _position.y }, _rotation, RED); }
  virtual void Update([[maybe_unused]] float delta) {}
  virtual void Move(Vector2 new_pos) { _position = new_pos; }

  Vector2 GetPosition() { return _position; }
  Vector2 GetSize() { return _size; }
  [[nodiscard]] float GetRotation() const { return _rotation; }
};


#endif// PROJECT_GODS_ENTITY_H
