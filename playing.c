#include "game.h"

int Playing(SDL_Renderer *renderer, struct Cell grid[GRID_HEIGHT][GRID_WIDTH], struct Cell grid2[GRID_HEIGHT][GRID_WIDTH])
{
    for (size_t i = 0; i < GRID_HEIGHT; i++)
    {
        for (size_t j = 0; j < GRID_WIDTH; j++)
        {
            if (grid[i][j].state == ALIVE)
            {
                int neighbours = CountNeighbours(i,j,grid);

                if (neighbours < 2 || neighbours > 3)
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
                int neighbours = CountNeighbours(i,j,grid);

                if (neighbours == 3)
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

int IsValid(size_t i, size_t j)
{
    int res = 0;
    if (i >= 0 && j >= 0 && i < GRID_WIDTH && j < GRID_HEIGHT)
        res = 1;
    return res;
}

int CountNeighbours(size_t i, size_t j, struct Cell grid[GRID_HEIGHT][GRID_WIDTH])
{
    int neighbours = 0;
    if (IsValid(i-1,j-1) == 1 && grid[i-1][j-1].state == ALIVE)
    {
        neighbours++;
    }
    if (IsValid(i-1,j) == 1 && grid[i-1][j].state == ALIVE)
    {
        neighbours++;
    }
    if (IsValid(i-1,j+1) == 1 && grid[i-1][j+1].state == ALIVE)
    {
        neighbours++;
    }
    if (IsValid(i,j-1) == 1 && grid[i][j-1].state == ALIVE)
    {
        neighbours++;
    }
    if (IsValid(i,j+1) == 1 && grid[i][j+1].state == ALIVE)
    {
        neighbours++;
    }
    if (IsValid(i+1,j-1) == 1 && grid[i+1][j-1].state == ALIVE)
    {
        neighbours++;
    }
    if (IsValid(i+1,j) == 1 && grid[i+1][j].state == ALIVE)
    {
        neighbours++;
    }
    if (IsValid(i+1,j+1) == 1 && grid[i+1][j+1].state == ALIVE)
    {
        neighbours++;
    }
    return neighbours;
}