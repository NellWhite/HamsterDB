#include "node.hpp"
#include "database.hpp"

using namespace std;

int main() 
{

class Person : public Node{
public:
    std::string primaryKey;
    int age;
    double llamas;
};

Person p;
p.primaryKey = "Nelll";
p.age = 12;
p.llamas = 3.4;


Database d;
//
d.addNode(p);
//
Person m;
p.primaryKey = "Mackenzie";
p.age = 14;
p.llamas = 5.2;
//
d.addNode(m);

Person * mp = new Person;
*mp = m;

p.addRelationship(mp, "Friendships!", false);
//
std::list<Node> nodeList = d.getNodeWithRelationship(m, "Friendships!");


//
//d.getRelationship(p, m);
//Person * mp = new Person;
//*mp = m;
//Person * pp = p;
//p.addRelationship(mp, "Friends", false);
//cout << p.getRelationship(mp) << endl;
//
//p.getNodesWithRel("Friends", false);
//p.removeRelationship(mp, "Friends", false);
//
//cout << p.getRelationship(mp) << endl;


}
