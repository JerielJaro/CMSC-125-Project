/*
	Authors:
		BASNILLO, Miles Lawrence R., 2013-12868
		JARO, Jeriel., 2013-_____

	CMSC 125 Project: 8-Puzzle Game

	** Please refer to README.md regarding editing, installing and running the program.
*/	

#include "../../sdk/dexsdk.h"
#include "../../sdk/time.h"

void Erase();
void EraseAll();
void PrintInstructions(int x, int y);
void RandomizeBoard();
void PrintMenu();
void PrintBoard(int x, int y);						
void PrintBorder(); 								

#define col 3
#define row 3

#define up 'w'
#define down 's'
#define left 'a'
#define right 'd'
#define quit 'q'
#define start 'e'

/* Global variables */
int board[row][col];

void main(int argc, char *argv[]){
	char keypress = start;

	RandomizeBoard();

	set_graphics(VGA_320X200X256);

	do{	
		PrintBorder();
		PrintMenu();
		keypress = (char)getch();

		if(keypress == start){
			EraseAll();
			do{
				PrintInstructions(15, 20);
				PrintBoard(155, 50);										//* Always prints update version of board at coordinates
				PrintBorder();														//* Always prints border
				keypress=(char)getch();
				
				if(keypress == up){
					Erase(155, 25, 150, 50);
					write_text("I pressed UP!", 155, 25, WHITE, -1);			//* Must update the values of the board after each keypress
				}else if(keypress == left){
					Erase(155, 25, 150, 50);
					write_text("I pressed LEFT!", 155, 25, WHITE, -1);
				}else if(keypress == right){
					Erase(155, 25, 150, 50);
					write_text("I pressed RIGHT!", 155, 25, WHITE, -1);
				}else if(keypress == down){
					Erase(155, 25, 150, 50);
					write_text("I pressed DOWN!", 155, 25, WHITE, -1);
				}else{
					Erase(155, 25, 150, 50);
					write_text("Invalid button!", 155, 25, WHITE, -1);
				}
				
			}while(keypress != quit);
		}
	}while(keypress != quit);
	
	set_graphics(VGA_TEXT80X25X16);
	clrscr();
}

void PrintMenu(){
	write_text("8-", 140, 20, GREEN, 1);
	write_text("Puzzle", 160, 20, RED, 1);
	write_text("A game by CMSC 125 Students", 75, 35, WHITE, 0);

	write_text("E - Start Game", 100, 100, WHITE, 1);
	write_text("Q - Quit", 100, 120, WHITE, 1);
}

void PrintBorder(){
	int i, x1=5, y1=5, x2=315, y2=195, color1, color2;
	color1 = GREEN;
	color2 = RED;

	for(i=5;i<315;i++) write_pixel(i, y1, color1);	//TOP
	for(i=5;i<315;i++) write_pixel(i, y1+2, color2);	//TOP
	for(i=5;i<315;i++) write_pixel(i, y2, color1);	//BOTTOM
	for(i=5;i<315;i++) write_pixel(i, y2+2, color2);	//BOTTOM
	for(i=5;i<195;i++) write_pixel(x1, i, color2);	//LEFT
	for(i=5;i<195;i++) write_pixel(x1+2, i, color1);	//LEFT
	for(i=5;i<195;i++) write_pixel(x2, i, color2);	//RIGHT
	for(i=5;i<195;i++) write_pixel(x2+2, i, color1);	//RIGHT
}

void PrintBoard(int x, int y){
	int i, j, k, l;
	k = x;
	l = y;

	char str[10];
	for(i=0; i<row; i++, l+=30){
		for(j=0; j<col; j++, k+=55){
			if(board[i][j] == 0){
				write_text(" ", k, l, WHITE, 0);
			}else{
				sprintf(str, "%d", board[i][j]);
				write_text(str, k, l, WHITE, 0);
			}
		}
		k = x;
	}
}

void Erase(int x, int y, int w, int h){ //basically covers an area with a black rectangle 
   int i,j;
   for (i=y;i<=(y+h);i++)
      for (j=x;j<=(x+w);j++)
         write_pixel(j,i,100);
}

void EraseAll(){
	int i, j;
	for(i=1;i<320;i++){
		for(j=1;j<200;j++){
			write_pixel(i,j,100);
		}
	}
}

void PrintInstructions(int x, int y){
	write_text("8-Puzzle Game", x, y, GREEN, 0);
	write_text("Instructions: ", x, y+20, RED, 0);
	write_text("W - Move Up", x, y+40, WHITE, 0);
	write_text("S - Move Down", x, y+50, WHITE, 0);
	write_text("A - Move Left", x, y+60, WHITE, 0);
	write_text("D - Move Right", x, y+70, WHITE, 0);
	write_text("Q - Exit", x, y+80, WHITE, 0);
}


void RandomizeBoard(){
	int i, j;
	int boardCheck[9] = {0};
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			while(1){
				srand(time());
				board[i][j] = rand()%9;
				if(boardCheck[board[i][j]] == 0){
					boardCheck[board[i][j]] = 1;
					break;
				}
			}
		}
	}
}


/*
	FUNCTION FOR CHECKING INVERSIONS (TO BE USED LATER)

int CheckBoard(int board[9]){
	int i,j,inversions = 0;
	for(i=0;i<8;i++){
		for(j=i+1;j<9;j++){
			if(board[i] > board[j]){
				inversions++;
			}
		}
	}
	return inversions;
}

*/