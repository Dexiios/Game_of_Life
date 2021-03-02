#include "game.h"

int InitGame(SDL_Renderer *renderer, struct Cell grid[GRID_HEIGHT][GRID_WIDTH], Sint32 i, Sint32 j)
{
    Sint32 xTemp = j;
    int countX = 0;
    while (xTemp >= CELLWIDTH)
    {
        xTemp = xTemp-CELLWIDTH;
        countX++;
    }

    Sint32 yTemp = i;
    int countY = 0;
    while (yTemp >= CELLWIDTH)
    {
        yTemp = yTemp-CELLWIDTH;
        countY++;
    }

    if (grid[countX][countY].state != ALIVE)
    {
        grid[countX][countY].state = ALIVE;
        DrawCell(renderer, countX, countY, grid);
        SDL_RenderPresent(renderer);
    }
    
    return 0;
}

//needs optimization !!!!!
int DrawCell(SDL_Renderer *renderer, size_t i, size_t j, struct Cell grid[GRID_HEIGHT][GRID_WIDTH])
{

    struct Cell cell = grid[i][j];

    if (cell.state == ALIVE)
    {
        cell.shape->h = CELLWIDTH;
        cell.shape->w = CELLWIDTH;
        cell.shape->x = j * CELLWIDTH; //translates grid index to window "index"
        cell.shape->y = i * CELLWIDTH; //translates grid index to window "index"
        SDL_SetRenderDrawColor(renderer, 0x00, 0xFF, 0x00, 0x00);
        SDL_RenderFillRect(renderer, cell.shape);
    }

    if (cell.state == DEAD)
    {
        cell.shape->h = CELLWIDTH;
        cell.shape->w = CELLWIDTH;
        cell.shape->x = j * CELLWIDTH; //translates grid index to window "index"
        cell.shape->y = i * CELLWIDTH; //translates grid index to window "index"

        SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0x00);
        SDL_RenderFillRect(renderer, cell.shape);
    }

    return 0;
}