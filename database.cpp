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
	for(iterator tableItr = hashTable_.begin(); tableItr != hashTable_.end(); ++tableItr)
	{
		list<relation_type> relList = tableItr->relationships;
		for(iterator listItr = relList.begin(); listItr != relList.end(); ++listItr)
		{
			if (listItr->tag == tag)
			{
				return listItr->other;
			}
		}
	}
	return null;
}

string Database::getRelationship(Node& n1, Node& n2)
{
	size_t key = hash_fn(n);
	Node node1 = hashTable_->find(key);
	for(iterator listItr = relList.begin(); listItr != relList.end(); ++listItr)
	{
		//find person, get relationship
	}
	return null;
}

void Database::addType()
{

}