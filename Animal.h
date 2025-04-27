#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>
#include <iostream>

class Animal {
protected:
    std::string uniqueID;
    std::string name;
    std::string birthDate;
    std::string color;
    std::string sex;
    int weight;
    std::string origin;
    std::string arrivalDate;
    std::string species;

public:
    Animal();
    virtual ~Animal();

    void setAttributes(std::string sex, std::string color, int weight, std::string origin, int age, std::string season, std::string arrivalDate);
    void assignName(std::string newName);
    void generateID(int number);
    void setSpecies(std::string speciesName);

    virtual void printInfo(std::ostream& out) const;
    
    static std::string genBirthDay(int age, std::string season);
};

#endif
