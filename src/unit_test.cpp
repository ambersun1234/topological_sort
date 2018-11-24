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

GTEST_API_ int main( int argc , char **argv ) {
    testing::InitGoogleTest( &argc , argv );
    return RUN_ALL_TESTS();
}
