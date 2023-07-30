#include "node.h"

//
node::node(int id, float startValue){
    node_id = id;
    value = startValue;
}

//Default constructor should not be called unless defining array, nothing here to make program faster 
node::node(){
}


int node::get_node_id(){
    return node_id;
}

void node::update_value(float newValue){
    value = newValue;
}

void node::update_given_node(node& given_node, float weight){
    given_node.add_to_sum(value*weight);
}

void node::update_value_from_sum(){
    value = sum/accesses;
}

void node::add_to_sum(float ammout){
    value += ammout;
    accesses ++;
}

float node::get_node_value(){
    return value;
}
