#include "game.h"

int Playing(SDL_Renderer *renderer, struct Cell grid[GRID_HEIGHT][GRID_WIDTH], struct Cell grid2[GRID_HEIGHT][GRID_WIDTH])
{
    for (size_t i = 0; i < GRID_HEIGHT; i++)
    {
        for (size_t j = 0; j < GRID_WIDTH; j++)
        {
            if (grid[i][j].state == ALIVE)
            {
                int neighbors = 0;

                if (grid[i - 1][j - 1].state == ALIVE)
                {
                    neighbors += 1;
                }
                if (grid[i - 1][j].state == ALIVE)
                {
                    neighbors += 1;
                }
                if (grid[i - 1][j + 1].state == ALIVE)
                {
                    neighbors += 1;
                }
                if (grid[i][j - 1].state == ALIVE)
                {
                    neighbors += 1;
                }
                if (grid[i][j + 1].state == ALIVE)
                {
                    neighbors += 1;
                }
                if (grid[i + 1][j - 1].state == ALIVE)
                {
                    neighbors += 1;
                }
                if (grid[i + 1][j].state == ALIVE)
                {
                    neighbors += 1;
                }
                if (grid[i + 1][j + 1].state == ALIVE)
                {
                    neighbors += 1;
                }

                if (neighbors < 2 || neighbors > 3)
                {
                    grid2[i][j].state = DEAD;
                    
                }
                else
                {
                    grid2[i][j].state = ALIVE;
                }
            }
            if(grid[i][j].state == DEAD)
            {
                int neighbors = 0;
                if (grid[i - 1][j - 1].state == ALIVE)
                {
                    neighbors += 1;
                }
                if (grid[i - 1][j].state == ALIVE)
                {
                    neighbors += 1;
                }
                if (grid[i - 1][j + 1].state == ALIVE)
                {
                    neighbors += 1;
                }
                if (grid[i][j - 1].state == ALIVE)
                {
                    neighbors += 1;
                }
                if (grid[i][j + 1].state == ALIVE)
                {
                    neighbors += 1;
                }
                if (grid[i + 1][j - 1].state == ALIVE)
                {
                    neighbors += 1;
                }
                if (grid[i + 1][j].state == ALIVE)
                {
                    neighbors += 1;
                }
                if (grid[i + 1][j + 1].state == ALIVE)
                {
                    neighbors += 1;
                }

                if (neighbors == 3)
                {
                    grid2[i][j].state = ALIVE;
                }
                else
                {
                    grid2[i][j].state = DEAD;
                }
            }
        }
    }

    for (size_t i = 0; i < GRID_HEIGHT; i++)
    {
        for (size_t j = 0; j < GRID_WIDTH; j++)
        {   
            DrawCell(renderer, i, j, grid2);
        }
    }
    return 0;
}