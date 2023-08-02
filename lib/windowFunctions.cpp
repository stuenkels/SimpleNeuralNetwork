#include "windowFunctions.h"


windowManager::windowManager(){
    for(int i=0; i<16; i++){
        for(int j=0; j<16; j++){
            rects[i][j].x = i*25;
            rects[i][j].y = j*25;
            rects[i][j].w = 25;
            rects[i][j].h = 25;
        }
    }
}
int windowManager::mouse_coordanates_to_grid(int value){
    return value/2/25;
}

void windowManager::update_mouse_vars(){
    if(SDL_GetMouseState(&mouseX, &mouseY) & SDL_BUTTON_LMASK){
        if(mouseDown ==false){
            mouseDownOnFrame = true;
        }else{
            mouseDownOnFrame = false;
        }
        mouseDown = true;
    }else{
        mouseDown = false;
    }
}


void windowManager::initWindow(){
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();
    SDL_CreateWindowAndRenderer(1000,800,0,&window, &renderer);
    SDL_RenderSetScale(renderer, 2, 2);
}

bool windowManager::checkEventsAndShouldQuit(){
    SDL_Event e;
        while(SDL_PollEvent(&e)){
            if(e.type == SDL_QUIT){
                return false;
            }
        }
        
        update_mouse_vars();
       return true;
}

void windowManager::drawBoxes(float grid[][16]){
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);


    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

    //Draw white grid
    for(int i=0; i<16; i++){
        for(int j=0; j<16; j++){
            // SDL_RenderDrawRect(renderer, &rects[i][j]);
        }
    }

    //fill in grid spaces
    for(int i=0; i<16; i++){
            for(int j=0; j<16; j++){
                if(grid[i][j]==1.0){
                    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
                    SDL_RenderFillRect(renderer, &rects[i][j]);
                    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
                    // SDL_RenderDrawRect(renderer, &rects[i][j]);
                }
            }
        }
}

void windowManager::updateDrawing(float grid[][16]){
    SDL_SetRenderDrawColor(renderer, 80, 80, 80, 100);
        
        int gridX = mouse_coordanates_to_grid(mouseX);
        int gridY = mouse_coordanates_to_grid(mouseY);
        

        if(mouseX < 800 && mouseY < 800 && mouseX > 1 && mouseY >1){ //pervent from offscreen
            SDL_RenderFillRect(renderer, &rects[gridX][gridY]);
            if(mouseDownOnFrame){
                if(grid[gridX][gridY] == 1.0){
                    drawing = false;
                }else{
                    drawing = true;
                }
            }
            

            if(mouseDown){
                if(drawing){
                    grid[gridX][gridY] = 1.0;
                }else{
                    grid[gridX][gridY] = 0.0;
                }
            }
        }
}

void windowManager::displayAndWait(){
    SDL_RenderPresent(renderer);
    SDL_Delay(10);
}