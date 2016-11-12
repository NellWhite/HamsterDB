/* node.hpp
 *
 * Interface definition of the Node class
 *
 */

#ifndef NODE_HPP_INCLUDED
#define NODE_HPP_INCLUDED = 1;

#include <string>
#include <unordered_set>
#include <unordered_map>
#include <list>

class Node {

private:

  //   class Relationship {
  //      Node * other;
  //      bool passive; // If the other node has this relationship towards this
  //   };

  class RelationshipType;
  class Relationship;
  //  class RelationshipType {
  //      std::string tag;
  //      std::unordered_map<const Node*, Relationship> relationshipInstances;
  //  };


public:
    
    using relation_type = RelationshipType;
    using ship = Relationship;

    // data members

    // This is a list that contains all the relationships a Node has 
    std::list<relation_type> relationships; 
    std::string primaryKey;
    
    // Functions
    
    // This adds a relationship between this and the given Node
    // The time scales linearly with the number of relationships this has
    void addRelationship(Node* other, std::string tag, bool passive);

    // This removes relationship specified by tag and passive, which
    // exists between this node and the given Node
    // The time scales linearly with the number of relationships this has
    void removeRelationship(Node* n, std::string tag, bool passive);

    /* \brief This returns the relationship shared between this and Node n 
     *
     * \remarks returns a default relationship when there is no relationship
     */
    ship getRelationship(Node* other); 


    /*
     * \brief This returns a list of Nodes with this relationship
     *
     */
    std::list<Relationship> getNodesWithRel(std::string tag, bool passive); 
    
    // Sometimes it is useful to print things
    std::ostream& print(std::ostream& out) const;

private:


    struct Relationship {
        Node * other;
        bool passive; // If the other node has this relationship towards this
    };


    using r = Relationship;

    // This a struct for the relationship objects
    struct RelationshipType {
        std::string tag;
        std::unordered_map<Node*, Relationship> relationshipInstances;
    };

};

#endif
