#include <iostream>
#include <string>
#include <sstream>
#include <stack>
#include <vector>

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

void go( listNode &root , ostream &os = cout ) {

}

void displayList( listNode &root ) {
    cout << " " << root.getName();
}

int main( int argc , char const *argv[] ) {
    int tableSize;
    stack< char > topologicalStack;
    vector< char > tempList;

    cout << "how many node in the graph: ";
    cin >> tableSize;
    graph *table = new graph( tableSize );

    for ( int i = 0 ; i < tableSize ; i++ ) {
        int temp;
        cout << "node " << table->getNameHelper( i ) << " has how many adjacent node: ";
        cin >> temp;
        if ( temp > tableSize ) {
            cout << "adjacent node number can't be larger than table size , abort" << endl;
            return 1;
        }

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
    cout << endl;

    for ( int i = 0 ; i < tableSize ; i++ ) {
        if ( table->getCountHelper( i ) == 0 ) {
            topologicalStack.push( ( char )( i + 65 ) );
            table->setCheckHelper( i );
        }

        cout << "node " << table->getNameHelper( i ) <<
            " , count = " << table->getCountHelper( i ) <<
            " , check = " << boolalpha << table->getCheckHelper( i ) <<
            " ->";
        table->travelListHelper( i , displayList , go );
        cout << endl;
    }
    cout << endl;

    if ( topologicalStack.empty() == true ) {
        cout << "This graph can not be sort." << endl;
        return 0;
    }
    else {
        // this graph can be sort
        cout << "Ans:";
        while ( !topologicalStack.empty() ) {
            char ans = topologicalStack.top();
            topologicalStack.pop();

            cout << " " << ans;

            tempList = table->updateListHelper( ( int )ans - 65 );

            for ( vector< char >::iterator iter = tempList.begin() ; iter != tempList.end() ; ++iter ) {
                table->decreaseCountHelper( ( int )( *iter ) - 65 );
            }

            for ( int i = 0 ; i < tableSize ; i++ ) {
                if ( table->getCheckHelper( i ) == false && table->getCountHelper( i ) == 0 ) {
                    topologicalStack.push( ( char )( i + 65 ) );
                    table->setCheckHelper( i );
                }
            }
        } // end while loop
        cout << endl;
    }

    delete table;

    return 0;
}
