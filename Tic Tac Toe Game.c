#include<stdio.h>
#include<stdbool.h>

void Print(char Ezra[4][4]);
bool Match(char Ezra[4][4], char player);
bool GameTied(char Ezra[4][4]);

int main()
{
  char Ezra[4][4] = {
    {'1', '2', '3', '4'},
    {'5', '6', '7', '8'},
    {'9', 'A', 'B', 'C'},  
    {'D', 'E', 'F', 'G'}
};


bool gamewon= false;
bool gametie= false;
char currentplayer='X';
int choice;
int row;
int column;



   while (!gamewon && !gametie)
   {
       Print(Ezra);

       printf("Player %c choose a number:",currentplayer);
       scanf("%d",&choice);


       row = (choice - 1) / 3;
       column = (choice - 1) % 3;

        if(Ezra[row][column]=='X'|| Ezra[row][column]== 'O')
       {
        printf("Number has already been chosen");
       }

       Ezra[row][column] = currentplayer;

       gamewon= Match(Ezra, currentplayer);
       gametie= GameTied(Ezra);

       currentplayer = (currentplayer == 'X') ? 'O':'X';

      
   }

Print(Ezra);
    if (gamewon) {
        printf("Player %c wins!\n", (currentplayer == 'X') ? 'O' : 'X'); // The last player who played is the winner
    } else if (gametie) {
        printf("The game is a tie!\n");
    }

    return 0;

}


void Print(char Ezra[4][4]) {
    printf(" %c | %c | %c | %c\n", Ezra[0][0], Ezra[0][1], Ezra[0][2], Ezra[0][3]);
    printf("---|---|---|---\n");
    printf(" %c | %c | %c | %c\n", Ezra[1][0], Ezra[1][1], Ezra[1][2], Ezra[1][3]);
    printf("---|---|---|---\n");
    printf(" %c | %c | %c | %c\n", Ezra[2][0], Ezra[2][1], Ezra[2][2], Ezra[2][3]);
}

bool Match(char Ezra[4][4], char player) {
    // Check rows and columns
    for (int i = 0; i < 4; i++) {
        if ((Ezra[i][0] == player && Ezra[i][1] == player && Ezra[i][2] == player && Ezra[i][3] == player) ||
            (Ezra[0][i] == player && Ezra[1][i] == player && Ezra[2][i] == player && Ezra[3][i] == player)) {
            return true;
        }
    }

    // Check diagonals
    if ((Ezra[0][0] == player && Ezra[1][1] == player && Ezra[2][2] == player && Ezra[3][3] == player) ||
          (Ezra[0][3] == player && Ezra[1][2] == player && Ezra[2][1] == player && Ezra[3][0] == player)) {
        return true;
    }

    return false;
}

// Function to check if the game is a tie
bool GameTied(char Ezra[4][4]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (Ezra[i][j] != 'X' && Ezra[i][j] != 'O') {
                return false;
            }
        }
    }
    return true;
}
