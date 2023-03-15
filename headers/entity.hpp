#pragma once

#include "raylib.h"

struct Entity {
    Entity(int x, int y, Color color, int w = 35, int h = 35, int dx = 0, int dy = 0);
    virtual void draw() const;
    virtual void update();

    int x, y, w, h, dx, dy;
    Color color;
};

struct Player : Entity {
    Player(int x, int y, Color color, int w = 40, int h = 60, int dx = 5, int dy = 4);
    virtual void draw() const;
    virtual void update();
};