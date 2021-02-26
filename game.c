#include "game.h"



int main()
{

    //initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        printf("Could not initialize sdl2 : %s\n", SDL_GetError());
        return EXIT_FAILURE;
    }

    //create the window to draw in
    SDL_Window *window = SDL_CreateWindow("Game of Life", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);

    if(window == NULL)
    {
        printf("SDL_Create_Window Error : %s\n", SDL_GetError());
        return EXIT_FAILURE;
    }

    //create render on window
    Uint32 render_flags = SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, render_flags);

    if(renderer == NULL)
    {
        printf("SDL_Renderer Error : %s\n", SDL_GetError());
        return EXIT_FAILURE;
    }

    //-------------------------------------------------------------------------------------------------------------

    struct Cell grid[GRID_HEIGHT][GRID_WIDTH];
    for (size_t i = 0; i < GRID_HEIGHT; i++)
    {
        for (size_t j = 0; j < GRID_WIDTH; j++)
        {
            grid[i][j].shape = malloc(sizeof(SDL_Rect));
        }
    }

    

    InitGame(renderer, grid);
    int closeRequested = 0;

    while(closeRequested == 0)
    {
        SDL_Event event;
        while(SDL_PollEvent(&event))
        {
            if(event.type == SDL_QUIT)
            {
                closeRequested = 1;
            }
        }

        struct Cell grid2[GRID_HEIGHT][GRID_WIDTH];
        for (size_t i = 0; i < GRID_HEIGHT; i++)
        {
            for (size_t j = 0; j < GRID_WIDTH; j++)
            {
                grid2[i][j].shape = malloc(sizeof(SDL_Rect));
                grid2[i][j].state = DEAD;
            }
        }

        SDL_Delay(100);
        Playing(renderer, grid, grid2);
        SDL_RenderPresent(renderer);
        

        for (size_t i = 0; i < GRID_HEIGHT; i++)
        {
            for (size_t j = 0; j < GRID_WIDTH; j++)
            {
                grid[i][j].state = grid2[i][j].state;
            }
        }

    }
    SDL_Quit();
    return 0;
}