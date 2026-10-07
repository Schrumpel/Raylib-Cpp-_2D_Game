#include "include/raylib.h"
#include "Player.h"
#include "Input.h"
#include "Camera.h"
#include "Rendering/RenderCore.h"
#include "Rendering/Init.h"
#include "WorldGen/WorldGen.h"
#include <vector>
#include <map>
#include<cmath>
#include<compare>
#include<algorithm>
//compile commands
//cd C:/Users/Anwender/Desktop/coding/2D_Game/manual/2D_Game
//gcc -o 2D_Game.exe main.cpp -Iinclude -Llib -lraylib -lgdi32 -lwinmm


int main() {
    Player player;
    uint64_t frameCount = 0;

    init();
    texture.load();

    generateWorld(player.getPosVec());
    loadChunks(player.getPosVec());


    while (!WindowShouldClose())
    {
        ClearBackground(RAYWHITE);

        frameCount++;

        if(frameCount % 5 == 0) handleInput(player);
        updateCamera(player);

        BeginDrawing();

            BeginMode2D(camera);

               if(frameCount % 60 == 0) loadChunks(player.getPosVec());

                renderWorld(player);

                DrawRectangle(0, -100, 100, 100, RED);

                rendering(player);

            EndMode2D();

            

        DrawFPS(0, 0);

        EndDrawing();
    }
  
    CloseWindow();
    return 0;
}