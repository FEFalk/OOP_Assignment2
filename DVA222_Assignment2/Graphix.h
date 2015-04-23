#pragma once

#include "glut.h"

//----------------------------------------------------------------------
//DO NOT DO ANYTHING HERE. JUST CLOSE THIS FILE. NOW!
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//I SAID NOW! CLOSE IT! CLOSE IT!
//----------------------------------------------------------------------


#pragma comment(lib, "opengl32")
#pragma comment(lib, "glu32")
#pragma comment(lib, "glut32")


static bool invalidate = true;

void InitGraphix(int argc, char** argv);
void DrawLine(int x1, int y1, int x2, int y2 );
void DrawRectanle(int x, int y, int width, int height );
void FillRectanle(int x, int y, int width, int height );

void DrawCircle(int cx, int cy, int radius);

void SetColor(int r, int  g, int  b);
void Redraw();
void Draw();
