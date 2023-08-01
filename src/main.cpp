#include "config.h"

//recogize digits nueral network
//Perhaps a gui coming later
//We create a 2d array repersenting a square 16*16
//Each value will be either 0 or 1, repersenting colored in or not colored in
//we will have 256 input layer nodes

float grid[16][16];
SDL_Rect rects[16][16];


void update_mouse_vars(int* x, int* y, bool* mouseDown, bool* mouseDownOnFrame);
int mouse_coordanates_to_grid(int value);


int main(){
    //SDL code for window
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();
    SDL_Window *window = nullptr;
    SDL_Renderer *renderer  = nullptr;
    SDL_CreateWindowAndRenderer(1000,800,0,&window, &renderer);
    SDL_RenderSetScale(renderer, 2, 2);

    


    node inputNodes[256];


    for(int i=0; i<16; i++){
        for(int j=0; j<16; j++){
            grid[i][j] = 0.0;

            rects[i][j].x = i*25;
            rects[i][j].y = j*25;
            rects[i][j].w = 25;
            rects[i][j].h = 25;
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


    for(int i=0; i<256; i++){
        std::cout<<inputNodes[i].get_node_value()<< std::endl;
    }

    std::cout << "Done " << std::endl;


    bool running = true;
    int mouseX, mouseY;
    bool mouseDown, mouseDownOnFrame;
    bool drawing = true;



    while(running){
        SDL_Event e;
        while(SDL_PollEvent(&e)){
            if(e.type == SDL_QUIT){
                running = false;
            }
        }
        if(running == false){ //breaking before would just jump out of the nested while loop, we need to jump out of the other one too
            break; 
        }
        update_mouse_vars(&mouseX, &mouseY, &mouseDown, &mouseDownOnFrame);
       



        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);


        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

        for(int i=0; i<16; i++){
            for(int j=0; j<16; j++){
                SDL_RenderDrawRect(renderer, &rects[i][j]);
            }
        }


        for(int i=0; i<16; i++){
            for(int j=0; j<16; j++){
                if(grid[i][j]==1.0){
                    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
                    SDL_RenderFillRect(renderer, &rects[i][j]);
                    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
                    SDL_RenderDrawRect(renderer, &rects[i][j]);
                }
            }
        }

        //Draw selected coordanate
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

        TTF_Init();
        TTF_Font* font = TTF_OpenFont("../assets/Debrosee-ALPnL.ttf", 24);
        SDL_Color White = {255, 255, 255};
        SDL_Surface* surfaceMessage = TTF_RenderText_Solid(font, "Clear", White); 
        SDL_Texture* Message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);
        SDL_Rect Message_rect; //create a rect
        Message_rect.x = 410;  //controls the rect's x coordinate 
        Message_rect.y = 0; // controls the rect's y coordinte
        int textw, texth;
        TTF_SizeText(font, "Clear", &textw, &texth);
        Message_rect.w = textw; // controls the width of the rect
        Message_rect.h = texth; // cont
        SDL_RenderCopy(renderer, Message, NULL, &Message_rect);
        SDL_FreeSurface(surfaceMessage);
        SDL_DestroyTexture(Message);


        SDL_RenderPresent(renderer);
        SDL_Delay(10);
    }

    SDL_Quit();
    std::cout<<"Window closed"<<std::endl;
    return 0;
}


void update_mouse_vars(int* x, int* y, bool* mouseDown, bool* mouseDownOnFrame){ //probally should move this to seperate file but ill do that later :)
    int tempx, tempy; //doing this because im dumb dumb

    if(SDL_GetMouseState(&tempx, &tempy) & SDL_BUTTON_LMASK){
        if(*mouseDown ==false){
            *mouseDownOnFrame = true;
        }else{
            *mouseDownOnFrame = false;
        }
        *mouseDown = true;
    }else{
        *mouseDown = false;
    }
    *x = tempx;
    *y = tempy;
}

int mouse_coordanates_to_grid(int value){
    return value/2/25;
}




