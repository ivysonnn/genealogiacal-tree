#include <string>
#include <union/core/Person.h>
#include <map>
#include <vector>

class FamilyManager {
    private: 
        std::map<std::string, Person*> registered_people;

    public:
        std::vector<Person*> getRegisteredPeople() const;   
        Person* getPerson(std::string name) const;
        std::vector<Person*> getMaleAncestors(Person* p) const;
        std::vector<Person*> getFemaleAncestors(Person* p) const;

        bool registerPerson(std::string name);

        bool bond(std::string childrenName, std::string fatherName, std::string motherName);
        bool areConnected(std::string name1, std::string name2);

        void cleanup();
};