#include <stdio.h>
#include <stdlib.h>
#include "ui.h"
#include "mapa.h"

char drawGhost[4][7] = {
    {" .-.  " },
    {"| OO| " },
    {"|   | " },
    {"'^^^' " }
};

char drawWall[4][7] = {
    {"......" },
    {"......" },
    {"......" },
    {"......" }
};

char drawHero[4][7] = {
    {" .--. "  },
    {"/ _.-'"  },
    {"\\  '-." },
    {" '--' "  }
};

char drawPill[4][7] = {
    {"      "},
    {" .-.  "},
    {" '-'  "},
    {"      "}
};

char drawBlankSpace[4][7] = {
    {"      "},
    {"      "},
    {"      "},
    {"      "}
};

void printPiece(char draw[4][7], int piece){
	printf("%s", draw[piece]);
}

void printMap(MAP* m){
	for(int i = 0; i < m->rows; i++){
		for(int piece = 0; piece < 4; piece++){
			for(int j = 0; j < m->columns; j++){
				switch(m->matrix[i][j]){
					case GHOST:
						printPiece(drawGhost, piece);
						break;
					case HERO:
						printPiece(drawHero, piece);
						break;
					case PILL:
						printPiece(drawPill, piece);
						break;
					case VERTICAL_WALL:
					case HORIZONTAL_WALL:
						printPiece(drawWall, piece);
						break;
					case EMPTY:
						printPiece(drawBlankSpace, piece);
				}
			}
			printf("\n");
		}
	}
}