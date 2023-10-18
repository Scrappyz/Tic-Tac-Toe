#include <gtest/gtest.h>
#include "tictactoe.hpp"

using namespace std;

TEST(play, occupied_space)
{
    Board b(3,3);
    Player p1 = 'O';
    Player p2 = 'X';

    ASSERT_TRUE(b.play(p1, 2, 2));
    ASSERT_FALSE(b.play(p1, 2, 2));
    ASSERT_FALSE(b.play(p2, 2, 2));
    ASSERT_TRUE(b.play(p2, 0, 0));
}

TEST(play, edge_case)
{
    Board b(3,3);
    Player p1 = 'O';

    ASSERT_FALSE(b.play(p1, -1, 0));
    ASSERT_FALSE(b.play(p1, 0, -1));
    ASSERT_FALSE(b.play(p1, 3, 0));
    ASSERT_FALSE(b.play(p1, 0, 3));
    ASSERT_TRUE(b.play(p1, 2, 2));
}