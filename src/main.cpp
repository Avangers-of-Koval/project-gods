#include "DebugObject.h"
#include "Entity.h"
#include "Player.h"
#include "box2d/box2d.h"
#include "raylib.h"
#include "vector"

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 450;
const float PLAYER_SIZE = 64.0f;
const float GRAVITY = 9.81f;

int32 velocityIterations = 6;
int32 positionIterations = 2;

b2Vec2 gravity(0.0f, -GRAVITY);
b2World world(gravity);

std::vector<Entity *> entities;

int main()
{
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Project Gods");

  SetTargetFPS(60);

  auto playerTexture = LoadTexture("assets/player.png");

  auto player = new Player(&world, { -40, -20 }, { PLAYER_SIZE, PLAYER_SIZE }, playerTexture, { 0, 0, 16.0f, 16.0f });

  entities.push_back(player);

  auto top = new DebugObject(&world, { 0, 0 }, { SCREEN_WIDTH, 32 });
  auto bottom = new DebugObject(&world, { 0, -SCREEN_HEIGHT + 32 }, { SCREEN_WIDTH, 32 });
  auto left = new DebugObject(&world, { 0, -32 }, { 32, SCREEN_HEIGHT - 64 });
  auto right = new DebugObject(&world, { -SCREEN_WIDTH + 32, -32 }, { 32, SCREEN_HEIGHT - 64 });

  entities.push_back(top);
  entities.push_back(bottom);
  entities.push_back(left);
  entities.push_back(right);

  Camera2D camera;
  camera.target = { 0, 0 };
  camera.offset = { 0, 0 };
  camera.rotation = 0;
  camera.zoom = 1.0f;

  while (!WindowShouldClose()) {
    auto delta = GetFrameTime();

    for (auto &entity : entities) { entity->Update(delta); }

    BeginDrawing();
    BeginMode2D(camera);
    ClearBackground(RAYWHITE);

    for (auto &entity : entities) { entity->Draw(); }

    EndMode2D();
    DrawFPS(0, 0);
    EndDrawing();

    world.Step(1.0f / 60.0f, velocityIterations, positionIterations);
  }

  for (auto &entity : entities) { delete entity; }
  entities.clear();
  CloseWindow();

  return 0;
}
