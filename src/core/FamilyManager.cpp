#include <union/core/Person.h>
#include <union/core/FamilyManager.h>

std::vector<Person*> FamilyManager::getRegisteredPeople() const { 
    std::vector<Person*> everyone;
    for (auto const& [name, person] : registered_people) {
        everyone.push_back(person);
    }
    return everyone;
}

Person* FamilyManager::getPerson(std::string name) const{
    auto it = registered_people.find(name);
    if (it != registered_people.end()) {
        return it->second;
    }
    return nullptr;
}

bool FamilyManager::registerPerson(std::string name) {
    if (getPerson(name)) return false;
    
    Person* p = new Person(name);
    registered_people.insert({p->getName(), p}); 
    return true;
}

bool FamilyManager::bond(std::string childrenName, std::string fatherName, std::string motherName) {
    Person* children = getPerson(childrenName);
    if (children == nullptr) return false;
    Person* father = getPerson(fatherName);
    Person* mother = getPerson(motherName);
    if (fatherName != "NULL" && father == nullptr) return false;
    if (motherName != "NULL" && mother == nullptr) return false;
    children->bondToParents(father, mother);
    return true;
}

bool FamilyManager::areConnected(std::string name1, std::string name2) {
    Person* p1 = getPerson(name1);
    Person* p2 = getPerson(name2);
    if (p1 == nullptr || p2 == nullptr) return false;
    Person* rep1 = p1->findSet();
    Person* rep2 = p2->findSet();
    if (rep1 != rep2) return false;
    return true;
}

void FamilyManager::cleanup() {
    for (auto const& [key, val] : registered_people) {
        delete val; 
    }
    registered_people.clear();
}