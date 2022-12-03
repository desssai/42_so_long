# so_long

## Overview

The aim of the project is to create a small 2D game using the minimalistic graphics library provided by ecole 42 "MinilibX".\
The project consists of map parsing, window management, event handling, colors, textures, generating sprites and so forth.\
The "MinilibX" was developed internally and includes basic necessary tools to open a window, create images and deal with\
keyboard and mouse events.

### Here is an example

![image](https://user-images.githubusercontent.com/75085822/205447071-34f7976a-fa50-41c0-815c-9fe6442aa51e.png)

### Or another one

![image](https://user-images.githubusercontent.com/75085822/205447137-4a78a567-8087-4165-9daa-eb7d0cf10ecd.png)

## Usage

1. Clone the repository.
2. Compile the game using a Makefile
3. Launch the game by writing `./so_long ./maps/map_to_open` or `./so_long_bonus ./maps/map_to_open` in terminal.

The Makefile rules are as follows:

| Rule | Despription |
| ---- | ----------- |
| ALL | Compiles the game with mandatory features. |
| BONUS | Compiles the game with mandatory and bonus features. |
| CLEAN | Removes object files leaving only the game present. |
| FCLEAN | Removes both the game and object files. |
| RE | Recompiles the game using **CLEAN** and **ALL** Makefile rules |

## Maps

The map has to be constructed with 5 components: player's starting position, exit, walls, collectibles, and free spaces.\
The map must be rectangular. The map must be closed/surrounded by walls. If it’s not, the program returnы an error.\
The map must contain 1 exit, at least 1 collectible, and 1 starting position to be valid.\
The map can be composed of only these 5 characters:
- 0 for an empty space,
- 1 for a wall,
- C for a collectible,
- E for a map exit,
- P for the player’s starting position.

Examples of an invalid map can be found in `maps` folder They are named from `1.ber` to `9.ber`.\
Examples of a valid map can be found in `maps` folder. They are named from `map1.ber` to `map5.ber`.\
You can create your own map using a text editor of your choice, if the map complies with the above criteria. 

## Bonus features

- Adds animation for the player.
- Adds enemy patrols. The player loses the game if enemies touch the player.
- Movement count is displayed directly on top of the player instead of in the terminal.

