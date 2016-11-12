/**
* \file database.cpp
*
* \authors Mackenzie Kong-Sivert
*
* \brief Implements the Database class.
*/

#include "database.hpp"
#include "node.hpp"

using namespace std;

void Database::removeNode(Node& n)
{
	//size_t key = hash_fn(n.primaryKey);
	hashTable_.erase(n.primaryKey);
}


void Database::addNode(Node n)
{
	//size_t key = hash_fn(n.primaryKey);
	iterator insertItr = hashTable_.find(n.primaryKey);
	hashTable_.insert(insertItr,n);
}

std::list<Node> Database::getNodeWithRelationship(Node& n, std::string tag)
{
	//size_t key = hash_fn(n.primaryKey);
	Node thisNode = hashTable_->find(n.primaryKey);
	list<Node::relation_type> relList = thisNode.relationships;
	for(list<Node::relation_type>::iterator listItr = relList.begin(); listItr != relList.end(); ++listItr)
	{
		if (listItr->tag == tag)
		{
            // create a list of Nodes
            auto shipList = listItr->relationshipInstances;
            std::list<Node> nodeList;
            for ( auto i = shipList.begin(); i != shipList.end(); ++i) {
                nodeList.push_back(*(i->second.other));
            }
			return nodeList;
		}
	}
	// maybe find a less sketchy thing to do if what we're looking for
	// is not in the list?
    std::list<Node> emptyList;
	return emptyList;
}

string Database::getRelationship(Node& n1, Node* n2)
{
	//size_t key = hash_fn(n1.primaryKey);
	Node node1 = hashTable_->find(n1.primaryKey);
	return node1.getRelationship(n2).other->primaryKey;
}

void Database::addType(string typeName)
{

}
