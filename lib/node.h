#pragma once

#define TEST 1

class node{
    int node_id;
    float value;
    float sum;
    int accesses;
    //pointers used to pervent recursion 
    //change array size later
    node *inputNodes[1];
    node *outputNodes[1];

    public:
     //constructor
     node(int, float);
     node(); //default
 

     int get_node_id();
     void update_value(float); //should only be used on input nodes
     void update_given_node(node&, float); //adds to sum of node passed in 
     void update_value_from_sum(); //updates self value, called after all nodes from previous layer have had updat_given_nodes(); called
     void add_to_sum(float); //how a node from one layer will change the value of a node from another layer
     float get_node_value(); //gets value, prob just for debugging
};