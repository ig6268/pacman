#ifndef _MAPA_H_
#define _MAPA_H_
#define HERO '@'
#define GHOST 'F'
#define EMPTY '.'
#define VERTICAL_WALL '|'
#define HORIZONTAL_WALL '-'
#define PILL 'P'

struct map{
	char** matrix;
	int rows, columns;
};
typedef struct map MAP;

struct position{
	int x, y;
}; 
typedef struct position POSITION;

int findMap(MAP* m, POSITION* p, char c);
void allocateMap(MAP* m);
void freeMap(MAP* m);
void readMap(MAP* m);
int isValid(MAP* m, int x, int y);
int isEmpty(MAP* m, int x, int y);
void walking(MAP* m, int originX, int originY, int destinyX, int destinyY);
void copyMap(MAP* destiny, MAP* origin);
int canWalk(MAP* m, char character, int x, int y);
int isCharacter(MAP* m, char character, int x, int y);
int isWall(MAP* m, int x, int y);
#endif