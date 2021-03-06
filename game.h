#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include <stdlib.h>
#include <stdio.h>

#define DEAD 0
#define ALIVE 1

#define PLAY 0
#define PAUSE 1

#define GRID_HEIGHT 100
#define GRID_WIDTH  100

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 800

#define CELLWIDTH  SCREEN_WIDTH/GRID_HEIGHT

struct Game
{
    int state;
};

struct Cell
{
    int state;
    SDL_Rect *shape;
};

int InitGame(SDL_Renderer *renderer, struct Cell grid[GRID_HEIGHT][GRID_WIDTH], Sint32 i, Sint32 j);
int DrawCell(SDL_Renderer *renderer, size_t i, size_t j, struct Cell grid[GRID_HEIGHT][GRID_WIDTH]);
int Playing(SDL_Renderer *renderer, struct Cell grid[GRID_HEIGHT][GRID_WIDTH], struct Cell grid2[GRID_HEIGHT][GRID_WIDTH], int neighboursI[3], int neighboursJ[3]);
int IsValid(int i, int j);
int CountNeighbours(int h, int w, struct Cell grid[GRID_HEIGHT][GRID_WIDTH] ,int neighboursI[3], int neighboursJ[3]);

#endif