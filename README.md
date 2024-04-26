# CDyM-LDR ARGB LED Control Project

## Overview
The "CDyM-LDR" repository hosts a project aimed at controlling an Addressable RGB (ARGB) LED using a Modular Finite State Machine (MEF) approach and timer ticks with the setting of timers. It provides a structured and modular way to manage the LED's behavior in response to environmental light levels, captured by a Light Dependent Resistor (LDR).

## Features
- Modular codebase using MEF principles.
- Light intensity measurement using an LDR sensor.
- Dynamic ARGB LED control based on ambient light.
- Software Pulse Width Modulation (PWM) implementation for fine-grained LED control.
- Efficient timer management for system tick updates.

## Repository Structure
The codebase is organized into various directories, each containing specific components of the project:

- `Debug`: Contains configuration files for debugging.
- `LDR`: Holds the source and header files for LDR sensor interfacing.
- `Leds`: Source and header files for ARGB LED control.
- `MEF`: Modular Finite State Machine files for managing LED states.
- `SW_PWM`: Software PWM implementation files.
- `Timers`: Timer configuration and handling files.
- `sEOS`: Simplified Embedded Operating System files for task scheduling.

## Getting Started
1. Clone the repository to your local machine.
2. Ensure you have the required development environment and tools set up, including support for `.pdsprj` and `.cproj` files.
3. Open the project using the provided project file (`TP4.cproj`).
4. Compile and upload the code to your Arduino 328 or compatible microcontroller.

## Contributions
Contributions to this project are welcome. Please ensure you follow the commit message conventions as seen in the repository (`final`, `Software PWM Working => and system tick updated`).

## License
This project is licensed under the MIT License - see the LICENSE.md file for details.

## Acknowledgments
- Thanks to all the contributors who have invested their time in improving this project.
- Special thanks to `FranGa1` and `JeronimoIam` for their significant contributions to the codebase.
