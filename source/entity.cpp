#include "raylib.h"
#include "headers/entity.hpp"

Entity::Entity(int x, int y, Color color, int w, int h, int dx, int dy) {
    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;
    this->dx = dx;
    this->dy = dy;
    this->color = color;
}

void Entity::draw() const {
    Color less = color;
    less.a = 200;

    DrawRectangle(x, y, w, h, less);
}

void Entity::update() {
    x += dx;
    y += dy;
}

Player::Player(int x, int y, Color color, int w, int h, int dx, int dy) :Entity(x, y, color, w, h, dx, dy) {}

void Player::update() {
    if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)) {
        x -= dx;
    }
    if (IsKeyDown(KEY_UP) || IsKeyDown(KEY_W)) {
        y -= dy;
    }
    if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) {
        x += dx;
    }
    if (IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S)) {
        y += dy;
    }
}

void Player::draw() const {
    Color less = color;
    less.a = 127;

    DrawRectangle(x, y, w, h, less);
    int margin = 10;
    DrawRectangle(x + margin, y + margin, w - margin*2, h - margin*2, less);
}