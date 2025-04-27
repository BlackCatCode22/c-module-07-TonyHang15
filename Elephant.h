#ifndef ELEPHANT_H
#define ELEPHANT_H

#include "Animal.h"

class Elephant : public Animal {
public:
    Elephant();
    void printInfo(ofstream& outFile) const override;
};

#endif // ELEPHANT_H
