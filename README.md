# AI-Enhanced-MPPT-Inverter-Design-with-Reverse-Engineering-Insights-(FYP)

## Overview
This project focuses on designing an **AI-Enhanced MPPT Inverter** by leveraging insights gained through **reverse engineering** of a commercial hybrid solar inverter. Our goal is to optimize Maximum Power Point Tracking (MPPT) using **Reinforcement Learning (RL)** algorithms to enhance the overall efficiency of the inverter.

## Reverse Engineering and Simulations
- Extracted the power circuitry, including the **boost converter, DC-to-AC conversion circuit, and battery charging circuit**.
- Simulated these circuits to validate their performance.
- Compared the simulation results with actual inverter testing under variable loads, successfully verifying our findings.
- **All simulations were conducted using PSIM software** to model and analyze circuit performance.

## Current Progress
We are now in the design phase of our own **MPPT inverter**, integrating AI-based RL algorithms to improve power extraction and inverter performance. The project is progressing with:
- Custom inverter hardware design
- Implementation of AI-based MPPT control
- Performance testing and validation

## Features
- **AI-Enhanced MPPT**: Utilizes Reinforcement Learning for improved tracking efficiency.
- **Reverse Engineering Insights**: Learning from existing commercial inverter designs.
- **High-Efficiency Power Conversion**: Optimized for minimal losses.
- **Protections**: Overvoltage, overcurrent, and short-circuit protection.
- **Real-Time Monitoring**: LCD/Serial interface for system parameters.

## Specifications
- **Power Rating**: 3.5 kW and above
- **Output Voltage**: 320V - 330V
- **Ripple Voltage**: 0.1%
- **MPPT Algorithm**: AI-based Reinforcement Learning
- **Switching Frequency**: Optimized for efficiency

## Components Used
- **Microcontroller/Processor** (ESP32 or Arduino)
- **MOSFETs & Gate Driver Circuit**
- **Inductor & Capacitors** (for filtering and boosting)
- **Current and Voltage Sensors**
- **Battery Pack with BMS**
- **LCD/Serial Monitor for Display**

## Working Principle
1. **Reverse Engineering Phase**: Analyzed an existing **3.5 kW INVEREX Hybrid Solar Inverter**.
2. **Simulation & Validation**: Extracted and tested key circuits in simulations using **PSIM software**.
3. **MPPT Control Implementation**: Developing **AI-based MPPT** algorithms to optimize power tracking.
4. **Inverter Design & Testing**: Building a customized inverter with enhanced efficiency and intelligence.

## Software & Algorithm
- **MPPT Algorithm**: Reinforcement Learning-based optimization.
- **PWM Control**: Generated via microcontroller.
- **Voltage & Current Sensing**: ADC readings for real-time monitoring.
- **Error Handling & Protection**: Overvoltage and short-circuit protection implemented.

## Future Enhancements
- IoT-based monitoring (via MQTT or Firebase)
- Mobile app for remote control and status updates
- Improved efficiency with advanced AI techniques
- Grid-tie functionality




