#include "game.h"

int Playing(SDL_Renderer *renderer, struct Cell grid[GRID_HEIGHT][GRID_WIDTH], struct Cell grid2[GRID_HEIGHT][GRID_WIDTH], int neighboursI[3], int neighboursJ[3])
{
    for (size_t i = 0; i < GRID_HEIGHT; i++)
    {
        for (size_t j = 0; j < GRID_WIDTH; j++)
        {
            if (grid[i][j].state == ALIVE)
            {
                int neighbours = CountNeighbours(i,j,grid, neighboursI, neighboursJ);

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
                int neighbours = CountNeighbours(i,j,grid, neighboursI, neighboursJ);

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

int IsValid(int i, int j)
{
    int res = 0;
    if (i >= 0 && j >= 0 && i < GRID_WIDTH && j < GRID_HEIGHT)
        res = 1;
    return res;
}

int CountNeighbours(int h, int w, struct Cell grid[GRID_HEIGHT][GRID_WIDTH] ,int neighboursI[3], int neighboursJ[3])
{

    int neighbours = 0;
    
    for (size_t i = 0; i < 3; i++)
    {
        int realI = neighboursI[i];
        
        for (size_t j = 0; j < 3; j++)
        {
            int realJ = neighboursJ[j];

            if (IsValid(h + realI, w + realJ) == 1)
            {
                if (grid[h + realI][w + realJ].state == ALIVE)
                {
                    neighbours++;
                }
            }
        }
        
    }

    return (grid[h][w].state == DEAD) ? neighbours : neighbours-1;
}