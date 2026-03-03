_This project has been created as part of the 42 curriculum by sjolliet_

# So Long - 42 Common Core

## Description

**so_long** is a small 2D game developed in C using the MiniLibX graphics library.

The game uses a top-down 2D view and its goal is simple : the player needs to collect all the collectibles found on the map in order to unlock the escape and end the game.

Any map can be used, as long as they respect the following rules :
- Must be rectangular
- Must be surrounded by walls
- Must contain 1 player, 1 exit and at least 1 collectible
- Must have a valid path
- Must use the *.ber* extension

The elements on the map are characters that represent the different components :

| Character | Meaning |
|-----------|----------|
| `0` | Empty space |
| `1` | Wall |
| `C` | Collectible |
| `E` | Exit |
| `P` | Player starting position |

If any errors is found, the program exits with :

```bash
Error
Explicit error message
```

## Instructions

Clone the repository and compile the project using `make`:

```bash
git clone <repository_url>
cd <project_name>
make
```

Then, you can run the program by passing a *.ber* file as an argument :
```bash
./so_long maps/map.ber
```

Make sure that your map file follows the instructions given in the description section or you will see an error message. Only one argument can be passed to run the program.

## Resources

- **Introduction to MiniLibX**  
  Practical overview of X Window programming with MiniLibX  
  https://medium.com/@jalal92/understanding-the-minilibx-a-practical-dive-into-x-window-programming-api-in-c-cb8a6f72bec3

- **MiniLibX GitHub Repository**  
  Official Linux version maintained by 42  
  https://github.com/42paris/minilibx-linux

- **MiniLibX Documentation (Harm Smits)**  
  Clear explanations and function references  
  https://harm-smits.github.io/42docs/libs/minilibx

- **libX11 Official Documentation**  
  Low-level X11 window system reference  
  https://www.x.org/releases/current/doc/libX11/libX11/libX11.html

- **Building Your First 2D Game (so_long article)**  
  Project-focused explanation and walkthrough  
  https://medium.com/@digitalpoolng/42-so-long-and-thanks-for-all-the-fish-building-your-first-2d-game-in-c-ccd24034bc8b

- **Understanding `mlx_init()`**  
  Beginner-friendly explanation of initialization  
  https://medium.com/@ahmadbilla07/understanding-mlx-init-in-minilibx-beginner-friendly-7272b7ac9181

---
AI tools were used as learning and productivity aids for :

- Generating and designing game sprites
- Guidance on formatting sprites correctly using GIMP
- Assistance understanding how to link MiniLibX in the Makefile
- Learning and understanding the flood fill algorithm
- Generating edge-case invalid maps for testing
- Improving the structure and formatting of this README
