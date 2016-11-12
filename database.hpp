
// include guards etc


class Database {

public:

    removeNode(Node& n);

    addNode(Node n);

    getNodeWithRelationship(std:string tag);


    /*
     * \brief gets a relationship between this and another node
     * 
     * \returns a string with the type of the relationship
     *
     * \remarks this returns Null if it has no relationship with Node n
     */
    getRelationship(Node& n);


    /* 
     * \details This creates the hash tables that allows one to query
     *     using different fields
     */
    addType()


private:

    // hashTable of fields and pointers to Nodes
    //








}


