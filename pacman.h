#ifndef _PACMAN_H_
#define _PACMAN_H_
#define UP 'w'
#define DOWN 's'
#define RIGHT 'd'
#define LEFT 'a'
#define BOMB 'b'

void move(char direction);
int end();
int isDirection(char direction);
void ghosts();
int moveGhost(int currentX, int currentY, int* destinyX, int* destinyY);
void explode();
void explosion(int x, int y, int sumX, int sumY, int qtd);
#endif