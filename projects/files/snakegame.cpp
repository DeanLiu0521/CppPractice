#include <cstdlib>
#include <ncurses.h>

using namespace std;

bool GameOver;
const int width = 20;
const int height = 20;
int x,y, fruitX, fruitY, score;

enum eDirection {STOP = 0, LEFT, RIGHT, UP, DOWN};
eDirection dir;

void Setup(){
	initscr();
    clear();
    noecho();
    cbreak();
    curs_set(0);
	GameOver = false;
	dir = STOP;
	x = width/2;
	y = height/2;
	fruitX = rand()%width+1;
	fruitY = rand()%height+1;
	score = 0;
}
void Draw(){
	clear();
	for(int i = 0; i<width+2; i++){
	    mvprintw(0,i, "#");
	}

	for(int i=0; i<height+2;i++){
		for(int j=0;j<width+2;j++){
			if (i == 0 | i ==21)
                mvprintw(i, j, "#");
            else if (j == 0 | j == 21)
                mvprintw(i, j, "+");
            else if (i == y && j == x)
                mvprintw(i, j, "0");
            else if (i == fruitY && j == fruitX)
                mvprintw(i, j, "0");
		}	
	}

	
	refresh();
}

void Input(){
	keypad(stdscr, TRUE);
	halfdelay(1);
	int c = getch();

	switch(c){
	case 'w':
		dir = UP;
		break;
	case 'a':
		dir = LEFT;
		break;
	case 's':
		dir = DOWN;
		break;
	case 'd':
		dir = RIGHT;
		break;
	case 'q':
		GameOver = true;
	default:
		break;
	}

}

void Logic(){
	switch(dir){
	case LEFT:
		x--;
		break;
	case RIGHT:
		x++;
		break;
	case UP:
		y--;
		break;
	case DOWN:
		y++;
		break;
	default:
		break;
	}
}


int main(){
	Setup();
	while(!GameOver){
		Draw();
		Input();
		Logic();
	}
	return 0;
}
