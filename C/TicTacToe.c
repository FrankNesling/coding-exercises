#include <stdio.h>
#include <stdbool.h>


char board[3][3] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };
char playerMarks[2] = { 'X', 'O' };


static void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

static int numberFromLetter(char letter) {
    switch (letter) {
    case 'A':
        return 1;
    case 'B':
        return 2;
    case 'C':
        return 3;
    default:
        return -1;
    }
}


static void displayBoard() {
    printf("\t 1\t 2\t 3");
    printf("\n");
    printf("A\t %c\t %c\t %c", board[0][0], board[0][1], board[0][2]);
    printf("\n");
    printf("B\t %c\t %c\t %c", board[1][0], board[1][1], board[1][2]);
    printf("\n");
    printf("C\t %c\t %c\t %c", board[2][0], board[2][1], board[2][2]);
}


static bool checkInputForPlacing(int inputSuccess, char inputLocation[]) {    
    bool isValidInput = false;

    if (inputSuccess != 1 || inputLocation[2] != '\0') {
        printf("Input must be A to C and 1 to 3. First letter, then number.\n");
        isValidInput = false;
    }

    if ((inputLocation[0] != 'A' && inputLocation[0] != 'B' && inputLocation[0] != 'C') ||
        (inputLocation[1] != '1' && inputLocation[1] != '2' && inputLocation[1] != '3')) {
        printf("Input must be A to C and 1 to 3. First letter, then number.\n");
        isValidInput = false;

    } 
    else {
        int letterNumber = numberFromLetter(inputLocation[0]);
        if (letterNumber == -1) {
            printf("Input Letter is wrong!");
            isValidInput = false;
        }
        else {
            if (board[letterNumber - 1][(inputLocation[1] - '0') - 1] != ' ') {       // - '0' converts char to digit
                printf("Input already occupied.\n");
                isValidInput = false;
            }
            else {
                isValidInput = true;
            }
        }      
    }

    clearInputBuffer();
    return isValidInput;
} 

static bool checkWin() {

    for (int i = 0; i < 3; i++) {
        // row
        if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) return true;

        // column
        if (board[0][i] != ' ' && board[0][i] == board[1][i] && board[1][i] == board[2][i]) return true;
    }

    // diagonal
    if (board[1][1] != ' ') {
        if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) return true;
        if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) return true;
    }
    
    return false;
}

static bool checkDraw() {
    bool isDraw = true;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') return false;
        }
    }
    return isDraw;
}


int main() {
    int input;
    bool gameFinished = false;
    int playerWon = 0;
    char userMarkLocationInput[3];

    int player = 0;
    displayBoard();


    while (!gameFinished) {
        printf("\n");
        printf("Player %d (%c): Enter the location you want to set your mark %c.\n", player + 1, playerMarks[player], playerMarks[player]);
        

        do {
            input = scanf("%2s", userMarkLocationInput);
        } while (!checkInputForPlacing(input, userMarkLocationInput));
         
            
       
        board[numberFromLetter(userMarkLocationInput[0]) - 1][(userMarkLocationInput[1] - '0') - 1] = playerMarks[player];
        

        if (checkDraw()) gameFinished = true;
        if (checkWin()) {
            gameFinished = true;
            playerWon = player + 1;
        }

        player = (player + 1) % 2;
        displayBoard();
    }

    if (playerWon > 0) {
        printf("\nCongratulations. Player %d with its %c mark has won!\n\n", playerWon, playerMarks[playerWon - 1]);
    }
    else {
        printf("\nDraw!\n\n");
    }

   
    system("pause");
    return 0;
}