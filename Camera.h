#pragma once 

#include "Player.h"
#include "include/raylib.h"

Camera2D camera = { 0 };

void updateCamera(Player player){
    camera.target = {player.getPosVec()};
    camera.offset = (Vector2){ GetScreenWidth()/2.0f, GetScreenHeight()/2.0f };
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;
}
