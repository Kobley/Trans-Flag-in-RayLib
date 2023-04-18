#include "include/raylib.h"
#include "Utils/Colors.h"
#include <math.h>

void drawFlagAsOutline(int thickness, int screenWidthin, int screenHeightin) {
    DrawRectangle(0, 0, screenWidthin, screenHeightin, COLOR_SKYBLUE);
    DrawRectangle(thickness, thickness, screenWidthin - thickness*2, screenHeightin - thickness*2, COLOR_PINK);
    DrawRectangle(thickness*2, thickness*2, screenWidthin - thickness*4, screenHeightin - thickness*4, COLOR_WHITE);
}

void drawFlag(int thickness, int screenWidthin, int screenHeightin) {
    DrawRectangle(0, 0, screenWidthin, screenHeightin, COLOR_SKYBLUE);
    DrawRectangle(0, thickness, screenWidthin, screenHeightin - thickness, COLOR_PINK);
    DrawRectangle(0, thickness*2, screenWidthin, screenHeightin - thickness*2, COLOR_WHITE);
    DrawRectangle(0, screenHeightin - thickness*2, screenWidthin, thickness*2, COLOR_PINK);
    DrawRectangle(0, screenHeightin - thickness, screenWidthin, thickness, COLOR_SKYBLUE);
}

int main(void)
{
    SetConfigFlags(FLAG_MSAA_4X_HINT | FLAG_WINDOW_RESIZABLE);

    InitWindow(1280, 720, "epic flag");
    SetWindowState(FLAG_VSYNC_HINT);
    HideCursor();

    int screenWidth = GetScreenWidth();
    int screenHeight = GetScreenHeight();
    int screenFPS = 60;
    int frameTime = 0;
    int drawOutline = 0;

    while (!WindowShouldClose())
    {
        SetTargetFPS(screenFPS);
        frameTime += screenFPS;
        screenWidth = GetScreenWidth();
        screenHeight = GetScreenHeight();

        BeginDrawing();
            ClearBackground(COLOR_WHITE);

            drawFlag(128, screenWidth, screenHeight);
            // drawFlagAsOutline(32, screenWidth, screenHeight);

            DrawText("raylib",screenWidth/2-50,screenHeight/2+4*sin((frameTime/2)*(PI/1500)),35,COLOR_LIGHTGRAY);
            DrawText("press esc to exit",4+4*sin((frameTime/2)*(PI/1500)),4+4*sin((frameTime)*(PI/1500)),20,COLOR_SKYBLUEOVERLAY);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}