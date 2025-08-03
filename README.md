# Ghost Busters

## Game Description

Ghost Busters is a tiny game where the player tries to find the position of a hidden ghost in a grid. All blocks are initially locked. The player clicks blocks to get clues about the ghost's location:

- **Snake**: Clicked block is 0-1 blocks away from the ghost
- **Turtle**: Clicked block is 2-3 blocks away from the ghost
- **Bunny**: Clicked block is 4 blocks away from the ghost
- **Random (Snake/Turtle/Bunny)**: Clicked block is more than 4 blocks away

After exploring, the player right-clicks to guess the ghost's location. If correct, a ghost is drawn; otherwise, the game is failed.

## File Structure

- `GhostBusters/`
  - `main.cpp`: Entry point for the game
  - `game.cpp`, `game.hpp`: Game logic and definitions
  - `GhostBuster.cpp`, `GhostBuster.hpp`: Main implementation file to complete (see comments inside)
  - `assets.png`, `assets.svg`, `hu.png`: Game assets
  - `How to Compile.txt`: Compilation instructions
  - `Solution.exe`: Provided solution binary
- `main.tex`: Assignment description (LaTeX)
- `CS224___Homework_2.pdf`: Assignment PDF

## How to Compile & Run

1. **Using VS Code**: Open the `GhostBusters` folder in VS Code and press `F5` to run.
2. **Using Terminal**: See `How to Compile.txt` for detailed instructions.

## Acknowledgement

This assignment is adapted from [UCBerkeley CS188 Probabilistic Inference](https://www.youtube.com/watch?v=sMNbLXsvRig).

---

**For more details, see `main.tex` or `CS224___Homework_2.pdf`.**
