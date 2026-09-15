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