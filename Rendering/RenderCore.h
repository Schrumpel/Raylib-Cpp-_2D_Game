#pragma once

#include "../include/raylib.h"
#include "TextureLoading.h"
#include "../Util.h"
#include "../Player.h"
#include "../Camera.h"
#include <vector>

bool CheckIfTileOnscreen(Player &player, int x, int y){
    if( x + 1> player.getPosX()-screenWidth/2
     && x - 1< player.getPosX()+screenWidth/2
     && y + 1> player.getPosY()-screenHeight/2
     && y - 1< player.getPosY()+screenHeight/2){
        return true;
     } else {
        return false;
     }
}

void rendering(Player &player){
    DrawTexture(texture.player, player.getPosX(), player.getPosY(), WHITE);

    
}

void renderWorld(Player &player){

    for(int i = 0; i < 9; i++){
        if (loadedChunks[i].tiles.empty()) {
            std::cout << " Warnung: Chunk " << i << " ist leer!" << std::endl;
            continue;
        }
        Vector2 relativeChunkCoord = {};
        if(i == 0) relativeChunkCoord = {-1, 1};
        if(i == 1) relativeChunkCoord = {0, 1};
        if(i == 2) relativeChunkCoord = {1, 1};

        if(i == 3) relativeChunkCoord = {-1, 0};
        if(i == 4) relativeChunkCoord = {0, 0};
        if(i == 5) relativeChunkCoord = {1, 0};
        
        if(i == 6) relativeChunkCoord = {-1, -1};
        if(i == 7) relativeChunkCoord = {0, -1};
        if(i == 8) relativeChunkCoord = {1, -1};

        for(int j = 0; j < 16; j++){
            for(int k = 0; k < 16; k++)
                if      (loadedChunks[i].tiles[j * k] == GRASS) DrawTexture(texture.T_grass, (loadedChunks[i].pos.x * 16) * 16 + k * 16, (loadedChunks[i].pos.y * 16) * 16 + j * 16,  WHITE);
                else if (loadedChunks[i].tiles[j * k] == DIRT ) DrawTexture(texture.T_dirt,  (loadedChunks[i].pos.x * 16) * 16 + k * 16, (loadedChunks[i].pos.y * 16) * 16 + j * 16,  WHITE);
        }
    }

}
