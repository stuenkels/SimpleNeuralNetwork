#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>


class windowManager{
    SDL_Rect rects[16][16];
    SDL_Window *window = nullptr;
    SDL_Renderer *renderer  = nullptr;
    int mouse_coordanates_to_grid(int);
    bool drawing = true;
    int mouseX, mouseY;
    void update_mouse_vars();
    bool mouseDown;
    bool mouseDownOnFrame;

    public:
     windowManager();
     void initWindow();
     bool checkEventsAndShouldQuit();
     void drawBoxes(float grid[][16]);
     void updateDrawing(float grid[][16]);
     void displayAndWait();
};


