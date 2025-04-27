#include "Animal.h"
#include <ctime>
#include <iomanip>
#include <sstream>

Animal::Animal() {}
Animal::~Animal() {}

void Animal::setAttributes(std::string sex, std::string color, int weight, std::string origin, int age, std::string season, std::string arrivalDate) {
    this->sex = sex;
    this->color = color;
    this->weight = weight;
    this->origin = origin;
    this->arrivalDate = arrivalDate;
    this->birthDate = genBirthDay(age, season);
}

void Animal::assignName(std::string newName) {
    name = newName;
}

void Animal::generateID(int number) {
    std::ostringstream oss;
    oss << species.substr(0, 2) << std::setfill('0') << std::setw(2) << number;
    uniqueID = oss.str();
}

void Animal::setSpecies(std::string speciesName) {
    species = speciesName;
}

std::string Animal::genBirthDay(int age, std::string season) {
    time_t now = time(0);
    tm *ltm = localtime(&now);
    int currentYear = 1900 + ltm->tm_year;
    int birthYear = currentYear - age;

    std::string monthDay = "01-01";
    if (season == "spring") monthDay = "03-15";
    else if (season == "summer") monthDay = "06-15";
    else if (season == "fall") monthDay = "09-15";
    else if (season == "winter") monthDay = "12-15";

    return std::to_string(birthYear) + "-" + monthDay;
}

void Animal::printInfo(std::ostream& out) const {
    out << uniqueID << "; " << name << "; birth date " << birthDate << "; " 
        << color << " color; " << sex << "; " << weight << " pounds; from " 
        << origin << "; arrived " << arrivalDate << std::endl;
}
