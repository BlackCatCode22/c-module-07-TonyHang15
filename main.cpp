#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <memory> 
#include "Animal.h"
#include "Hyena.h"
#include "Lion.h"
#include "Tiger.h"
#include "Bear.h"
#include "Elephant.h"  
#include "readNames.h"

using namespace std;

int main() {
    vector<unique_ptr<Hyena>> hyenas;
    vector<unique_ptr<Lion>> lions;
    vector<unique_ptr<Tiger>> tigers;
    vector<unique_ptr<Bear>> bears;
    vector<unique_ptr<Elephant>> elephants; 

    queue<string> nameQueue;
    try {
        nameQueue = loadAnimalNames("animalNames.txt");
    } catch (const exception& e) {
        cerr << e.what() << endl;
        return 1;
    }

    ifstream inFile("arrivingAnimals.txt");
    if (!inFile.is_open()) {
        cerr << "Could not open arrivingAnimals.txt" << endl;
        return 1;
    }

    string line;
    int hyenaCount = 0, lionCount = 0, tigerCount = 0, bearCount = 0, elephantCount = 0;  // Counter for elephants
    string arrivalDate = "2025-04-25"; 

    while (getline(inFile, line)) {
        // Parse info
        int age, weight;
        string sex, species, color, season, origin;

        size_t pos1 = line.find(" year old ");
        age = stoi(line.substr(0, pos1));

        size_t pos2 = line.find(" ", pos1 + 10);
        sex = line.substr(pos1 + 10, pos2 - (pos1 + 10));

        size_t pos3 = line.find(",", pos2);
        species = line.substr(pos2 + 1, pos3 - (pos2 + 1));
        species.erase(remove(species.begin(), species.end(), ','), species.end());

        size_t pos4 = line.find("born in ");
        if (pos4 != string::npos) {
            size_t pos5 = line.find(",", pos4);
            season = line.substr(pos4 + 8, pos5 - (pos4 + 8));
        } else {
            season = "";
        }

        size_t colorStart = line.find("color,");
        color = line.substr(colorStart - 4, 3);

        size_t weightStart = line.find("pounds");
        size_t weightComma = line.rfind(",", weightStart);
        weight = stoi(line.substr(weightComma + 2, weightStart - weightComma - 8));

        size_t originStart = line.rfind("from");
        origin = line.substr(originStart + 5);

        
        if (species.find("hyena") != string::npos) {
            auto hyena = make_unique<Hyena>();
            hyena->setAttributes(sex, color, weight, origin, age, season, arrivalDate);
            hyena->assignName(nameQueue.front());
            nameQueue.pop();
            hyena->generateID(++hyenaCount);
            hyenas.push_back(move(hyena));
        } else if (species.find("lion") != string::npos) {
            auto lion = make_unique<Lion>();
            lion->setAttributes(sex, color, weight, origin, age, season, arrivalDate);
            lion->assignName(nameQueue.front());
            nameQueue.pop();
            lion->generateID(++lionCount);
            lions.push_back(move(lion));
        } else if (species.find("tiger") != string::npos) {
            auto tiger = make_unique<Tiger>();
            tiger->setAttributes(sex, color, weight, origin, age, season, arrivalDate);
            tiger->assignName(nameQueue.front());
            nameQueue.pop();
            tiger->generateID(++tigerCount);
            tigers.push_back(move(tiger));
        } else if (species.find("bear") != string::npos) {
            auto bear = make_unique<Bear>();
            bear->setAttributes(sex, color, weight, origin, age, season, arrivalDate);
            bear->assignName(nameQueue.front());
            nameQueue.pop();
            bear->generateID(++bearCount);
            bears.push_back(move(bear));
        } else if (species.find("elephant") != string::npos) { 
            auto elephant = make_unique<Elephant>();
            elephant->setAttributes(sex, color, weight, origin, age, season, arrivalDate);
            elephant->assignName(nameQueue.front());
            nameQueue.pop();
            elephant->generateID(++elephantCount);  
            elephants.push_back(move(elephant));
        }
    }

    inFile.close();

    ofstream outFile("zooPopulation.txt");
    if (!outFile.is_open()) {
        cerr << "Could not create zooPopulation.txt" << endl;
        return 1;
    }

    outFile << "Hyena Habitat:\n";
    for (const auto& h : hyenas) {
        h->printInfo(outFile);
    }

    outFile << "\nLion Habitat:\n";
    for (const auto& l : lions) {
        l->printInfo(outFile);
    }

    outFile << "\nTiger Habitat:\n";
    for (const auto& t : tigers) {
        t->printInfo(outFile);
    }

    outFile << "\nBear Habitat:\n";
    for (const auto& b : bears) {
        b->printInfo(outFile);
    }

    outFile << "\nElephant Habitat:\n";  
    for (const auto& e : elephants) { 
        e->printInfo(outFile);
    }

    outFile.close();
    cout << "Zoo population report created successfully!" << endl;

    return 0;
}
