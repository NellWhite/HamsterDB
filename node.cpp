


void Node::addRelationship(Node* other, std::string tag, bool passive) {
   
   // If the relationship is already in the list
   if(this.relationships.find(tag) != this.relationships.end()) {
       
       relation_type currentRel = this.relationships.find(tag);
       
       // Check if this relationship with this Node already exists
       if(currentRel.find(others) != currentRel.end()) {
           return; // do nothing
       }
       currentRel.push_front(other); // otherwise, push this node
       return
   }

   // If the relationship is not yet in the list 
   
   // create a new relationship object with appropriate values
   RelationshipType rt;
   rt.tag = tag;
   Relationship r;
   r.others = other;
   r.passive = passive;
   rt.relationshipInstances = r;

   // add this relationship to the list
   relationships.push_front(rt);


   // if this is not a passive relationship, we need to add it to the other Node
   if (! passive) { 
       other.addRelationship(this, tag, true);
   }
}


// This is a generic function to find if a value is in a list
template<typename t>
bool member(t value, std::list<t> l) {
    for (std::list::iterator i = i.begin(); i != i.end;++ i) {
        if(value == *i) {
            return true;
        }
    }
    return false;
}


void Node::removeRelationship(Node* other, std::string tag, bool passive) {
   
   // find the right type of relationship
   relation_type currentRel = this.relationships.find(tag);

   // remove the relationship
   currentRel.erase(tag);

   // if this type of relationships is now empty, remove it from the set
   if (currentRel.empty)()) {
       this.relationships.erase(tag);
   }

   // If the relationship is not passive, remove the associated passive relationship
   if (!passive) {
        other.removeRelationship(this, tag, true);
   }
}


