#include <iostream>
#include "tictactoe.hpp"

template<typename T>
void print(const std::vector<T>& v)
{
    for(int i = 0; i < v.size(); i++) {
        std::cout << v[i] << " ";
    }
}

int main(int argc, char** argv)
{
    Board b(1);
    Player p1 = 'X';
    b.print();
    b.play(p1, 1, 1);
    b.setSize(3);
    b.play(p1, 3, 3);
    b.print();
    b.setSize(9);
    b.print();
    b.clear();
    b.print();

    return 0;
}