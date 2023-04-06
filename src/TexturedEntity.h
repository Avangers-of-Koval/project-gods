//
// Created by Andrii on 06.04.23.
//

#ifndef PROJECT_GODS_TEXTUREDENTITY_H
#define PROJECT_GODS_TEXTUREDENTITY_H

#include "Entity.h"

class TexturedEntity : public Entity
{
protected:
  Texture2D _texture;
  Rectangle _source;

public:
  TexturedEntity(Texture2D texture, Rectangle source) : _texture(texture), _source(source) {}

  void Draw() override
  {
    DrawTexturePro(_texture, _source, { 0, 0, _position.x, _position.y }, _position, _rotation, WHITE);
  }

  ~TexturedEntity() override { UnloadTexture(_texture); }
};


#endif// PROJECT_GODS_TEXTUREDENTITY_H
