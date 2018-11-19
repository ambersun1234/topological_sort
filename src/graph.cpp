#ifndef graph_h
    #define graph_h
    #include "graph.hpp"
#endif

#ifndef node_h
    #define node_h
    #include "node.hpp"
#endif

graph::graph( int size ) {
    this->size = size;
    this->table = new adjacencyNode*[ size ];

    for ( int i = 0 ; i < size ; i++ ) {
        this->table[ i ] = new adjacencyNode( ( i + 65 ) );
    }
}

graph::~graph() {
    for ( int i = 0 ; i < this->size ; i++ ) {
        delete this->table[ i ];
    }
    delete this->table;
}

char graph::getName( int index ) {
    return this->table[ index ]->getName();
}
