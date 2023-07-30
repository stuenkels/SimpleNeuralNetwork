#include "config.h"

//recogize digits nueral network
//Perhaps a gui coming later
//We create a 2d array repersenting a square 16*16
//Each value will be either 0 or 1, repersenting colored in or not colored in
//we will have 256 input layer nodes

float grid[16][16];

int main(){

    node inputNodes[256];


    float counter = 0.0;
    for(int i=0; i<16; i++){
        for(int j=0; j<16; j++){
            grid[i][j] = counter;
            counter += 1.0;
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

    return 0;
}