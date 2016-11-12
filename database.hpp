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
     *  relationship to this object
     *
     * \param tag  the given relationship   

     * \returns a Node with the given relationship to this object
     * 
     * \note linear time
     */
    Node getNodeWithRelationship(std:string tag);

    /**
     * \brief finds the relationship between this and the given Node
     *
     * \details
     *
     * \param n     Node to look up
     * 
     * \note constant time
     */
    string getRelationship(Node& n);

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

    // hash table of fields and pointers to Nodes
    hash<Node> nodes_;

}
