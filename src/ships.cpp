#include <iostream>
#include <string>
#include <fstream>
#include <map>

size_t solve(bool** board, int x, int y) {
    board[y][x] = false;
    size_t parts = 1;

    if(y-1 >= 0 && board[y-1][x]) {
        parts += solve(board, x, y-1);
    }

    if(y+1 < 8 && board[y+1][x]) {
        parts += solve(board, x, y+1);
    }

    if(x-1 >= 0 && board[y][x-1]) {
        parts += solve(board, x-1, y);
    }

    if(x+1 < 8 && board[y][x+1]) {
        parts += solve(board, x+1, y);
    }

    return parts;
}

int main()
{
    bool** board = new bool*[8];
    for(size_t i = 0; i < 8; i++) {
        board[i] = new bool[8];
    }

    std::ifstream in("ships.txt");
    
    std::string line;
    for(size_t i = 0; i < 8; i++) {
        in >> line;
        for(size_t j = 0; j < 8; j++) {
            board[i][j] = line[j] - '0';
        }
    }
    in.close();

    for(size_t i = 0; i < 8; i++) {
        for(size_t j = 0; j < 8; j++) {
            if(!board[i][j]) continue;

            size_t size = solve(board, j, i);

            std::cout << "Found " << size << std::endl;
        }
    }

    return 0;
}
