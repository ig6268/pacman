#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "pacman.h"
#include "mapa.h"
#include "ui.h"

MAP m;
POSITION hero;
int pill = 0;

int moveGhost(int currentX, int currentY, int* destinyX, int* destinyY){
	int options[4][2] = {
		{currentX, currentY + 1},
		{currentX + 1, currentY},
		{currentX, currentY - 1},
		{currentX - 1, currentY}
	};

	srand(time(0));
	for(int i = 0; i < 10; i++){
		int position = rand() % 4;
		if(canWalk(&m, GHOST, options[position][0], options[position][1])){
			*destinyX = options[position][0];
			*destinyY = options[position][1];

			return 1;
		}
	}

	return 0;
}

void ghosts(){
	MAP copy;

	copyMap(&copy, &m);
	for(int i = 0; i < m.rows; i++){
		for(int j = 0; j < m.columns; j++){
			if(copy.matrix[i][j] == GHOST){
				
				int destinyX, destinyY;
				int find = moveGhost(i, j, &destinyX, &destinyY);

				if(find){
					walking(&m, i, j, destinyX, destinyY);
				}
			}
		}
	}
	freeMap(&copy);
}

int end(){
	POSITION pos;
	int pacman = findMap(&m, &pos, HERO);
	printf("You lost!\n");
	return !pacman;
}

void explode(){
	if(!pill) return;
	explosion(hero.x, hero.y, 0, 1, 3);
	explosion(hero.x, hero.y, 0, -1, 3);
	explosion(hero.x, hero.y, 1, 0, 3);
	explosion(hero.x, hero.y, -1, 0, 3);

	pill = 0;
}

void explosion(int x, int y, int sumX, int sumY, int qtd){
	
	if(qtd == 0) return;

	int newX = x + sumX;
	int newY = y + sumY;

	if(!isValid(&m, newX, newY)) return;
	if(isWall(&m, newX, newY)) return;
	m.matrix[newX][newY] = EMPTY;
	explosion(newX, newY, sumX, sumY, qtd - 1);	
}

int isDirection(char direction){
	return direction == 'a' ||
		direction == 'w' ||
		direction == 's' ||
		direction == 'd';
}

void move(char direction){
	
	if(!isDirection(direction))
		return;

	int nextX = hero.x;
	int nextY = hero.y;

	switch(direction){
		case LEFT: 
			nextY--;
			break;
		case UP:
			nextX--;
			break;
		case DOWN:
			nextX++;
			break;
		case RIGHT:
			nextY++;
			break;
	}

	if(!canWalk(&m, HERO, nextX, nextY)) return;

	if(isCharacter(&m, PILL, nextX, nextY)){
		pill = 1;

	}

	walking(&m, hero.x, hero.y, nextX, nextY);
	hero.x = nextX;
	hero.y = nextY;
}

int main(){

	readMap(&m);
	findMap(&m, &hero, HERO);

	do {

		system("clear");
		printf("Pills: %d\n", pill);
		printMap(&m);
		char command;
		scanf("%c", &command);
		move(command);
		if(command == BOMB) explode();
		ghosts();
	} while (!end());
	freeMap(&m);
  return 0;
}
