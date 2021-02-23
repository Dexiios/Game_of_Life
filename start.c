#include "game.h"

int InitGame(SDL_Renderer *renderer, struct Cell grid[100][100])
{
    // puts start alive cells in grid
    
    for (size_t j = 10; j < GRID_WIDTH-10; j++)
    {
        grid[50][j].state = ALIVE;
        DrawCell(renderer, 50, j, grid);
    }

    SDL_RenderPresent(renderer);
    return 0;
}

//needs optimization !!!!!
int DrawCell(SDL_Renderer *renderer, size_t i, size_t j, struct Cell grid[100][100])
{
    
    struct Cell cell = grid[i][j];

    if (cell.state == ALIVE)
    {
        cell.shape->h = CELLHEIGHT;
        cell.shape->w = CELLWIDTH;
        cell.shape->x = j * CELLWIDTH;  //translates grid index to window "index"
        cell.shape->y = i * CELLHEIGHT; //translates grid index to window "index"

        SDL_SetRenderDrawColor(renderer, 0x00, 0xFF, 0x00, SDL_ALPHA_OPAQUE);
        SDL_RenderFillRect(renderer, cell.shape);
    }

    if (cell.state == DEAD)
    {
        cell.shape->h = CELLHEIGHT;
        cell.shape->w = CELLWIDTH;
        cell.shape->x = j * CELLWIDTH;  //translates grid index to window "index"
        cell.shape->y = i * CELLHEIGHT; //translates grid index to window "index"

        SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, SDL_ALPHA_OPAQUE);
        SDL_RenderFillRect(renderer, cell.shape);
    }
    

    return 0;
}