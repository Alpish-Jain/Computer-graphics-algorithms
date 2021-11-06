#include<iostream>
#include<graphics.h>
#include<dos.h>
using namespace std;
void boundaryfill(int x,int y,int fill_color,int boundary_color)
{
	if(getpixel(x,y)!=boundary_color && getpixel(x,y)!=fill_color)
	{
		putpixel(x,y,fill_color);
		boundaryfill(x+1,y,fill_color,boundary_color);
		boundaryfill(x,y+1,fill_color,boundary_color);
		boundaryfill(x-1,y,fill_color,boundary_color);
		boundaryfill(x,y-1,fill_color,boundary_color);
	}
}
//getpixel(x,y) gives the color of specified pixel

int main()
{
	int gm,gd=DETECT,radius;
	int x,y;
	cout<<"Enter x and y positions for circle\n";
	cin>>x>>y;
	cout<<"Enter radius of circle\n";
	cin>>radius;

	initgraph(&gd,&gm,"c:\\turboc3\\bgi");
	circle(x,y,radius);
	boundaryfill(x,y,4,15);
	delay(5000);
	closegraph();

	return 0;
}
