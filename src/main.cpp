#include "raylib.h"

int main() {
    InitWindow(1280, 720, "D&D GM Engine");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(DARKGRAY);
        DrawText("Welcome, Dungeon Master!", 420, 360, 20, RAYWHITE);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
