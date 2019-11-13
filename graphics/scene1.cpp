// tweening-arrow.cpp : Defines the entry point for the console application.
//
#include <stdlib.h>
#include <stdio.h>
#include "glut.h"
#include <math.h>

int frame = 0;

int sqone[5][2];
int sqtwo[5][2];
int sqthree[5][2];
int sqfour[5][2];
int sqfive[5][2];
int sqfall[5][2];
int triangle[5][2];

float tx = 0.0;
float ty = 0.0;
float sx = 1.0;
float sy = 1.0;
float rx = 0.0;
float ry = 0.0;
float theta = 0.0;
float theta2 = 0.0;

int tweenPoly[10][2];
float proportion = 0.0;

int mode;

void init(void)
{

	glClearColor(0.0, 0.0, 0.0, 0.0);

	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 500, 0, 500);

	sqone[0][0] = 50;
	sqone[0][1] = 50;

	sqone[1][0] = 50;
	sqone[1][1] = 125;

	sqone[2][0] = 125;
	sqone[2][1] = 125;

	sqone[3][0] = 125;
	sqone[3][1] = 50;

	sqone[4][0] = 50;
	sqone[4][1] = 50;


	sqtwo[0][0] = 175;
	sqtwo[0][1] = 175;

	sqtwo[1][0] = 175;
	sqtwo[1][1] = 250;

	sqtwo[2][0] = 250;
	sqtwo[2][1] = 250;

	sqtwo[3][0] = 250;
	sqtwo[3][1] = 175;

	sqtwo[4][0] = 175;
	sqtwo[4][1] = 175;


	sqthree[0][0] = 300;
	sqthree[0][1] = 50;

	sqthree[1][0] = 300;
	sqthree[1][1] = 125;

	sqthree[2][0] = 375;
	sqthree[2][1] = 125;

	sqthree[3][0] = 375;
	sqthree[3][1] = 50;

	sqthree[4][0] = 300;
	sqthree[4][1] = 50;


	sqfour[0][0] = 450;
	sqfour[0][1] = 175;

	sqfour[1][0] = 450;
	sqfour[1][1] = 250;

	sqfour[2][0] = 525;
	sqfour[2][1] = 250;

	sqfour[3][0] = 525;
	sqfour[3][1] = 175;

	sqfour[4][0] = 450;
	sqfour[4][1] = 175;


	sqfive[0][0] = 0;
	sqfive[0][1] = 175;

	sqfive[1][0] = 0;
	sqfive[1][1] = 250;

	sqfive[2][0] = 25;
	sqfive[2][1] = 250;

	sqfive[3][0] = 25;
	sqfive[3][1] = 175;

	sqfive[4][0] = 0;
	sqfive[4][1] = 175;

    
	sqfall[0][0] = 250;
	sqfall[0][1] = 425;

	sqfall[1][0] = 250;
	sqfall[1][1] = 500;

	sqfall[2][0] = 325;
	sqfall[2][1] = 500;

	sqfall[3][0] = 325;
	sqfall[3][1] = 425;

	sqfall[4][0] = 250;
	sqfall[4][1] = 425;
	

	triangle[0][0] = 300;
	triangle[0][1] = 50;

	triangle[1][0] = 380;
	triangle[1][1] = 50;

	triangle[2][0] = 340;
	triangle[2][1] = 150;

	triangle[3][0] = 300;
	triangle[3][1] = 50;

	triangle[4][0] = 380;
	triangle[4][1] = 50;

}
void circle(double radius, double xc, double yc)
{
	int i;
	double angle = 2 * 3.1415 / 20;	// circle is drawn using 20 line.
	double circle_xy[40][2];

	circle_xy[0][0] = radius + xc;
	circle_xy[0][1] = yc;


	glBegin(GL_LINE_LOOP);
	for (i = 1; i<20; i++)
	{
		circle_xy[i][0] = radius * cos(i *angle) + xc;
		circle_xy[i][1] = radius * sin(i * angle) + yc;

		glVertex2f(circle_xy[i - 1][0], circle_xy[i - 1][1]);
		glVertex2f(circle_xy[i][0], circle_xy[i][1]);

	}
	glEnd();
}

void tween(int source[10][2], int destination[10][2], int numPoints, double proportion, int tweenPoly[10][2])
{

	for (int p = 0; p < numPoints; p++)
	{
		// get the source point
		double sourceX = source[p][0];
		double sourceY = source[p][1];

		// get the destination point
		double destinationX = destination[p][0];
		double destinationY = destination[p][1];

		// get the difference between source and destination
		double differenceX = (destinationX - sourceX);
		double differenceY = (destinationY - sourceY);

		// tween point is source position + proportion
		// of distance between source and destination
		double tweenX = sourceX + (differenceX * proportion);
		double tweenY = sourceY + (differenceY * proportion);

		// create point with tween co-ordinates in tween array
		tweenPoly[p][0] = int(tweenX);
		tweenPoly[p][1] = int(tweenY);
	}


}

void renderSpacedBitmapString(float x, float y, void *font, char *string) {
	char *c;
	int x1 = x;
	for (c = string; *c != '\0'; c++) {
		glRasterPos2f(x1, y);
		glutBitmapCharacter(font, *c);
		x1 = x1 + glutBitmapWidth(font, *c);
	}
}
void first() {
	circle(10, 150, 150);
}
void second() {
	circle(20, 200, 190);
}
void third() {
	circle(50, 275, 250);
}
void shape() {
	glBegin(GL_LINES);
	glVertex2i(250, 230);
    glVertex2i(275, 290);
	glVertex2i(250, 230);
	glVertex2i(300, 230);
	glVertex2i(300, 230);
	glVertex2i(275, 290);
	glEnd();
}
void nightsky() {
	glClearColor(0.0,0.0, 0.51,0.2);
}
void background1() {

	int P1[] = {0, 0 };
	int P2[] = { 0, 200 };
	int P3[] = { 500, 200 };
	int P4[] = {500, 0 };
	int P5[] = { 0, 0 };

	int P6[] = {0,205 };
	int P7[] = {0, 500 };
	int P8[] = {500, 500 };
	int P9[] = { 500, 205};
	int P10[] = {0, 205 };

	glBegin(GL_LINE_STRIP);
	glColor3f(0.0, 1.0, 0.0);
	glVertex2iv(P1);
	glVertex2iv(P2);
	glVertex2iv(P3);
	glVertex2iv(P4);
	glVertex2iv(P5);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glColor3f(0.0, 0.0, 1.0);
	glVertex2iv(P6);
	glVertex2iv(P7);
	glVertex2iv(P8);
	glVertex2iv(P9);
	glVertex2iv(P10);
	glEnd();
}
void square_1() {
	glColor3f(1.0, 1.0, 0.0);
	glBegin(GL_LINE_LOOP);
	int i;
	for (i = 0; i<5; i++)
		glVertex2i(sqone[i][0], sqone[i][1]);	
	glEnd();
}
void square_two() {
	glColor3f(1.0, 1.0, 0.0);
	glBegin(GL_LINE_LOOP);
	int i;
	for (i = 0; i<5; i++)
		glVertex2i(sqtwo[i][0], sqtwo[i][1]);	
	glEnd();
}

void square_three() {
	glColor3f(1.0, 1.0, 0.0);
	glBegin(GL_LINE_LOOP);
	int i;
	for (i = 0; i<5; i++)
		glVertex2i(sqthree[i][0], sqthree[i][1]);

	glEnd();

}
void square_four() {
	glColor3f(1.0, 1.0, 0.0);
	glBegin(GL_LINE_LOOP);
	int i;
	for (i = 0; i<5; i++)
		glVertex2i(sqfour[i][0], sqfour[i][1]);	
	glEnd(); 
}
void square_five() {
	glColor3f(1.0, 1.0, 0.0);
	glBegin(GL_LINE_LOOP);
	int i;
	for (i = 0; i<5; i++)
		glVertex2i(sqfive[i][0], sqfive[i][1]);
	glEnd();
}
void square_fall() {
	glColor3f(1.0, 1.0, 0.0);
	glBegin(GL_LINE_LOOP);
	int i;
	for (i = 0; i<5; i++)
		glVertex2i(sqfall[i][0], sqfall[i][1]);	
	glEnd();
}
void draw_tri() {
	glColor3f(1.0, 1.0, 0.0);
	glBegin(GL_LINE_LOOP);
	int i;
	for (i = 0; i<5; i++)
		glVertex2i(triangle[i][0], triangle[i][1]);	
	glEnd();
}
void morph() {
	glColor3f(1.0, 1.0, 0.0);
	tween(sqone, triangle, 5, proportion, tweenPoly);

	glBegin(GL_LINE_LOOP);
	int i;
	for (i = 0; i<5; i++)
		glVertex2i(tweenPoly[i][0], tweenPoly[i][1]);	
	glEnd();
	proportion += 0.02;

	if (proportion >1.0) proportion = 0.0;
}
void translate_square() {
	glPushMatrix();
	glTranslatef(tx, ty, 0.0);
	square_1();
	glPopMatrix();

	tx = tx + 6;
	ty = ty + 0;
}

void rotate_square() {
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glTranslatef(215.5, 380.5, 0.0);
	glRotatef(theta, rx, ry, 1.0);
	glTranslatef(-215.5, -380.5, 0.0);
	square_fall();
	glPopMatrix();
	theta = theta - 5;
	rx = rx + 0;
	ry = ry + 0;
}
void rotate_down_square() {
	glPushMatrix();
	glRotatef(theta2, rx, ry, 1.0);
	rotate_square();
	glPopMatrix();
	theta2 = theta2 - 1;
}
void scale_square() {

	glPushMatrix();
	glScalef(sx, sy, 0.1);
	square_1();
	glPopMatrix();

	sx = sx * 0.99;
	sy = sy * 0.99;
}
void believe(){
 renderSpacedBitmapString(100, 250, GLUT_BITMAP_HELVETICA_18, "Believe");
}
void viewport(){
	glViewport(0,0,500,400);
    believe();
    glViewport(200,0,500,400);
	believe();
	renderSpacedBitmapString(10, 400, GLUT_BITMAP_HELVETICA_18, "Scene 6");
}
void display(void)
{
	/* clear all pixels  */
	int i;
	glClear(GL_COLOR_BUFFER_BIT);

	frame++;		// Using frame to control the scenes.

	glLineWidth(5.0);

	if ((frame >=0) && (frame<15))
	{
		square_1();
		renderSpacedBitmapString(50, 400, GLUT_BITMAP_HELVETICA_18, "Scene 1");
	}
	else if ((frame >= 15) && (frame<25))
	{
		square_1();
		first();
	}
	else if ((frame >= 25) && (frame<35))
	{
		square_1();
		first();
		second();
	}
	else if ((frame >= 35) && (frame<50))
	{
		square_1();
		first();
		second();
		third();
		shape();

	}
	
	///////////////////////////////////////////////Scene 2/////////////////////////////////////////////////
	else if ((frame >= 50) && (frame<60))
	{
		renderSpacedBitmapString(50, 400, GLUT_BITMAP_HELVETICA_18, "Scene 2");
		square_1();
	}
	
	else if ((frame >= 60) && (frame<70))
	{
		square_two();

	}
	else if ((frame >= 70) && (frame<80))
	{
		square_three();
	}
	else if ((frame >= 80) && (frame<90))
	{
		square_four();
	}
	else if ((frame >= 90) && (frame<100))
	{
		square_five();
	}
	else if ((frame >= 100) && (frame<110))
	{
		square_1();

	}
	else if ((frame >= 110) && (frame<120))
	{
		square_two();
	}
	else if ((frame >= 120) && (frame<130))
	{
		square_three();
	}
	else if ((frame >= 130) && (frame<140))
	{
		square_four();
	}
	else if ((frame >= 140) && (frame<150))
	{
		square_five();
	}
	else if ((frame >= 150) && (frame<160))
	{
		square_1();
	}

	////////////////////////////////////////Scene 3//////////////////////////////////////////////////////////////
	
	else if ((frame >=160) && (frame<260))
	{
		renderSpacedBitmapString(50, 400, GLUT_BITMAP_HELVETICA_18, "Scene 3");
		translate_square();
	}
	//////////////////////////Scene 4//////////////////////////////////////
	else if ((frame >= 260) && (frame < 360))
	{
	renderSpacedBitmapString(50, 400, GLUT_BITMAP_HELVETICA_18, "Scene 4");
	rotate_down_square();
	}
	
	//////////////////////////////Scene 5//////////////////////////////////////
	else if ((frame >= 360) && (frame < 410))
	{
	renderSpacedBitmapString(50, 400, GLUT_BITMAP_HELVETICA_18, "Scene 5");
	scale_square();
	}
	else if ((frame >= 410) && (frame <460))
	{
	morph();
	}
	else if ((frame >= 460) && (frame <490))
	{
	viewport();
	}
	else if (frame > 500)
	{
		frame = 0;
		proportion = 0.0;
	}
	fprintf(stdout, "Frame number= %i\n", frame);
	glFlush();

}

void Timer(int value)
{
	if (value) glutPostRedisplay();
	glutTimerFunc(40, Timer, value);
}

void visibility(int state)
{
	switch (state)
	{
	case GLUT_VISIBLE:
		Timer(1);
		break;
	case GLUT_NOT_VISIBLE:
		Timer(0);
		break;
	default:
		break;
	}
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Goal");
	init();
	glutDisplayFunc(display);
	glutVisibilityFunc(visibility);
	glutMainLoop();
	return 0;   
}



