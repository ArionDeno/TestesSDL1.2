#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>

#include "retang.h"

#define FPS 30
#define TITULO "Protetor de Tela SDL"
#define LAR 520
#define ALT 340
#define DPI 32
#define FUNDO 0x0


int main(int argc, char *argv[])
{
  atexit(SDL_Quit);
  SDL_Surface *tela =NULL;
  SDL_Event ev;
  SDL_bool gameloop = SDL_TRUE;

  short int unsigned tempo_ini=0, tempo_fim=0, deltatm =0, fps=0;

  /*inicaliza a SDL*/
  if(SDL_Init(SDL_INIT_AUDIO|SDL_INIT_TIMER|SDL_INIT_VIDEO)==-1)
  {
    printf("Erro ao inicializar a SDL\n%s",SDL_GetError());
    return(EXIT_FAILURE);
  }

   //incializa o video
   tela = SDL_SetVideoMode(LAR,ALT,DPI,SDL_SWSURFACE|SDL_DOUBLEBUF);
   if(tela == NULL)
   {
     printf("Erro ao inicializar a SDL\n%s",SDL_GetError());
     exit(EXIT_FAILURE);
   }
   SDL_WM_SetCaption(TITULO,NULL);

/*---LOAD--------------------------------------------------*/
   inicializa_jogador();
   inicializa_retang_dieg();
   inicializa_retang_hor();
   inicializa_retang_vert();
   inicializa_obstaculos();
/*---LOAD--------------------------------------------------*/

 while(gameloop !=SDL_FALSE)
 {
   tempo_ini = SDL_GetTicks();
/*--INPUT---------------------------------------------------*/
    if(SDL_PollEvent(&ev))
    {
        if(ev.type == SDL_QUIT || ev.key.keysym.sym == SDLK_ESCAPE)
        { gameloop = SDL_FALSE; }
    }
/*--INPUT---------------------------------------------------*/

/*-----UPDATE------------------------------------------------*/

  controla_jogador();
  movimenta_retan_vert();
  movimenta_retan_hor();
  movimenta_retan_dieg();

  verifica_limites_daTela(&jogador);

/*-----UPDATE------------------------------------------------*/


/*--DRAW---------------------------------------------------*/
    SDL_FillRect(tela,NULL,FUNDO);
//-----------------

 desenha_retang(&retan_dieg,tela);
 desenha_retang(&retan_hor,tela);
 desenha_retang(&retan_vert,tela);
 desenha_retang(&obstaculo1,tela);
 desenha_retang(&obstaculo2,tela);
 desenha_retang(&jogador,tela);



//-----------------
   SDL_Flip(tela);
/*--DRAW---------------------------------------------------*/


/*--FPS---------------------------------------------------*/
  tempo_fim = SDL_GetTicks();
  ++fps;


//calulcando o deltatm
  deltatm = tempo_ini - tempo_fim;


  // calculando o fps
  if(tempo_fim >= 1000)
  {
    printf("FPS do jogo : %d\n", (deltatm/ fps)/1000);
    fps =0;
  }

// regulando o tempo para não ficar tão pesado
  if(FPS > deltatm)
   {
     SDL_Delay(FPS - deltatm);
     printf("delta tempo %d\n", FPS - deltatm);
   }

/*--FPS---------------------------------------------------*/
 }
 /*--UNLOAD---------------------------------------------------*/
  SDL_FreeSurface(tela);

 /*--UNLOAD---------------------------------------------------*/

  exit(EXIT_SUCCESS);
}
