// ConsoleApplication6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <GL/glut.h>
#include <iostream>
#include <string>
#include <bits/stdc++.h> 

void init();
void display_callback();
void render_board();
void draw_numbers();
void draw_grid();
void draw_text(const char *text, int length, double x, double y);


void render_board()
{
	draw_grid();

	draw_numbers();
}

void draw_grid()
{
	glColor3f(1.0, 1.0, 1.0);
	glLineWidth(3.0);

	//This loop renders the horizontal lines of the board.
	for (float y = 0.667; y >= -1; y = y - 0.163)
	{
		glBegin(GL_LINES);
		glVertex2f(-296, y); glVertex2f(296, y);
		glEnd();
	}

	// This loop renderes the vertical lines of the board
	for (float x = -0.995; x <= 1; x = x + 0.199)
	{
		glBegin(GL_LINES);
		glVertex2f(x, 0.667); glVertex2f(x, -.96);
		glEnd();
	}
}

void draw_numbers()
{

	double x = -.92;
	double y = -.9;
	int num = 1, length, flag = 1;
	for (int i = 0; i < 10; i++)
	{
		x = -0.92;
		for (int j = 0; j < 10; j++)
		{
			std::string text = std::to_string(num);
			draw_text(text.c_str(), text.length(), x, y);
			x = x + 0.2;
			if (flag)
				num = num + 1;
			else
				num = num - 1;
		}
		if (flag)
		{
			num = num + 9;
			flag = 0;
		}
		else
		{
			num = num + 11;
			flag = 1;
		}
		length = 2;
		y = y + 0.16;

	}
}

void draw_text(const char *text, int length, double x, double y)
{
	glColor3f(1, 1, 1);
	double x_pos = length / 56.0;
	glMatrixMode(GL_PROJECTION);
	double *matrix = new double[16];
	glGetDoublev(GL_PROJECTION_MATRIX, matrix);
	glLoadIdentity();
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glPushMatrix();
	glLoadIdentity();
	glRasterPos2f(x, y);
	for (int i = 0; i < length; i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, (int)text[i]);
	}
	glPopMatrix();
	glMatrixMode(GL_PROJECTION);
	glLoadMatrixd(matrix);
	glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char**argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowPosition(10, 10);
	glutInitWindowSize(550, 600);
	glutCreateWindow("Snake and Ladder-OpenGL");
	glutDisplayFunc(display_callback);
	init();
	glutMainLoop();
	return 0;
}

void init()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
}

void display_callback()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	render_board();
	glutSwapBuffers();
}
