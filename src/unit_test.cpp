#include <iostream>
#include <sstream>
#include <string>

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

extern ostringstream oss; // reference to ./node.cpp line 18

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

class adjacencyNodeTest : public testing::Test {
    protected:
        adjacencyNode *ad1 = new adjacencyNode( 'A' );
        adjacencyNode *ad2 = new adjacencyNode( 'B' );
    public:
        static void go( listNode &root , ostream &os = cout ) {
            os << " " << root.getName();
        }
        static void displayList( listNode &root ) {

        }
};

TEST_F( adjacencyNodeTest , constructor ) {
    EXPECT_EQ( ad1->getName() , 'A' );
    EXPECT_GT( ad2->getName() , 'A' );
    EXPECT_TRUE( ad1->getCount() == 0 );
    EXPECT_LT( ad2->getCount() , 1 );
    EXPECT_TRUE( !ad1->getCheck() );
    EXPECT_FALSE( ad2->getCheck() );
    EXPECT_TRUE( ad1->getHead() == nullptr );
    EXPECT_EQ( ad2->getHead() , nullptr );
}

TEST_F( adjacencyNodeTest , travel ) {
    EXPECT_EQ( ad1->addListNodeHelper( 'B' ) , true );
    EXPECT_TRUE( ad1->addListNodeHelper( 'Y' ) );
    EXPECT_FALSE( !ad1->addListNodeHelper( 'C' ) );

    oss.str( string() );
    ad1->travelHelper( displayList , go );
    assert( oss && oss.str() == " B Y C" );
    oss.str( string() );

    oss.str( string() );
    ad2->travelHelper( displayList , go );
    assert( oss && oss.str() == "" );
    oss.str( string() );

    ad1->deleteListHelper();
    oss.str( string() );
    ad1->travelHelper( displayList , go );
    assert( oss && oss.str() == "" );
    oss.str( string() );
    EXPECT_EQ( ad1->getHead() , nullptr );
}

TEST_F( adjacencyNodeTest , setter ) {
    for ( int i = 0 ; i < 10 ; i++ ) {
        ad1->increaseCount();
    }
    EXPECT_EQ( ad1->getCount() , 10 );
    for ( int i = 0 ; i < 2 ; i++ ) {
        ad1->decreaseCount();
    }
    EXPECT_GT( ad1->getCount() , 5 );

    ad2->increaseCount();
    ad2->increaseCount();
    ad2->increaseCount();
    EXPECT_LT( ad2->getCount() , 8 );

    ad1->setCheck();
    EXPECT_TRUE( ad1->getCheck() );
}

GTEST_API_ int main( int argc , char *argv[] ) {
    testing::InitGoogleTest( &argc , argv );
    return RUN_ALL_TESTS();
}
