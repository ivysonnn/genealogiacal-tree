#include <union/Person.h>

Person* Person::findSet() {
    if(this->representative == this) return this;
}