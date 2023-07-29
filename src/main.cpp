#include "config.h"

int main(){

    node myNode = node(23);
    int value = myNode.get_node_id();

    std::cout << "Vlaue: " << value << std::endl;

    return 0;
}