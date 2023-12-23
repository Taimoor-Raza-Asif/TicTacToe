#include <iostream>
#include<Windows.h>
using namespace std;

char Game_Board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
char player = 'X';
void Draw_Board();
void Move(int Player_Move);
void Player_Switch();
bool Win_Checker();
bool Game_Over();
void Validation(int move);

int main()
{
    char Winner_Player;
    int move;

    Draw_Board();
    while (!Win_Checker())
    {
        cout << " Enter number from 1 to 9 \n'" << player << "' it's your turn now \n";
        cin >> move;
        Validation(move);
        Move(move);
        system("cls");
        Draw_Board();
        if (Game_Over() == true)
        {
            cout << " This game has Tie \n";
            exit(0);
        }
    }
     Winner_Player=(player=='X')?'O':'X';
    
    cout << " Congratulation! " << Winner_Player << " You have won the game \n";
    return 0;
}

void Draw_Board()
{
    cout << "   "
         << "  | "
         << "   "
         << " | "
         << "   " << endl;
    cout << "  " << Game_Board[0][0] << "  |  " << Game_Board[0][1] << "  |  " << Game_Board[0][2] << "   " << endl;
    cout << "_____|_____|_____" << endl;
    cout << "   "
         << "  | "
         << "   "
         << " | "
         << "   " << endl;
    cout << "  " << Game_Board[1][0] << "  |  " << Game_Board[1][1] << "  |  " << Game_Board[1][2] << "   " << endl;
    cout << "_____|_____|_____" << endl;
    cout << "   "
         << "  | "
         << "   "
         << " | "
         << "   " << endl;
    cout << "  " << Game_Board[2][0] << "  |  " << Game_Board[2][1] << "  |  " << Game_Board[2][2] << "   " << endl;
    cout << "   "
         << "  | "
         << "   "
         << " | "
         << "   " << endl;
}
void Move(int Player_Move)
{
    int rows, cols;
    rows = (Player_Move - 1) / 3;
    cols = (Player_Move - 1) % 3;

    if (Game_Board[rows][cols] == 'X' || Game_Board[rows][cols] == 'O')
    {
        cout << "Invalid Move!!! This place is already taken \n";
        Sleep(700);
        // No need to switch players here
    }
    else
    {
        Game_Board[rows][cols] = player;
        Player_Switch();
    }
}


void Player_Switch()
{
    if (player == 'X')
    {
        player = 'O';
    }
    else
    {
        player = 'X';
    }
}

bool Win_Checker()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {

            if (Game_Board[i][0] == Game_Board[i][1] && Game_Board[i][1] == Game_Board[i][2])
            {
                return true;
            }
            if (Game_Board[0][j] == Game_Board[1][j] && Game_Board[1][j] == Game_Board[2][j])
            {
                return true;
            }
            if (Game_Board[0][0] == Game_Board[1][1] && Game_Board[1][1] == Game_Board[2][2])
            {
                return true;
            }
            if (Game_Board[0][2] == Game_Board[1][1] && Game_Board[1][1] == Game_Board[2][0])
            {
                return true;
            }
        }
    }
    return false;
}

bool Game_Over()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (Game_Board[i][j] == '1' || Game_Board[i][j] == '2' || Game_Board[i][j] == '3' || Game_Board[i][j] == '4' || Game_Board[i][j] == '5' || Game_Board[i][j] == '6' || Game_Board[i][j] == '7' || Game_Board[i][j] == '8' || Game_Board[i][j] == '9')
            {
                return false;
            }
        }
    }
    return true;
}

void Validation(int move)
{
    while (move < 1 || move > 9)
    {
        cout << " Invalid input! Enter number in between from 1 to 9 \n";
        cin >> move;
    }
}