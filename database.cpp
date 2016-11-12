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
	size_t key = hash_fn(n.primaryKey);
	hashTable_.erase(key);
}


void Database::addNode(Node n)
{
	size_t key = hash_fn(n.primaryKey);
	iterator insertItr = hashTable_.find(key);
	hashTable_.insert(insertItr,n);
}

Node Database::getNodeWithRelationship(Node& n, std::string tag)
{
	size_t key = hash_fn(n.primaryKey);
	Node thisNode = hashTable_->find(key);
	list<relation_type> relList = thisNode->relationships;
	for(iterator listItr = relList.begin(); listItr != relList.end(); ++listItr)
	{
		if (listItr->tag == tag)
		{
			return listItr->other;
		}
	}
	return null;
}

string Database::getRelationship(Node& n1, Node& n2)
{
	size_t key = hash_fn(n.primaryKey);
	Node node1 = hashTable_->find(key);
	return node1.getRelationship(n2);
}

void Database::addType()
{

}