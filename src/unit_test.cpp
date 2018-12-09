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

static void go( listNode &root , ostream &os = cout ) {
    os << " " << root.getName();
}
static void displayList( listNode &root ) {

}

class adjacencyNodeTest : public testing::Test {
    protected:
        adjacencyNode *ad1 = new adjacencyNode( 'A' );
        adjacencyNode *ad2 = new adjacencyNode( 'B' );
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

class graphTest : public testing::Test {
    protected:
        graph *g1 = new graph( 5 );
        graph *g2 = new graph( 10 );
};

TEST_F( graphTest , constructor ) {
    EXPECT_EQ( g1->size , 5 );
    EXPECT_LT( g2->size , 11 );

    for ( int i = 0 ; i < 5 ; i++ ) {
        EXPECT_EQ( static_cast< int >( g1->table[ i ]->getName() ) , 65 + i );
        EXPECT_FALSE( g1->table[ i ]->getHead() );
    }
    for ( int i = 0 ; i < 10 ; i++ ) {
        EXPECT_EQ( static_cast< int >( g2->table[ i ]->getName() ) , 65 + i );
        EXPECT_TRUE( !g2->table[ i ]->getHead() );
    }
}

TEST_F( graphTest , setter_getter ) {
    EXPECT_TRUE( g1->setNodeHelper( 2 , 'C' ) );
    EXPECT_FALSE( !g1->setNodeHelper( 4 , 'A' ) );
    EXPECT_EQ( g1->getNameHelper( 2 ) , 'C' );
    EXPECT_GT( g1->getNameHelper( 4 ) , 'B' );

    EXPECT_EQ( g2->setNodeHelper( 9 , 'P' ) , true );
    EXPECT_TRUE( g2->setNodeHelper( 9 , 'O' ) );
    EXPECT_GT( g2->getNameHelper( 9 ) , 'H' );

    EXPECT_EQ( g1->getCountHelper( 0 ) , 0 );
    EXPECT_TRUE( !g1->getCheckHelper( 3 ) );

    g2->setCheckHelper( 2 );
    EXPECT_FALSE( !g2->getCheckHelper( 2 ) );

    for ( int i = 0 ; i < 4 ; i++ ) {
        g1->increaseCountHelper( 0 );
    }
    EXPECT_LT( g1->getCountHelper( 0 ) , 5 );
    g1->decreaseCountHelper( 0 );
    g1->decreaseCountHelper( 0 );
    EXPECT_EQ( g1->getCountHelper( 0 ) , 2 );
}

TEST_F( graphTest , travel ) {
    EXPECT_EQ( g2->setNodeHelper( 9 , 'P' ) , true );
    EXPECT_TRUE( g2->setNodeHelper( 9 , 'O' ) );
    oss.str( string() );
    g2->travelListHelper( 9 , displayList , go );
    assert( oss && oss.str() == " P O" );
    oss.str( string() );

    EXPECT_FALSE( !g1->setNodeHelper( 4 , 'A' ) );
    oss.str( string() );
    g1->travelListHelper( 4 , displayList , go );
    assert( oss && oss.str() == " A" );
    oss.str( string() );
}

GTEST_API_ int main( int argc , char *argv[] ) {
    testing::InitGoogleTest( &argc , argv );
    return RUN_ALL_TESTS();
}
