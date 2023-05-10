
#include <Windows.h>
#include <GL\glew.h>
#include <GL\freeglut.h>
#include <iostream>
#include<math.h>
#define DEG2RAD 3.14159/180.0
using namespace std;
int h = 0, k = -35, q = 0;
float a = 20, b = 150;
int flag = 0;                 //day- 1, night- 0
int angle = 1;



void myinit()    //initialization
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-500, 500, -500, 500);
	glMatrixMode(GL_MODELVIEW);
}
void key(unsigned char k, int x, int y)
{
	if (k == 'd') flag = 1;
	else if (k == 'n') flag = 0;
	glutPostRedisplay();
}

void bg()                  //background 
{

	int i, j, dy = 20;
	float angle, ang1, ang2;
	float r = 20, x, y, x1, y1, x2, y2, cx = -50, cy = -50;
	glBegin(GL_QUADS);
	glVertex2f(-400, -500);                            //big tree trunk
	glVertex2f(-200, -500);
	glVertex2f(-200, 0);
	glVertex2f(-400, -0);
	glVertex2f(-400, 0);                                //small left branch
	glVertex2f(-300, 0);
	glVertex2f(-350, 100);
	glVertex2f(-450, 100);
	glVertex2f(-200, 0);                                  //small right branch
	glVertex2f(-300, 0);
	glVertex2f(-250, 100);
	glVertex2f(-150, 100);
	glEnd();

	glColor3f(0, 0.5, 0);
	r = 250; cx = -300; cy = 300;
	glBegin(GL_TRIANGLE_FAN);                                      //tree green major part
	for (j = 0; j < 360; j++)
	{
		angle = 3.14 / 180 * j;
		x = cx + r * (cos(angle));
		y = cy + r * (sin(angle));
		glVertex2f(x, y);

	}
	r = 100; cx = -100; cy = 425;
	glBegin(GL_TRIANGLE_FAN);                             //tree green right smaller part
	for (j = 0; j < 360; j++)
	{
		angle = 3.14 / 180 * j;
		x = cx + r * (cos(angle));
		y = cy + r * (sin(angle));
		glVertex2f(x, y);

	}
	glEnd();
	r = 100; cx = -100; cy = 300;
	glBegin(GL_TRIANGLE_FAN);                           //tree green right below part 1
	for (j = 0; j < 360; j++)
	{
		angle = 3.14 / 180 * j;
		x = cx + r * (cos(angle));
		y = cy + r * (sin(angle));
		glVertex2f(x, y);

	}
	glEnd();
	r = 75; cx = -100; cy = 200;
	glBegin(GL_TRIANGLE_FAN);                            //tree green right dbelow part 2
	for (j = 0; j < 360; j++)
	{
		angle = 3.14 / 180 * j;
		x = cx + r * (cos(angle));
		y = cy + r * (sin(angle));
		glVertex2f(x, y);

	}
	glEnd();
	if(flag==0)
		glColor3f(1, 1, 1);
	else 
		glColor3f(1, 1, 0);
	r = 75; cx = 350; cy = 350;
	glBegin(GL_TRIANGLE_FAN);                //moon
	for (j = 0; j < 360; j++)
	{

		angle = 3.14 / 180 * j;
		x = cx + r * (cos(angle));
		y = cy + r * (sin(angle));
		glVertex2f(x, y);

	}
	glEnd();
	int r1 = 100, r2 = 150;


	glBegin(GL_TRIANGLES);
	glColor3f(0.6, 0.3, 0.2);
	glVertex2f(-400, -500);                           //left tree trunk
	glVertex2f(-500, -500);
	glVertex2f(-400, -400);
	glVertex2f(-100, -500);                          //right tree trunk
	glVertex2f(-200, -400);
	glVertex2f(-200, -500);
	glEnd();

	glBegin(GL_LINES);                               //grass
	glColor3f(0, 1, 0);
	int yii = -440, yi = -450;
	for (int w = -500; w <= 500; w++)
	{
		glVertex2f(w, yi);
		w = w + 10;
		glVertex2f(w, yii);
	}
	glEnd();
	glColor3f(0, 1, 0);                         //ground
	glBegin(GL_POLYGON);
	glVertex2f(-500, -500);
	glVertex2f(-500, -450);
	glVertex2f(500, -450);
	glVertex2f(500, -500);
	glEnd();
	glFlush();
}

void displayText(const char *string, int x, int y)                  //display text
{
	int j = strlen(string);

	if (flag == 0)
		glColor3f(0, 1, 1);
	else
		glColor3f(0, 0, 0);
	glRasterPos2f(x, y);
	for (int i = 0; i < j; i++) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, string[i]);
	}
}



void circles()
{
	glPushMatrix();
	glScalef(0.5, 0.5, 0);
	glTranslatef(0, 90, 0);
	glColor3f(0, 1, 1);
	glBegin(GL_TRIANGLE_FAN);                          //circle 1 on right wing
	for (int i = 0; i < 30; i++)
	{
		float angle = (3.14 / 15)*i;
		glVertex2f(20 * cos(angle) + 120, 20 * sin(angle) + 50);
	}
	glEnd();

	glColor3f(0, 1, 0);
	glBegin(GL_TRIANGLE_FAN);                              //circle 2 on right wing
	for (int i = 0; i < 30; i++)
	{
		float angle = (3.14 / 15)*i;
		glVertex2f(10 * cos(angle) + 80, 10 * sin(angle));
	}
	glEnd();

	glColor3f(0, 1, 1);
	glBegin(GL_TRIANGLE_FAN);                                     //circle 1 on left wing
	for (int i = 0; i < 30; i++)
	{
		float angle = (3.14 / 15)*i;
		glVertex2f(20 * cos(angle) - 120, 20 * sin(angle) + 50);
	}
	glEnd();

	glColor3f(0, 1, 0);
	glBegin(GL_TRIANGLE_FAN);                                       //circle 2 on left wing
	for (int i = 0; i < 30; i++)
	{
		float angle = (3.14 / 15)*i;
		glVertex2f(10 * cos(angle) - 80, 10 * sin(angle));
	}
	glEnd();
	glFlush();
	glPopMatrix();
}
void wingr()                //right wing
{
	//glPushMatrix();
	glScalef(0.5, 0.5, 0);
	glTranslatef(0, 90, 0);

	glLineWidth(1.0);
	glColor3f(0, 0, 1);
	glBegin(GL_POLYGON);
	glVertex2f(18, 20);
	glVertex2f(120, 120);
	glVertex2f(200, 30);
	glVertex2f(120, -80);
	glVertex2f(18, -20);
	glEnd();

	glColor3f(0, 0.5, 1);
	glBegin(GL_POLYGON);
	glVertex2f(120, -80);
	glVertex2f(50, -120);
	glVertex2f(18, -40);
	glVertex2f(18, -20);
	glEnd();
	glFlush();

}
void wingl()                  //left wing
{
	
	glScalef(0.5, 0.5, 0);
	glTranslatef(0, 90, 0);

	glLineWidth(1.0);
	glColor3f(0, 0, 1);
	glBegin(GL_POLYGON);
	glVertex2f(-18, 20);
	glVertex2f(-120, 120);
	glVertex2f(-200, 30);
	glVertex2f(-120, -80);
	glVertex2f(-18, -20);
	glEnd();

	glColor3f(0, 0.5, 1);
	glBegin(GL_POLYGON);
	glVertex2f(-120, -80);
	glVertex2f(-50, -120);
	glVertex2f(-18, -40);
	glVertex2f(-18, -20);
	glEnd();

	glFlush();

}

void ellipse()                                 //butterfly body
{
	glPushMatrix();
	glScalef(0.5, 0.5, 0);
	glTranslatef(0, 90, 0);
	glPointSize(1);
	double I, J;
	int i, j;
	glLineWidth(1);

	displayText(" When the caterpillar has done all of its forming and ", -400, -430);
	char strings[] = " changing inside the pupa, it emerges out as a butterfly";
	int n = strlen(strings);

	if (flag == 0)
		glColor3f(0, 1, 1);
	else
		glColor3f(0, 0, 0);
	glRasterPos2f(-400, -520);
	for (int i = 0; i < n; i++) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, strings[i]);
	}
	glColor3f(0, 0.8, 1);
	glBegin(GL_LINE_LOOP);
	glVertex2s(h, k);
	for (i = 0; i <= a; i += 1)
	{
		J = sqrt(1 - (i*i) / (a*a))*b;
		j = (int)(J);
		glVertex2s(h + i, k + j);
		glVertex2s(h - i, k + j);
		glVertex2s(h - i, k - j);
		glVertex2s(h + i, k - j);
	}
	glColor3f(1, 1, 1);

	glEnd();

	glColor3f(0, 0.5, 1);            //right antenna and eye
	glBegin(GL_LINES);

	glVertex2f(0, 110);
	glVertex2f(30, 240);
	glEnd();

	//glPointSize(0.5);
	glColor3f(0, 0, 0);
	glBegin(GL_POINTS);
	glVertex2f(4, 90);
	glEnd();

	glColor3f(0, 0.5, 1);            //left antenna and eye
	glBegin(GL_LINES);
	glVertex2f(0, 110);
	glVertex2f(-30, 240);
	glEnd();

	//glPointSize(0.5);
	glColor3f(0, 0, 0);
	glBegin(GL_POINTS);
	glVertex2f(-4, 90);
	glEnd();

	glFlush();
	glPopMatrix();
}
void butterfly()
{
	if (flag == 0)
		glClearColor(0, 0, 0, 1);
	else
		glClearColor(0, 1, 1,1);
	glClear(GL_COLOR_BUFFER_BIT);

	glPushMatrix();
	glColor3f(0.6, 0.3, 0.2);          //twig
	glLineWidth(7.0);
	glTranslatef(00, 27, 0);

	glBegin(GL_LINES);
	glVertex2f(-200, -30);
	glVertex2f(60, -30);
	glVertex2f(-130, -30);
	glVertex2f(-90, -60);
	glEnd();

	glPopMatrix();
	bg();
	
	ellipse();
	for (int i = 0; i < 50; i++)
	{
		for (int j = 0; j < 50000000; j++);
		if (i % 2 == 0)
		{
			glPushMatrix();
			glTranslatef(10, 10, 0);
			wingr();
			glPopMatrix();
			glPushMatrix();
			glTranslatef(-10, 10, 0);
			wingl();
			glPopMatrix();
		}
		else
		{
			glPushMatrix();
			glTranslatef(-1, -1, 0);
			wingr();
			glPopMatrix();
			glPushMatrix();
			glTranslatef(1, -1, 0);
			wingl();
			glPopMatrix();
		}
		glutPostRedisplay();
		circles();
	}
	

}

void egg()
{
	glPushMatrix();
	glScalef(0.3, 0.3, 0);
	glColor3f(1, 1, 1);
	glBegin(GL_TRIANGLE_FAN);                      //egg 1
	for (int i = 0; i < 30; i++)
	{
		float angle = (3.14 / 15)*i;
		glVertex2f(40 * cos(angle), 40 * sin(angle));
	}
	glEnd();

	glBegin(GL_TRIANGLE_FAN);                          //egg 2
	for (int i = 0; i < 30; i++)
	{
		float angle = (3.14 / 15)*i;
		glVertex2f(40 * cos(angle) + 80, 40 * sin(angle) + 40);
	}
	glEnd();

	glBegin(GL_TRIANGLE_FAN);                          //egg 3
	for (int i = 0; i < 30; i++)
	{
		float angle = (3.14 / 15)*i;
		glVertex2f(40 * cos(angle) + 80, 40 * sin(angle) - 50);
	}
	glEnd();
	glFlush();
	glPopMatrix();
}

void leaf()
{
	glPushMatrix();
	glScalef(0.3, 0.3, 0);
	if (flag == 0)
		glClearColor(0, 0, 0, 1);
	else
		glClearColor(0, 0.7, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_POLYGON);                      //leaf body
	glColor3f(0.0f, 1.0f, 0.0f);

	glVertex2f(-200, 0);
	glVertex2f(00, 150);
	glVertex2f(150, 120);
	glVertex2f(350, 0);
	glVertex2f(150, -120);
	glVertex2f(00, -150);
	glVertex2f(-200, 0);
	glEnd();


	glLineWidth(5.0);
	glBegin(GL_LINES);                  //leaf veins
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(-200, 0);
	glVertex2f(350, 0);
	glVertex2f(-100, 0);
	glVertex2f(0, 140);
	glVertex2f(-100, 0);
	glVertex2f(0, -140);
	glVertex2f(0, 0);
	glVertex2f(70, 120);
	glVertex2f(0, 0);
	glVertex2f(70, -110);
	glVertex2f(100, 0);
	glVertex2f(150, 110);
	glVertex2f(100, 0);
	glVertex2f(150, -110);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex2f(-200, 0);
	glVertex2f(-300, 0);
	glEnd();

	glColor3f(0.6, 0.3, 0.2);          //twig
	glLineWidth(7.0);
	glTranslatef(-400, 47, 0);
	glBegin(GL_LINES);
	glVertex2f(-270, -50);
	glVertex2f(170, -50);
	glVertex2f(-130, -50);
	glVertex2f(-70, -150);
	glEnd();

	glPopMatrix();
	bg();
	glFlush();
	displayText("A butterfly starts life as an egg laid by female butterflies", -200, -230);

	egg();

}



void pupa()
{
	glPushMatrix();
	glScalef(0.3, 0.3, 0);
	glTranslatef(-520, -350, 0);
	if (flag == 0)
		glClearColor(0, 0, 0, 1);
	else
		glClearColor(0, 0.7, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);

	int i, j, dy = 20;
	float angle, ang1, ang2;
	float r = 30, x, y, x1, y1, x2, y2, cx = -50, cy = -50;

	for (i = 0; i < 8; i++)								       //pupa body-bottom to middle
	{
		if (i % 2 == 0)
		{
			glColor3f(0, 0.5, 0.2);
		}
		else
			glColor3f(0, 0.7, 0);

		glBegin(GL_TRIANGLE_FAN);
		for (j = 0; j < 360; j++)
		{
			angle = 3.14 / 180 * j;
			x = cx + 50 + r * (cos(angle));
			y = cy + r * (sin(angle));
			glVertex2f(x, y);
		}
		glEnd();
		cy = cy + dy;
		r = r + 5;
	}

	for (i = 0; i < 8; i++)                            //pupa body-middle to top
	{
		if (i % 2 == 0)
		{
			glColor3f(0, 0.5, 0.2);
		}
		else
			glColor3f(0, 0.7, 0);
		glBegin(GL_TRIANGLE_FAN);
		for (j = 0; j < 360; j++)
		{
			angle = 3.14 / 180 * j;
			x = cx + 50 + r * (cos(angle));
			y = cy + r * (sin(angle));
			glVertex2f(x, y);
		}
		glEnd();
		cy = cy + dy;
		r = r - 5;
	}
	r = r + 5;
	cy = cy - dy;

	glColor3f(0.6, 0.3, 0.2);
	glLineWidth(6);
	glBegin(GL_LINES);                             //branch
	for (j = 0; j < 360; j++)
	{
		angle = 3.14 / 180 * j;
		x = cx + 15 + r * (cos(90));
		y = cy + r * (sin(90));
	}
	glVertex2f(x + 52, y);
	glVertex2f(x + 50, y + 50);
	glVertex2f(x - 110, y + 50);
	glVertex2f(x + 310, y + 50);
	glEnd();
	glPopMatrix();
	bg();
	displayText("Pupa is the resting stage of a caterpillar", -170, -230);
	glFlush();

}

void larva()
{
	glPushMatrix();
	glScalef(0.3, 0.3, 0);
	glTranslatef(-300, 70, 0);
	if (flag == 0)
		glClearColor(0, 0, 0, 1);
	else
		glClearColor(0, 0.7, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);

	int i, j, dy = 40;
	double angle, ang1, ang2;
	float r = 40, x, y, x1, y1, x2, y2, cx = -200;
	for (i = 0; i < 7; i++)                                     //body
	{
		if (i % 2 == 0)
			glColor3f(0, 0.5, 0.2);
		else
			glColor3f(0, 0.7, 0.0);

		glBegin(GL_TRIANGLE_FAN);
		for (j = 0; j < 360; j++)
		{
			angle = 3.14 / 180 * j;
			x = cx + r * (cos(angle));
			y = r * (sin(angle));
			glVertex2f(x, y);
		}
		glEnd();
		cx = cx + dy;
	}

	cx = -200;                      //legs
	glLineWidth(3.0);
	for (i = 0; i < 7; i++)
	{
		glColor3f(0, 0.5, 0);
		glBegin(GL_LINES);
		ang1 = 225;
		ang2 = 180;
		x1 = cx + r * (cos(ang1));
		y1 = r * (sin(ang1));
		x2 = cx + r * (cos(ang2));
		y2 = r * (sin(ang2));
		glVertex2f(x1, y1);
		glVertex2f(x1, y1 - 8);
		glVertex2f(x2, y2);
		glVertex2f(x2, y2 - 8);

		glEnd();
		cx = cx + dy;
	}

	cx = cx - 36;

	glBegin(GL_LINES);                     //antennas
	ang1 = 45;
	ang2 = 90;
	x1 = cx + r * (cos(ang1));
	y1 = r * (sin(ang1));
	x2 = cx + r * (cos(ang2));
	y2 = r * (sin(ang2));
	glVertex2f(x1, y1);
	glVertex2f(x1 + 3, y1 + 16);
	glVertex2f(x2, y2);
	glVertex2f(x2 - 3, y2 + 17);
	glEnd();

	glColor3f(0, 0, 0);            //eyes
	glPointSize(2.0);
	glBegin(GL_POINTS);
	glVertex2f(cx - 8, 5);
	glVertex2f(cx + 8, 5);
	glEnd();
	glPopMatrix();

	glColor3f(0.6, 0.3, 0.2);          //twig
	glLineWidth(7.0);
	glPushMatrix();

	glBegin(GL_LINES);
	glVertex2f(-270, 0);
	glVertex2f(0, 0);
	glVertex2f(-130, 0);
	glVertex2f(-90, -20);
	glEnd();

	glPopMatrix();
	bg();
	displayText("The eggs hatch into caterpillars / larva", -170, -230);
	glFlush();


}

void cycle()
{

	leaf();
	for (int q = 0; q < 2000000000; q++);                   // 5s delay
	larva();
	for (int q = 0; q < 1500000000; q++);
	pupa();
	for (int q = 0; q < 2000000000; q++);
	butterfly();
	for (int q = 0; q < 200000500; q++);
	exit(0);
}

int main(int argc, char* argv[])
{


	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(800, 600);

	glutCreateWindow("Life cycle of a butterfly");

	myinit();
	PlaySound(TEXT("butterfly.wav"), NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
	glutKeyboardFunc(key);
	glutDisplayFunc(cycle);
	GLenum err = glewInit();
	if (GLEW_OK != err)
	{
		fprintf(stderr, "GLEW error");
		return 1;
	}
	glutMainLoop();
	return 0;
}
