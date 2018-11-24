class listNode {
    private:
        char name;
        listNode *next;

    public:
        listNode( char name );

        bool setNext( listNode *input );
        listNode* getNext();
        bool setName( char name );
        char getName();
};
