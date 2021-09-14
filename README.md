# Algorithmics

This repository contains solutions to common (and some unusual) algorithmics problems.

## 🐙 `ships.cpp`

All of us have propably ever played a game of ships. This program finds sizes of all ships on a board.

### How to use

1. Create a file named `ships.txt`
2. Fill the file with a square of size 8x8 filled with `0` (water) and `1` (ship).

>💡 **Tip:** If you are not sure how the file should look like, feel free to take a look at the example in `./samples/` directory.

3. Compile the program
```bash
g++ ships.cpp -o ships.out
```
4. Run the program and watch the console window
```bash
./ships.out
```

## 🌀 `spiral.cpp`

Fills spirally a square array with consecutive numbers in the choosen direction.

### How to use

1. Compile the program
```bash
g++ spiral.cpp -o spiral.out
```
2. Run the program
```bash
./spiral.out
```
3. Input a direction
    - `0` for counter-clockwise
    - `1` for clockwise
4. Type in a size
5. Watch the console window
