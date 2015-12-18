#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mapa.h"

int canWalk(MAP* m, char character, int x, int y){
	return isValid(m, x, y) && !isWall(m, x, y) && !isCharacter(m, character, x, y);
}

int isWall(MAP* m, int x, int y){
	return m->matrix[x][y] == VERTICAL_WALL || m->matrix[x][y] == HORIZONTAL_WALL;
}

int isCharacter(MAP* m, char character, int x, int y){
	return m->matrix[x][y] == character;
}

void copyMap(MAP* destiny, MAP* origin){
	destiny->rows = origin->rows;
	destiny->columns = origin->columns;

	allocateMap(destiny);
	for(int i = 0; i < origin->rows; i++){
		strcpy(destiny->matrix[i], origin->matrix[i]);
	}
}	

void walking(MAP* m, int originX, int originY, int destinyX, int destinyY){
	char character = m->matrix[originX][originY];
	m->matrix[destinyX][destinyY] = character;
	m->matrix[originX][originY] = EMPTY;
}

int isValid(MAP* m, int x, int y){
	if(x >= m->rows) return 0;
	if(y >= m->columns) return 0;

	return 1;
}

int isEmpty(MAP* m, int x, int y){
	return m->matrix[x][y] == EMPTY;
}

int findMap(MAP* m, POSITION* p, char c){
	for(int i = 0; i < m->rows; i++){
		for(int j = 0; j < m->columns; j++){
			if(m->matrix[i][j] == c){
				p->x = i;
				p->y = j;
				return 1;
			}
		}
	}
	return 0;
}

void allocateMap(MAP* m){
	m->matrix = malloc(sizeof(char*) * m->rows);
	for(int i = 0; i < m->rows; i++){
		m->matrix[i] = malloc(sizeof(char) * (m->columns + 1));
	}
}

void freeMap(MAP* m){
	for(int i = 0; i < m->rows; i++){
		free(m->matrix[i]);
	}
	free(m->matrix);
}

void readMap(MAP* m){
	FILE* f;
	f = fopen("mapa.txt", "r");
	if(f == 0){
		printf("Error #01: File isn't available.\n");
		exit(1);
	}

	fscanf(f, "%d %d", &(m->rows), &(m->columns));

	allocateMap(m);

	for(int i = 0; i < 5; i++){
		fscanf(f, "%s", m->matrix[i]);
	}
	fclose(f);
}