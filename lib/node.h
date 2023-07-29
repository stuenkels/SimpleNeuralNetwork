#pragma once

#define TEST 1

class node{
    int node_id;
    
    //pointers used to pervent recursion 
    //change array size later
    node *inputNodes[1];
    node *outputNodes[1];

    public:
     //constructor
     node(int);
     //deconstructor
    

     int get_node_id();

    
};