/**
 * \file database.hpp
 *
 * \authors Nelll White and Mackenzie Kong-Sivert
 *
 * \brief Declares the Database class.
 */

#ifndef DATABASE_HPP_INCLUDED
#define DATABASE_HPP_INCLUDED 1

#include <cstddef>
#include <string>
#include <list>
#include <functional>
#include <iostream>
#include <type_traits>

/**
 * \class Database
 * \brief Stores Node objects and their relationships to one another
 *    in a hash table
 *
 * \details
 *
 * \remarks
 */
class Database {

public:

    /**
     * \brief Removes a Node from the Database
     *
     * \details
     * If the Database hash table does not have that Node, do nothing.
     * Otherwise, remove from the Database hash table.
     *
     * \param n   Node to remove
     * 
     * \note constant time
     */
    void removeNode(Node& n);

    /**
     * \brief Inserts a Node at the end of the Database
     *
     * \details Inserts Node into the hash table that stores all the Nodes
     *
     * \param n   Node to insert
     * 
     * \note constant time
     */
    void addNode(Node n);

    /**
     * \brief Finds the Node with a given relationship
     *
     * \details
     *  Seaches through all the Nodes and finds the ones with a given
     *  relationship to the given node
     *
     * \param tag  the given relationship   
     * \param n    the given node
     *
     * \returns a Node with the given relationship to the given node
     * 
     * \note linear time
     */
    Node getNodeWithRelationship(Node& n, std::string tag);

    /**
     * \brief finds the relationship between the two inputs
     *
     * \details looks up n1 and returns its relationship to n2
     *
     * \param n1     Node with the relationship
     * \param n2     Node to which the relationship applies
     * 
     * \remarks this returns Null if it has no relationship with Node n
     * 
     * \note linear(?) time
     */
    std::string getRelationship(Node& n1, Node& n2);

    /* 
     * \details This creates the hash tables that allows one to query
     *     using different fields
     */
    void addType()


private:

    // hash table of fields and pointers to Nodes
    std::hash<std::string> hash_fn;
    unordered_set<size_t,Node> hashTable_;
}
