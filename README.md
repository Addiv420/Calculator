# Calculator

A C++ CLI application for calculating geometric properties with unit conversion capabilities. Developed as a school assignment to demonstrate OOP principles and robust input handling.

![CLI Demo](https://via.placeholder.com/600x300.png?text=Geometry+Calculator+Demo) *Example screenshot placeholder*

## Features

- **Volume Calculation**  
  Calculate cuboid volumes (length × width × height)
- **Circumference Calculation**  
  Compute circle circumferences (2πr)
- **Unit Conversion**  
  Supports millimeters (mm), centimeters (cm), decimeters (dm), and meters (m)
- **Input Validation**  
  Robust error handling with progressive warnings
- **Colorful Interface**  
  ANSI-colored terminal output
- **Localization**  
  UTF-8 support for special characters
- **Persistent Settings**  
  Maintains unit preference between calculations

## GitHub Project Description
`📐 A C++ CLI geometry calculator with unit conversion and playful input validation. Created for educational purposes. Features ANSI colors, error resilience, and measurement prefixes.`

## Installation

### Requirements
- C++17 compiler
- Linux/Windows terminal with UTF-8 support

### Linux
```bash
g++ -o geometry_calculator main.cpp -std=c++17