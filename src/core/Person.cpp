#include <union/core/Person.h>

Person* Person::findSet() {
    if (this->representative == this) return this;

    this->representative = this->representative->findSet();

    return this->representative;
}

void Person::unite(Person* p1, Person* p2) {
    Person* r1 = p1->findSet();
    Person* r2 = p2->findSet();

    if (r1 == r2) {
        return;
    }

    if (r1->level > r2->level) {
        r2->representative = r1;
    } else if (r2->level > r1->level) {
        r1->representative = r2;
    } else {
        r1->representative = r2;
        r2->level++;
    }
}

bool Person::bondToParents(Person* father, Person* mother) {
    bool changed = false; 

    if (father != nullptr) {
        if (this->father == nullptr) {
            this->setFather(father); 
            Person::unite(this, father); 
            changed = true;
        }
    }

    if (mother != nullptr) {
        if (this->mother == nullptr) {
            this->setMother(mother);
            Person::unite(this, mother);
            changed = true;
        }
    }
    
    return changed;
}