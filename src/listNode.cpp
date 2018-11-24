#ifndef listNode_h
    #define listNode_h
    #include "listNode.hpp"
#endif

listNode::listNode( char name ) : name( name ) , next( nullptr ) {

}

bool listNode::setNext( listNode *input ) {
    this->next = input;
    return this->next == input ? true : false;
}

listNode* listNode::getNext() {
    return this->next;
}

bool listNode::setName( char name ) {
    this->name = name;
    return this->name == name ? true : false;
}

char listNode::getName() {
    return this->name;
}
