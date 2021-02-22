#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include <stdlib.h>
#include <stdio.h>

#define DEAD 0
#define ALIVE 1

#define GRID_HEIGHT 100
#define GRID_WIDTH  100

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 800

#define CELLWIDTH  SCREEN_WIDTH/100
#define CELLHEIGHT  SCREEN_HEIGHT/100

struct Cell
{
    int state;
    SDL_Rect *shape;
};

int InitGame(SDL_Renderer *renderer, struct Cell grid[100][100]);
int DrawCell(SDL_Renderer *renderer, size_t i, size_t j, struct Cell grid[100][100]);
int Playing(SDL_Renderer *renderer, struct Cell grid[100][100]);

#endif