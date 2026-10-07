#pragma once

#include "include/raylib.h"
#include <vector>
#include<map>
#include<cmath>
#include<iostream>

//Utility global variables

int screenWidth = 1800;
int screenHeight = 900;

enum WorldTiles{
    GRASS,
    DIRT
};

enum UIClickFunction{
    CLOSE_GAME,
    RESUME,
    LOAD_WORLD,
    SAVE,
    VOID,
    
};

//The Chunk Struct; Holds tile information and chunk position
struct Chunk{
    std::vector<WorldTiles> tiles;
    Vector2 pos;
};

//Button Struct; Generic rectangular button for UI
struct Button{
    Vector2 startPos = {0, 0};
    int width = 400;
    int height = 50;
    
    UIClickFunction function = VOID;
    
};

//Holds the data for the world tiles
std::map<Vector2, std::vector<WorldTiles>> World = {};

//Holds the information af the currently loaded chunks
std::vector<Chunk> loadedChunks(9);

//Changes Tile coordinates to chunk coordinates
Vector2 calculateChunkCoordinates(Vector2 coordinates){
    float chunkY;
    float chunkX;

    if(coordinates.x >= 0) chunkX = floor(coordinates.x/256);
    if(coordinates.x < 0) chunkX = floor(coordinates.x/256);

    if(coordinates.y >= 0) chunkY = floor(coordinates.y/256);
    if(coordinates.y < 0) chunkY = floor(coordinates.y/256);

    return {chunkX, chunkY};
}