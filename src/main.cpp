#include <iostream>
#include "tictactoe.hpp"

int main(int argc, char** argv)
{
    Board board(3);
    Player p1 = 'O';
    Player p2 = 'X';
    board.print();

    board.play(p1, 1, 1);
    board.play(p2, 2, 1);
    board.print();

    return 0;
}