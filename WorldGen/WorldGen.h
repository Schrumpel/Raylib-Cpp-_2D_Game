#pragma once

#include "../include/raylib.h"
#include "../Util.h"
#include "../Camera.h"
#include <random>
#include <map>
#include<iostream>
#include<algorithm>


void generateChunk(Vector2 chunkPos){
    std::vector<WorldTiles> tempChunk = {};

    
    for(int i = 0; i < 256; i++){
        int rng = rand() % 2;
        if(rng == 0)  tempChunk.push_back(GRASS);
        if(rng == 1)  tempChunk.push_back(DIRT);
        
    }

    World.insert({chunkPos, tempChunk});
}


void checkForChunk(Vector2 chunkPos){
    //searches the World map for the chunk
    auto it = World.find(chunkPos);

    if (it != World.end()) {
          std::cout << "Chunk found" << chunkPos.x << " " << chunkPos.y << "\n";
    } else {
        generateChunk(chunkPos);
    }

}

void generateWorld(Vector2 playerPos){

    Vector2 chunkPos = calculateChunkCoordinates(playerPos);
    std::vector<WorldTiles> tempChunk = {};

    
    for(int i = 0; i < 256; i++){
        tempChunk.push_back(GRASS);
        
    }

    World.insert({chunkPos, tempChunk});

}

//checks if a chunk exists and loads it
void loadChunks(Vector2 playerPos){
    Vector2 chunkPos = calculateChunkCoordinates(playerPos);

    checkForChunk({chunkPos.x - 1, chunkPos.y + 1});
    loadedChunks[0].tiles = World.at({chunkPos.x - 1, chunkPos.y + 1});
    loadedChunks[0].pos = {chunkPos.x - 1, chunkPos.y + 1};

    checkForChunk({chunkPos.x    , chunkPos.y + 1});
    loadedChunks[1].tiles = World.at({chunkPos.x    , chunkPos.y + 1});
    loadedChunks[1].pos = {chunkPos.x    , chunkPos.y + 1};

    checkForChunk({chunkPos.x + 1, chunkPos.y + 1});
    loadedChunks[2].tiles = World.at({chunkPos.x + 1, chunkPos.y + 1});
    loadedChunks[2].pos = {chunkPos.x + 1, chunkPos.y + 1};


    checkForChunk({chunkPos.x - 1, chunkPos.y});
    loadedChunks[3].tiles = World.at({chunkPos.x - 1, chunkPos.y});
    loadedChunks[3].pos = {chunkPos.x - 1, chunkPos.y};

    checkForChunk({chunkPos.x    , chunkPos.y});
    loadedChunks[4].tiles = World.at({chunkPos.x    , chunkPos.y});
    loadedChunks[4].pos = {chunkPos.x    , chunkPos.y};

    checkForChunk({chunkPos.x + 1, chunkPos.y});
    loadedChunks[5].tiles = World.at({chunkPos.x + 1, chunkPos.y});
    loadedChunks[5].pos = {chunkPos.x + 1, chunkPos.y};


    checkForChunk({chunkPos.x - 1, chunkPos.y - 1});
    loadedChunks[6].tiles = World.at({chunkPos.x - 1, chunkPos.y - 1});
    loadedChunks[6].pos = {chunkPos.x - 1, chunkPos.y - 1};

    checkForChunk({chunkPos.x    , chunkPos.y - 1});
    loadedChunks[7].tiles = World.at({chunkPos.x    , chunkPos.y - 1});
    loadedChunks[7].pos = {chunkPos.x    , chunkPos.y - 1};

    checkForChunk({chunkPos.x + 1, chunkPos.y - 1});
    loadedChunks[8].tiles = World.at({chunkPos.x + 1, chunkPos.y - 1});
    loadedChunks[8].pos = {chunkPos.x + 1, chunkPos.y - 1};
}