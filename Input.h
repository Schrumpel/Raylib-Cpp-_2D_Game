#pragma once

#include "include/raylib.h"
#include "Player.h"

void handleInput(Player &player){


    

    if(IsKeyDown(KEY_W)) player.moveY(1, false);    
    if(IsKeyDown(KEY_A)) player.moveX(1, false);    
    if(IsKeyDown(KEY_S)) player.moveY(1, true);    
    if(IsKeyDown(KEY_D)) player.moveX(1, true);    

}