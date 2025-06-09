@ECHO OFF
SET SDL_CFLAGS=-IC:/msys64/ucrt64/include/SDL2 -Dmain=SDL_main
SET SDL_LIBS=-LC:/msys64/ucrt64/lib -lmingw32 -mwindows -lSDL2main -lSDL2
SET CFLAGS=-Wall -Wextra
@ECHO ON

gcc .\src\main.c -o .\out\main.exe %SDL_CFLAGS% %SDL_LIBS%