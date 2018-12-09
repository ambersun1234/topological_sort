#include <iostream>

#include "gtest/gtest.h"

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

class listNodeTest : public testing::Test {
    protected:
        listNode *ln1 = new listNode( 'C' );
        listNode *ln2 = new listNode( 'O' );
};

TEST_F( listNodeTest , constructor ) {
    EXPECT_EQ( ln1->getNext() , nullptr );
    EXPECT_EQ( ln2->getNext() , nullptr );
    EXPECT_EQ( ln1->getName() , 'C' );
    EXPECT_GT( ln2->getName() , 'A' );
}

TEST_F( listNodeTest , setter ) {
    EXPECT_TRUE( ln1->setName( 'B' ) );
    EXPECT_EQ( ln1->getName() , 'B' );
    ln1->setNext( ln2 );
    EXPECT_EQ( ln1->getNext() , ln2 );
}

GTEST_API_ int main( int argc , char *argv[] ) {
    testing::InitGoogleTest( &argc , argv );
    return RUN_ALL_TESTS();
}
