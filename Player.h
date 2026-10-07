#pragma once

#include "include/raylib.h"

class Player{
    private:
        Vector2 position = {0, 0};
        Vector2 chunkCoordinates = {position.x / 8, position.y / 8};
        

    public:
        //setters
        void setPos(Vector2 pos){
            position = pos;
        }

        void moveX(int stepSize, bool foward){
            if(foward) position.x += stepSize;
            if(!foward) position.x -= stepSize;
        }

        void moveY(int stepSize, bool foward){
            if(foward) position.y += stepSize;
            if(!foward) position.y -= stepSize;
        }

        //getters
        int getPosX(){
            return position.x;
        }

        int getPosY(){
            return position.y;
        }

        Vector2 getPosVec(){
            return position;
        }

};