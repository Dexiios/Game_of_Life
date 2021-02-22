#include "game.h"

int InitGame(SDL_Renderer *renderer, struct Cell grid[100][100])
{
    // puts start alive cells in grid
    
    for (size_t i = 10; i < GRID_WIDTH-10; i++)
    {
        grid[i][50].state = ALIVE;
        DrawCell(renderer, i, 50, grid);
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
        cell.shape->x = i * CELLWIDTH;  //translates grid index to window "index"
        cell.shape->y = j * CELLHEIGHT; //translates grid index to window "index"

        SDL_SetRenderDrawColor(renderer, 0x00, 0xFF, 0x00, SDL_ALPHA_OPAQUE);
        SDL_RenderFillRect(renderer, cell.shape);
    }

    if (cell.state == DEAD)
    {
        cell.shape->h = CELLHEIGHT;
        cell.shape->w = CELLWIDTH;
        cell.shape->x = i * CELLWIDTH;  //translates grid index to window "index"
        cell.shape->y = j * CELLHEIGHT; //translates grid index to window "index"

        SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, SDL_ALPHA_OPAQUE);
        SDL_RenderFillRect(renderer, cell.shape);
    }
    

    return 0;
}