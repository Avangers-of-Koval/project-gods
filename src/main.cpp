#include "raylib.h"

int main()
{
  // Initialization
  //--------------------------------------------------------------------------------------
  const int screenWidth = 800;
  const int screenHeight = 450;

  InitWindow(screenWidth, screenHeight, "Project Gods");

  Vector2 ballPosition = { static_cast<float>(screenWidth) / 2.0f, static_cast<float>(screenHeight) / 2.0f };

  SetTargetFPS(60);

  while (!WindowShouldClose())    // Detect window close button or ESC key
  {
    if (IsKeyDown(KEY_RIGHT)) ballPosition.x += 2.0f;
    if (IsKeyDown(KEY_LEFT)) ballPosition.x -= 2.0f;
    if (IsKeyDown(KEY_UP)) ballPosition.y -= 2.0f;
    if (IsKeyDown(KEY_DOWN)) ballPosition.y += 2.0f;

    BeginDrawing();

    ClearBackground(RAYWHITE);

    DrawText("move the ball with arrow keys", 10, 10, 20, DARKGRAY);

    DrawCircleV(ballPosition, 50, MAROON);

    EndDrawing();
  }

  CloseWindow();

  return 0;
}