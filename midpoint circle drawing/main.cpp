#include <stdio.h>
#include <iostream>
#include <GL/glut.h>
using namespace std;

int xc, yc, r;

void plot(int x, int y)
{
    //glPointSize(10.0);
	glBegin(GL_POINTS);
	glVertex2i(x+xc, y+xc);//plotting the points
	glEnd();
}


void myInit (void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);//set the background to black after clearing the screen
	glColor3f(1.0f, 1.0f, 1.0f);//set the color of points to white
	//glPointSize(10.0);
	glMatrixMode(GL_PROJECTION);//set the projection matrix
	glLoadIdentity();//initialize the projection matrix
	gluOrtho2D(0.0, 640.0, 0.0, 480.0);//we are using orthographic projection and setting the coordinates of viewport
}


void midPointCircleAlgo()
{
	int x = 0;
	int y = r;
	float decision = 5/4 - r;
	plot(x, y);

	while (y > x)
	{
		if (decision < 0)
		{
			x++;
			decision += 2*x+1;
		}
		else
		{
			y--;
			x++;
			decision += 2*(x-y)+1;
		}
		plot(x, y);
		plot(x, -y);
		plot(-x, y);
		plot(-x, -y);
		plot(y, x);
		plot(-y, x);
		plot(y, -x);
		plot(-y, -x);
	}

}

void myDisplay(void)
{
	glClear (GL_COLOR_BUFFER_BIT);//clear the frame buffer
	glColor3f (1.0, 1.0, 1.0);//set the color to white
	//glPointSize(1.0);
/*
    glPointSize(10.0);
	glBegin(GL_POINTS);
	glVertex2i(xc, yc);
	glEnd();*///center

	glPointSize(2.0);//set the point size
	midPointCircleAlgo();

	glFlush ();//print the content of the buffer
}

int main(int argc, char** argv)
{
	cout << "Enter the coordinates of the center and radius:" << endl;

	cin>>xc>>yc>>r;


	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);//set the display mode
	glutInitWindowSize (640, 480);//specify the width and height of window
	glutInitWindowPosition (100, 150);//set the window position
	glutCreateWindow ("Midpoint cicle drawing");//create the actual window
	glutDisplayFunc(myDisplay);//call the display callback function
	myInit ();////initialize the projection matrix
	glutMainLoop();//to keep the program in the execution loop
return 0;
}

