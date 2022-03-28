#include<iostream>                                                                             //COE 2nd SEMESTER PROJECT
#include<windows.h>                                                                      //TIC TAC TOE Game MADE BY DHEERAJ KUMAR 
#include<cstdlib>                                                                        
#include<ctime>                                                                        
using namespace std;

char Tictactoe[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};                                        

char current_marker;
int current_player;

void gameboard()
{
    cout << "\t\t     |     |     " << endl;
    cout << "\t\t  " << Tictactoe[0][0] << "  |  " << Tictactoe[0][1] << "  |  " << Tictactoe[0][2] << endl;
    cout << "\t\t_____|_____|_____" << endl;
    cout << "\t\t     |     |     " << endl;
    cout << "\t\t  " << Tictactoe[1][0] << "  |  " << Tictactoe[1][1] << "  |  " << Tictactoe[1][2] << endl;
    cout << "\t\t_____|_____|_____" << endl;
    cout << "\t\t     |     |     " << endl;
    cout << "\t\t  " << Tictactoe[2][0] << "  |  " << Tictactoe[2][1] << "  |  " << Tictactoe[2][2] << endl;
    cout << "\t\t     |     |     " << endl;
    cout << endl;
}

bool Mark_X_O(int slot)
{
    int row = slot / 3;
    int col;

    if (slot % 3 == 0)
    {
        row = row - 1;
        col = 2;
    }
    else
    {
        col = slot % 3 - 1;
    }
    if (Tictactoe[row][col] != 'X' && Tictactoe[row][col] != 'O')
    {
        Tictactoe[row][col] = current_marker;
        return true;
    }
    else
    {
        return false;
    }
}

int winner()
{
    for (int i = 0; i < 3; i++)
    {
        //for rows
        if (Tictactoe[i][0] == Tictactoe[i][1] && Tictactoe[i][1] == Tictactoe[i][2])
        {
            return current_player;
        }
        //for columns
        if (Tictactoe[0][i] == Tictactoe[1][i] && Tictactoe[1][i] == Tictactoe[2][i])
        {
            return current_player;
        }
    }
    // diagnol conditions;
    if (Tictactoe[0][0] == Tictactoe[1][1] && Tictactoe[1][1] == Tictactoe[2][2])
    {
        return current_player;
    }
    if (Tictactoe[0][2] == Tictactoe[1][1] && Tictactoe[1][1] == Tictactoe[2][0])
    {
        return current_player;
    }
    return 0;
}

void swap_player_and_marker()
{
    if (current_marker == 'X')
    {
        current_marker = 'O';
    }
    else
    {
        current_marker = 'X';
    }
    if (current_player == 1)
    {
        current_player = 2;
    }
    else
    {
        current_player = 1;
    }
}

void game()
{
    int choice;
    cout << "1. Player1 Vs Player2 \t 2. Player Vs Computer "<<endl;
    cout<<  "\n    Please select a option from 1 and 2 : ";
    cin >> choice;
    cout<<endl;
    int player_won;

    if (choice == 2)
    {
    cout << "     Please choose your marker(X or O): ";
    char marker_p1;
    cin >> marker_p1;
    current_player = 1;
    current_marker = marker_p1;
    cout<<"\n";
        for (int i = 0; i < 9; i++)
        {
            int slot;
            if (current_player == 1)
            {
                cout << "   It's your turn. Enter your slot: ";
                cin >> slot;
            }

            else if (current_player == 2)
            {

                srand(time(NULL));
                cout << "   It`s computer turn : ";
                cout<<(rand()%(9))+1;
                slot=(rand()%(9))+1;
            }

            if (slot < 1 || slot > 9)
            {
                cout << "That slot is invalid! please try again";
                i--;
                continue;
            }

            if (!Mark_X_O(slot))
            {
                cout << "That slot is occupied! please try again";
                i--;
                continue;
            }
            cout<<"\n";
            gameboard();
            player_won = winner();

            if (player_won == 1)
            {
                cout << " Congratulations! you won! ";
                break;
            }
            if (player_won == 2)
            {
                cout << "Computer won !";
                break;
            }

        swap_player_and_marker();    
        }
        if (player_won == 0)
        {
            cout << "! That is a Tie game !";
        }
    }

    if (choice == 1)
    {
    cout << "     Player 1 Please choose your marker: ";
    char marker_p1;
    cin >> marker_p1;
    current_player = 1;
    current_marker = marker_p1;
    cout<<"\n";
        for (int i = 0; i < 9; i++)
        {
            cout << "       It's player " << current_player << "'s turn. Enter your slot: ";
            int slot;
            cin >> slot;

            if (slot < 1 || slot > 9)
            {
                cout << "You choose a invalid slot! please try again";
                i--;
                continue;
            }

            if (!Mark_X_O(slot))
            {
                cout << "That slot is occupied! please try again";
                i--;
                continue;
            }
            gameboard();

            player_won = winner();

            if (player_won == 1)
            {
                cout << "  Congratulations! Player one won! ";
                break;
            }
            if (player_won == 2)
            {
                cout << "  Congratulations! Player two won! ";
                break;
            }

        swap_player_and_marker();    
        }
        if (player_won == 0)
        {
            cout << "! That is a Tie game !";
        }
    }
}

int main()
{
    HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h,13);
    cout << "===============================================" << endl;
    cout << "|        Welcome To the Tic Tac Toe Game      |" << endl;
    cout << "===============================================" << endl;
    cout<<endl;
    cout<<  " MADE BY DHEERAJ KUMAR "<<endl;
    SetConsoleTextAttribute(h,11);
    gameboard();
    SetConsoleTextAttribute(h,14);
    game();
}
