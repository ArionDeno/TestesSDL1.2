#include <stdio.h>
#include <stdlib.h>
#include<SDL/SDL.h>

#define LAR 520
#define ALT 340
#define DPI 32
#define FPS 30


int main(int argc, char *argv[])
{

 SDL_Surface *tela=NULL;
 SDL_Event ev;
 SDL_bool gameloop = SDL_TRUE;
 short int t_ini=0, t_fim=0, deltatm=0;


 if(SDL_Init(SDL_INIT_AUDIO|SDL_INIT_TIMER|SDL_INIT_VIDEO) ==-1)
 {
   printf("Erro na SDL %s\n",SDL_GetError());
   return(EXIT_FAILURE);
 }

 tela = SDL_SetVideoMode(LAR,ALT,DPI,SDL_SWSURFACE|SDL_DOUBLEBUF);
 if(tela == NULL)
 { printf("Erro na SDL %s\n",SDL_GetError());
   return(EXIT_FAILURE);
 }
SDL_WM_SetCaption("Eventos SDL teclado",NULL);

//----LOAD------------------

SDL_Rect qa={120,130,32,32};


//----LOAD------------------

while(gameloop != SDL_FALSE)
{
 t_ini= SDL_GetTicks();
//----INPUT------------------
 if(SDL_PollEvent(&ev))
 {
   if(ev.type == SDL_QUIT || ev.key.keysym.sym == SDLK_ESCAPE)
   { gameloop = SDL_FALSE; }

   switch(ev.key.keysym.sym)
   {
     case SDLK_UP:
         qa.y -= 22;
     break ;

     case SDLK_DOWN:
         qa.y += 22;
     break ;

     case SDLK_LEFT:
         qa.x -= 22;
     break ;

     case SDLK_RIGHT:
         qa.x += 22;
     break ;

   }
 }
//----INPUT------------------

//-----UPDATE-----------------
//-----UPDATE-----------------



//-----DRAW-----------------
SDL_FillRect(tela,NULL,0x0);
//--

SDL_FillRect(tela,&qa,0xFFAACC);

//--
SDL_Flip(tela);

//-----FPS-----------------
   t_fim= SDL_GetTicks();
   deltatm = t_ini - t_fim;

   if(deltatm < FPS)
   {
    printf("tempo de atraso %d", FPS - deltatm);
    SDL_Delay(FPS - deltatm);
   }


//-----FPS-----------------
}

//-----UNLOAD-----------------
  SDL_FreeSurface(tela);

//-----UNLOAD-----------------


 SDL_Quit();

  return EXIT_SUCCESS;
}
