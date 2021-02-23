#include "game.h"

int Playing(SDL_Renderer *renderer, struct Cell grid[100][100], struct Cell grid2[100][100])
{

    for (size_t i = 0; i < GRID_WIDTH; i++)
    {
        for (size_t j = 0; j < GRID_HEIGHT; j++)
        {

            if (grid[i][j].state == ALIVE)
            {
                int neighbors = 0;
                if (i == 0 && j == 0)
                {
                    if (grid[i][j + 1].state == ALIVE)
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

                    if (neighbors < 2)
                    {
                        grid2[i][j].state = DEAD;
                        DrawCell(renderer, i, j, grid2);
                    }
                    if (neighbors > 3)
                    {
                        grid2[i][j].state = DEAD;
                        DrawCell(renderer, i, j, grid2);
                    }
                }

                else if (i == GRID_HEIGHT - 1 && j == 0)
                {
                    if (grid[i - 1][j].state == ALIVE)
                    {
                        neighbors += 1;
                    }
                    if (grid[i - 1][j + 1].state == ALIVE)
                    {
                        neighbors += 1;
                    }
                    if (grid[i][j + 1].state == ALIVE)
                    {
                        neighbors += 1;
                    }

                    if (neighbors < 2)
                    {
                        grid2[i][j].state = DEAD;
                        DrawCell(renderer, i, j, grid2);
                    }
                    if (neighbors > 3)
                    {
                        grid2[i][j].state = DEAD;
                        DrawCell(renderer, i, j, grid2);
                    }
                }

                else if (i == 0 && j == GRID_WIDTH - 1)
                {
                    if (grid[i][j - 1].state == ALIVE)
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

                    if (neighbors < 2)
                    {
                        grid2[i][j].state = DEAD;
                        DrawCell(renderer, i, j, grid2);
                    }
                    if (neighbors > 3)
                    {
                        grid2[i][j].state = DEAD;
                        DrawCell(renderer, i, j, grid2);
                    }
                }

                else if (i == GRID_HEIGHT - 1 && j == GRID_WIDTH - 1)
                {
                    if (grid[i - 1][j - 1].state == ALIVE)
                    {
                        neighbors += 1;
                    }
                    if (grid[i][j - 1].state == ALIVE)
                    {
                        neighbors += 1;
                    }
                    if (grid[i - 1][j].state == ALIVE)
                    {
                        neighbors += 1;
                    }

                    if (neighbors < 2)
                    {
                        grid2[i][j].state = DEAD;
                        DrawCell(renderer, i, j, grid2);
                    }
                    if (neighbors > 3)
                    {
                        grid2[i][j].state = DEAD;
                        DrawCell(renderer, i, j, grid2);
                    }
                }
                else
                {
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

                    if (neighbors < 2)
                    {
                        grid2[i][j].state = DEAD;
                        DrawCell(renderer, i, j, grid2);
                    }
                    if (neighbors > 3)
                    {
                        grid2[i][j].state = DEAD;
                        DrawCell(renderer, i, j, grid2);
                    }
                }
            }
            else
            {
                int neighbors = 0;
                if (i == 0 && j == 0)
                {
                    if (grid[i][j + 1].state == ALIVE)
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
                        grid2[i][j].state == ALIVE;
                        DrawCell(renderer, i, j, grid2);
                    }
                }

                else if (i == GRID_HEIGHT - 1 && j == 0)
                {
                    if (grid[i - 1][j].state == ALIVE)
                    {
                        neighbors += 1;
                    }
                    if (grid[i - 1][j + 1].state == ALIVE)
                    {
                        neighbors += 1;
                    }
                    if (grid[i][j + 1].state == ALIVE)
                    {
                        neighbors += 1;
                    }

                    if (neighbors == 3)
                    {
                        grid2[i][j].state == ALIVE;
                        DrawCell(renderer, i, j, grid2);
                    }
                }

                else if (i == 0 && j == GRID_WIDTH - 1)
                {
                    if (grid[i][j - 1].state == ALIVE)
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

                    if (neighbors == 3)
                    {
                        grid2[i][j].state == ALIVE;
                        DrawCell(renderer, i, j, grid2);
                    }
                }

                else if (i == GRID_HEIGHT - 1 && j == GRID_WIDTH - 1)
                {
                    if (grid[i - 1][j - 1].state == ALIVE)
                    {
                        neighbors += 1;
                    }
                    if (grid[i][j - 1].state == ALIVE)
                    {
                        neighbors += 1;
                    }
                    if (grid[i - 1][j].state == ALIVE)
                    {
                        neighbors += 1;
                    }

                    if (neighbors == 3)
                    {
                        grid2[i][j].state == ALIVE;
                        DrawCell(renderer, i, j, grid2);
                    }
                }
                else
                {
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
                        grid2[i][j].state == ALIVE;
                        DrawCell(renderer, i, j, grid2);
                    }
                }
            }
        }
    }
    memcpy(grid, grid2, sizeof(struct Cell)*100*100);
    return 0;
}