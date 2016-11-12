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

Database::Database()
{
	//Nothing to do yet
}

void Database::removeNode(Node& n)
{
	size_t key = hash_fn(n);
	hashTable_.erase(key);
}


void Database::addNode(Node n)
{
	size_t key = hash_fn(n);
	iterator insertItr = hashTable_.find(key);
	hashTable_.insert(insertItr,n);
}

Node Database::getNodeWithRelationship(std::string tag)
{
	for(iterator itr = hashTable_.begin(); itr < hashTable_.end(); ++itr)
	{
		// this will depend on the implementation of the Node class
		return null;
	}
}

string Database::getRelationship(Node& n)
{
	size_t key = hash_fn(n);
	Node thisNode = hashTable_->find(key);
	// this will depend on the implementation of the Node class
	return null;
}

void Database::addType()
{

}