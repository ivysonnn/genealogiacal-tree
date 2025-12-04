#pragma once

#include <string>

class Person {
    private:
        std::string name;
        Person* father;
        Person* mother;

        void setMother(Person *mother) { this->mother = mother; }
        void setFather(Person *father) { this->father = father; }
    public:
        Person* representative;
        int level;

        Person(std::string name) : name(name), father(nullptr), mother(nullptr), representative(this), level(0) {}

        std::string getName() {return this->name;}
        Person* getMother() {return this->mother;}
        Person* getFather() {return this->father;}

        // funções do unite-find
        Person* findSet();
        static void unite(Person* p1, Person* p2);

        bool bondToParents(Person* father, Person* mother);
};