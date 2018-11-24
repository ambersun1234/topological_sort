#ifndef node_h
    #define node_h
    #include "node.hpp"
#endif

#ifndef listNode_h
    #define listNode_h
    #include "listNode.hpp"
#endif

class graph {
    private:
        adjacencyNode **table;
        int size;

    protected:
        bool setNode( int index , char name );

    public:
        graph( int size );
        ~graph();

        bool setNodeHelper( int index , char name );

        char getNameHelper( int index );
        void travelListHelper( int index , void display( listNode &root ) );
        vector< char > updateListHelper( int index );

        int getCountHelper( int index );
        bool getCheckHelper( int index );
        void setCheckHelper( int index );
        void decreaseCountHelper( int index );
        void increaseCountHelper( int index );
};
