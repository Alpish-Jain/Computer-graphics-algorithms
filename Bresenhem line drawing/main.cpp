#include<GL/glut.h>
#include<stdio.h>
#include<stdlib.h>

int x1,x2,y1,y2;
void display (void)
{
int dx=x2-x1;
int dy=y2-y1;
int d = 2*dy - dx;
float x=x1,y=y1;

glClear (GL_COLOR_BUFFER_BIT);

glColor3f (0.0, 1.0, 0.0);
glBegin(GL_POINTS);
glVertex2i(x,y);
int D =d;
int k;
for(k=0;k<dx;k++)
{
if(D<0)
{
x = x+1;
glVertex2i(x,y);
}

else
{
x = x+1; y = y+1;
glVertex2i(x,y);
}
}

glEnd();
glFlush();
}

void init(void)
{
glClearColor (0.0, 0.0, 0.0, 0.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glOrtho(-100.0, 100.0, -100.0, 100.0, -1.0, 1.0);
}

int main(int argc, char** argv)
{
printf("Enter the points\n(X1,Y1,X2,Y2):-\n");
scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
glutInit(&argc, argv);
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize (500, 500);
glutInitWindowPosition (100, 100);
glutCreateWindow ("Breshanman Line Algorithm ");
init ();
glutDisplayFunc(display);
glutMainLoop();
return 0;
}
