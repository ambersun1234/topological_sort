#ifndef graph_h
    #define graph_h
    #include "graph.hpp"
#endif

#ifndef node_h
    #define node_h
    #include "node.hpp"
#endif

#ifndef listNode_h
    #define listNode_h
    #include "listNode.hpp"
#endif

#include <sstream>

using namespace std;

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

vector< char > graph::updateListHelper( int index ) {
    return this->table[ index ]->updateList();
}

int graph::getCountHelper( int index ) {
    return this->table[ index ]->getCount();
}

bool graph::getCheckHelper( int index ) {
    return this->table[ index ]->getCheck();
}

void graph::setCheckHelper( int index ) {
    this->table[ index ]->setCheck();
}

void graph::decreaseCountHelper( int index ) {
    this->table[ index ]->decreaseCount();
}

void graph::increaseCountHelper( int index ) {
    this->table[ index ]->increaseCount();
}

void graph::travelListHelper( int index , void display( listNode &root ) , void go( listNode &root , ostream &os ) ) {
    this->table[ index ]->travelHelper( display , go );
}

char graph::getNameHelper( int index ) {
    return this->table[ index ]->getName();
}

bool graph::setNode( int index , char name ) {
    return this->table[ index ]->addListNodeHelper( name );
}

bool graph::setNodeHelper( int index , char name ) {
    return this->setNode( index , name );
}
