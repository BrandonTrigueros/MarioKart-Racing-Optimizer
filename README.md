# Mario Kart Simulator

A C++ application that simulates and analyzes Mario Kart racing dynamics, helping players find the optimal combinations of characters, vehicles, tires, and gliders for different tracks and scenarios.

## Project Description

This simulator allows users to:
- Compare different character, vehicle, tire, and glider combinations
- Find the optimal setup for specific tracks
- Analyze driver performance across all tracks
- Create custom cup tournaments and determine the best configuration

The project implements data structures like Red-Black Trees for efficient storage and retrieval of parts and drivers information, and includes various driver types with unique characteristics that affect their performance on different terrains (land, water, and air).

## Project Structure

- `src/` - Source code files
  - `Driver/` - Classes for different driver types (Kart, Motorcycle, ATV)
  - `Parts/` - Classes for vehicles, tires, and gliders
  - `RBTree.hpp` - Implementation of Red-Black Tree data structure
  - `Garage.hpp/cpp` - Main class managing all parts and calculations
  - `Menu.hpp/cpp` - User interface functionality
  - `IOHandler.hpp/cpp` - Input/Output handling
- `input/` - CSV data files
  - `players.csv` - Driver configurations
  - `pieces.csv` - Vehicle parts information

## Installation

### Prerequisites
- C++17 compatible compiler (GCC, Clang, or MSVC)
- Make build system

### Building the project
```bash
# Clone the repository
git clone https://git.ucr.ac.cr/JOHAN.ABARCACASCANTE/progra2_23a_brandon_johan.git
cd progra2_23a_brandon_johan

# Build the project using Make
make
```

## Usage

Run the compiled executable:
```bash
./bin/HelloGoogleTest
```

The interactive menu provides the following options:
1. Display all available parts (vehicles, tires, gliders)
2. Find the best combination for all tracks
3. Find the best combination for a specific track
4. Calculate average position of a player across all tracks
5. Create a cup (4 tracks) and find the best configuration
6. Exit the program

### Data Files

The program reads data from CSV files in the `input/` directory:
- `pieces.csv` - Contains information about karts, bikes, ATVs, tires, and gliders
- `players.csv` - Contains tracks information and player configurations

## Features

- Red-Black Tree implementation for efficient data management
- Multiple driver types with different performance characteristics
- Time calculations based on terrain type (land, water, air)
- Command-line interface for easy interaction
- Support for custom driver and track configurations

## Authors

- Brandon Trigueros
- Johan Abarca Cascante

## License

This project is created for educational purposes at the University of Costa Rica.
