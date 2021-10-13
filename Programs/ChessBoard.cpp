#include <iostream>
#include<GL/glew.h>
#include <GL/freeglut.h>
#include <math.h>

using namespace std;

float  xend, yend;
int l = 40;

void setPixel(int x, int y)
{
	glPointSize(2);
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
	glFlush();
}

void DDA()
{
	int p, x, y;
	x = 0;
	xend = 320;
	y = 0;
	yend = 320;
	float m = 0;

	for (int i = 0; i < 40 * 8; i++)
	{
		while (x < xend)
		{
			x = x + 1;
			if (y < 40 || (y > 80 && y < 120) || (y > 160 && y < 200) || (y > 240 && y < 280))
			{
				if (x < 40 || (x > 80 && x < 120) || (x > 160 && x < 200) || (x > 240 && x < 280))
					glColor3f(0, 0, 0);
				else
					glColor3f(1, 1, 1);
				setPixel(x, y);
			}
			else
			{
				if (x < 40 || (x > 80 && x < 120) || (x > 160 && x < 200) || (x > 240 && x < 280))
					glColor3f(1, 1, 1);
				else
					glColor3f(0, 0, 0);
				setPixel(x, y);
			}
		}

		y += 1;
		x = 0;
	}
}

void display()
{
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glViewport(100, 100, 1000, 1000);
	DDA();
	glColor3f(1, 0, 0);
	glLineWidth(5); 

	glBegin(GL_LINE_LOOP);
	glVertex2f(0, 0);
	glVertex2f(0, 320);
	glVertex2f(320, 320);
	glVertex2f(320, 0);
	glEnd();
	glFlush();
}

void myinit()
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glColor3f(1.0, 0.0, 0.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluOrtho2D(0.0, 1000.0, 0.0, 1000.0);
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(5000, 5000);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Chessboard using DDA");
	myinit();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
