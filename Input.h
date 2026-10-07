#pragma once

#include "include/raylib.h"
#include "Player.h"

void handleInput(Player &player){
   /*if(IsKeyPressed){                  //check if there is any input
        switch (GetKeyPressed())    
        {
        case KEY_W:
            player.moveY(15, false);
            break;

        case KEY_A:
            player.moveX(15, false);
            break;

        case KEY_S:
            player.moveY(15, true);
            break;

        case KEY_D:
            player.moveX(15, true);
            break;
        
        default:
            break;
        }
    }*/

    if(IsKeyDown(KEY_W)) player.moveY(1, false);    
    if(IsKeyDown(KEY_A)) player.moveX(1, false);    
    if(IsKeyDown(KEY_S)) player.moveY(1, true);    
    if(IsKeyDown(KEY_D)) player.moveX(1, true);    

}