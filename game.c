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

    /*SDL_Rect carre;

    int cellWidth = SCREEN_WIDTH / 100;
    int cellHeight = SCREEN_HEIGHT / 100;

    carre.h = cellHeight;
    carre.w = cellWidth;

    carre.x = 320;
    carre.y = 240;

    SDL_SetRenderDrawColor(renderer, 0x00, 0xFF, 0x00, SDL_ALPHA_OPAQUE);

    SDL_RenderFillRect(renderer, &carre);

    SDL_RenderPresent(renderer);*/
    
    struct Cell **grid = malloc(sizeof(struct Cell)*CELLHEIGHT*CELLWIDTH);
    
    InitGame(renderer, grid);
    

    SDL_Delay(5000);
    SDL_Quit();
    
    return 0;
}