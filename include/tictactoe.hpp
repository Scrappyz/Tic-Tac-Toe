#pragma once

#include <iostream>
#include <string>
#include <vector>

class Player {
    private:
        std::string name;
        char ch;
    public:
        Player() : name(), ch() {}
        Player(const std::string& n) : name(n), ch() {}
        Player(char c) : name(), ch(c) {}
        Player(const std::string& n, char c) : name(n), ch(c) {}

        const std::string& getName() const
        {
            return name;
        }

        char getChar() const
        {
            return ch;
        }

        void setName(const std::string& n)
        {
            name = n;
        }

        void setChar(char ch)
        {
            this->ch = ch;
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
        Board() : board(3, std::vector<char>(3, ' ')) {}

        Board(int n) : board()
        {
            setSize(n);
        }

        Board(const std::vector<std::vector<char>>& b) : board() 
        {
            setBoard(b);
        }

        void setBoard(const std::vector<std::vector<char>>& b)
        {
            if(b.size() != b[0].size()) {
                throw "[Error] Board needs to have the same rows and columns";
            }

            board = b;
        }

        void setSize(int n)
        {
            if(n < 1) {
                throw "[Error] Board size cannot be lesser than 1";
            }

            if(board.size() == n) {
                return;
            }

            for(int i = 0; i < board.size(); i++) {
                board[i].resize(n, ' ');
            }
            board.resize(n, std::vector<char>(n, ' '));
        }

        bool play(const Player& p, int x, int y)
        {
            x--; y--; // base of 1 in input

            if(x < 0 || y < 0 || y >= board.size() || x >= board[y].size()) { // out of range
                return false;
            }

            if(board[y][x] != ' ') { // is occupied
                return false;
            }

            board[y][x] = p.getChar();
            return true;
        }

        char winner() const
        {
            int max_x = board[0].size();
            int max_y = board.size();
            char win = ' ';

            // check rows
            for(int i = 0; i < max_y; i++) {
                if(board[i][0] != ' ') { // if 1st element is empty, then there is no winner in that row
                    win = board[i][0]; // will be the winning character to match
                    for(int j = 1; j < max_x; j++) {
                        if(board[i][j] != win) {
                            win = ' ';
                            break;
                        }
                    }
                    if(win != ' ') { // if 'win` is not empty, then it has consistently matched the whole row
                        return win;
                    }
                }
            }

            // check columns
            for(int j = 0; j < max_x; j++) {
                if(board[0][j] != ' ') {
                    win = board[0][j];
                    for(int i = 1; i < max_y; i++) {
                        if(board[i][j] != win) {
                            win = ' ';
                            break;
                        }
                    }
                    if(win != ' ') {
                        return win;
                    }
                }
            }

            // check diagonals
            if(board[0][0] != ' ') {
                win = board[0][0];
                int i = 1;
                int j = 1;
                while(i < max_y && j < max_x) {
                    if(board[i][j] != win) {
                        win = ' ';
                        break;
                    }
                    i++;
                    j++;
                }
                if(win != ' ') {
                    return win;
                }
            }

            if(board[0][max_x-1] != ' ') {
                win = board[0][max_x-1];
                int i = 1;
                int j = max_x-2;
                while(i < max_y && j >= 0) {
                    if(board[i][j] != win) {
                        win = ' ';
                        break;
                    }
                    i++;
                    j--;
                }
                if(win != ' ') {
                    return win;
                }
            }

            return win;
        }

        void clear()
        {
            for(int i = 0; i < board.size(); i++) {
                for(int j = 0; j < board[0].size(); j++) {
                    board[i][j] = ' ';
                }
            }
        }

        void print()
        {
            int counter = 1;
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
                std::cout << i+1;
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