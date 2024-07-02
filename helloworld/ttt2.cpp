#include <iostream>
#include <array>
class TicTacToe 
{
private:
    std::array<char, 9> board;
    char currentPlayer;
    void clearBoard() 
    {
        board.fill('.');
    }
    void showBoard() 
    {
        for (int i = 0; i < 9; i++) 
        {
            std::cout << board[i] << " ";
            if ((i + 1) % 3 == 0) std::cout << "\n";
        }
    }
    bool isValidMove(int move) 
    {
        return move >= 0 && move < 9 && board[move] == '.';
    }
    bool checkWin() 
    {
        const int winPatterns[8][3] = 
        {
            {0,1,2}, {3,4,5}, {6,7,8}, // for rows
            {0,3,6}, {1,4,7}, {2,5,8}, // for columns
            {0,4,8}, {2,4,6}           // for diagonals
        };
        for (const auto& pattern : winPatterns) 
        {
            if (board[pattern[0]] != '.' &&
                board[pattern[0]] == board[pattern[1]] &&
                board[pattern[1]] == board[pattern[2]]) 
                {
                return true;
                }
        }
        return false;
    }
    bool isBoardFull() 
    {
        for (char cell : board) 
        {
            if (cell == '.') return false;
        }
        return true;
    }

public:
    TicTacToe() : currentPlayer('X') 
    {
        clearBoard();
    }
    void play() 
    {
        bool gameOver = false;
        int move;
        while (!gameOver) 
        {
            showBoard();
            std::cout << "Player " << currentPlayer << ", enter your move (0-8): ";
            std::cin >> move;
            if (isValidMove(move)) 
            {
                board[move] = currentPlayer;
                if (checkWin()) 
                {
                    showBoard();
                    std::cout << "Player " << currentPlayer << " wins!\n";
                    gameOver = true;
                } 
                else if (isBoardFull()) 
                {
                    showBoard();
                    std::cout << "It's a draw:(\n";
                    gameOver = true;
                } 
                else 
                {
                    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
                }
            } 
            else 
            {
                std::cout << "Invalid move! Try again.\n";
            }
        }
        char playAgain;
        std::cout << "Do you want to play again? (Y/N): ";
        std::cin >> playAgain;
        if (playAgain == 'y' || playAgain == 'Y') 
        {
            clearBoard();
            currentPlayer = 'X';
            play();
        }
    }
};
int main() 
{
    TicTacToe game;
    game.play();
    return 0;
}