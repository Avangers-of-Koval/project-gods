#include "raylib.h"
#include "headers/entity.hpp"

void UpdateDrawFrame(void);

Player player(300, 100, LIME);
Entity entity(13, 13, RED);

int main() {
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "hehe");

    SetTargetFPS(60);
    while (!WindowShouldClose()) {
        UpdateDrawFrame();
    }

    CloseWindow();
    return 0;
}

void UpdateDrawFrame(void) {
    Vector2 oldPos;

    oldPos = Vector2 {(float)player.x, (float)player.y};
    player.update();
    if (CheckCollisionRecs(Rectangle{(float)player.x, (float)player.y, (float)player.w, (float)player.h},
        Rectangle{(float)entity.x, (float)entity.y, (float)entity.w, (float)entity.h})) {
        player.x = oldPos.x;
        player.y = oldPos.y;
    }

    oldPos = Vector2 {(float)entity.x, (float)entity.y};
    entity.update();
    if (CheckCollisionRecs(Rectangle{(float)player.x, (float)player.y, (float)player.w, (float)player.h},
        Rectangle{(float)entity.x, (float)entity.y, (float)entity.w, (float)entity.h})) {
        entity.x = oldPos.x;
        entity.y = oldPos.y;
    }

    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawText("HALLLLOOOO!!!", 200, 200, 40, SKYBLUE);
    player.draw();
    entity.draw();
    EndDrawing();
}