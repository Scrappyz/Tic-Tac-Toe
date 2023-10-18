#pragma once

#include <iostream>
#include <vector>

class Player {
    private:
        char ch;
    public:
        Player(char c) : ch(c) {}

        char getChar() const
        {
            return ch;
        }

        void operator=(char ch)
        {
            this->ch = ch;
        }
};

class Board {
    private:
        std::vector<std::vector<char>> board;
    public:
        Board() : board() {}
        Board(int columns, int rows) : board(rows, std::vector<char>(columns, ' ')) {}

        bool play(const Player& p, int x, int y)
        {
            if(x < 0 || y < 0 || y >= board.size() || x >= board[y].size()) {
                return false;
            }

            if(board[y][x] != ' ') {
                return false;
            }
            
            board[y][x] = p.getChar();
            return true;
        }

        void print()
        {
            int counter = 0;
            std::cout << " ";
            for(int i = 0; i < board[0].size() + board[0].size() + 1; i++) {
                if(i % 2 != 0) {
                    std::cout << counter;
                    counter++;
                    continue;
                }
                std::cout << " ";
            }

            std::cout << std::endl;

            for(int i = 0; i < board.size(); i++) {
                std::cout << i;
                for(int j = 0; j < board[i].size(); j++) {
                    if(j == 0) {
                        std::cout << "|";
                    }
                    std::cout << board[i][j] << "|";
                }
                std::cout << std::endl;
            }
        }
};