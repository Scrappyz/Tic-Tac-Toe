#include <iostream>
#include <vector>
#include <random>
#include <chrono>

using namespace std;

int randomNum(int min, int max)
{
    std::random_device rd;
    std::mt19937::result_type seed = rd() ^ (
            (std::mt19937::result_type)
            std::chrono::duration_cast<std::chrono::seconds>(
                std::chrono::system_clock::now().time_since_epoch()
                ).count() +
            (std::mt19937::result_type)
            std::chrono::duration_cast<std::chrono::microseconds>(
                std::chrono::high_resolution_clock::now().time_since_epoch()
                ).count() );

    std::mt19937 gen(seed);
    std::uniform_int_distribution<unsigned> distrib(min, max);

    return distrib(gen);
}

class TicTacToe {
public:
    bool Ai;
    bool goingFirst;
    vector<char> board;
    vector<vector<int>> winCond;

    TicTacToe();

    bool isFull(int);
    void playAgainstAi();
    void printMap(int, char);
    int makeMove(char);
    int enemyMakeMove();
    bool win();
};

TicTacToe::TicTacToe() : Ai(false), goingFirst(false), board(9), winCond(8, vector<int>(3))
{
    board = { // The Tic-Tac-Toe board
                ' ', ' ', ' ',
                ' ', ' ', ' ',
                ' ', ' ', ' '
            };
    winCond = { // Possible combinations to obtain a win
                {0,1,2}, {3,4,5}, {6,7,8}, {0,3,6}, {1,4,7}, {2,5,8}, {0,4,8}, {2,4,6}
              };
}

bool TicTacToe::isFull(int n)
{
    if(board[n-1] != ' ')
        return true;
    return false;
}

void TicTacToe::playAgainstAi()
{
    char ch;
    cout << "Would you like to play against an AI? y/n: ";
    cin >> ch;
    if(ch == 'y') {
        Ai = true;
        cout << "[AI is active]" << endl;
    }
    else
        cout << "[AI is not active]" << endl;
}

void TicTacToe::printMap(int pos, char ch)
{
    for(int i = 0; i<board.size(); i++) {
        if(i == pos-1) {
            board[i] = ch;
        }
        if(i % 3 == 0 && i != 0)
            cout << endl;
        cout << board[i];
        if(i != 2 && i != 5 && i != 8)
            cout << "|";
    }
}

int TicTacToe::enemyMakeMove()
{
    int n;
    cout << "AI: ";
    if(goingFirst) {

    } else {
        cin >> n;
    }
    return n;
}

bool TicTacToe::win()
{
    bool check;
    for(int i = 0; i<8; i++) {
        for(int j = 0; j<3-1; j++) {
            if((board[winCond[i][j]] == board[winCond[i][j+1]]) && board[winCond[i][j]] != ' ')
                check = true;
            else {
                check = false;
                break;
            }
            if(check && j == 1)
                return true;
        }
    }

    return check;
}

bool valid(char& ch)
{
    switch(ch) {
    case 'x':
        ch = 'X';
    case 'X':
        return true;
    case 'o':
        ch = 'O';
    case 'O':
        return true;
    default:
        return false;
    }
}

int main()
{
    cout << "========TIC-TAC-TOE========" << endl;
    TicTacToe tic;
    tic.playAgainstAi();

    char player1;
    char player2;
    while(true) {
        cout << "Would you like to be 'X' or 'O'? ";
        cin >> player1;
        if(valid(player1))
            break;
        cin.ignore();
    }

    if(player1 == 'X')
        player2 = 'O';
    else
        player2 = 'X';

    cout << "Player 1 is '" << player1 << "'" << endl;
    cout << "Player 2 is '" << player2 << "'" << endl;

    cout << "[How to play] Enter the position by inputting 1-9" << endl;
    cout << "1|2|3\n4|5|6\n7|8|9" << endl;
    cout << "\nLET'S START!!" << endl;

    char temp;
    int ntemp = 2;//randomNum(1, 2);
    if(ntemp == 1) {
        temp = player1;
        cout << "Player 1 is going first" << endl;
        tic.goingFirst = true;
    } else {
        temp = player2;
        cout << "Player 2 is going first" << endl;
    }

    int turn = 1;
    int n = 0;
    tic.printMap(n, temp);
    do {
        cout << "Turn " << turn << ":" << endl;
        //n = makeMove(temp);
        if((n < 1 || n > 9) || tic.isFull(n)) {
            n = 0;
            continue;
        }
        tic.printMap(n, temp);
        if(tic.win()) {
            cout << "\nYou won";
            return 0;
        }
        if(temp == player1)
            temp = player2;
        else
            temp = player1;
        turn++;
    } while(cin);

    return 0;
}
