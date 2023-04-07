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

  for (int i = 0; i < SCREEN_WIDTH / 58; ++i) {
    auto ground = new DebugObject(&world, { -58 * static_cast<float>(i), -128 }, { 32, 32 });
    entities.push_back(ground);
  }

  Camera2D camera;
  camera.target = { player->GetPosition().x + player->GetSize().x / 2,
    player->GetPosition().y + player->GetSize().y / 2 };
  camera.offset = { 0, 0 };
  camera.rotation = 0.0f;
  camera.target = { 0, 0 };
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
