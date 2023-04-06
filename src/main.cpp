#include "DebugObject.h"
#include "Entity.h"
#include "Player.h"
#include "box2d/box2d.h"
#include "raylib.h"
#include "string"
#include "vector"

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 450;
const float PLAYER_SIZE = 64.0f;
const float GRAVITY = 9.81f;

int32 velocityIterations = 6;
int32 positionIterations = 2;

b2Vec2 gravity(0.0f, -GRAVITY);
b2World world(gravity);

std::vector<Entity> entities;

int main()
{
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Project Gods");

  SetTargetFPS(60);

  auto playerTexture = LoadTexture("assets/player.png");

  Player player(&world, { 0, 0 }, { PLAYER_SIZE, PLAYER_SIZE }, playerTexture, { 0, 0, 16.0f, 16.0f });

  entities.push_back(player);

  for (int i = 0; i < SCREEN_WIDTH / 32; ++i) {
    DebugObject ground(&world, { -32 * static_cast<float>(i), static_cast<float>(-GetScreenHeight()) }, { 32, 32 });

    entities.push_back(ground);
  }

  while (!WindowShouldClose()) {
    auto delta = GetFrameTime();

    for (Entity entity : entities) { entity.Update(delta); }

    BeginDrawing();

    ClearBackground(RAYWHITE);

    for (Entity entity : entities) { entity.Draw(); }

    DrawFPS(0, 0);
    world.Step(1.0f / 60.0f, velocityIterations, positionIterations);
    EndDrawing();
  }

  CloseWindow();

  return 0;
}
