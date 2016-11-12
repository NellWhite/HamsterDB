/* node.hpp
 *
 * Interface definition of the Node class
 *
 */

#ifndef NODE_HPP_INCLUDED
#define NODE_HPP_INCLUDED = 1;

#include <std>


class Node {

public:
    
    using relation_type = RelationshipType

    // data members

    // This is a list that contains all the relationships a Node has 
    std::list<relation_type> relationships; 

    
    // Functions
    
    // This adds a relationship between this and the given Node
    // The time scales linearly with the number of relationships this has
    void addRelationship(Node* other, std::string tag);

    // This removes whatever relationships exist between this node and the 
    // given Node
    // The time scales linearly with the number of relationships this has
    void removeRelationship(Node* n);

    /* \brief This returns the relationship shared between this and Node n 
     *
     * \remarks returns null when there is no relationship
     */
    void getRelationship(Node*); 


private:

    struct Relationship {
        Node * other;
        bool passive; // If the other node has this relationship towards this
    }
    
    // This a struct for the relationship objects
    struct RelationshipType {
        std::string tag;
        std::unordered_set<Node*, Relationship> relationshipInstances;
    }

}
