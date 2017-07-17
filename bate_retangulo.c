#include <SDL/SDL.h>

#define VELO 1
int main(int argc ,char *argv[])
{
SDL_Init(SDL_INIT_VIDEO);
SDL_Surface *screen;
SDL_Event event;
SDL_Rect dest = {0,0,0,0};
int vel = VELO;

screen = SDL_SetVideoMode(320, 240, 16, SDL_SWSURFACE|SDL_DOUBLEBUF);

int done = 0;
dest.y = 120;
dest.w = 16;
dest.h = 8;
while (done == 0)
{
while (SDL_PollEvent(&event))
{
if (event.type == SDL_QUIT || event.key.keysym.sym == SDLK_ESCAPE)
done = 1;
}
dest.x += vel;


if (dest.x < 0)
vel = VELO;
else if (dest.x + dest.w > screen->w)
{
 vel = -VELO;
 dest.h  += 32;
 dest.w += 32;
}

SDL_FillRect(screen, NULL, 0x0);
SDL_FillRect(screen, &dest, SDL_MapRGB(screen->format, 255, 255, 0));
SDL_UpdateRect(screen, 0,0,0,0);
SDL_Delay(30);
}
SDL_Quit();
return 0;
}
