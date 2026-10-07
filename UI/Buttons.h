#pragma once

#include "../include/raylib.h"
#include "../Util.h"
#include <iostream>

Button resumeButton;

void InitButtons(){
    resumeButton.startPos = {900, 450};
    resumeButton.function = RESUME;
    resumeButton.width = 400;
    resumeButton.height = 50;

    std::cout << "INFO: Button initialization succesfull\n";
}
