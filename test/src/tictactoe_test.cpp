#include <gtest/gtest.h>
#include "tictactoe.hpp"

using namespace std;

TEST(play, occupied_space)
{
    Board b(3);
    Player p1 = 'O';
    Player p2 = 'X';

    ASSERT_TRUE(b.play(p1, 2, 2));
    ASSERT_FALSE(b.play(p1, 2, 2));
    ASSERT_FALSE(b.play(p2, 2, 2));
    ASSERT_TRUE(b.play(p2, 1, 1));
}

TEST(play, edge_case)
{
    Board b(3);
    Player p1 = 'O';

    ASSERT_FALSE(b.play(p1, 0, 1));
    ASSERT_FALSE(b.play(p1, 1, 0));
    ASSERT_FALSE(b.play(p1, 4, 1));
    ASSERT_FALSE(b.play(p1, 1, 4));
    ASSERT_TRUE(b.play(p1, 3, 3));
}

TEST(winner, rows)
{
    Board b(3);

    b.setBoard({{' ', 'O', 'X'}, {'O', 'X', 'O'}, {'X', 'X', 'X'}});
    EXPECT_EQ(b.winner(), 'X');
    b.setBoard({{' ', 'O', 'X'}, {'O', 'X', 'O'}, {'O', ' ', 'O'}});
    EXPECT_EQ(b.winner(), ' ');
    b.setBoard({{' ', 'O', 'X'}, {'O', 'O', 'O'}, {'X', 'X', 'O'}});
    EXPECT_EQ(b.winner(), 'O');
}

TEST(winner, columns)
{
    Board b(3);

    b.setBoard({
        {'O', 'X', ' '},
        {'O', ' ', 'X'},
        {'O', 'X', 'O'}
    });
    EXPECT_EQ(b.winner(), 'O');

    b.setBoard({
        {'O', 'O', ' '},
        {' ', 'O', 'X'},
        {' ', 'O', ' '}
    });
    EXPECT_EQ(b.winner(), 'O');

    b.setBoard({
        {' ', 'O', 'X'},
        {' ', 'X', 'X'},
        {' ', 'O', 'X'}
    });
    EXPECT_EQ(b.winner(), 'X');
}

TEST(winner, diagonals)
{
    Board b(3);

    b.setBoard({
        {'X', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', 'X'}
    });
    EXPECT_EQ(b.winner(), ' ');

    b.setBoard({
        {'X', ' ', ' '},
        {' ', 'X', 'O'},
        {' ', 'O', 'X'}
    });
    EXPECT_EQ(b.winner(), 'X');
    
    b.setBoard({
        {' ', ' ', 'O'},
        {' ', 'X', 'O'},
        {'X', ' ', ' '}
    });
    EXPECT_EQ(b.winner(), ' ');

    b.setBoard({
        {'X', ' ', 'O'},
        {'X', 'O', ' '},
        {'O', ' ', 'X'}
    });
    EXPECT_EQ(b.winner(), 'O');
}

TEST(winner, extra)
{
    Board b(4);

    b.setBoard({
        {'X', 'X', 'O', 'X'},
        {'X', 'X', 'X', 'X'},
        {' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' '}
    });
    EXPECT_EQ(b.winner(), 'X');

    b.setBoard({
        {' ', ' ', 'X', ' '},
        {' ', 'O', 'X', ' '},
        {' ', 'O', 'X', ' '},
        {' ', ' ', 'X', ' '}
    });
    EXPECT_EQ(b.winner(), 'X');

    b.setBoard({
        {'X', ' ', ' ', 'O'},
        {'O', 'X', ' ', 'O'},
        {'O', ' ', 'X', 'O'},
        {'O', ' ', ' ', 'X'}
    });
    EXPECT_EQ(b.winner(), 'X');

    b.setBoard({
        {' ', ' ', ' ', 'X'},
        {' ', ' ', 'X', ' '},
        {' ', 'X', ' ', ' '},
        {'X', 'O', 'O', 'O'}
    });
    EXPECT_EQ(b.winner(), 'X');
}