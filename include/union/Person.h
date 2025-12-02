#pragma once

#include <string>

enum Sex {
    MALE,
    FEMALE
};

class Person {
    private:
        std::string name;
        Sex sex;
        Person* father;
        Person* mother;
    public:
        Person* representative;
        int level;

        Person(std::string name, Sex sex) : name(name), sex(sex), father(nullptr), mother(nullptr), representative(    this), level(0) {}

        std::string getName() {return this->name;}
        Person* getMother() {return this->mother;}
        Person* getFather() {return this->father;}
        
        void setMother(Person* mother) {this->mother = mother;}
        void setFather(Person* father) {this->father = father;}

        Person* findSet();
        void unite(Person* p1, Person* p2);
};