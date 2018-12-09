#ifndef listNode_h
    #define listNode_h
    #include "listNode.hpp"
#endif

#include <vector>
#include <sstream>

using namespace std;

class adjacencyNode {
    private:
        int count;
        bool check;
        char name;
        listNode *head;

    protected:
        void deleteList( listNode *root );
        bool addListNode( char name );
        void travel( listNode *root , void display( listNode &root ) , void go( listNode &root , ostream &os) );

    public:
        adjacencyNode( char input );
        ~adjacencyNode();

        char getName();
        int getCount();
        bool getCheck();
        listNode* getHead();

        void decreaseCount();
        void increaseCount();
        void setCheck();

        void deleteListHelper();
        bool addListNodeHelper( char name );

        void travelHelper( void display( listNode &root ) , void go( listNode &root , ostream &os ) );
        vector< char > updateList();
};
