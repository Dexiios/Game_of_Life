#include "game.h"

int InitGame(SDL_Renderer *renderer, struct Cell grid[GRID_HEIGHT][GRID_WIDTH])
{
    // puts start alive cells in grid

    grid[50][50].state = ALIVE;
    DrawCell(renderer, 50, 50, grid);

    grid[51][51].state = ALIVE;
    DrawCell(renderer, 51, 51, grid);

    grid[52][49].state = ALIVE;
    DrawCell(renderer, 52, 49, grid);
    grid[52][50].state = ALIVE;
    DrawCell(renderer, 52, 50, grid);
    grid[52][51].state = ALIVE;
    DrawCell(renderer, 52, 51, grid);

    /*grid[50][49].state = ALIVE;
    DrawCell(renderer, 50, 49, grid);
    grid[50][50].state = ALIVE;
    DrawCell(renderer, 50, 50, grid);
    grid[50][51].state = ALIVE;
    DrawCell(renderer, 50, 51, grid);*/

    SDL_RenderPresent(renderer);
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
        cell.shape->x = j * CELLWIDTH;  //translates grid index to window "index"
        cell.shape->y = i * CELLWIDTH; //translates grid index to window "index"
        SDL_SetRenderDrawColor(renderer, 0x00, 0xFF, 0x00, SDL_ALPHA_OPAQUE);
        SDL_RenderFillRect(renderer, cell.shape);
        
    }

    if (cell.state == DEAD)
    {
        cell.shape->h = CELLWIDTH;
        cell.shape->w = CELLWIDTH;
        cell.shape->x = j * CELLWIDTH;  //translates grid index to window "index"
        cell.shape->y = i * CELLWIDTH; //translates grid index to window "index"
        
        
        SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, SDL_ALPHA_OPAQUE);
        SDL_RenderFillRect(renderer, cell.shape);
        
    }
    
    
    return 0;
}