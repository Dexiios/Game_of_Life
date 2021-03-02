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

    if (window == NULL)
    {
        printf("SDL_Create_Window Error : %s\n", SDL_GetError());
        return EXIT_FAILURE;
    }

    //create render on window
    Uint32 render_flags = SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, render_flags);

    if (renderer == NULL)
    {
        printf("SDL_Renderer Error : %s\n", SDL_GetError());
        return EXIT_FAILURE;
    }

    //-------------------------------------------------------------------------------------------------------------

    int neighboursI[3];
    int neighboursJ[3];

    neighboursI[0] = -1;
    neighboursI[1] = 0;
    neighboursI[2] = 1;
    neighboursJ[0] = -1;
    neighboursJ[1] = 0;
    neighboursJ[2] = 1;

    int hold = 0;

    struct Game game;
    game.state = PAUSE;

    struct Cell grid[GRID_HEIGHT][GRID_WIDTH];
    for (size_t i = 0; i < GRID_HEIGHT; i++)
    {
        for (size_t j = 0; j < GRID_WIDTH; j++)
        {
            grid[i][j].shape = malloc(sizeof(SDL_Rect));
        }
    }

    int closeRequested = 0;

    while (closeRequested == 0)
    {
        SDL_Event event;
        SDL_RenderClear(renderer);

        for (size_t i = 0; i < GRID_HEIGHT; i++)
        {
            for (size_t j = 0; j < GRID_WIDTH; j++)
            {
                DrawCell(renderer, i, j, grid);
            }
        }
        if (game.state == PAUSE)
        {
            SDL_RenderPresent(renderer);
        }

        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                closeRequested = 1;
                break;
            case SDL_MOUSEBUTTONDOWN:
                if (event.button.button == SDL_BUTTON_LEFT)
                {
                    Sint32 i = event.button.x;
                    Sint32 j = event.button.y;
                    InitGame(renderer, grid, i, j);
                    hold = 1;
                }
                break;

            case SDL_MOUSEBUTTONUP:
                hold = 0;
                break;

            case SDL_MOUSEMOTION:
                if (hold == 1)
                {
                    Sint32 i = event.motion.x;
                    Sint32 j = event.motion.y;
                    InitGame(renderer, grid, i, j);
                }
                break;

            case SDL_KEYDOWN:
                if (event.key.keysym.sym == SDLK_SPACE)
                {
                    if (game.state == PAUSE)
                    {
                        game.state = PLAY;
                    }
                    else
                    {
                        game.state = PAUSE;
                    }
                }
                break;

            default:
                break;
            }
        }

        if (game.state == PLAY)
        {
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
            Playing(renderer, grid, grid2, neighboursI, neighboursJ);
            SDL_RenderPresent(renderer);

            for (size_t i = 0; i < GRID_HEIGHT; i++)
            {
                for (size_t j = 0; j < GRID_WIDTH; j++)
                {
                    grid[i][j].state = grid2[i][j].state;
                }
            }
        }
    }
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}