#pragma once

#include "../include/raylib.h"

struct textures{
    Texture2D player;

    //Tile textures (T_ means its a tile texture)
    Texture2D T_dirt;
    Texture2D T_grass;

    void load(){
        player = LoadTexture("assets/player.png");
        T_dirt = LoadTexture("assets/tiles/DirtTile.png");
        T_grass = LoadTexture("assets/tiles/GrassTile.png");
    }
};

textures texture;
