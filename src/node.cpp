#ifndef node_h
    #define node_h
    #include "node.hpp"
#endif

adjacencyNode::adjacencyNode( char input ) : count( 0 ) , check( 0 ) , name( input ) {

}

char adjacencyNode::getName() {
    return this->name;
}
