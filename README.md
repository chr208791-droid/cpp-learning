# C++ Learning

This repository records my C++ learning process for robotics development.

## Environment

- Windows
- VS Code
- MSYS2
- g++

## Day 1

Topics:

- Hello World
- Variables and basic data types
- `std::cin` / `std::cout`
- `if / else if / else`
- `for`
- `while`
- Functions
- Basic Git workflow

## Mini Project: Obstacle Monitor

The program reads an obstacle distance and outputs the robot state.

Rules:

- distance < 0.5 m → STOP
- 0.5 m <= distance < 1.5 m → SLOW
- distance >= 1.5 m → SAFE

## Build

```bash
g++ robot_practice.cpp -o robot_practice