#include <iostream>
#include <string>

#ifndef node_h
    #define node_h
    #include "node.hpp"
#endif

#ifndef graph_h
    #define graph_h
    #include "graph.hpp"
#endif

#ifndef listNode_h
    #define listNode_h
    #include "listNode.hpp"
#endif

using namespace std;

void displayList( listNode &root ) {
    cout << " " << root.getName();
}

int main( int argc , char const *argv[] ) {
    int tableSize;

    cout << "how many node in the graph: ";
    cin >> tableSize;
    graph *table = new graph( tableSize );

    for ( int i = 0 ; i < tableSize ; i++ ) {
        int temp;
        cout << "node " << table->getNameHelper( i ) << " has how many adjacent node: ";
        cin >> temp;

        if ( temp > 0 ) {
            char tempNode;
            cout << "\tplease enter nodes that node " << table->getNameHelper( i ) << " adjacent of: ";
            for ( int j = 0 ; j < temp ; j++ ) {
                cin >> tempNode;
                table->increaseCountHelper( ( int )tempNode - 65 );
                table->setNodeHelper( i , tempNode );
            }
        } // end if
    }

    for ( int i = 0 ; i < tableSize ; i++ ) {
        cout << "node " << table->getNameHelper( i ) <<
            " , count = " << table->getCountHelper( i ) <<
            " , check = " << boolalpha << table->getCheckHelper( i ) <<
            " ->";
        table->travelListHelper( i , displayList );
        cout << endl;
    }

    delete table;

    return 0;
}
