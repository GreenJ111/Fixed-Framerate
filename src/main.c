#include <SDL2\SDL.h>
#include <stdio.h>

#define WIDTH 900
#define HEIGHT 600
#define LENGTH 50

#define FPS 60
#define TARGET_FRAME_TIME (1000/FPS)

struct Ball{float x; float y; float width; float height;};

int main(int argc, char* argv[]) {
    //printf("hello world");

    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* window = SDL_CreateWindow("The window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, 0);
    SDL_Surface* surface = SDL_GetWindowSurface(window);
    SDL_Event event;

    struct Ball ball = {200, 200, LENGTH, LENGTH};
    SDL_Rect rect = {(int)ball.x, (int)ball.y, (int)ball.width, (int)ball.height};

    int lastFrameTime = 0;
    float deltaTime = 0;
    int frameDelay = 0;

    int dx = 1;
    int dy = 1;

    int game = 1;
    while (game == 1) {
        frameDelay = TARGET_FRAME_TIME - (SDL_GetTicks() - lastFrameTime);
        if (0 < frameDelay && frameDelay <= TARGET_FRAME_TIME) {
            SDL_Delay(frameDelay);
        };

        deltaTime = (SDL_GetTicks() - lastFrameTime) / 1000.0f;
        lastFrameTime = SDL_GetTicks();
        
        SDL_FillRect(surface, NULL, 0x00000000);

        while(SDL_PollEvent(&event)){
            switch (event.type){
                case(SDL_QUIT):
                game=0;
                break;
            }
        };

        if (rect.x + LENGTH + (int)dx > WIDTH) {
            dx *= -1;
        }
        if (rect.x + (int)dx < 0) {
            dx *= -1;
        }
        if (rect.y + LENGTH + (int)dy > HEIGHT) {
            dy *= -1;
        }
        if (rect.y + (int)dy < 0.0) {
            dy *= -1;
        }
        ball.x += (dx * 50 * deltaTime);
        ball.y += (dy * 100 * deltaTime);

        rect.x = (int)ball.x;
        rect.y = (int)ball.y;

        //dx+= dx*0.01;
        //dy+= dy*0.01;
        
        /*
        if (dx < 0)
            dx -=1;
        else
            dx +=1;

        if (dy < 0)
            dy -=1;
        else
            dy +=1;
        */

        SDL_FillRect(surface, &rect, 0xffffffff);
        SDL_UpdateWindowSurface(window);
    };

    SDL_DestroyWindowSurface(window);
    SDL_DestroyWindow(window);
    
    return 0;
}