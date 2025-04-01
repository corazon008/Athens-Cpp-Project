# Mille Bornes

## Description

Mille Borne is a card game that simulates a road trip. Players take turns drawing cards and playing them to move their
car forward, while also trying to stop their opponents from moving. The goal is to be the first player to reach 1000
miles.

## Features

- Two or Three players
- Card deck with various types of cards

### Cards Type

| Type     | Description                                                                         |
|----------|-------------------------------------------------------------------------------------|
| Distance | Increase your score                                                                 |
| Hazard   | Stop your opponent                                                                  |
| Remedy   | Remove a hazard                                                                     |
| Safety   | Protect yourself by removing current applied hazard and preventing from receive one |

| Hazard      | Card                                     |
|-------------|------------------------------------------|
| Accident    | ![img.png](images/hazard/accident.png)   |
| Out of Gas  | ![img.png](images/hazard/outofgas.png)   |
| Flat Tire   | ![img.png](images/hazard/flattire.png)   |
| Stop Sign   | ![img.png](images/hazard/stop.png)       |
| Speed Limit | ![img.png](images/hazard/speedlimit.png) |

| Remedy             | Card                                          |
|--------------------|-----------------------------------------------|
| Repair             | ![img.png](images/remedy/repair.png)          |
| Gasoline           | ![img.png](images/remedy/gasoline.png)        |
| Spare Tire         | ![img.png](images/remedy/sparetire.png)       |
| Go                 | ![img.png](images/remedy/go.png)              |
| End of Speed Limit | ![img.png](images/remedy/endofspeedlimit.png) |

| Safety            | Card |
|-------------------|------|
| Driving Ace      | ![img.png](images/safety/drivingace.png) |
| Extra Tank     | ![img.png](images/safety/extratank.png)   |
| Puncture Proof   | ![img.png](images/safety/punctureproof.png) |
| Right of Way     | ![img.png](images/safety/rightofway.png)   |

## Requirements!

- Work on Linux System (build-essential libssl-dev cmake)
- don't work on Windows, but can run on WSL
- didn't test on MacOS

## Installation

- Clone the repository:
- Build the project:

```bash
cmake -B build
```

- Compile the project:

```bash
cmake --build build
```

- Run the project:

```bash
./build/MilleBornes
```

## Usage

- To start a new game, run the program and follow the prompts.
- To play a card, select the card you want to play from your hand and follow the instructions on the card.

## Preview

Preview of the game interface:
![Preview 1](preview1.png)

![Preview 2](preview2.png)

## Credit

- [Mille Bornes](https://en.wikipedia.org/wiki/Mille_Bornes) - Wikipedia