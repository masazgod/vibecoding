#include "raylib.h"

int main(void) {
    const int screenWidth = 1000;
    const int screenHeight = 700;

    InitWindow(screenWidth, screenHeight, "Raylib Paint");
    SetTargetFPS(60);

    RenderTexture2D canvas = LoadRenderTexture(screenWidth, screenHeight);

    BeginTextureMode(canvas);
    ClearBackground(RAYWHITE);
    EndTextureMode();

    const int brushRadius = 8;
    const Rectangle clearButton = {20, 20, 150, 45};

    while (!WindowShouldClose()) {
        Vector2 mouse = GetMousePosition();
        bool clearHotkey = IsKeyPressed(KEY_C);
        bool clearClick = CheckCollisionPointRec(mouse, clearButton) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT);

        if (clearHotkey || clearClick) {
            BeginTextureMode(canvas);
            ClearBackground(RAYWHITE);
            EndTextureMode();
        }

        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) && !CheckCollisionPointRec(mouse, clearButton)) {
            BeginTextureMode(canvas);
            DrawCircleV(mouse, (float)brushRadius, BLACK);
            EndTextureMode();
        }

        BeginDrawing();
        ClearBackground(LIGHTGRAY);

        DrawTextureRec(canvas.texture,
                       (Rectangle){0, 0, (float)canvas.texture.width, -(float)canvas.texture.height},
                       (Vector2){0, 0},
                       WHITE);

        DrawRectangleRounded(clearButton, 0.35f, 10, MAROON);
        DrawText("Сброс", 58, 33, 22, RAYWHITE);
        DrawText("ЛКМ: рисовать", 20, 80, 22, DARKGRAY);
        DrawText("Клавиша C: очистить", 20, 110, 22, DARKGRAY);

        EndDrawing();
    }

    UnloadRenderTexture(canvas);
    CloseWindow();

    return 0;
}
