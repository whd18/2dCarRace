#include <GL/glut.h>

#include<stdlib.h>

int score, exit1 = 0, col;
float xa, ya, bx, by;
float x1 = 0, y1 = 300;
float x2 = -90, y2 = 800;
float x3 = 90, y3 = 800;
float x4 = 0, y4 = 1300;
float x5 = 90, y5 = 1300;

float n = 0;
typedef struct lines
{
	float x, y;
}linet;
linet line[5];

typedef struct boats
{
	float x, y;
}boatX;
boatX boatxy[5];

void car(float a, float b)
{

	glPushMatrix();
	glBegin(GL_POLYGON);
	glColor3f(0.2, 0.8, 1);
	glVertex2f(270 + a, 0 + b);
	glVertex2f(350 + a, 0 + b);
	glVertex2f(350 + a, 75 + b);
	glVertex2f(270 + a, 75 + b);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(.05, .2, 0.8);
	glVertex2f(280 + a, 10 + b);
	glVertex2f(340 + a, 10 + b);
	glVertex2f(340 + a, 50 + b);
	glVertex2f(280 + a, 50 + b);
	glEnd();
	//upper and lower cover
	glBegin(GL_POLYGON);
	glColor3f(.05, .02, 0.8);
	glVertex2f(280 + a, 50 + b);
	glVertex2f(270 + a, 75 + b);
	glVertex2f(350 + a, 75 + b);
	glVertex2f(340 + a, 50 + b);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(.05, .02, 0.8);
	glVertex2f(280 + a, 10 + b);
	glVertex2f(270 + a, 0 + b);
	glVertex2f(350 + a, 0 + b);
	glVertex2f(340 + a, 10 + b);
	glEnd();

	glPopMatrix();


	glEnd();
	glFlush();

}

void lake()
{
	glBegin(GL_POLYGON);
	glColor3f(.5, .5, 1);
	glVertex2i(0, 0);
	glVertex2i(175, 0);
	glVertex2i(175, 500);
	glVertex2i(0, 500);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(.4, .08, .8);
	glVertex2i(20, 0);
	glVertex2i(155, 0);
	glVertex2i(155, 500);
	glVertex2i(20, 500);
	glEnd();
}

void park()
{
	//background
	glBegin(GL_POLYGON);
	glColor3f(0.7, 1, 0.6);
	glVertex2i(445, 0);
	glVertex2i(750, 0);
	glVertex2i(750, 500);
	glVertex2i(445, 500);
	glEnd();



	//Tree
	glBegin(GL_POLYGON);
	glColor3f(.04, .7, .06);
	glVertex2i(550, 450);
	glVertex2i(630, 415);
	glVertex2i(630, 345);
	glVertex2i(550, 305);
	glVertex2i(470, 345);
	glVertex2i(470, 415);
	glEnd();

	//brunch
	glBegin(GL_POLYGON);
	glColor3f(.5, .05, 0.05);
	glVertex2i(532, 230);
	glVertex2i(522, 246);
	glVertex2i(536, 315);
	glVertex2i(550, 305);
	glVertex2i(563, 312);
	glVertex2i(576, 247);
	glVertex2i(565, 230);

	glEnd();
}


void enemy(float a, float b)
{
	//glPushMatrix();
	glBegin(GL_POLYGON);
	glColor3f(1, .5, 0);
	glVertex2f(270 + a, 350 + b);
	glVertex2f(350 + a, 350 + b);
	glVertex2f(350 + a, 420 + b);
	glVertex2f(270 + a, 420 + b);

	//glPopMatrix();
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(.7, .3, .06);
	glVertex2f(280 + a, 360 + b);
	glVertex2f(340 + a, 360 + b);
	glVertex2f(340 + a, 410 + b);
	glVertex2f(280 + a, 410 + b);

	////glPopMatrix();
	glEnd();

	glFlush();
	//glutPostRedisplay();

	//glPopMatrix();
}

void road()
{
	glBegin(GL_POLYGON);
	glColor3f(0.08, 0.08, 0.09);
	glVertex2i(180, 0);
	glVertex2i(450, 0);
	glVertex2i(450, 510);
	glVertex2i(180, 510);
	glEnd();
	glFlush();
}

void sc(int a)
{
	int i, j, k;
	i = a / 100;
	j = a / 10 - i * 10;
	k = a - j * 10 - i * 100;

	glPushMatrix();
	glColor3f(0, 0, 1);
	//glTranslated(500, 300, 0);
	glScaled(.3, .2, 0);
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'S');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'c');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'o');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'r');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'e');
	glColor3f(0, 0, 1);
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)' ');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)':');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)' ');
	glColor3f(0, 0, 1);
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)i + 48);
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)j + 48);
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)k + 48);
	glPopMatrix();
}
void EndGame() {

	glutIdleFunc(NULL);

	glPushMatrix();
	glColor3f(0, 0, 1);
	glTranslated(180, 300, 0);
	glScaled(.2, .2, 0);
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'->');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)' ');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'P');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'r');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'e');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'s');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'s');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)' ');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'r');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)' ');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'t');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'o');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)' ');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'r');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'e');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'s');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'t');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'a');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'r');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'t');

	glPopMatrix();

	glPushMatrix();
	glColor3f(1, 0, 0);
	glTranslated(190, 250, 0);
	glScaled(.2, .2, 0);
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'->');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)' ');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'P');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'r');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'e');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'s');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'s');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)' ');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'e');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)' ');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'t');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'o');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)' ');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'e');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'x');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'i');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'t');


	glPopMatrix();
	glFlush();
}
void Start()
{
	glPushMatrix();
	glColor3f(0, 0, 0);
	glTranslated(425, 170, 0);
	glScaled(.19, .19, 0);
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'->');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)' ');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'P');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'r');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'e');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'s');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'s');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)' ');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'s');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)' ');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'t');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'o');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)' ');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'S');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'t');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'a');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'r');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'t');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)' ');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'G');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'a');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'m');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'e');
	glPopMatrix();

	glPushMatrix();
	glColor3f(0, 0, 0);
	glTranslated(450, 120, 0);
	glScaled(.2, .2, 0);
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'->');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'U');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'P');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)' ');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'A');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'r');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'r');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'o');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'w');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)' ');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'S');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'p');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'e');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'e');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'d');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)' ');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'U');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'P');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)' ');
	glPopMatrix();


	glPushMatrix();
	glColor3f(0, 0, 0);
	glTranslated(450, 90, 0);
	glScaled(.17, .2, 0);
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'->');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'D');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'o');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'w');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'n');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)' ');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'A');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'r');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'r');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'o');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'w');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)' ');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'S');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'p');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'e');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'e');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'d');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)' ');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'D');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'o');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'w');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'n');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)' ');
	glPopMatrix();


	glPushMatrix();
	glColor3f(0, 0, 0);
	glTranslated(450, 30, 0);
	glScaled(.2, .2, 0);
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'->');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)' ');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'P');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'r');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'e');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'s');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'s');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)' ');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'q');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)' ');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'t');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'o');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)' ');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'Q');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'u');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'i');
	glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'t');
	glPopMatrix();


	//glPushMatrix();
	//glColor3f(0, 0, 0);
	//glTranslated(500, 50, 0);
	//glScaled(.1, .2, 0);
	//glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'->');
	//glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)' ');
	//glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'P');
	//glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'r');
	//glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'e');
	//glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'s');
	//glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'s');
	//glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)' ');
	//glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'P');
	//glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)' ');
	//glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'t');
	//glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'o');
	//glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)' ');
	//glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'p');
	//glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'a');
	//glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'u');
	//glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'s');
	//glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'e');
	//glPopMatrix();

}

void myDisplay()
{

	if (exit1 == 0)
	{

		if (score >= 0)
		{
			y1 -= .2;
			y2 -= .2;
			y3 -= .2;
			y4 -= .2;
			y5 -= .2;
			bx += .5;
			by += .5;

		}
		/*if (score >= 20 && score < 70)
		{
		y1 -= .3;
		y2 -= .3;
		y3 -= .3;
		y4 -= .3;
		y5 -= .3;

		}
		if (score >= 70 && score < 170)
		{
		y1 -= .4;
		y2 -= .4;
		y3 -= .4;
		y4 -= .4;
		y5 -= .4;

		}
		if (score >= 170)
		{
		y1 -= .5;
		y2 -= .5;
		y3 -= .5;
		y4 -= .5;
		y5 -= .5;

		}*/
		if (y1 < -418)
		{

			score += 2;
			y1 = 1000;

		}
		if (y2 < -418)
		{
			score += 2;
			y2 = 2000;

		}
		if (y3 < -418)
		{

			score += 2;
			y3 = 1000;

		}
		if (y4 < -418)
		{
			score += 2;
			y4 = 2000;

		}
		if (y5 < -418)
		{
			score += 2;
			y5 = 2000;

		}


		road();
		//road divider
		glPushMatrix();
		glColor3f(1.0, 1.0, 1.0);
		for (int i = 0; i < 5; i++)
		{
			line[i].y += -0.5;
			if (line[i].y < -400)
			{
				line[i].y += 800;
			}
		}

		for (int i = 0; i < 5; i++)
		{
			//left
			glBegin(GL_POLYGON);
			glVertex2f(line[i].x + 260, line[i].y + 10);
			glVertex2f(line[i].x + 260, line[i].y + 150);
			glVertex2f(line[i].x + 270, line[i].y + 150);
			glVertex2f(line[i].x + 270, line[i].y + 10);
			glEnd();
			glBegin(GL_POLYGON);
			glVertex2f(line[i].x + 260, line[i].y + 350);
			glVertex2f(line[i].x + 260, line[i].y + 490);
			glVertex2f(line[i].x + 270, line[i].y + 490);
			glVertex2f(line[i].x + 270, line[i].y + 350);
			glEnd();

			//right
			glBegin(GL_POLYGON);
			glVertex2f(line[i].x + 350, line[i].y + 10);
			glVertex2f(line[i].x + 350, line[i].y + 150);
			glVertex2f(line[i].x + 360, line[i].y + 150);
			glVertex2f(line[i].x + 360, line[i].y + 10);
			glEnd();
			glBegin(GL_POLYGON);
			glVertex2f(line[i].x + 350, line[i].y + 350);
			glVertex2f(line[i].x + 350, line[i].y + 490);
			glVertex2f(line[i].x + 360, line[i].y + 490);
			glVertex2f(line[i].x + 360, line[i].y + 350);
			glEnd();


		}

		//boat riding
		lake();
		glPushMatrix();
		glColor3f(1.0, 1.0, 1.0);
		for (int i = 0; i < 5; i++)
		{
			boatxy[i].y += 0.05;
			if (boatxy[i].y > 600)
			{
				boatxy[i].y -= 600;
			}
		}

		for (int i = 0; i < 8; i++)
		{
			glBegin(GL_POLYGON);
			glColor3f(.5, 1, .5);
			glVertex2f(boatxy[i].x + 85, boatxy[i].y + 0);
			glVertex2f(boatxy[i].x + 50, boatxy[i].y - 30);
			glVertex2f(boatxy[i].x + 50, boatxy[i].y - 80);
			glVertex2f(boatxy[i].x + 35, boatxy[i].y - 90);
			glVertex2f(boatxy[i].x + 135, boatxy[i].y - 90);
			glVertex2f(boatxy[i].x + 120, boatxy[i].y - 80);
			glVertex2f(boatxy[i].x + 120, boatxy[i].y - 30);
			glEnd();
			if (score > 24 || score > 200)
			{
				glBegin(GL_POLYGON);
				glColor3f(.04, .7, .06);
				glVertex2f(boatxy[i].x + 85, boatxy[i].y + 0);
				glVertex2f(boatxy[i].x + 50, boatxy[i].y - 30);
				glVertex2f(boatxy[i].x + 50, boatxy[i].y - 80);
				glVertex2f(boatxy[i].x + 35, boatxy[i].y - 90);
				glVertex2f(boatxy[i].x + 135, boatxy[i].y - 90);
				glVertex2f(boatxy[i].x + 120, boatxy[i].y - 80);
				glVertex2f(boatxy[i].x + 120, boatxy[i].y - 30);
				glEnd();
			}

			if (score > 48 || score > 250)
			{
				glBegin(GL_POLYGON);
				glColor3f(.5, .08, .06);
				glVertex2f(boatxy[i].x + 85, boatxy[i].y + 0);
				glVertex2f(boatxy[i].x + 50, boatxy[i].y - 30);
				glVertex2f(boatxy[i].x + 50, boatxy[i].y - 80);
				glVertex2f(boatxy[i].x + 35, boatxy[i].y - 90);
				glVertex2f(boatxy[i].x + 135, boatxy[i].y - 90);
				glVertex2f(boatxy[i].x + 120, boatxy[i].y - 80);
				glVertex2f(boatxy[i].x + 120, boatxy[i].y - 30);
				glEnd();
			}

			if (score > 96 || score > 300)
			{
				glBegin(GL_POLYGON);
				glColor3f(.06, .5, .07);
				glVertex2f(boatxy[i].x + 85, boatxy[i].y + 0);
				glVertex2f(boatxy[i].x + 50, boatxy[i].y - 30);
				glVertex2f(boatxy[i].x + 50, boatxy[i].y - 80);
				glVertex2f(boatxy[i].x + 35, boatxy[i].y - 90);
				glVertex2f(boatxy[i].x + 135, boatxy[i].y - 90);
				glVertex2f(boatxy[i].x + 120, boatxy[i].y - 80);
				glVertex2f(boatxy[i].x + 120, boatxy[i].y - 30);
				glEnd();
			}

			if (score > 150 || score > 350)
			{
				glBegin(GL_POLYGON);
				glColor3f(.5, .8, .3);
				glVertex2f(boatxy[i].x + 85, boatxy[i].y + 0);
				glVertex2f(boatxy[i].x + 50, boatxy[i].y - 30);
				glVertex2f(boatxy[i].x + 50, boatxy[i].y - 80);
				glVertex2f(boatxy[i].x + 35, boatxy[i].y - 90);
				glVertex2f(boatxy[i].x + 135, boatxy[i].y - 90);
				glVertex2f(boatxy[i].x + 120, boatxy[i].y - 80);
				glVertex2f(boatxy[i].x + 120, boatxy[i].y - 30);
				glEnd();
			}


		}
		glPopMatrix();

		glFlush();
		park();

		glPushMatrix();
		glTranslated(470, 210, 0);
		sc(score);
		glPopMatrix();

		Start();
		car(xa, ya);
		enemy(x1, y1);
		enemy(x2, y2);
		enemy(x3, y3);
		enemy(x4, y4);
		enemy(x5, y5);


		if (x1 == 0 && xa == 0 && y1<-275 ||
			x2 == -90 && xa == -90 && y2<-275 ||
			x3 == 90 && xa == 90 && y3<-275 ||
			x4 == 0 && xa == 0 && y4<-275 ||
			x5 == 90 && xa == 90 && y5<-275
			)
		{

			EndGame();
			col = 1;
		}

		glutSwapBuffers();

	}
	else
	{
		glLineWidth(5);
		glClear(GL_COLOR_BUFFER_BIT);

		glPushMatrix();
		glTranslated(220, 300, 0);
		sc(score);
		glPopMatrix();
		if (score >= 0 && score < 50) {
			glPushMatrix();
			glColor3f(1.0, 0.0, 1.0);
			glTranslated(70, 350, 0);
			glScaled(.3, .2, 0);
			glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)' ');
			glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)' ');
			glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'G');
			glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'A');
			glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'M');
			glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'E');
			glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)' ');
			glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'O');
			glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'V');
			glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'E');
			glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'R');

			glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'(');
			glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'-');
			glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'_');
			glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)'-');
			glutStrokeCharacter(GLUT_STROKE_ROMAN, (int)')');
			glPopMatrix();
		}

		if (score >= 50)
		{
			glPushMatrix();
			glColor3f(1.0, 0.0, 1.0);
			glTranslated(70, 350, 0);
			glScaled(.3, .2, 0);
			glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, (int)' ');
			glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, (int)' ');
			glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, (int)'G');
			glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, (int)'A');
			glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, (int)'M');
			glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, (int)'E');
			glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, (int)' ');
			glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, (int)' ');
			glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, (int)'O');
			glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, (int)'V');
			glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, (int)'E');
			glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, (int)'R');

			glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, (int)'(');
			glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, (int)'^');
			glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, (int)'_');
			glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, (int)'^');
			glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, (int)')');
			glPopMatrix();
		}

		glFlush();
		glutSwapBuffers();
	}
}


void carHighspeed()
{

	y1 -= .3;
	y2 -= .3;
	y3 -= .3;
	y4 -= .3;
	y5 -= .3;

	glutPostRedisplay();
}

void carLowspeed()
{

	y1 -= .005;
	y2 -= .005;
	y3 -= .005;
	y4 -= .005;
	y5 -= .005;
	glutPostRedisplay();
}

void myInit(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor4f(0.0f, 0.0f, 0.0f, 0.0f);
	glPointSize(3.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 750.0, 0.0, 500.0);
}



void specialKeyInput(int key, int x, int y)
{

	if (key == GLUT_KEY_UP)
	{
		if (col == 1) {

		}
		else
		{
			glutIdleFunc(carHighspeed);
		}

	}
	if (key == GLUT_KEY_DOWN)
	{

		if (col == 1) {

		}
		else
		{
			glutIdleFunc(carLowspeed);
		}
	}
	if (key == GLUT_KEY_LEFT)
	{
		if (xa >= 0 && col == 0)
		{
			xa -= 90;
		}

	}
	if (key == GLUT_KEY_RIGHT)
	{
		if (xa < 90 && col == 0)
		{
			xa += 90;
		}
	}

	glutPostRedisplay();
}



void keyboards(unsigned char keys, int x4, int y4)
{
	if (keys == 'q' || keys == 'Q')
	{
		exit(0);
	}

	if (keys == 's' || keys == 'S')
	{
		if (score == 0) {

			glutIdleFunc(myDisplay);
		}
	}
	if (keys == 'p' || keys == 'P')
	{
		glutIdleFunc(NULL);
	}
	if (keys == 'r' || keys == 'R')
	{
		xa = -90;
		y1 = 300;
		y2 = 800;
		y3 = 800;
		y4 = 1300;
		y5 = 1300;
		glPushMatrix();
		col = 0;
		score = 0;
		glutIdleFunc(myDisplay);

	}
	if (keys == 'e' || keys == 'E')
	{
		exit1 = 1;
		//exit(0);
	}
	glutPostRedisplay();
}

void main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(700, 600);
	glutInitWindowPosition(300, 50);
	glutCreateWindow("CAR RACE ");
	glClearColor(1, 1, 1, 1);//set Background
	glutDisplayFunc(myDisplay);
	glutKeyboardFunc(keyboards);
	glutSpecialFunc(specialKeyInput);
	myInit();
	glutMainLoop();
}
