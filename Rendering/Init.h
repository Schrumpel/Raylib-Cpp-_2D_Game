#pragma once 

#include "../include/raylib.h"
#include "../Util.h"
#include "../UI/Buttons.h"

void init(){
    InitWindow(screenWidth, screenHeight, "2D Game Playtest");
    InitButtons();
}
