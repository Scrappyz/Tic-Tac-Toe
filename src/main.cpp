#include <iostream>
#include "tictactoe.hpp"

template<typename T>
void print(const std::vector<T>& v)
{
    for(int i = 0; i < v.size(); i++) {
        std::cout << v[i] << " ";
    }
}

void clearInputBuffer()
{
    std::cin.clear();
    std::cin.ignore(256, '\n');
}

int main(int argc, char** argv)
{
    Board board;
    std::cout << "Enter number of players: ";
    int number_of_players;
    std::cin >> number_of_players;

    std::vector<Player> players(number_of_players);
    
    return 0;
}