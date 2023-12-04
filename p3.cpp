#include <iostream>
using namespace std;

// Define the size of the board
const int SIZE = 3;

// Define the symbols for the players and the empty cell
const char X = 'X';
const char O = 'O';
const char EMPTY = ' ';

// Define a 2D array to represent the board
char board[SIZE][SIZE];

// Initialize the board with empty cells
void initBoard() {
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      board[i][j] = EMPTY;
    }
  }
}

// Display the board on the console
void displayBoard() {
  cout << "  1 2 3\n"; // Display the column numbers
  for (int i = 0; i < SIZE; i++) {
    cout << i + 1 << " "; // Display the row number
    for (int j = 0; j < SIZE; j++) {
      cout << board[i][j]; // Display the cell value
      if (j < SIZE - 1) {
        cout << "|"; // Display a vertical line after each cell except the last one
  }
    }
    cout << "\n"; // Move to the next line
    if (i < SIZE - 1) {
      cout << "  -+-+-\n"; // Display a horizontal line after each row except the last one
    }
  }
}

// Get the input from the current player and validate it
void getPlayerInput(char symbol) {
  int row, col;
  bool validInput = false;
  // Repeat until the input is valid
  do {
    cout << "Player " << symbol << ", enter your move (row[1-3] and column[1-3]): ";
    cin >> row >> col; // Get the input from the user
    row--; // Adjust the row index
    col--; // Adjust the column index
    // Check if the input is within the board range and the cell is empty
    if (row >= 0 && row < SIZE && col >= 0 && col < SIZE && board[row][col] == EMPTY) {
      board[row][col] = symbol; // Update the board with the symbol
      validInput = true; // Set the flag to true to exit the loop
    } else {
      cout << "Invalid input, please try again.\n"; // Display an error message
    }
  } while (!validInput);
}

// Check if the board is full or not
bool isBoardFull() {
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      if (board[i][j] == EMPTY) {
        return false; // There is an empty cell
      }
    }
  }
  return true; // There is no empty cell
}

// Check if a player has won or not
bool isWin(char symbol) {
  // Check the rows
  for (int i = 0; i < SIZE; i++) {
    if (board[i][0] == symbol && board[i][1] == symbol && board[i][2] == symbol) {
      return true; // There is a horizontal line
    }
  }
  // Check the columns
  for (int j = 0; j < SIZE; j++) {
    if (board[0][j] == symbol && board[1][j] == symbol && board[2][j] == symbol) {
      return true; // There is a vertical line
    }
  }
  // Check the diagonals
  if (board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol) {
    return true; // There is a diagonal line
  }
  if (board[0][2] == symbol && board[1][1] == symbol && board[2][0] == symbol) {
    return true; // There is a diagonal line
  }
  return false; // There is no line
}

// The main function
int main() {
  char answer; // To store the answer of the user
  do {
    initBoard(); // Initialize the board
    displayBoard(); // Display the board
    char turn = X; // Set the turn to X
    bool gameOver = false; // Set the game over flag to false
 // Repeat until the game is over
    do {
      getPlayerInput(turn); // Get the input from the current player
      displayBoard(); // Display the board
      if (isWin(turn)) { // Check if the current player has won
        cout << "Player " << turn << " wins!\n"; // Display the winning message
        gameOver = true; // Set the game over flag to true
      } else if (isBoardFull()) { // Check if the board is full
        cout << "It's a tie!\n"; // Display the tie message
        gameOver = true; // Set the game over flag to true
      } else {
        turn = (turn == X) ? O : X; // Switch the turn
      }
    } while (!gameOver);
    cout << "Do you want to play again (y/n)? "; // Ask the user to play again
    cin >> answer; // Get the answer from the user
  } while (answer == 'y' || answer == 'Y'); // Repeat if the answer is yes
  return 0;
}