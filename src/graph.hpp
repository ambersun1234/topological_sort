#ifndef node_h
    #define node_h
    #include "node.hpp"
#endif

class graph {
    private:
        adjacencyNode **table;
        int size;

    public:
        graph( int size );
        ~graph();
        char getName( int index );
};
