#ifndef node_h
    #define node_h
    #include "node.hpp"
#endif

#ifndef listNode_h
    #define listNode_h
    #include "listNode.hpp"
#endif

#include <new>
#include <vector>

using namespace std;

adjacencyNode::adjacencyNode( char input ) : count( 0 ) , check( false ) , name( input ) , head( nullptr ) {

}

adjacencyNode::~adjacencyNode() {
    this->deleteList( this->head );
    this->head = nullptr;
}

void adjacencyNode::travelHelper( void display( listNode &root ) ) {
    this->travel( this->head , display );
}

void adjacencyNode::travel( listNode *root , void display( listNode &root ) ) {
    while ( root != nullptr ) {
        display( *root );
        root = root->getNext();
    }
    return;
}

void adjacencyNode::deleteListHelper() {
    this->deleteList( this->head );
}

void adjacencyNode::deleteList( listNode *root ) {
    if ( root == nullptr ) {
        return;
    }
    this->deleteList( root->getNext() );
    delete root;
    root = nullptr;
}

vector< char > adjacencyNode::updateList() {
    vector< char > temp;
    listNode *root = this->head;

    while ( root != nullptr ) {
        temp.push_back( root->getName() );
        root = root->getNext();
    }

    return temp;
}

bool adjacencyNode::addListNodeHelper( char name ) {
    return this->addListNode( name );
}

bool adjacencyNode::addListNode( char name ) {
    listNode *temp = this->head , *newNode;

    try {
        newNode = new listNode( name );
    }
    catch ( bad_alloc ) {
        // bad_alloc define in <new> , namespace std
        return false;
    } // new failed

    if ( temp == nullptr ) {
        head = newNode;
    }
    else {
        while ( temp->getNext() != nullptr ) {
            temp = temp->getNext();
        }
        temp->setNext( newNode );
    }
    return true;
}

int adjacencyNode::getCount() {
    return this->count;
}

bool adjacencyNode::getCheck() {
    return this->check;
}

char adjacencyNode::getName() {
    return this->name;
}

void adjacencyNode::increaseCount() {
    this->count++;
    return;
}

void adjacencyNode::decreaseCount() {
    this->count--;
    return;
}

void adjacencyNode::setCheck() {
    this->check = true;
    return;
}
