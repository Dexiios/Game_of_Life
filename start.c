#include "game.h"

int InitGame(SDL_Renderer *renderer, struct Cell **grid)
{
    // puts start alive cells
    
    for (size_t i = 0; i < SCREEN_WIDTH; i+=CELLWIDTH)
    {
        printf("coucou1\n");
        DrawCell(renderer, i, 400, grid);
        printf("coucou2\n");
        grid[i][400].state = 1;
    }
    

    // puts all the dead cells
    for (size_t j = 0; j < SCREEN_WIDTH; j+=CELLWIDTH)
    {
        for (size_t k = 0; k < SCREEN_HEIGHT; k+=CELLHEIGHT)
        {
            if (k != 400)
            {
                grid[j][k].state = 0;
            }
        }
    }

    
    


    
    SDL_RenderPresent(renderer);
    return 0;
}

int DrawCell(SDL_Renderer *renderer, size_t i, size_t j, struct Cell **grid)
{
    
    struct Cell cell = grid[i][j];
    cell.shape->h = CELLHEIGHT;
    cell.shape->w = CELLWIDTH;
    cell.shape->x = i;
    cell.shape->y = j;
    SDL_SetRenderDrawColor(renderer, 0x00, 0xFF, 0x00, SDL_ALPHA_OPAQUE);
    SDL_RenderFillRect(renderer, cell.shape);
    
    return 0;
}