# Zookeeper's Challenge - C++ Program

## Project Overview

The **Zookeeper's Challenge** is a C++ application designed to simulate the management of a dynamic zoo environment. The program reads information from two input files (`arrivingAnimals.txt` and `animalNames.txt`), processes the data, and generates a detailed report (`zooPopulation.txt`) that categorizes the zoo population by species and includes essential information about each animal.

### Features:
- **Data Parsing**: Extracts details from `arrivingAnimals.txt` and assigns names from `animalNames.txt`.
- **Unique Animal ID Generation**: Creates unique IDs for each animal based on species and arrival order.
- **Animal Birthdays**: Calculates the animal's birthdate using the provided age and birth season.
- **Categorization**: Organizes animals into their respective habitats (Hyena, Lion, Tiger, Bear).
- **Output Report**: Generates a well-organized zoo population report (`zooPopulation.txt`), detailing the species, names, attributes, and habitat information.

## Files

### 1. `arrivingAnimals.txt`
This file contains data about the animals arriving at the zoo, including their age, sex, species, color, weight, and origin. Each line in the file describes one animal.

Example:
```plaintext
4 year old female hyena, born in spring, tan color, 70 pounds, from Friguia Park, Tunisia
