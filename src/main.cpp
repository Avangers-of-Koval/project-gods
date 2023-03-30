#include "raylib.h"

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 450;
const float PLAYER_SIZE = 64.0f;

int main()
{
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Project Gods");

  Vector2 ballPosition = { -static_cast<float>(SCREEN_WIDTH) / 2.0f + PLAYER_SIZE / 2.0f, -static_cast<float>(SCREEN_HEIGHT) / 2.0f + PLAYER_SIZE / 2.0f };

  SetTargetFPS(60);

  auto playerTexture = LoadTexture("assets/player.png");

  Rectangle source = {0, 0, 16.0f, 16.0f};
  Rectangle dest = {0, 0, PLAYER_SIZE, PLAYER_SIZE};

  while (!WindowShouldClose())
  {
    if (IsKeyDown(KEY_RIGHT)) ballPosition.x -= 2.0f;
    if (IsKeyDown(KEY_LEFT)) ballPosition.x += 2.0f;
    if (IsKeyDown(KEY_UP)) ballPosition.y += 2.0f;
    if (IsKeyDown(KEY_DOWN)) ballPosition.y -= 2.0f;

    BeginDrawing();

    ClearBackground(RAYWHITE);

    DrawTexturePro(playerTexture, source, dest, ballPosition, 0.0f, WHITE);

    DrawText("move the player with arrow keys", 10, 10, 20, DARKGRAY);


    EndDrawing();
  }

  CloseWindow();

  return 0;
}