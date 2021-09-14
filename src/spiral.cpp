#include <iostream>
#include <iomanip>

int** generate_board(int size) {
    int** board = new int*[size];

    for(int i = 0; i < size; i++) {
        board[i] = new int[size];

        for(int j = 0; j < size; j++) {
            board[i][j] = 0;
        }
    }

    return board;
}

void print(int** board, int size) {

    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            std::cout << std::setw(3);
            std::cout << board[i][j];
        }

        std::cout << std::endl;
    }
}

void next_vector(int& x, int& y, bool cw = true) {
    if(cw) {
        if(x == 1 && y == 0) { x = 0; y = 1; }
        else if(x == 0 && y == 1) { x = -1; y = 0; }
        else if(x == -1 && y == 0) { x = 0; y = -1; }
        else { x = 1; y = 0; }
        return;
    }

    if(x == 0 && y == 1) { x = 1; y = 0; }
    else if(x == 1 && y == 0) { x = 0; y = -1; }
    else if(x == 0 && y == -1) { x = -1; y = 0; }
    else { x = 0; y = 1; }
}

int main() {
    bool cw;
    int size;

    std::cin >> cw;
    std::cin >> size;

    int** board = generate_board(size);

    int x = 0, y = 0;
    int dx = 0, dy = 0;

    if(cw) dx = 1;
    else dy = 1;

    for(int i = 1; i <= size * size; i++) {
        board[y][x] = i;

        int new_x = x + dx;
        int new_y = y + dy;

        if(
            new_x < 0 || new_x >= size ||
            new_y < 0 || new_y >= size ||
            board[new_y][new_x] != 0
        ) {
            next_vector(dx, dy, cw);
        }
        
        x += dx;
        y += dy;
    }

    print(board, size);
}