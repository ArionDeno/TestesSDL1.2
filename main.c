/*-
 gcc main.c -lSDLmain -lSDL -lopengl32 -lglu
-*/
#include <stdio.h>
#include <stdlib.h>
#include <GL/gl.h>
#include<GL/glu.h>
#include<SDL/SDL.h>
#define LAR 640
#define ALT 480
#define DPI  32
#define FPS  30
#define TITULO "OpenGL e SDL 1.2 meu primero texte"

int main(int argc, char *argv[])
{
 atexit(SDL_Quit);
 SDL_Surface * tela=NULL;
 SDL_Event  eve;
 SDL_bool gameloop = SDL_TRUE;
 short int inico = 0, fim=0,deltatm =0;
 float angulo =0;

 // inicializando o video e os sub stemas da SDL
 if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) == -1)
 {
   printf("Erro ao Inciar a SDL \n %s",SDL_GetError());
   exit(EXIT_FAILURE);
 }

 //incializando o video
 tela = SDL_SetVideoMode(LAR,ALT,DPI,SDL_SWSURFACE|SDL_DOUBLEBUF|SDL_HWPALETTE |SDL_OPENGL);
 if(tela == NULL)
 {
   printf("Erro ao incializar a SDL com a openGL\n%s",SDL_GetError());
   exit(EXIT_FAILURE);
 }
 SDL_WM_SetCaption(TITULO,NULL);
//-------------INIT--------------------------------
  SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER,1);
  SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE,32 > 24 ? 24 : 32);
  SDL_GL_SetAttribute(SDL_GL_ACCUM_RED_SIZE,0);
  SDL_GL_SetAttribute(SDL_GL_ACCUM_GREEN_SIZE,0);
  SDL_GL_SetAttribute(SDL_GL_ACCUM_BLUE_SIZE,0);
  SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE,0);
  glViewport(0,0,LAR,ALT);


 while(gameloop != SDL_FALSE)
 {
   inico= SDL_GetTicks();
//--------------INPUT-------------------
 if(SDL_PollEvent(&eve))
 {
   if(eve.type== SDL_QUIT || eve.key.keysym.sym == SDLK_ESCAPE)
   { gameloop =SDL_FALSE;}
 }
 //----------UPDATE-----------------------------

 angulo += 0.180f * deltatm;

 //-----------DRAW------------------------------
   glPushMatrix();
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   glRotated(angulo,0,0,1);
    glBegin(GL_TRIANGLES);
      glColor3f(0.25f,1.0f,0.45f);
      glVertex2f(0.0f,0.5f);
      glVertex2f(-0.5f, -0.5f);
      glVertex2f(0.5f,-0.5f);
   glEnd();
   glPopMatrix();

//---------
 SDL_GL_SwapBuffers();
//-----------FPS--------------------
   fim= SDL_GetTicks();
   deltatm = (fim - inico) / FPS;
   SDL_Delay(deltatm);
 }

 SDL_FreeSurface(tela);

  exit(EXIT_SUCCESS);
}
