#include "node.hpp"

bool member(std::list<Node::relation_type> l, std::string value) {
    for (auto i = l.begin(); i != l.end();++ i) {
        if(value == i->tag) {
            return true;
        }
    }
    return false;
}


// This is a function to find if a tag key is in the relationship list
//template<typename t, typename r>
Node::relation_type find(std::list<Node::relation_type> l, std::string value) {
    for (auto i = l.begin(); i != l.end();++ i) {
        if(value == i->tag) {
            return *i;
        }
    }
 }

bool findAndDelete(std::list<Node::relation_type> l, std::string value) {
    for (auto i = l.begin(); i != l.end();++ i) {
        if(value == i->tag) {
            l.erase(i);
            return true;
        }
    }
    return false;
}

void Node::addRelationship(Node* other, std::string tag, bool passive) {
   
   // If the relationship is already in the list
   if(member(this->relationships, tag)) {
       
       Node::relation_type currentRel = find(this->relationships, (tag));
       
       // Check if this relationship with this Node already exists
       if(currentRel.relationshipInstances.find(other) 
          != currentRel.relationshipInstances.end()) {
           return; // do nothing
       }
       // otherwise, push a new relationshipInstance node
       Relationship r;
       r.other = other;
       r.passive = passive;
       // make a pair in order to insert
       currentRel.relationshipInstances.insert(std::make_pair(other, r));
       return;
   }

   // If the relationship is not yet in the list 
   
   // create a new relationship object with appropriate values
   RelationshipType rt;
   rt.tag = tag;
   Relationship r;
   r.other = other;
   r.passive = passive;
   rt.relationshipInstances.insert(std::make_pair(other,r));

   // add this relationship to the list
   this->relationships.push_front(rt);


   // if this is not a passive relationship, we need to add it to the other Node
   if (! passive) { 
       other->addRelationship(this, tag, true);
   }
}


// This is a generic function to find if a value is in a list
template<typename t>
bool member(t value, std::list<t> l) {
    for (auto i = l.begin(); i != i.end;++ i) {
        if(value == *i) {
            return i;
        }
    }
    return l.end();
}


void Node::removeRelationship(Node* other, std::string tag, bool passive) {
   
   // find the right type of relationship
   relation_type currentRel = find(this->relationships, (tag));

   // remove the relationship
   currentRel.relationshipInstances.erase(other);

   // if this type of relationships is now empty, remove it from the set
   if (currentRel.relationshipInstances.empty()) {
        findAndDelete(this->relationships, tag); 
   }

   // If the relationship is not passive, remove the associated passive relationship
   if (!passive) {
        other->removeRelationship(this, tag, true);
   }
}

Node::ship Node::getRelationship(Node* other) {
    for(auto i = this->relationships.begin(); i != this->relationships.end();
                                        ++i) {
        // check if the Node is connected by this relationship
        // assumes only one relationship between Nodes
        relation_type currentRel = *i;
        if (i->relationshipInstances.find(other) 
           != i->relationshipInstances.end()) {
            Node::ship s = i->relationshipInstances.find(other)->second;
            return s;
        }
    }
    // a default relationship means no relationship was found
    Relationship r;
    return r;
}

std::ostream& Node::print(std::ostream& out) const
{
  out << primaryKey;
}
