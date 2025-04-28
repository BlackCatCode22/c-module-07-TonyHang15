# Zoo Management System

This project is a C++ based program to manage a zoo population consisting of various animal species. The zoo includes animals such as Hyenas, Lions, Tigers, Bears, and Elephants. The program reads input from a file with animal details, processes the information, assigns unique IDs, and outputs a report of the zoo population to a text file.

## Features

- **Animal Management**: Supports various animals like Hyenas, Lions, Tigers, Bears, and Elephants.
- **Attributes**: Each animal has attributes such as name, sex, color, weight, origin, birth date, and arrival date.
- **Unique ID Generation**: Animals are assigned unique IDs based on their species and order of arrival.
- **Data Processing**: The program reads animal information from an input file (`arrivingAnimals.txt`) and processes the details.
- **Output Report**: Generates a report (`zooPopulation.txt`) listing all animals in their respective habitats.

## Animal Species

- **Hyena**
- **Lion**
- **Tiger**
- **Bear**
- **Elephant** *(Newly added in this version)*

## Files

1. **Animal.h** / **Animal.cpp**: Base class for animal attributes and methods.
2. **Hyena.h** / **Hyena.cpp**: Class for Hyena-specific details and methods.
3. **Lion.h** / **Lion.cpp**: Class for Lion-specific details and methods.
4. **Tiger.h** / **Tiger.cpp**: Class for Tiger-specific details and methods.
5. **Bear.h** / **Bear.cpp**: Class for Bear-specific details and methods.
6. **Elephant.h** / **Elephant.cpp**: Class for Elephant-specific details and methods *(new addition)*.
7. **readNames.h**: Helper function for loading animal names from a file.
8. **arrivingAnimals.txt**: Input file with animal arrival details.
9. **zooPopulation.txt**: Output file containing the zoo population report.

## How It Works

1. The program loads animal names from the `animalNames.txt` file into a queue.
2. It then reads the `arrivingAnimals.txt` file, which contains details about the animals arriving at the zoo. These details include:
   - Age
   - Sex
   - Species (Hyena, Lion, Tiger, Bear, Elephant)
   - Color
   - Weight
   - Season of birth
   - Origin (where the animal came from)
3. The program processes each line of data, creates the corresponding animal object (e.g., Hyena, Lion, Tiger, Bear, Elephant), and assigns unique attributes to the animals (name, unique ID, birth date, etc.).
4. The zoo population is then printed to the `zooPopulation.txt` file in an organized manner, categorized by habitat (Hyena, Lion, Tiger, Bear, Elephant).
