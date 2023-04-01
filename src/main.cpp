#include "raylib.h"
#include "string"
#include "vector"
#include <math.h>

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 450;
const float PLAYER_SIZE = 64.0f;
const float GRAVITY = 9.8f * 40.f;

enum EntityType { GROUND, ENEMY, ITEM, PLAYER };

struct Entity
{
  Texture2D texture;
  Rectangle source = { 0, 0, 0, 0 };
  Vector2 pos = { 0, 0 };
  Vector2 size = { 0, 0 };
  float rotation = 0.0f;
  EntityType type;
};

std::vector<Entity> entities;

[[maybe_unused]] bool CheckCollisionEntities(Entity a, Entity b)
{
  Rectangle rect1 = { abs(a.pos.x), abs(a.pos.y), a.size.x, a.size.y };
  Rectangle rect2 = { abs(b.pos.x), abs(b.pos.y), b.size.x, b.size.y };

  return CheckCollisionRecs(rect1, rect2);
}

bool isOnTheGround(Entity actor)
{
  Rectangle rect1 = { abs(actor.pos.x) + actor.size.x / 4, abs(actor.pos.y - actor.size.y), actor.size.x / 2, 2 };

  return std::any_of(entities.begin(), entities.end(), [&rect1](Entity entity) {
    Rectangle rect2 = { abs(entity.pos.x), abs(entity.pos.y), entity.size.x, entity.size.y };
    return entity.type == GROUND && CheckCollisionRecs(rect1, rect2);
  });
}

int main()
{
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Project Gods");

  SetTargetFPS(60);

  auto playerTexture = LoadTexture("assets/player.png");
  auto tilesetTexture = LoadTexture("assets/platformer.png");

  Entity player = { playerTexture,
    { 0, 0, 16.0f, 16.0f },
    { -static_cast<float>(SCREEN_WIDTH) / 2.0f + PLAYER_SIZE / 2.0f,
      -static_cast<float>(SCREEN_HEIGHT) / 2.0f + 3 * PLAYER_SIZE / 2.0f },
    { PLAYER_SIZE, PLAYER_SIZE },
    0.0f,
    PLAYER };


  entities.push_back(player);

  Entity ground = { tilesetTexture, { 1, 0, 8.0f, 8.0f }, { 0, -SCREEN_HEIGHT + 32 }, { 32, 32 }, 0.0f, GROUND };

  entities.push_back(ground);
  for (int i = 0; i < SCREEN_WIDTH / 32; ++i) {
    ground.pos.x -= 32;
    entities.push_back(ground);
  }

  ground.pos.x = -SCREEN_WIDTH / 2;
  ground.pos.y = -SCREEN_HEIGHT + 128;
  entities.push_back(ground);

  Vector2 forces = { 0, 0 };

  while (!WindowShouldClose()) {
    auto delta = GetFrameTime();

    auto pl = &entities.at(0);
    auto on_ground = isOnTheGround(*pl);

    if (IsKeyDown(KEY_RIGHT)) pl->pos.x -= 2.0f;
    if (IsKeyDown(KEY_LEFT)) pl->pos.x += 2.0f;

    if (!on_ground) { forces.y -= GRAVITY * delta; }
    if (on_ground) forces.y = 0;

    if (IsKeyDown(KEY_UP) & on_ground) forces.y += sqrt(2 * GRAVITY * 100);

    pl->pos.x += forces.x * delta;
    pl->pos.y += forces.y * delta;

    BeginDrawing();

    ClearBackground(RAYWHITE);

    for (Entity entity : entities) {
      DrawTexturePro(
        entity.texture, entity.source, { 0, 0, entity.size.x, entity.size.y }, entity.pos, entity.rotation, WHITE);
    }

    DrawText(std::to_string(delta).c_str(), 10, 10, 20, DARKGRAY);

    EndDrawing();
  }

  for (Entity obj : entities) { UnloadTexture(obj.texture); }
  CloseWindow();

  return 0;
}