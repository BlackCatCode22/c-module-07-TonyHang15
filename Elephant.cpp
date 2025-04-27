#include "Elephant.h"
#include <iostream>

Elephant::Elephant() {
    setSpecies("elephant"); //"elephant"
}

Elephant::~Elephant() {}

void Elephant::setAttributes(std::string sex, std::string color, int weight, std::string origin, int age, std::string season, std::string arrivalDate) {
    Animal::setAttributes(sex, color, weight, origin, age, season, arrivalDate);
}

void Elephant::printInfo(std::ostream& out) const {
    out << "Elephant Habitat:\n";
    Animal::printInfo(out);
}
