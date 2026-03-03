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

Make sure that your map file follows the instructions given in the description section. or you will see an error message.

## Resources

- **Introduction to the project**  
  https://medium.com/@jalal92/understanding-the-minilibx-a-practical-dive-into-x-window-programming-api-in-c-cb8a6f72bec3  
  This article helped me understand what the project is all about and where to start.
- https://github.com/42paris/minilibx-linux
- https://harm-smits.github.io/42docs/libs/minilibx
- https://www.x.org/releases/current/doc/libX11/libX11/libX11.html
- https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html#installation
- https://42-cursus.gitbook.io/guide/2-rank-02/so_long
- https://sethbb.itch.io/32rogues
- https://medium.com/@digitalpoolng/42-so-long-and-thanks-for-all-the-fish-building-your-first-2d-game-in-c-ccd24034bc8b
https://medium.com/@ahmadbilla07/understanding-mlx-init-in-minilibx-beginner-friendly-7272b7ac9181

Used AI for :

- Use gimp to have a correct image format for my textures
- AI helped me to create the makefile and link the library
- Asked AI how to render the texttures, as in if my item, hero or monster images should have a background or could just be added on top of the floor (game design related question)
- Learn more about flood fill for the path validation
- Asked it to generate me many test maps to make sure i covered all cases
