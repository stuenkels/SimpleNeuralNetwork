#include "config.h"

//recogize digits nueral network
//Perhaps a gui coming later
//We create a 2d array repersenting a square 16*16
//Each value will be either 0 or 1, repersenting colored in or not colored in
//we will have 256 input layer nodes

float grid[16][16];




int main(){
    //SDL code for window

    node inputNodes[256];


    for(int i=0; i<16; i++){
        for(int j=0; j<16; j++){
            grid[i][j] = 0.0;
        }
    }

    int node_id = 0;
    int node_index = 0;
    for(int i=0; i<16; i++){
        for(int j=0; j<16; j++){
            inputNodes[node_index] = node(node_id, grid[i][j]);
            node_id ++;
            node_index ++;
        }
    }

    bool running = true;
    
    windowManager manager = windowManager();
    manager.initWindow();

    while(running){
        if(manager.checkEventsAndShouldQuit() == false){ 
            break;
        }

        manager.drawBoxes(grid);
        manager.updateDrawing(grid);
        manager.displayAndWait();


        // TTF_Init();
        // TTF_Font* font = TTF_OpenFont("../assets/Debrosee-ALPnL.ttf", 24);
        // SDL_Color White = {255, 255, 255};
        // SDL_Surface* surfaceMessage = TTF_RenderText_Solid(font, "Clear", White); 
        // SDL_Texture* Message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);
        // SDL_Rect Message_rect; //create a rect
        // Message_rect.x = 410;  //controls the rect's x coordinate 
        // Message_rect.y = 0; // controls the rect's y coordinte
        // int textw, texth;
        // TTF_SizeText(font, "Clear", &textw, &texth);
        // Message_rect.w = textw; // controls the width of the rect
        // Message_rect.h = texth; // cont
        // SDL_RenderCopy(renderer, Message, NULL, &Message_rect);
        // SDL_FreeSurface(surfaceMessage);
        // SDL_DestroyTexture(Message);


        
    }

    SDL_Quit();
    std::cout<<"Window closed"<<std::endl;
    return 0;
}



