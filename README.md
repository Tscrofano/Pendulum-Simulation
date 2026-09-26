# Pendulum Simulation

A C++ numerical simulation of a simple pendulum using the [Eigen](https://eigen.tuxfamily.org/) linear algebra library.

## Overview

This project models the motion of a simple pendulum by numerically integrating its angular position and angular velocity over time.

The simulation stores the trajectory in an Eigen matrix with:

- Column 1: angular position, $\theta$
- Column 2: angular velocity, $\omega$

## Physics Model

For a simple pendulum, the equation of motion is:

$$
\ddot{\theta} = -\frac{g}{l}\sin(\theta)
$$

where:

- $g = 9.8\ m/s^2$ is gravitational acceleration
- $l = 1.0\ m$ is the pendulum length
- $\theta$ is angular position
- $\omega = \dot{\theta}$ is angular velocity

The program uses a time-stepping numerical integration method:

$$
\omega_{new} = \omega_{prev} - \frac{g}{l}\sin(\theta_{prev})\Delta t
$$

$$
\theta_{new} = \theta_{prev} + \omega_{new}\Delta t
$$

## Project Structure

```text
Pendulum-Simulation/
├── main.cpp
├── README.md
└── .gitignore
```

## Requirements

- C++ compiler
- Eigen 3

## Building

If Eigen is installed and available to your compiler, the program can be compiled with:

```bash
g++ main.cpp -o pendulum -I/path/to/eigen
```

Then run:

```bash
./pendulum
```

On Windows, the executable will typically be:

```text
pendulum.exe
```

## Current Simulation

The current example uses:

```cpp
Pendulum results2(7, 90, 60, 0.25);
```

which represents:

- Initial angular velocity: `7`
- Initial angle: `2` radians
- Simulation time: `60` seconds
- Time step: `0.25` seconds

## Results

The `results/` directory is reserved for simulation output such as:

- CSV trajectory data
- Plots of angular position versus time
- Plots of angular velocity versus time
- Future pendulum animations

## Future Improvements

- Convert input angles from degrees to radians automatically
- Export trajectory data to CSV
- Plot $\theta(t)$ and $\omega(t)$
- Calculate and track mechanical energy
- Compare numerical results with an analytical approximation
- Implement higher-order integration methods such as Runge-Kutta 4 (RK4)
- Animate the pendulum motion
