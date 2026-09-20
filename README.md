# C++ Learning

This repository records my C++ learning process for robotics development.

## Environment

- Windows
- VS Code
- MSYS2
- g++

## Day 1

Topics covered:

- Hello World
- Variables and basic data types
- `std::cin` / `std::cout`
- `if / else`
- `for`
- `while`
- Functions
- Basic Git workflow
- GitHub push workflow

## Mini Project: Obstacle Monitor

A simple C++ program that reads the obstacle distance and outputs the robot status.

### Logic

- distance < 0.5 m → STOP
- distance >= 0.5 m → SAFE

## Build

```bash
g++ robot_practice.cpp -o robot_practice
```

## Run

On Windows PowerShell:

```powershell
.\robot_practice.exe
```

## Example

Input:

```text
0.3
```

Output:

```text
STOP
```

Input:

```text
1.2
```

Output:

```text
SAFE
```

## Repository Structure

```text
cpp-learning/
├── .gitignore
├── README.md
├── hello.cpp
├── robot_practice.cpp
└── .vscode/
```

## Notes

Compiled files such as `.exe`, `.o`, `.obj`, and `.out` are ignored by Git through `.gitignore`.

This repository will continue to be updated as I learn more C++ topics related to robotics development.

## Day 2

Topics covered:

- Pass by value
- References
- Pointers
- `nullptr`
- `const`
- `const` references
- Basic `std::vector`
- Simple LiDAR distance analysis

## Day 3

Topics covered:

- Classes and objects
- `public` / `private`
- Constructors and destructors
- Member initialization lists
- `const` member functions
- Object lifetime
- RAII
- Sensor / Frame practice

## Day 4

Topics covered:

- STL containers
- `std::vector`
- `std::map`
- `std::unordered_map`
- `std::sort`
- `std::min_element`
- `std::max_element`
- `std::count_if`
- Iterators
- Lambda expressions
- Sensor data statistics and lookup

## Day 5-6

Topics covered:

- Linux file permissions
- grep / find
- Process management
- Git branch and merge
- CMake multi-file project
- include / src / app structure
- add_library
- add_executable
- target_include_directories
- target_link_librariess