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

using namespace std;

int main( int argc , char const *argv[] ) {
    adjacencyNode *adjno = new adjacencyNode( 'L' );
    graph *table = new graph( 10 );

    cout << adjno->getName() << endl;

    for ( int i = 0 ; i < 10 ; i++ ) {
        cout << table->getName( i ) << endl;
    }

    delete adjno;
    delete table;

    return 0;
}
