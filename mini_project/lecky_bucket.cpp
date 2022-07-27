#include<stdio.h>
#include<GL/glut.h>
#include<math.h>

int k;
int flag = 0;
int start = 0;
int overflow = 0;
int temp = 0, change = 0;
int res = 0;

void drawBitmapText(float x, float y, float z, char* string)
{
	char* c;
	glRasterPos3f(x, y, z);

	for (c = string; *c != '\0'; c++)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
	}
}


int compute()
{
	int c = 0;
	int op, pk[30], bucketsize, n, i;
	printf("Enter the output rate:\n");
	scanf_s("%d", &op);
	printf("Enter the bucket size: \n");
	scanf_s("%d", &bucketsize);
	printf("Enter the number of packets:\n");
	scanf_s("%d", &n);
	for (i = 1; i <= n; i++)
	{
		printf("Enter packet %d bandwidth: ", i);
		scanf_s("%d", &pk[i]);
	}
	for (i = 1; i <= n; i++)
	{
		if (pk[i] > bucketsize)
		{
			printf("\nbucket overflow\n");
			overflow = 1;

		}
		else
		{
			while (pk[i] > op)
			{
				printf("\n%d Bytes outputted", op);
				pk[i] = pk[i] - op;
				c++;
			}
			if (pk[i] > 0)
				c++;
			printf("\n Last %d bytes sent", pk[i]);
			printf("\n Bucket output successful\n");
		}
	}
	printf("\n Number of packets sent=%d\n", c);
	return c;

}

void setpoint(GLint x, GLint y)
{
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
}



int round1(double number)
{
	return (number >= 0) ? (int)(number + 0.5) : (int)(number - 0.5);
}


void LineWithDDA(int x0, int y0, int x1, int y1)
{
	int dy = y1 - y0;
	int dx = x1 - x0;
	int steps, i;
	float xinc, yinc, x = x0, y = y0;
	if (abs(dx) > abs(dy))
	{
		steps = abs(dx);
	}
	else
	{
		steps = abs(dy);
	}
	xinc = (float)dx / (float)steps;
	yinc = (float)dy / (float)steps;
	setpoint(round1(x), round1(y));
	for (i = 0; i < steps; i++)
	{
		x += xinc;
		y += yinc;
		setpoint(round1(x), round1(y));
	}
	glPointSize(5);
	glutSwapBuffers();
}

void Circle(int r, int xCenter, int yCenter)
{

	int x = 0, y = r;
	int d = 3 / 2 - r;
	glColor3f(0, 0, 1);
	while (x <= y)
	{
		setpoint(xCenter + x, yCenter + y);
		setpoint(xCenter + y, yCenter + x);
		setpoint(xCenter - x, yCenter + y);
		setpoint(xCenter + y, yCenter - x);
		setpoint(xCenter - x, yCenter - y);
		setpoint(xCenter - y, yCenter - x);
		setpoint(xCenter + x, yCenter - y);
		setpoint(xCenter - y, yCenter + x);

		if (d < 0)
			d += (2 * x) + 3;
		else
		{
			d += (2 * (x - y)) + 5;
			y -= 1;
		}
		x++;
	}
	glFlush();
}


void ke(unsigned char key, int x, int y)
{
	switch (key)
	{
	case's': { start = 1; flag = 1;

		break;
	}
	
	case 'e':exit(1);
		break;
	}
	glutPostRedisplay();
}


void display()
{
	int i;
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	if (start == 0)
	{
		glColor3f(1.0, 0.0, 0.0);
		char f[] = "VIVEKANANDA COLLEGE OF ENGINEERING AND TECHNOLOGY";
		glRasterPos2f(200.0, 450.0);

		for (i = 0; f[i] != '\0'; i++)
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, f[i]);


		glColor3f(0.0, 0.0, 1.0);
		char g[] = "DEPARTMENT OF COMPUTER SCIENCE AND ENGINEERING";
		glRasterPos2f(220.0, 400.0);
		for (i = 0; g[i] != '\0'; i++)
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, g[i]);


		glColor3f(1.0, 0.5, 0.0);
		char h[] = "A MINI PROJECT ON:";
		glRasterPos2f(350.0, 300.0);
		for (i = 0; h[i] != '\0'; i++)
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, h[i]);


		glColor3f(2.0, 0.5, 1.0);
		char e[] = "Leaky Bucket Algorithm";
		glRasterPos2f(350.0, 250.0);
		for (i = 0; e[i] != '\0'; i++)
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, e[i]);


		glColor3f(1.0, 1.0, 0.0);
		char t[] = "BY:";
		glRasterPos2f(50.0, 200.0);
		for (i = 0; t[i] != '\0'; i++)
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, t[i]);


		glColor3f(1.0, 1.0, 1.0);
		char s[] = "Harshitha B V    4VP18CS035";
		glRasterPos2f(80.0, 170.0);
		for (i = 0; s[i] != '\0'; i++)
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, s[i]);


		glColor3f(1.0, 1.0, 1.0);
		char u[] = "Bhoomika M      4VP18CS017";
		glRasterPos2f(80.0, 130.0);
		for (i = 0; u[i] != '\0'; i++)
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, u[i]);


		glColor3f(1.0, 1.0, 0.0);
		char v[] = "GUIDE:";
		glRasterPos2f(600.0, 200.0);
		for (i = 0; v[i] != '\0'; i++)
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, v[i]);


		glColor3f(1.0, 1.0, 1.0);
		char w[] = " Mr. Krishna Mohana";
		glRasterPos2f(660.0, 170.0);
		for (i = 0; w[i] != '\0'; i++)
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, w[i]);


		glColor3f(0.0, 1.0, 0.0);
		char x[] = " PRESS 's' TO START";
		glRasterPos2f(350.0, 80.0);
		for (i = 0; x[i] != '\0'; i++)
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, x[i]);
		glMatrixMode(GL_MODELVIEW);

	}
	else {
		if (start == 1)
		{


			int const w = glutGet(GLUT_WINDOW_WIDTH);
			int const h = glutGet(GLUT_WINDOW_HEIGHT);

			glTranslatef(700, 0, 0);
			glRotatef(180, 0, 1, 0);
			glScalef(2.0, 2.0, 0);

			if (flag == 1)
				temp = compute();
			int x = temp;

			Circle(3, 102, 183);
			Circle(1, 102, 183);
			glColor3f(1.0, 0.0, 1.0);
			LineWithDDA(40, 180, 100, 180);
			LineWithDDA(40, 185, 100, 185);


			glColor3f(1.0, 0.0, 0.0);
			LineWithDDA(40, 60, 40, 250);
			glColor3f(1.0, 1.0, 1.0);
			LineWithDDA(100, 185, 100, 192);
			glColor3f(1.0, 1.0, 1.0);
			LineWithDDA(95, 192, 105, 192);


			glColor3f(1.0, 1.0, 1.0);
			LineWithDDA(75, 60, 125, 60);
			LineWithDDA(125, 60, 125, 120);
			LineWithDDA(75, 120, 75, 60);


			int i = 0;
			glColor3f(0, 0, 255);

			while (i < 13)
			{
				k = 0;
				while (k < 10000)
				{
					int j = 0;
					while (j < 10000)
					{
						j++;
					}
					k++;
				}
				Circle(3, 102, 183 - (10 * i));
				Circle(1, 102, 183 - (10 * i));

				i++;
			}
			//overflow
			if (overflow == 1)
			{
				char z[20] = "BUCKET OVERFLOW";
				int i = 0;
				glColor3f(0, 0, 1);
				LineWithDDA(76, 61, 124, 61);
				while (i < 60)
				{
					k = 0;
					while (k < 1000)
					{
						int j = 0;
						while (j < 10000)
						{
							j++;
						}
						k++;
					}

					LineWithDDA(76, 61 + i, 124, 61 + i);
					i++;
				}


				glClearColor(0, 0, 0, 0);
				glColor3f(1.0, 0.5, 0.0);
				drawBitmapText(200, 100, 0.0, z);


			}



			if (overflow == 0)
			{
				i = 0;
				glColor3f(0, 0, 255);
				LineWithDDA(76, 61, 124, 61);
				while (i < 10)
				{
					k = 0;
					while (k < 1000)
					{
						int j = 0;
						while (j < 10000)
						{
							j++;
						}
						k++;
					}

					LineWithDDA(76, 61 + i, 124, 61 + i);
					i++;
				}

				glColor3f(0, 0, 200 / 255.0);
				Circle(1, 102, 63);
				i = 0;
				while (i < (x + 1))
				{
					k = 0;
					while (k < 10000)
					{
						int j = 0;
						while (j < 10000)
						{
							j++;
						}
						k++;
					}
					Circle(1, 102, 63 - (10 * i));

					i++;
				}
			}
			res = 1;
			flag = 0;

		}
	

	}
	glFlush();
	glutSwapBuffers();

}
void reshape(int w, int h)
{

	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, w, 0, h);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	if (res == 1)
		start = 2;
	glutPostRedisplay();


}

int main(int argc, char** argv)
{

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(50, 50);
	glutInitWindowSize(1000, 600);
	glutCreateWindow("Leaky Bucket");
	glutKeyboardFunc(ke);
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMainLoop();
	return 0;


}