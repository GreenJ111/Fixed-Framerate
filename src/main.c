#include <SDL2\SDL.h>
#include <stdio.h>

#define WIDTH 900
#define HEIGHT 600
#define LENGTH 50

int main(int argc, char* argv[]) {
    //printf("hello world");

    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* window = SDL_CreateWindow("The window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, 0);
    SDL_Surface* surface = SDL_GetWindowSurface(window);
    SDL_Rect rect = {200,200,LENGTH,LENGTH};
    SDL_Event event;

    double dx = 1;
    double dy = 1;

    int game = 1;
    while (game == 1) {
        SDL_FillRect(surface, NULL, 0x00000000);

        while(SDL_PollEvent(&event)){
            switch (event.type){
                case(SDL_QUIT):
                game=0;
                break;
            }
        };

        if ((double)rect.x + (double)LENGTH + dx > (double)WIDTH) {
            dx /= abs(dx);
            dy /= abs(dy);
            dx *= -1;
        }
        if ((double)rect.x + dx < 0.0) {
            dx /= abs(dx);
            dy /= abs(dy);
            dx *= -1;
        }
        if ((double)rect.y + (double)LENGTH + dy > (double)HEIGHT) {
            dx /= abs(dx);
            dy /= abs(dy);
            dy *= -1;
        }
        if ((double)rect.y +  dy < 0.0) {
            dx /= abs(dx);
            dy /= abs(dy);
            dy *= -1;
        }
        rect.x += (int)dx;
        rect.y += (int)dy;

        SDL_FillRect(surface, &rect, 0xffffffff);
        SDL_UpdateWindowSurface(window);

        SDL_Delay(16);
    };

    SDL_DestroyWindowSurface(window);
    SDL_DestroyWindow(window);
    
    return 0;
}