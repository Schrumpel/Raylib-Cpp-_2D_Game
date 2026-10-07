#pragma once

#include "../include/raylib.h"
#include "../Util.h"
#include "Buttons.h"
#include <iostream>


bool checkIfButtonClicked(Button &button ){
    if( button.startPos.x >= GetMouseX() 
        && button.startPos.y <= GetMouseY()
        && button.startPos.x + button.width <= GetMouseX()
        && button.startPos.y + button.height >= GetMouseY() ){
            std::cout << "Button clicked: " << button.function << "\n";
            return true;
    } else {
        return false;
    }
}

