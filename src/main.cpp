#include <iostream>
#include <unordered_map>
#include "tictactoe.hpp"

template<typename T>
void print(const std::vector<T>& v)
{
    for(int i = 0; i < v.size(); i++) {
        std::cout << v[i] << " ";
    }
}

void printPlayers(const std::vector<Player>& v)
{
    std::cout << "Players:" << std::endl;
    for(int i = 0; i < v.size(); i++) {
        std::cout << v[i].getName() << " | " << v[i].getChar() << std::endl;
    }
    std::cout << std::endl;
}

void clearInputBuffer()
{
    std::cin.clear();
    std::cin.ignore(256, '\n');
}

void setPlayers(std::vector<Player>& p, std::unordered_map<char, std::string>& c)
{
    clearInputBuffer();
    for(int i = 0; i < p.size(); i++) {
        std::string name;
        std::cout << "Enter name of player " << i+1 << ": ";
        std::getline(std::cin, name);
        p[i].setName(name);

        std::cout << "Enter character of " << name << ": ";
        char ch = '\0';
        std::cin >> ch;
        while(ch == ' ' || c.count(ch) > 0) {
            std::cout << "That character is already taken, try another: ";
            std::cin >> ch;
        }
        p[i].setChar(ch);
        clearInputBuffer();

        c.insert({ch, name});
        std::cout << std::endl;
    }
}

int main(int argc, char** argv)
{
    Board board;
    int board_size = 3;
    std::cout << "Enter board size: ";
    while(!(std::cin >> board_size)) {
        clearInputBuffer();
        std::cout << "Please enter an integer: ";
    }
    board.setSize(board_size);

    std::cout << "Enter number of players: ";
    int number_of_players;
    while(!(std::cin >> number_of_players)) {
        clearInputBuffer();
        std::cout << "Please enter an integer: ";
    }

    std::cout << std::endl;

    std::vector<Player> players(number_of_players);
    std::unordered_map<char, std::string> characters;
    setPlayers(players, characters);
    printPlayers(players);

    char ch = 'y';
    while(ch == 'Y' || ch == 'y') {
        int turn = 1;
        int i = 0;
        char winner = ' ';
        while(winner == ' ' && !board.isFull()) {
            std::cout << "Turn " << turn << ": " << players[i].getName() << std::endl;
            board.print();

            int x, y;
            std::cout << "Enter two numbers: ";
            std::cin >> x >> y;
            while(!board.play(players[i], x, y)) {
                std::cout << "[Invalid Move] Try again: ";
                std::cin >> x >> y;
            }
            std::cout << std::endl;

            turn++;
            i++;

            if(i >= players.size()) {
                i = 0;
            }

            winner = board.winner();
        }

        board.print();
        if(winner == ' ') {
            std::cout << "Its a draw." << std::endl;
        } else {
            std::cout << "The winner is " << characters.at(winner) << "!!" << std::endl;
        }

        std::cout << "Try again (y/n): ";
        std::cin >> ch;

        board.clear();
        std::cout << std::endl;
    }

    return 0;
}