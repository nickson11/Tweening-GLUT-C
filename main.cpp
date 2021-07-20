#include <GL/glut.h>
#include<windows.h>
#include <GL/freeglut.h>
#include <stdlib.h>


void init(void);
void tampil(void);
void keyboard(unsigned char, int, int);
void ukuran(int, int);
//void idle();
void mouse(int button, int state, int x, int y);
void mouseMotion(int x, int y);
bool mouseDown = false;
int is_depth;
float xrot = 0.0f;
float yrot = 0.0f;
float xdiff = 0.0f;
float ydiff = 0.0f;

float xpos = 0.0f;
float ypos = 0.0f;
float zpos = 0.0f;


int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(250, 80);
	glutCreateWindow("TR GRAFKOM KELOMPOK 5 DURHAM UNIVERSITY");
	init();
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glutDisplayFunc(tampil);
	glutMouseFunc(mouse);
	glutMotionFunc(mouseMotion);
	glutKeyboardFunc(keyboard);
	glutReshapeFunc(ukuran);
	glutMainLoop();
	return 0;
}

void init(void)
{
glClearColor(1.0, 1.0, 1.0, 0.0);
glEnable(GL_DEPTH_TEST);
//pencahayaan
glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);
glEnable(GL_LIGHTING);
glEnable(GL_LIGHT0);
//set cahaya
GLfloat qaAmbientLight[] = { 0.2,0.2,0.2,1.0 };
GLfloat qaDiffuseLight[] = { 1,1,1,1 };
GLfloat qaSpecularLight[] = { 1,1,1,1 };
glLightfv(GL_LIGHT0, GL_AMBIENT, qaAmbientLight);
glLightfv(GL_LIGHT0, GL_DIFFUSE, qaDiffuseLight);
glLightfv(GL_LIGHT0, GL_SPECULAR, qaSpecularLight);
//posisi cahaya
GLfloat posisilampu[] = { 0,160,200,1 };
glLightfv(GL_LIGHT0, GL_POSITION, posisilampu);
glEnable(GL_COLOR_MATERIAL);
glShadeModel(GL_SMOOTH);
glMatrixMode(GL_MODELVIEW);
glOrtho(-30, 30, -30, 30, -30, 30);
glPointSize(2.0);
glLineWidth(2.0);
}

void castil(){
				glBegin(GL_POLYGON); // BALOK TINGGI
				glColor3ub(158, 55, 0);
				glVertex3f(-60,18.2,0);
				glVertex3f(-60,23,0);
				glVertex3f(-55,23,0);
				glVertex3f(-55,18.2,0);
				glEnd();

				glBegin(GL_POLYGON); // BALOK PENDEK
				glColor3ub(158, 55, 0);
				glVertex3f(-55,18.2,0);
				glVertex3f(-55,21,0);
				glVertex3f(-50,21,0);
				glVertex3f(-50,18.2,0);
				glEnd();

}

void castil1(){
				glBegin(GL_POLYGON); // BALOK PENDEK
				glColor3ub(158, 55, 0);
				glVertex3f(-55,18.2,0);
				glVertex3f(-55,21,0);
				glVertex3f(-50,21,0);
				glVertex3f(-50,18.2,0);
				glEnd();

}

void castil2(){

				glBegin(GL_POLYGON); // BALOK TINGGI
				glColor3ub(158, 55, 0);
				glVertex3f(-60,18.2,0);
				glVertex3f(-60,23,0);
				glVertex3f(-55,23,0);
				glVertex3f(-55,18.2,0);
				glEnd();
}

void tanah(){
				glBegin(GL_POLYGON);
				glColor3ub(42, 201, 56);
				glVertex3f(-90,-18,50);
				glVertex3f(100,-18,50);
				glVertex3f(100,-18,-80);
				glVertex3f(-90,-18,-80);
				glEnd();
}

void tiang(){
				glBegin(GL_POLYGON);//bawah
				glColor3ub(158, 158, 158);
				glVertex3f(-10,-18,10);
				glVertex3f(-9,-18,10);
				glVertex3f(-9,-18,9);
				glVertex3f(-10,-18,9);
				glEnd();

				glBegin(GL_POLYGON);//atas
				glColor3ub(158, 158, 158);
				glVertex3f(-10,14,10);
				glVertex3f(-9,14,10);
				glVertex3f(-9,14,9);
				glVertex3f(-10,14,9);
				glEnd();

				glBegin(GL_POLYGON);//kiri
				glColor3ub(158, 158, 158);
				glVertex3f(-10,-18,9);
				glVertex3f(-10,-18,10);
				glVertex3f(-10,14,10);
				glVertex3f(-10,14,9);
				glEnd();

				glBegin(GL_POLYGON);//kanan
				glColor3ub(158, 158, 158);
				glVertex3f(-9,-18,9);
				glVertex3f(-9,-18,10);
				glVertex3f(-9,14,10);
				glVertex3f(-9,14,9);
				glEnd();

				glBegin(GL_POLYGON);//depan
				glColor3ub(158, 158, 158);
				glVertex3f(-10,-18,10);
				glVertex3f(-9,-18,10);
				glVertex3f(-9,14,10);
				glVertex3f(-10,14,10);
				glEnd();

				glBegin(GL_POLYGON);//belakang
				glColor3ub(158, 158, 158);
				glVertex3f(-10,-18,9);
				glVertex3f(-9,-18,9);
				glVertex3f(-9,14,9);
				glVertex3f(-10,14,9);
				glEnd();

				//bendera
				glBegin(GL_POLYGON);//belakang
				glColor3ub(54, 77, 255);
				glVertex3f(-9,7,9.5);
				glVertex3f(2,7,9.5);
				glVertex3f(2,12,9.5);
				glVertex3f(-9,12,9.5);
				glEnd();
}

void mading(){
                //tiangkiri
				glBegin(GL_POLYGON);//bawah
				glColor3ub(158, 55, 0);
				glVertex3f(-15,-18,-15);
				glVertex3f(-14,-18,-15);
				glVertex3f(-14,-18,-14);
				glVertex3f(-15,-18,-14);
				glEnd();

				glBegin(GL_POLYGON);//atas
				glColor3ub(158, 55, 0);
				glVertex3f(-15,1,-15);
				glVertex3f(-14,1,-15);
				glVertex3f(-14,1,-14);
				glVertex3f(-15,1,-14);
				glEnd();

				glBegin(GL_POLYGON);//kiri
				glColor3ub(158, 55, 0);
				glVertex3f(-15,-18,-14);
				glVertex3f(-15,-18,-15);
				glVertex3f(-15,1,-15);
				glVertex3f(-15,1,-14);
				glEnd();

				glBegin(GL_POLYGON);//kanan
				glColor3ub(158, 55, 0);
				glVertex3f(-14,-18,-14);
				glVertex3f(-14,-18,-15);
				glVertex3f(-14,1,-15);
				glVertex3f(-14,1,-14);
				glEnd();

				glBegin(GL_POLYGON);//depan
				glColor3ub(158, 158, 158);
				glVertex3f(-15,-18,-15);
				glVertex3f(-14,-18,-15);
				glVertex3f(-14,1,-15);
				glVertex3f(-15,1,-15);
				glEnd();

				glBegin(GL_POLYGON);//belakang
				glColor3ub(158, 55, 0);
				glVertex3f(-15,-18,-14);
				glVertex3f(-14,-18,-14);
				glVertex3f(-14,1,-14);
				glVertex3f(-15,1,-14);
				glEnd();

                //tiangkanan
                glBegin(GL_POLYGON);//bawah
				glColor3ub(158, 55, 0);
				glVertex3f(15,-18,-15);
				glVertex3f(14,-18,-15);
				glVertex3f(14,-18,-14);
				glVertex3f(15,-18,-14);
				glEnd();

				glBegin(GL_POLYGON);//atas
				glColor3ub(158, 55, 0);
				glVertex3f(15,1,-15);
				glVertex3f(14,1,-15);
				glVertex3f(14,1,-14);
				glVertex3f(15,1,-14);
				glEnd();

				glBegin(GL_POLYGON);//kiri
				glColor3ub(158, 55, 0);
				glVertex3f(15,-18,-14);
				glVertex3f(15,-18,-15);
				glVertex3f(15,1,-15);
				glVertex3f(15,1,-14);
				glEnd();

				glBegin(GL_POLYGON);//kanan
				glColor3ub(158, 55, 0);
				glVertex3f(14,-18,-14);
				glVertex3f(14,-18,-15);
				glVertex3f(14,1,-15);
				glVertex3f(14,1,-14);
				glEnd();

				glBegin(GL_POLYGON);//depan
				glColor3ub(158, 55, 0);
				glVertex3f(15,-18,-15);
				glVertex3f(14,-18,-15);
				glVertex3f(14,1,-15);
				glVertex3f(15,1,-15);
				glEnd();

				glBegin(GL_POLYGON);//belakang
				glColor3ub(158, 55, 0);
				glVertex3f(15,-18,-14);
				glVertex3f(14,-18,-14);
				glVertex3f(14,1,-14);
				glVertex3f(15,1,-14);
				glEnd();

				//papanmading
				glBegin(GL_POLYGON);//depan
				glColor3ub(500, 500, 500);
				glVertex3f(15,-14,-15);
				glVertex3f(-14,-14,-15);
				glVertex3f(-14,1,-15);
                glColor3ub(1, 1, 1);
				glVertex3f(15,1,-15);
				glEnd();

				glBegin(GL_POLYGON);//belakang
				glColor3ub(500, 500, 500);
				glVertex3f(15,-14,-14);
				glVertex3f(-14,-14,-14);
				glVertex3f(-14,1,-14);
				glColor3ub(1, 1, 1);
				glVertex3f(15,1,-14);
				glEnd();

                glBegin(GL_POLYGON);//atas
				glColor3ub(500, 500, 500);
				glVertex3f(15,1,-15);
				glVertex3f(-14,1,-15);
				glVertex3f(-14,1,-14);
				glVertex3f(15,1,-14);
				glEnd();

}

void papantulis(){
                //tiangkiri
				glBegin(GL_POLYGON);//bawah
				glColor3ub(158, 55, 0);
				glVertex3f(50,-18,-15);
				glVertex3f(49,-18,-15);
				glVertex3f(49,-18,-14);
				glVertex3f(50,-18,-14);
				glEnd();

				glBegin(GL_POLYGON);//atas
				glColor3ub(158, 55, 0);
				glVertex3f(50,-5,-15);
				glVertex3f(49,-5,-15);
				glVertex3f(49,-5,-14);
				glVertex3f(50,-5,-14);
				glEnd();

				glBegin(GL_POLYGON);//kiri
				glColor3ub(158, 55, 0);
				glVertex3f(50,-18,-14);
				glVertex3f(50,-18,-15);
				glVertex3f(50,-5,-15);
				glVertex3f(50,-5,-14);
				glEnd();

				glBegin(GL_POLYGON);//kanan
				glColor3ub(158, 55, 0);
				glVertex3f(49,-18,-14);
				glVertex3f(49,-18,-15);
				glVertex3f(49,-5,-15);
				glVertex3f(49,-5,-14);
				glEnd();

				glBegin(GL_POLYGON);//depan
				glColor3ub(158, 55, 0);
				glVertex3f(50,-18,-15);
				glVertex3f(49,-18,-15);
				glVertex3f(49,-5,-15);
				glVertex3f(50,-5,-15);
				glEnd();

				glBegin(GL_POLYGON);//belakang
				glColor3ub(158, 55, 0);
				glVertex3f(50,-18,-14);
				glVertex3f(49,-18,-14);
				glVertex3f(49,-5,-14);
				glVertex3f(50,-5,-14);
				glEnd();

                //tiangkanan
                glBegin(GL_POLYGON);//bawah
				glColor3ub(158, 55, 0);
				glVertex3f(75,-18,-15);
				glVertex3f(74,-18,-15);
				glVertex3f(74,-18,-14);
				glVertex3f(75,-18,-14);
				glEnd();

				glBegin(GL_POLYGON);//atas
				glColor3ub(158, 55, 0);
				glVertex3f(75,-5,-15);
				glVertex3f(74,-5,-15);
				glVertex3f(74,-5,-14);
				glVertex3f(75,-5,-14);
				glEnd();

				glBegin(GL_POLYGON);//kiri
				glColor3ub(158, 55, 0);
				glVertex3f(75,-18,-14);
				glVertex3f(75,-18,-15);
				glVertex3f(75,-5,-15);
				glVertex3f(75,-5,-14);
				glEnd();

				glBegin(GL_POLYGON);//kanan
				glColor3ub(158, 55, 0);
				glVertex3f(74,-18,-14);
				glVertex3f(74,-18,-15);
				glVertex3f(74,-5,-15);
				glVertex3f(74,-5,-14);
				glEnd();

				glBegin(GL_POLYGON);//depan
				glColor3ub(158, 55, 0);
				glVertex3f(75,-18,-15);
				glVertex3f(74,-18,-15);
				glVertex3f(74,-5,-15);
				glVertex3f(75,-5,-15);
				glEnd();

				glBegin(GL_POLYGON);//belakang
				glColor3ub(158, 55, 0);
				glVertex3f(75,-18,-14);
				glVertex3f(74,-18,-14);
				glVertex3f(74,-5,-14);
				glVertex3f(75,-5,-14);
				glEnd();

                //papandepan papantulis
                glBegin(GL_POLYGON);//depan
				glColor3ub(500, 500, 500);
				glVertex3f(50,-15,-15);
				glVertex3f(74,-15,-15);
				glVertex3f(74,-5,-15);
				glColor3ub(1, 1, 1);
				glVertex3f(50,-5,-15);
				glEnd();

				//papanbelakang papantulis
				glBegin(GL_POLYGON);//belakang
				glColor3ub(500, 500, 500);
				glVertex3f(50,-15,-14);
				glVertex3f(74,-15,-14);
				glVertex3f(74,-5,-14);
				glColor3ub(1, 1, 1);
				glVertex3f(50,-5,-14);
				glEnd();

				//papanatas papantulis
				glBegin(GL_POLYGON);//atas
				glColor3ub(500, 500, 500);
				glVertex3f(50,-5,-15);
				glVertex3f(74,-5,-15);
				glVertex3f(74,-5,-14);
				glVertex3f(50,-5,-14);
				glEnd();
}

void jendela(){
				glBegin(GL_POLYGON);//belakang
				glColor3ub(0, 0, 0);
				glVertex3f(10,7,12.5);
				glVertex3f(15,7,12.5);
				glVertex3f(15,14,12.5);
				glVertex3f(10,14,12.5);
				glEnd();

				glBegin(GL_LINES);//belakang
				glColor3ub(56, 56, 56);
				glVertex3f(12.5,14,12.6);
				glVertex3f(12.5,7,12.6);
				glEnd();

				glBegin(GL_LINES);//belakang
				glColor3ub(56, 56, 56);
				glVertex3f(10,11.5,12.6);
				glVertex3f(15,11.5,12.6);
				glEnd();

}

void bangun1(){

		glBegin(GL_POLYGON); // belakang
		glColor3ub(255, 154, 54);
		glVertex3f(-60,-18,-30);
		glVertex3f(-36,-18,-30);
		glVertex3f(-36,18,-30);
		glVertex3f(-60,18,-30);
		glEnd();

		glBegin(GL_POLYGON); // atas
		glColor3ub(150, 150, 150);
		glVertex3f(-60,18,0);
		glVertex3f(-40,18,0);
		glVertex3f(-36,18,-5.0);
		glVertex3f(-36,18,-30);
		glVertex3f(-60,18,-30);
		glEnd();

		glBegin(GL_POLYGON); // bawah
		glColor3ub(8, 48, 48);
		glVertex3f(-60,-18,0);
		glVertex3f(-40,-18,0);
		glVertex3f(-36,-18,-5.0);
		glVertex3f(-36,-18,-30);
		glVertex3f(-60,-18,-30);
		glEnd();

		glBegin(GL_POLYGON); // kiri
		glColor3ub(255, 145, 36);
		glVertex3f(-60,-18,-30);
		glVertex3f(-60,-18,0);
		glVertex3f(-60,18,0);
		glVertex3f(-60,18,-30);
		glEnd();

		glBegin(GL_POLYGON); // kanan
		glColor3ub(255, 145, 36);
		glVertex3f(-36,-18,-5.0);
		glVertex3f(-36,-18,-30);
		glVertex3f(-36,18,-30);
		glVertex3f(-36,18,-5.0);
		glEnd();

		glBegin(GL_POLYGON); // depan-samping
		glColor3ub(179, 89, 0);
		glVertex3f(-40,-18,0);
		glVertex3f(-36,-18,-5.0);
		glVertex3f(-36,18,-5.0);
		glVertex3f(-40,18,0);
		glEnd();

		glBegin(GL_POLYGON); // depan
		glColor3ub(255, 145, 36);
		glVertex3f(-60,-18,0);
		glVertex3f(-40,-18,0);
		glVertex3f(-40,18,0);
		glVertex3f(-60,18,0);
		glEnd();

		//------------------------------------
		//kastil atas
			glBegin(GL_LINE_LOOP); // LINE LOOP
			glColor3ub(8, 8, 8);
			glVertex3f(-60,18.2,0);
			glVertex3f(-40,18.2,0);
			glVertex3f(-36,18.2,-5.0);
			glVertex3f(-36,18.2,-30);
			glVertex3f(-60,18.2,-30);
			glEnd();

			//DEPAN
				glBegin(GL_POLYGON); // BALOK TINGGI
				glColor3ub(158, 55, 0);
				glVertex3f(-60,18.2,0);
				glVertex3f(-60,23,0);
				glVertex3f(-55,23,0);
				glVertex3f(-55,18.2,0);
				glEnd();

				glBegin(GL_POLYGON); // BALOK PENDEK
				glColor3ub(158, 55, 0);
				glVertex3f(-55,18.2,0);
				glVertex3f(-55,21,0);
				glVertex3f(-50,21,0);
				glVertex3f(-50,18.2,0);
				glEnd();

				glBegin(GL_POLYGON); // BALOK TINGGI
				glColor3ub(158, 55, 0);
				glVertex3f(-50,18.2,0);
				glVertex3f(-50,23,0);
				glVertex3f(-45,23,0);
				glVertex3f(-45,18.2,0);
				glEnd();

				glBegin(GL_POLYGON); // BALOK PENDEK
				glColor3ub(158, 55, 0);
				glVertex3f(-45,18.2,0);
				glVertex3f(-45,21,0);
				glVertex3f(-40,21,0);
				glVertex3f(-40,18.2,0);
				glEnd();

				glBegin(GL_POLYGON); // BALOK TINGGI
				glColor3ub(158, 55, 0);
				glVertex3f(-40,18.2,0);
				glVertex3f(-40,23,0);
				glVertex3f(-36,23,-5);
				glVertex3f(-36,18.2,-5);
				glEnd();

			//BELAKANG
				glBegin(GL_POLYGON); // BALOK TINGGI
				glColor3ub(158, 55, 0);
				glVertex3f(-60,18.2,-30);
				glVertex3f(-60,23,-30);
				glVertex3f(-55,23,-30);
				glVertex3f(-55,18.2,-30);
				glEnd();

				glBegin(GL_POLYGON); // BALOK PENDEK
				glColor3ub(158, 55, 0);
				glVertex3f(-55,18.2,-30);
				glVertex3f(-55,21,-30);
				glVertex3f(-50,21,-30);
				glVertex3f(-50,18.2,-30);
				glEnd();

				glBegin(GL_POLYGON); // BALOK TINGGI
				glColor3ub(158, 55, 0);
				glVertex3f(-50,18.2,-30);
				glVertex3f(-50,23,-30);
				glVertex3f(-45,23,-30);
				glVertex3f(-45,18.2,-30);
				glEnd();

				glBegin(GL_POLYGON); // BALOK PENDEK
				glColor3ub(158, 55, 0);
				glVertex3f(-45,18.2,-30);
				glVertex3f(-45,21,-30);
				glVertex3f(-40,21,-30);
				glVertex3f(-40,18.2,-30);
				glEnd();

				glBegin(GL_POLYGON); // BALOK TINGGI
				glColor3ub(158, 55, 0);
				glVertex3f(-40,18.2,-30);
				glVertex3f(-40,23,-30);
				glVertex3f(-36,23,-30);
				glVertex3f(-36,18.2,-30);
				glEnd();
			//KIRI
				glBegin(GL_POLYGON); // BALOK TINGGI
				glColor3ub(158, 55, 0);
				glVertex3f(-60,18.2,0);
				glVertex3f(-60,23,0);
				glVertex3f(-60,23,-5);
				glVertex3f(-60,18.2,-5);
				glEnd();

				glBegin(GL_POLYGON); //BALOK SEDANG
				glColor3ub(158, 55, 0);
				glVertex3f(-60,18.2,-5);
				glVertex3f(-60,21,-5);
				glVertex3f(-60,21,-10);
				glVertex3f(-60,18.2,-10);
				glEnd();

				glBegin(GL_POLYGON); // BALOK TINGGI
				glColor3ub(158, 55, 0);
				glVertex3f(-60,18.2,-10);
				glVertex3f(-60,23,-10);
				glVertex3f(-60,23,-15);
				glVertex3f(-60,18.2,-15);
				glEnd();

				glBegin(GL_POLYGON); //BALOK SEDANG
				glColor3ub(158, 55, 0);
				glVertex3f(-60,18.2,-15);
				glVertex3f(-60,21,-15);
				glVertex3f(-60,21,-20);
				glVertex3f(-60,18.2,-20);
				glEnd();

				glBegin(GL_POLYGON); //BALOK SEDANG
				glColor3ub(158, 55, 0);
				glVertex3f(-60,18.2,-20);
				glVertex3f(-60,23,-20);
				glVertex3f(-60,23,-25);
				glVertex3f(-60,18.2,-25);
				glEnd();

				glBegin(GL_POLYGON); //BALOK SEDANG
				glColor3ub(158, 55, 0);
				glVertex3f(-60,18.2,-25);
				glVertex3f(-60,21,-25);
				glVertex3f(-60,21,-30);
				glVertex3f(-60,18.2,-30);
				glEnd();
			//Kanan

				glBegin(GL_POLYGON); //BALOK SEDANG
				glColor3ub(158, 55, 0);
				glVertex3f(-36,18.2,-5);
				glVertex3f(-36,21,-5);
				glVertex3f(-36,21,-10);
				glVertex3f(-36,18.2,-10);
				glEnd();

				glBegin(GL_POLYGON); // BALOK TINGGI
				glColor3ub(158, 55, 0);
				glVertex3f(-36,18.2,-10);
				glVertex3f(-36,23,-10);
				glVertex3f(-36,23,-15);
				glVertex3f(-36,18.2,-15);
				glEnd();

				glBegin(GL_POLYGON); // BALOK TINGGI
				glColor3ub(158, 55, 0);
				glVertex3f(-36,18.2,-15);
				glVertex3f(-36,21,-15);
				glVertex3f(-36,21,-20);
				glVertex3f(-36,18.2,-20);
				glEnd();

				glBegin(GL_POLYGON); // BALOK TINGGI
				glColor3ub(158, 55, 0);
				glVertex3f(-36,18.2,-20);
				glVertex3f(-36,23,-20);
				glVertex3f(-36,23,-25);
				glVertex3f(-36,18.2,-25);
				glEnd();

				glBegin(GL_POLYGON); // BALOK TINGGI
				glColor3ub(158, 55, 0);
				glVertex3f(-36,18.2,-25);
				glVertex3f(-36,21,-25);
				glVertex3f(-36,21,-30);
				glVertex3f(-36,18.2,-30);
				glEnd();
	}

void bangun2(){
glBegin(GL_QUADS); // BAWAH
    glColor3f(1, 1, 1);
    glVertex3f(-60,-18,-30.0);
    glVertex3f(65.8,-18,-30.0);
    glVertex3f(65.8,-18,-60.0);
    glVertex3f(-60,-18,-60);
    //kecil
    glVertex3f(-36,-18,-25.0);
    glVertex3f(10.8,-18,-25.0);
    glVertex3f(10.8,-18,-30.0);
    glVertex3f(-36,-18,-30);
	//kecil2
    glVertex3f(26,-18,-25.0);
    glVertex3f(40,-18,-25.0);
    glVertex3f(40,-18,-30.0);
    glVertex3f(26,-18,-30);

    //atas
    glColor3ub(150, 150, 150);
    glVertex3f(-60, 18,-30.0);
    glVertex3f(65.8, 18,-30.0);
    glVertex3f(65.8, 18,-60.0);
    glVertex3f(-60, 18,-60);
    //kecil
    glVertex3f(-36, 18,-25.0);
    glVertex3f(10.8, 18,-25.0);
    glVertex3f(10.8, 18,-30.0);
    glVertex3f(-36, 18,-30);
	//kecil2
    glVertex3f(26, 18,-25.0);
    glVertex3f(40, 18,-25.0);
    glVertex3f(40, 18,-30.0);
    glVertex3f(26, 18,-30);

    //tembok
    //belakang
    glColor3ub(255, 154, 54);
    glColor3ub(255, 154, 54);
    glVertex3f(-60, 18, -60.0);
    glVertex3f(65.8, 18, -60.0);
    glVertex3f(65.8, -18, -60.0);
    glVertex3f(-60, -18, -60);
    //depan kecil 1
    glVertex3f(-36, 18, -25.01);
    glVertex3f(10.8, 18, -25.01);
    glVertex3f(10.8, -18, -25.01);
    glVertex3f(-36, -18, -25.01);
    //depan kecil 1
	glVertex3f(26, 18, -25.01);
    glVertex3f(40, 18, -25.01);
    glVertex3f(40, -18, -25.01);
    glVertex3f(26, -18, -25.01);

    //samping
    //kiri
    glColor3ub(255, 154, 54);
    glVertex3f(-60, 18, -30.0);
    glVertex3f(-60, -18, -30.0);
    glVertex3f(-60, -18, -60.0);
    glVertex3f(-60, 18, -60);
    //kanan
    glColor3ub(255, 154, 54);
    glVertex3f(65.8, 18, -30.0);
    glVertex3f(65.8, -18, -30.0);
    glVertex3f(65.8, -18, -60.0);
    glVertex3f(65.8, 18, -60);

    //ornamen
    //depan
    glColor3ub(158, 55, 0);
    glVertex3f(-36, 21, -25.01);
    glVertex3f(10.8, 21, -25.01);
    glVertex3f(10.8, 18, -25.01);
    glVertex3f(-36, 18, -25.01);
    //
    glVertex3f(26, 21, -25.01);
    glVertex3f(40, 21, -25.01);
    glVertex3f(40, 18, -25.01);
    glVertex3f(26, 18, -25.01);
    //1
    glVertex3f(-36, 23, -25.01);
    glVertex3f(-32, 23, -25.01);
    glVertex3f(-32, 21, -25.01);
    glVertex3f(-36.0, 21, -25.01);
    //2
    glVertex3f(-27, 23, -25.01);
    glVertex3f(-22, 23, -25.01);
    glVertex3f(-22, 21, -25.01);
    glVertex3f(-27.0, 21, -25.01);
    //3
    glVertex3f(-17, 23, -25.01);
    glVertex3f(-12, 23, -25.01);
    glVertex3f(-12, 21, -25.01);
    glVertex3f(-17.0, 21, -25.01);
    //4
    glVertex3f(-7, 23, -25.01);
    glVertex3f(-2, 23, -25.01);
    glVertex3f(-2, 21, -25.01);
    glVertex3f(-7.0, 21, -25.01);
    //5
    glVertex3f(3, 23, -25.01);
    glVertex3f(8, 23, -25.01);
    glVertex3f(8, 21, -25.01);
    glVertex3f(3.0, 21, -25.01);
    //7
    glVertex3f(26, 23, -25.01);
    glVertex3f(28, 23, -25.01);
    glVertex3f(28, 21, -25.01);
    glVertex3f(26, 21, -25.01);
    //8
    glVertex3f(33, 23, -25.01);
    glVertex3f(38, 23, -25.01);
    glVertex3f(38, 21, -25.01);
    glVertex3f(33, 21, -25.01);

    //belakang
    glVertex3f(-60, 21, -60.0);
    glVertex3f(65.8, 21, -60.0);
    glVertex3f(65.8, 18, -60.0);
    glVertex3f(-60, 18, -60);
    //1
    glVertex3f(-60, 23, -60.0);
    glVertex3f(-54, 23, -60.0);
    glVertex3f(-54, 21, -60.0);
    glVertex3f(-60.0, 21, -60);
    //2
    glVertex3f(-49, 23, -60.0);
    glVertex3f(-43, 23, -60.0);
    glVertex3f(-43, 21, -60.0);
    glVertex3f(-49.0, 21, -60);
    //3
    glVertex3f(-38, 23, -60.0);
    glVertex3f(-32, 23, -60.0);
    glVertex3f(-32, 21, -60.0);
    glVertex3f(-38.0, 21, -60);
    //4
    glVertex3f(-27, 23, -60.0);
    glVertex3f(-22, 23, -60.0);
    glVertex3f(-22, 21, -60.0);
    glVertex3f(-27.0, 21, -60);
    //5
    glVertex3f(-17, 23, -60.0);
    glVertex3f(-12, 23, -60.0);
    glVertex3f(-12, 21, -60.0);
    glVertex3f(-17.0, 21, -60);
    //6
    glVertex3f(-7, 23, -60.0);
    glVertex3f(-2, 23, -60.0);
    glVertex3f(-2, 21, -60.0);
    glVertex3f(-7.0, 21, -60);
    //7
    glVertex3f(3, 23, -60.0);
    glVertex3f(8, 23, -60.0);
    glVertex3f(8, 21, -60.0);
    glVertex3f(3.0, 21, -60);
    //8
    glVertex3f(13, 23, -60.0);
    glVertex3f(18, 23, -60.0);
    glVertex3f(18, 21, -60.0);
    glVertex3f(13, 21, -60);
    //9
    glVertex3f(23, 23, -60.0);
    glVertex3f(28, 23, -60.0);
    glVertex3f(28, 21, -60.0);
    glVertex3f(23, 21, -60);
    //10
    glVertex3f(33, 23, -60.0);
    glVertex3f(38, 23, -60.0);
    glVertex3f(38, 21, -60.0);
    glVertex3f(33, 21, -60);
    //11
    glVertex3f(43, 23, -60.0);
    glVertex3f(48, 23, -60.0);
    glVertex3f(48, 21, -60.0);
    glVertex3f(43, 21, -60);
    //12
    glVertex3f(53, 23, -60.0);
    glVertex3f(58, 23, -60.0);
    glVertex3f(58, 21, -60.0);
    glVertex3f(53, 21, -60);
    //13
    glVertex3f(63, 23, -60.0);
    glVertex3f(65.8, 23, -60.0);
    glVertex3f(65.8, 21, -60.0);
    glVertex3f(63, 21, -60);

    //samping
    //kiri
    glVertex3f(-60, 21, -30.0);
    glVertex3f(-60, 18, -30.0);
    glVertex3f(-60, 18, -60.0);
    glVertex3f(-60, 21, -60);
    //1
    glVertex3f(-60, 23, -55.0);
    glVertex3f(-60, 21, -55.0);
    glVertex3f(-60, 21, -60.0);
    glVertex3f(-60, 23, -60);
    //2
    glVertex3f(-60, 23, -45.0);
    glVertex3f(-60, 21, -45.0);
    glVertex3f(-60, 21, -50.0);
    glVertex3f(-60, 23, -50);
    //3
    glVertex3f(-60, 23, -35.0);
    glVertex3f(-60, 21, -35.0);
    glVertex3f(-60, 21, -40.0);
    glVertex3f(-60, 23, -40);


    //samping
    //kanan
    glVertex3f(65.8, 21, -30.0);
    glVertex3f(65.8, 18, -30.0);
    glVertex3f(65.8, 18, -60.0);
    glVertex3f(65.8, 21, -60);
    //1
    glVertex3f(65.8, 23, -55.0);
    glVertex3f(65.8, 21, -55.0);
    glVertex3f(65.8, 21, -60.0);
    glVertex3f(65.8, 23, -60);
    //2
    glVertex3f(65.8, 23, -45.0);
    glVertex3f(65.8, 21, -45.0);
    glVertex3f(65.8, 21, -50.0);
    glVertex3f(65.8, 23, -50);
    //3
    glVertex3f(65.8, 23, -35.0);
    glVertex3f(65.8, 21, -35.0);
    glVertex3f(65.8, 21, -40.0);
    glVertex3f(65.8, 23, -40);

glEnd();
    //garis list
glBegin(GL_LINES);// LINE LOOP
    glColor3ub(8, 8, 8);
    glVertex3f(-60,18.2,-60.0);
    glVertex3f(-60,18.2,-30);
    glVertex3f(-36, 18.2, -25.01);
    glVertex3f(10.8, 18.2, -25.01);
    glVertex3f(26, 18.2, -25.01);
    glVertex3f(40, 18.2, -25.01);
	glVertex3f(65.8, 18.2, -30);
    glVertex3f(65.8, 18.2, -60);
    glVertex3f(65.8, 18.2, -60);
    glVertex3f(-60, 18.2, -60);
glEnd();
}

void bangun3(){
		glBegin(GL_POLYGON); // BAWAH
		glColor3ub(2, 145, 36);
		glVertex3f(-35.8,-18,-11.0);
		glVertex3f(10.8,-18,-11.0);
		glVertex3f(10.8,-18,-25.0);
		glVertex3f(-35.8,-18,-25);
		glEnd();

		glBegin(GL_POLYGON); // ATAS
		glColor3ub(150, 150, 150);
		glVertex3f(-35.8,3,-11.0);
		glVertex3f(10.8,3,-11.0);
		glVertex3f(10.8,3,-25.0);
		glVertex3f(-35.8,3,-25);
		glEnd();

		glBegin(GL_POLYGON); // KANAN
		glColor3ub(2, 145, 36);
		glVertex3f(10.8,-18,-11.0);
		glVertex3f(10.8,-18,-25.0);
		glVertex3f(10.8,3,-25.0);
		glVertex3f(10.8,3,-11.0);
		glEnd();

		glBegin(GL_POLYGON); // KIRI
		glColor3ub(2, 145, 36);
		glVertex3f(-35.8,-18,-11.0);
		glVertex3f(-35.8,-18,-25.0);
		glVertex3f(-35.8,3,-25.0);
		glVertex3f(-35.8,3,-11.0);
		glEnd();

		glBegin(GL_POLYGON); // DEPAN
		glColor3ub(255, 145, 36);
		glVertex3f(-35.8,-18,-11.0);
		glVertex3f(-5.8,-18,-11.0);
		glVertex3f(-5.8,3,-11.0);
		glVertex3f(-35.8,3,-11.0);
		glEnd();

		glBegin(GL_POLYGON); // PINTU
		glColor3ub(255, 145, 36);
		glVertex3f(-5.8,-18,-11.0);
		glVertex3f(10.8,-18,-11.0);
		glVertex3f(10.8,9,-11.0);
		glVertex3f(-5.8,9,-11.0);
		glEnd();

		glBegin(GL_POLYGON); // PINTU
		glColor3ub(55, 45, 36);
		glVertex3f(-4,-18,-10.9);
		glVertex3f(8,-18,-10.9);
		glVertex3f(8,6,-10.9);
		glVertex3f(-4,6,-10.9);
		glEnd();

		//------------------------------------
		//kastil atas

			glPushMatrix();
			glTranslatef(24,-15.2,-25); //belakang
			castil();
			glPopMatrix();

			glPushMatrix();
			glTranslatef(34,-15.2,-25); //belakang
			castil();
			glPopMatrix();

			glPushMatrix();
			glTranslatef(44,-15.2,-25); //belakang
			castil();
			glPopMatrix();

			glPushMatrix();
			glTranslatef(54,-15.2,-25); //belakang
			castil();
			glPopMatrix();
			glPushMatrix();
			glTranslatef(64,-15.2,-25); //belakang
			castil();
			glPopMatrix();

				glPopMatrix();
				glPushMatrix();
				glTranslatef(24,-15.2,-11); //depan
				castil();
				glPopMatrix();

				glPushMatrix();
				glTranslatef(34,-15.2,-11); //depan
				castil();
				glPopMatrix();

				glPushMatrix();
				glTranslatef(44,-15.2,-11); //depan
				castil();
				glPopMatrix();

				glPushMatrix();
				glTranslatef(55,-9.2,-11); //depan
				castil();
				glPopMatrix();

				glPushMatrix();
				glTranslatef(65,-9.2,-11); //depan
				castil2();
				glPopMatrix();

	}

void bangun4(){

		glBegin(GL_POLYGON); // sisi BELAKANG
		glColor3ub(12, 15, 36);
		glVertex3f(10.8,-18,-18.0);
		glVertex3f(23,-18,-18.0);
		glVertex3f(23,16,-18.0);
		glVertex3f(10.8,16,-18.0);
		glEnd();
		glBegin(GL_POLYGON); // sisi BAWAH
		glColor3ub(122, 15, 36);
		glVertex3f(10.8,-18,-5.0);
		glVertex3f(23,-18,-5.0);
		glVertex3f(23,-18,-18.0);
		glVertex3f(10.8,-18,-18.0);
		glEnd();

		glBegin(GL_POLYGON); // sisi KIRI
		glColor3ub(255, 145, 36);
		glVertex3f(10.8,16,-18.0);
		glVertex3f(10.8,16,-5.0);
		glVertex3f(10.8,-18,-5.0);
		glVertex3f(10.8,-18,-18.0);
		glEnd();

		glBegin(GL_POLYGON); // sisi KANAN
		glColor3ub(255, 145, 36);
		glVertex3f(23,16,-18.0);
		glVertex3f(23,16,-5.0);
		glVertex3f(23,-18,-5.0);
		glVertex3f(23,-18,-18.0);
		glEnd();

		glBegin(GL_POLYGON); // sisi ATAS
		glColor3ub(150, 150, 150);
		glVertex3f(10.8,16,-5.0);
		glVertex3f(23,16,-5.0);
		glVertex3f(23,16,-18.0);
		glVertex3f(10.8,16,-18.0);
		glEnd();

		glBegin(GL_POLYGON); // sisi DEPAN
		glColor3ub(255, 145, 36);
		glVertex3f(10.8,-18,-5.0);
		glVertex3f(23,-18,-5.0);
		glVertex3f(23,16,-5.0);
		glVertex3f(10.8,16,-5.0);
		glEnd();
		//------------------------------------
		//kastil atas
		glBegin(GL_LINE_LOOP); // sisi ATAS
		glColor3ub(8,8,8);
		glVertex3f(10.8,16,-5.0);
		glVertex3f(23,16,-5.0);
		glVertex3f(23,16,-18.0);
		glVertex3f(10.8,16,-18.0);
		glEnd();
				glPushMatrix();
				glTranslatef(71.5,-2,-5); //depan
				castil();
				glPopMatrix();
        }

void bangun6(){

    glBegin(GL_POLYGON); // BAWAH
		glColor3ub(2, 145, 36);
		glVertex3f(65.8,-18,-11.0);
		glVertex3f(22.8,-18,-11.0);
		glVertex3f(22.8,-18,-25.0);
		glVertex3f(65.8,-18,-25);
		glEnd();

		glBegin(GL_POLYGON); // ATAS
		glColor3ub(150, 150, 150);
		glVertex3f(65.8,3,-11.0);
		glVertex3f(22.8,3,-11.0);
		glVertex3f(22.8,3,-25.0);
		glVertex3f(65.8,3,-25);
		glEnd();

		glBegin(GL_POLYGON); // KANAN
		glColor3ub(2, 145, 36);
		glVertex3f(65.8,-18,-11.0);
		glVertex3f(22.8,-18,-25.0);
		glVertex3f(22.8,3,-25.0);
		glVertex3f(65.8,3,-11.0);
		glEnd();

		glBegin(GL_POLYGON); // KIRI
		glColor3ub(255, 145, 36);
		glVertex3f(65.8,-18,-11.0);
		glVertex3f(65.8,-18,-25.0);
		glVertex3f(65.8,3,-25.0);
		glVertex3f(65.8,3,-11.0);
		glEnd();

		glBegin(GL_POLYGON); // DEPAN
		glColor3ub(255, 145, 36);
		glVertex3f(65.8,-18,-11.0);
		glVertex3f(22.8,-18,-11.0);
		glVertex3f(22.8,3,-11.0);
		glVertex3f(65.8,3,-11.0);
		glEnd();



		//------------------------------------
		//kastil atas

			glPushMatrix();
			glTranslatef(83,-15.2,-25); //belakang
			castil();
			glPopMatrix();

			glPushMatrix();
			glTranslatef(93,-15.2,-25); //belakang
			castil();
			glPopMatrix();

			glPushMatrix();
			glTranslatef(103,-15.2,-25); //belakang
			castil();
			glPopMatrix();

			glPushMatrix();
			glTranslatef(113,-15.2,-25); //belakang
			castil();
			glPopMatrix();
			glPushMatrix();
			glTranslatef(115,-15.2,-25); //belakang
			castil();
			glPopMatrix();

				glPopMatrix();
				glPushMatrix();
				glTranslatef(83,-15.2,-11); //depan
				castil();
				glPopMatrix();

				glPushMatrix();
				glTranslatef(93,-15.2,-11); //depan
				castil();
				glPopMatrix();

				glPushMatrix();
				glTranslatef(103,-15.2,-11); //depan
				castil();
				glPopMatrix();

				glPushMatrix();
				glTranslatef(113,-15.2,-11); //depan
				castil();
				glPopMatrix();

				glPushMatrix();
				glTranslatef(121,-15.2,-11); //depan
				castil2();
				glPopMatrix();

    }

void bangun5(){
		glBegin(GL_POLYGON); // bawah
		glColor3ub(255, 145, 36);
		glVertex3f(10.8,-18,-18.0);
		glVertex3f(26,-18,-18);
		glVertex3f(26,-18,-30);
		glVertex3f(10.8,-18,-30);
		glEnd();

		glBegin(GL_POLYGON); // atas
		glColor3ub(150, 150, 150);
		glVertex3f(10.8,24,-18.0);
		glVertex3f(26,24,-18);
		glVertex3f(26,24,-30);
		glVertex3f(10.8,24,-30);
		glEnd();

		glBegin(GL_POLYGON); // depan
		glColor3ub(255, 145, 36);
		glVertex3f(10.8,-18,-18.0);
		glVertex3f(26,-18,-18);
		glVertex3f(26,24,-18);
		glVertex3f(10.8,24,-18.0);
		glEnd();

		glBegin(GL_POLYGON); // belakang
		glColor3ub(255, 145, 36);
		glVertex3f(10.8,-18,-30.0);
		glVertex3f(26,-18,-30);
		glVertex3f(26,24,-30);
		glVertex3f(10.8,24,-30.0);
		glEnd();

		glBegin(GL_POLYGON); // kiri
		glColor3ub(255, 145, 36);
		glVertex3f(10.8,-18,-30);
		glVertex3f(10.8,-18,-18);
		glVertex3f(10.8,24,-18);
		glVertex3f(10.8,24,-30);
		glEnd();

		glBegin(GL_POLYGON); // kanan
		glColor3ub(255, 145, 36);
		glVertex3f(26,-18,-30);
		glVertex3f(26,-18,-18);
		glVertex3f(26,24,-18);
		glVertex3f(26,24,-30);
		glEnd();

		//kastil atas
		glBegin(GL_LINE_LOOP); // atas
		glColor3ub(8, 8, 8);
		glVertex3f(10.8,24,-18.0);
		glVertex3f(26,24,-18);
		glVertex3f(26,24,-30);
		glVertex3f(10.8,24,-30);
		glEnd();

			//depan
				glPushMatrix();
				glTranslatef(71,6,-18); //1
				castil2();
				glPopMatrix();
				glPushMatrix();
				glTranslatef(71,6,-18); //2
				castil1();
				glPopMatrix();
				glPushMatrix();
				glTranslatef(81,6,-18); //3
				castil2();
				glPopMatrix();
			//belakang
				glPushMatrix();
				glTranslatef(71,6,-30); //1
				castil2();
				glPopMatrix();
				glPushMatrix();
				glTranslatef(71,6,-30); //2
				castil1();
				glPopMatrix();
				glPushMatrix();
				glTranslatef(81,6,-30); //3
				castil2();
				glPopMatrix();
	}

void bangun7(){
        glBegin(GL_POLYGON); // bawah
		glColor3ub(255, 145, 36);
		glVertex3f(65.8,-18,-18.0);
		glVertex3f(40,-18,-18);
		glVertex3f(40,-18,-30);
		glVertex3f(65.8,-18,-30);
		glEnd();

		glBegin(GL_POLYGON); // atas
		glColor3ub(150, 150, 150);
		glVertex3f(65.8,24,-18.0);
		glVertex3f(40,24,-18);
		glVertex3f(40,24,-30);
		glVertex3f(65.8,24,-30);
		glEnd();

		glBegin(GL_POLYGON); // depan
		glColor3ub(255, 145, 36);
		glVertex3f(65.8,-18,-18.0);
		glVertex3f(40,-18,-18);
		glVertex3f(40,24,-18);
		glVertex3f(65.8,24,-18.0);
		glEnd();

		glBegin(GL_POLYGON); // belakang
		glColor3ub(255, 145, 36);
		glVertex3f(65.8,-18,-30.0);
		glVertex3f(40,-18,-30);
		glVertex3f(40,24,-30);
		glVertex3f(65.8,24,-30.0);
		glEnd();

		glBegin(GL_POLYGON); // kiri
		glColor3ub(255, 145, 36);
		glVertex3f(65.8,-18,-30);
		glVertex3f(65.8,-18,-18);
		glVertex3f(65.8,24,-18);
		glVertex3f(65.8,24,-30);
		glEnd();

		glBegin(GL_POLYGON); // kanan
		glColor3ub(255, 145, 36);
		glVertex3f(40,-18,-30);
		glVertex3f(40,-18,-18);
		glVertex3f(40,24,-18);
		glVertex3f(40,24,-30);
		glEnd();

		//kastil atas
		glBegin(GL_LINE_LOOP); // atas
		glColor3ub(8, 8, 8);
		glVertex3f(65.8,24,-18.0);
		glVertex3f(40,24,-18);
		glVertex3f(40,24,-30);
		glVertex3f(65.8,24,-30);
		glEnd();

			//depan
				glPushMatrix();
				glTranslatef(100,6,-18); //1
				castil2();
				glPopMatrix();
				glPushMatrix();
				glTranslatef(100,6,-18); //2
				castil1();
				glPopMatrix();
				glPushMatrix();
				glTranslatef(110,6,-18); //3
				castil2();
				glPopMatrix();
				glPushMatrix();
				glTranslatef(110,6,-18); //1
				castil2();
				glPopMatrix();
				glPushMatrix();
				glTranslatef(110,6,-18); //2
				castil1();
				glPopMatrix();
				glPushMatrix();
				glTranslatef(120,6,-18); //3
				castil2();
				glPopMatrix();
			//belakang
				glPushMatrix();
				glTranslatef(100,6,-30); //1
				castil2();
				glPopMatrix();
				glPushMatrix();
				glTranslatef(100,6,-30); //2
				castil1();
				glPopMatrix();
				glPushMatrix();
				glTranslatef(110,6,-30); //3
				castil2();
				glPopMatrix();
				glPushMatrix();
				glTranslatef(110,6,-30); //1
				castil2();
				glPopMatrix();
				glPushMatrix();
				glTranslatef(110,6,-30); //2
				castil1();
				glPopMatrix();
				glPushMatrix();
				glTranslatef(120,6,-30); //3
				castil2();
				glPopMatrix();

	}

void bangku (){
glBegin(GL_QUADS);
 //sofa
    glColor3f(1.0,0.0,0.0);
    glVertex3f(-20.0, -7.0, -19.995);// sofa belakang
	glVertex3f(-20.0, 0.0, -19.995);
	glVertex3f(15.0, 0.0, -19.995);
    glVertex3f(15.0,-7.0, -19.995);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(-20.0, -6.5, -19.495);// sofa belakang 2
    glColor3f(1.0,0.0,0.0);
	glVertex3f(-20.0, 0.0, -19.495);
	glVertex3f(15.0, 0.0, -19.495);
	glColor3f(0.0,0.0,0.0);
    glVertex3f(15.0,-6.5, -19.495);
    //tutup atas
    glColor3f(1.0,1.0,1.0);
    glVertex3f(-20, 0, -19.995);//alas bawah
	glVertex3f( 15, 0, -19.995);
	glVertex3f( 15, 0, -19.495);
	glVertex3f(-20, 0, -19.495);
    glColor3f(1.0,0.0,0.0);
    //alas
    glVertex3f(-20, -7, -19.995);//alas bawah
	glVertex3f( 15, -7, -19.995);
	glVertex3f( 15, -7, -13.0);
	glVertex3f(-20, -7, -13.0);
	glVertex3f(-20, -6.5, -19.495);// alas atas
	glVertex3f( 15, -6.5, -19.495);
	glVertex3f( 15, -6.5, -13.0);
	glVertex3f(-20, -6.5, -13.0);

    //tutup alas
    glColor3f(1.0,1.0,1.0);
	glVertex3f(-20, -7.0, -13);// tutup alas depan
	glVertex3f(-20, -6.5, -13);
	glVertex3f(15, -6.5, -13);
    glVertex3f(15, -7.0, -13);
    glVertex3f(15.0, -7.0, -20);// tutup alas depan kiri
	glVertex3f(15.0, -6.5, -20);
	glVertex3f(15.0, -6.5, -13);
    glVertex3f(15.0, -7.0, -13);
    glVertex3f(-20, -7.0, -20);// tutup alas depan kanan
	glVertex3f(-20, -6.5, -20);
	glVertex3f(-20, -6.5, -13);
    glVertex3f(-20, -7.0, -13);

    glColor3f(1.0,0.0,0.0);
    glVertex3f(-20.0, -10.0, -19.995);// sofa kaki kiri
	glVertex3f(-20.0, -7.0, -19.995);
	glVertex3f(-19.5, -7.0, -19.995);
    glVertex3f(-19.5, -10.0, -19.995);
    glVertex3f(-20.0, -10.0, -19.495);// sofa kaki kiri 2
	glVertex3f(-20.0, -7.0, -19.495);
	glVertex3f(-19.5, -7.0, -19.495);
    glVertex3f(-19.5, -10.0, -19.495);
    glVertex3f(-20.0, -10.0, -19.995);// sofa kaki kiri samping + tutup
	glVertex3f(-20.0, 0.0, -19.995);
	glVertex3f(-20.0, 0.0, -19.495);
    glVertex3f(-20.0, -10.0, -19.495);
    glVertex3f(-19.5, -10.0, -19.995);// sofa kaki kiri samping 2
	glVertex3f(-19.5, -7.0, -19.995);
	glVertex3f(-19.5, -7.0, -19.495);
    glVertex3f(-19.5, -10.0, -19.495);

    glVertex3f(14.5, -10.0, -19.995);// sofa kaki kanan
	glVertex3f(14.5, -7.0, -19.995);
	glVertex3f(15, -7.0, -19.995);
    glVertex3f(15, -10.0, -19.995);
    glVertex3f(14.5, -10.0, -19.495);// sofa kaki kanan 2
	glVertex3f(14.5, -7.0, -19.495);
	glVertex3f(15, -7.0, -19.495);
    glVertex3f(15, -10.0, -19.495);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(15.0, -10.0, -19.995);// sofa kaki kanan samping +tutup
	glVertex3f(15.0, 0.0, -19.995);
	glVertex3f(15.0, 0.0, -19.495);
    glVertex3f(15.0, -10.0, -19.495);
    glVertex3f(14.5, -10.0, -19.995);// sofa kaki kanan samping 2
	glVertex3f(14.5, -7.0, -19.995);
	glVertex3f(14.5, -7.0, -19.495);
    glVertex3f(14.5, -10.0, -19.495);

    //depan
    glVertex3f(-20.0, -10.0, -13);// sofa kaki kiri
	glVertex3f(-20.0, -4.0, -13);
	glVertex3f(-19.5, -4.0, -13);
    glVertex3f(-19.5, -10.0, -13);
    glVertex3f(-20.0, -10.0, -13.5);// sofa kaki kiri 2
	glVertex3f(-20.0, -4.0, -13.5);
	glVertex3f(-19.5, -4.0, -13.5);
    glVertex3f(-19.5, -10.0, -13.5);
    glVertex3f(-20.0, -10.0, -13.5);// sofa kaki kiri samping
	glVertex3f(-20.0, -4.0, -13.5);
	glVertex3f(-20.0, -4.0, -13);
    glVertex3f(-20.0, -10.0, -13);
    glVertex3f(-19.5, -10.0, -13.5);// sofa kaki kiri samping 2
	glVertex3f(-19.5, -4.0, -13.5);
	glVertex3f(-19.5, -4.0, -13);
    glVertex3f(-19.5, -10.0, -13);

    glVertex3f(14.5, -10.0, -13);// sofa kaki kanan
	glVertex3f(14.5, -4.0, -13);
	glVertex3f(15, -4.0, -13);
    glVertex3f(15, -10.0, -13);
    glVertex3f(14.5, -10.0, -13.5);// sofa kaki kanan 2
	glVertex3f(14.5, -4.0, -13.5);
	glVertex3f(15, -4.0, -13.5);
    glVertex3f(15, -10.0, -13.5);
    glVertex3f(15.0, -10.0, -13.5);// sofa kaki kanan samping
	glVertex3f(15.0, -4.0, -13.5);
	glVertex3f(15.0, -4.0, -13);
    glVertex3f(15.0, -10.0, -13);
    glVertex3f(14.5, -10.0, -13.5);// sofa kaki kanan samping 2
	glVertex3f(14.5, -4.0, -13.5);
	glVertex3f(14.5, -4.0, -13);
    glVertex3f(14.5, -10.0, -13);

    //pagar
    glVertex3f( -19.5, -4, -19.995);// alas atas
	glVertex3f( -20, -4, -19.995);
	glVertex3f( -20, -4, -13.0);
	glVertex3f( -19.5, -4, -13.0);
	glVertex3f( -19.5, -3.5, -19.995);// alas atas
	glVertex3f( -20, -3.5, -19.995);
	glVertex3f( -20, -3.5, -13.0);
	glVertex3f( -19.5, -3.5, -13.0);
    glVertex3f( -20, -4.0, -19.995);// tutup alas depan kanan
	glVertex3f( -20, -3.5, -19.995);
	glVertex3f( -20, -3.5, -13);
    glVertex3f( -20, -4.0, -13);
    glVertex3f( -19.5, -4.0, -19.995);// tutup alas depan kanan 2
	glVertex3f( -19.5, -3.5, -19.995);
	glVertex3f( -19.5, -3.5, -13);
    glVertex3f( -19.5, -4.0, -13);

    glVertex3f( 14.5, -4, -19.995);// alas atas
	glVertex3f( 15, -4, -19.995);
	glVertex3f( 15, -4, -13.0);
	glVertex3f( 14.5, -4, -13.0);
	glVertex3f( 14.5, -3.5, -19.995);// alas atas
	glVertex3f( 15, -3.5, -19.995);
	glVertex3f( 15, -3.5, -13.0);
	glVertex3f( 14.5, -3.5, -13.0);
    glVertex3f( 15, -4.0, -19.995);// tutup alas depan kanan
	glVertex3f( 15, -3.5, -19.995);
	glVertex3f( 15, -3.5, -13);
    glVertex3f( 15, -4.0, -13);
    glVertex3f( 14.5, -4.0, -19.995);// tutup alas depan kanan 2
	glVertex3f( 14.5, -3.5, -19.995);
	glVertex3f( 14.5, -3.5, -13);
    glVertex3f( 14.5, -4.0, -13);

glEnd();
}

void meja(void){
glBegin(GL_QUADS);
    glColor3f(0.0,0.0,1.0);
    glVertex3f( -5, 5, -40);// meja atas
	glVertex3f( 25, 5, -40);
	glVertex3f( 25, 5, 0);
	glVertex3f( -5, 5, 0);
    glVertex3f( -5, 3, -40);// meja atas 2
	glVertex3f( 25, 3, -40);
	glVertex3f( 25, 3, 0);
	glVertex3f( -5, 3 , 0);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(-5, 3.0, 0);// tutup meja depan
	glVertex3f(-5, 5, 0);
	glVertex3f(25, 5, 0);
    glVertex3f(25, 3.0, 0);
    glVertex3f(-5, 3.0, -40);// tutup meja belakang
	glVertex3f(-5, 5, -40);
	glVertex3f(25, 5, -40);
    glVertex3f(25, 3.0, -40);
    glVertex3f( -5, 3.0, -40);// tutup meja kiri
	glVertex3f( -5, 5, -40);
	glVertex3f( -5, 5, 0);
    glVertex3f( -5, 3.0, 0);
    glVertex3f( 25, 3.0, -40);// tutup meja kanan
	glVertex3f( 25, 5, -40);
	glVertex3f( 25, 5, 0);
    glVertex3f( 25, 3.0, 0);

    glColor3f(0.0,1.0,1.0);
    glVertex3f(24, -10.0, -39);// meja kaki Belakang
	glVertex3f(24, 3, -39);
	glVertex3f(25, 3, -39);
    glVertex3f(25, -10.0, -39);
    glVertex3f(24, -10.0, -40);// meja kaki Depan
	glVertex3f(24, 3, -40);
	glVertex3f(25, 3, -40);
    glVertex3f(25, -10.0, -40);
    glVertex3f(25.0, -10.0, -40);// meja kaki kanan samping
	glVertex3f(25.0, 3, -40);
	glVertex3f(25.0, 3, -39);
    glVertex3f(25.0, -10.0, -39);
    glVertex3f(24, -10.0, -40);// meja kaki kanan samping 2
	glVertex3f(24, 3, -40);
	glVertex3f(24, 3, -39);
    glVertex3f(24, -10.0, -39);

    glColor3f(0.0,1.0,1.0);
    glVertex3f(-4, -10.0, -39);// meja kaki kanan
	glVertex3f(-4, 3, -39);
	glVertex3f(-5, 3, -39);
    glVertex3f(-5, -10.0, -39);
    glVertex3f(-4, -10.0, -40);// meja kaki kanan 2
	glVertex3f(-4, 3, -40);
	glVertex3f(-5, 3, -40);
    glVertex3f(-5, -10.0, -40);
    glVertex3f(-5.0, -10.0, -40);// meja kaki kanan samping
	glVertex3f(-5.0, 3, -40);
	glVertex3f(-5.0, 3, -39);
    glVertex3f(-5.0, -10.0, -39);
    glVertex3f(-4, -10.0, -40);// meja kaki kanan samping 2
	glVertex3f(-4, 3, -40);
	glVertex3f(-4, 3, -39);
    glVertex3f(-4, -10.0, -39);

    //depan
    glVertex3f(24, -10.0, 0);// meja kaki kanan
	glVertex3f(24, 3, 0);
	glVertex3f(25, 3, 0);
    glVertex3f(25, -10.0, 0);
    glVertex3f(24, -10.0, -1);// meja kaki kanan 2
	glVertex3f(24, 3, -1);
	glVertex3f(25, 3, -1);
    glVertex3f(25, -10.0, -1);
    glVertex3f(25.0, -10.0, -1);// meja kaki kanan samping
	glVertex3f(25.0, 3, -1);
	glVertex3f(25.0, 3, 0);
    glVertex3f(25.0, -10.0, 0);
    glVertex3f(24, -10.0, -1);// meja kaki kanan samping 2
	glVertex3f(24, 3, -1);
	glVertex3f(24, 3, 0);
    glVertex3f(24, -10.0, 0);

    glVertex3f(-4, -10.0, 0);// meja kaki kanan
	glVertex3f(-4, 3, 0);
	glVertex3f(-5, 3, 0);
    glVertex3f(-5, -10.0, 0);
    glVertex3f(-4, -10.0, -1);// meja kaki kanan 2
	glVertex3f(-4, 3, -1);
	glVertex3f(-5, 3, -1);
    glVertex3f(-5, -10.0, -1);
    glVertex3f(-5.0, -10.0, -1);// meja kaki kanan samping
	glVertex3f(-5.0, 3, -1);
	glVertex3f(-5.0, 3, 0);
    glVertex3f(-5.0, -10.0, 0);
    glVertex3f(-4, -10.0, -1);// meja kaki kanan samping 2
	glVertex3f(-4, 3, -1);
	glVertex3f(-4, 3, 0);
    glVertex3f(-4, -10.0, 0);

    //bawah list meja
    //depan
    glColor3f(0.0,0.0,1.0);
    glVertex3f(-5, -8, 0);// tutup meja depan
	glVertex3f(-5, -7, 0);
	glVertex3f(25, -7, 0);
    glVertex3f(25, -8, 0);
    glVertex3f(-5, -8, -1);// tutup meja depan 2
	glVertex3f(-5, -7, -1);
	glVertex3f(25, -7, -1);
    glVertex3f(25, -8, -1);
    glVertex3f( -5, -7, -1);// tutup meja bawah
	glVertex3f( 25, -7, -1);
	glVertex3f( 25, -7, 0);
	glVertex3f( -5, -7, 0);
    glVertex3f( -5, -8, -1);// tutup meja bawah
	glVertex3f( 25, -8, -1);
	glVertex3f( 25, -8, 0);
	glVertex3f( -5, -8, 0);

	//belakang
    glVertex3f(-5, -8, -39);// tutup meja depan
	glVertex3f(-5, -7, -39);
	glVertex3f(25, -7, -39);
    glVertex3f(25, -8, -39);
    glVertex3f(-5, -8, -40);// tutup meja depan 2
	glVertex3f(-5, -7, -40);
	glVertex3f(25, -7, -40);
    glVertex3f(25, -8, -40);
    glVertex3f( -5, -7, -40);// tutup meja atas
	glVertex3f( 25, -7, -40);
	glVertex3f( 25, -7, -39);
	glVertex3f( -5, -7, -39);
    glVertex3f( -5, -8, -40);// tutup meja bawah
	glVertex3f( 25, -8, -40);
	glVertex3f( -5, -8, -39);
	glVertex3f( 25, -8, -39);

    //tutup
    //samping
    glVertex3f(11, -8, -40);// tutup kaki kiri samping
	glVertex3f(11, -7.0, -40);
	glVertex3f(11, -7.0, 0);
    glVertex3f(11, -8, 0);
    glVertex3f(9, -8, -40);// tutup kaki kiri samping 2
	glVertex3f(9, -7.0, -40);
	glVertex3f(9, -7.0, 0);
    glVertex3f(9, -8, 0);
    glVertex3f( 11, -7, -40);// tutup meja atas
	glVertex3f( 9, -7, -40);
	glVertex3f( 9, -7, 0);
	glVertex3f( 11, -7, 0);
    glVertex3f( 11, -8, -40);// tutup meja atas 2
	glVertex3f( 9, -8, -40);
	glVertex3f( 9, -8, 0);
	glVertex3f( 11, -8, 0);


	//jari jari
	//kiri 1
	glVertex3f(-5, 3, -5);// tutup kaki kiri samping
	glVertex3f(-5, 3.0, -5);
	glVertex3f(-5, 0.0, -1);
    glVertex3f(-5, 3, -1);
    glVertex3f(-4, 3, -5);// tutup kaki kiri samping 2
	glVertex3f(-4, 3, -5);
	glVertex3f(-4, 0, -1);
    glVertex3f(-4, 3, -1);
    glVertex3f( -5, 3, -5);// tutup bawah
	glVertex3f( -4, 3, -5);
	glVertex3f( -4, 0, -1);
	glVertex3f( -5, 0, -1);
	//kiri2
	glVertex3f(-1, 3, 0);// tutup kiri samping
	glVertex3f(-4, 0, 0);
	glVertex3f(-4, 0, 0);
    glVertex3f(-4, 3, 0);
    glVertex3f(-1, 3, -1);// tutup kiri samping 2
	glVertex3f(-4, 0, -1);
	glVertex3f(-4, 0, -1);
    glVertex3f(-4, 3, -1);
    glVertex3f(-1, 3, -1);// tutup bawah
	glVertex3f(-4, 0, -1);
	glVertex3f(-4, 0, 0);
    glVertex3f(-1, 3, 0);
	//kanan 1
	glVertex3f(25, 3, -5);// tutup kaki kanan samping
	glVertex3f(25, 3, -5);
	glVertex3f(25, 0, -1);
    glVertex3f(25, 3, -1);
    glVertex3f(24, 3, -5);// tutup kaki kanan samping 2
	glVertex3f(24, 3, -5);
	glVertex3f(24, 0, -1);
    glVertex3f(24, 3, -1);
    glVertex3f( 25, 3, -5);// tutup bawah
	glVertex3f( 24, 3, -5);
	glVertex3f( 24, 0, -1);
	glVertex3f( 25, 0, -1);
	//kanan2
	glVertex3f(21, 3, 0);// tutup kiri samping
	glVertex3f(24, 0, 0);
	glVertex3f(24, 0, 0);
    glVertex3f(24, 3, 0);
    glVertex3f(21, 3, -1);// tutup kiri samping 2
	glVertex3f(24, 0, -1);
	glVertex3f(24, 0, -1);
    glVertex3f(24, 3, -1);
    glVertex3f(21, 3, -1);// tutup bawah
	glVertex3f(24, 0, -1);
	glVertex3f(24, 0, 0);
    glVertex3f(21, 3, 0);


	//belakang
    //kiri1
    glVertex3f(-5, 3, -39);// tutup kaki kiri samping
	glVertex3f(-5, 0.0, -39);
	glVertex3f(-5, 3.0, -36);
    glVertex3f(-5, 3, -36);
    glVertex3f(-4, 3, -39);// tutup kaki kiri samping 2
	glVertex3f(-4, 0, -39);
	glVertex3f(-4, 3, -36);
    glVertex3f(-4, 3, -36);
    glVertex3f( -5, 3, -36);// tutup bawah
	glVertex3f( -4, 3, -36);
	glVertex3f( -4, 0, -39);
	glVertex3f( -5, 0, -39);
	//kiri2
	glVertex3f(-1, 3, -39);// tutup kiri samping
	glVertex3f(-4, 0, -39);
	glVertex3f(-4, 0, -39);
    glVertex3f(-4, 3, -39);
    glVertex3f(-1, 3, -40);// tutup kiri samping 2
	glVertex3f(-4, 0, -40);
	glVertex3f(-4, 0, -40);
    glVertex3f(-4, 3, -40);
    glVertex3f(-1, 3, -40);// tutup bawah
	glVertex3f(-4, 0, -40);
	glVertex3f(-4, 0, -39);
    glVertex3f(-1, 3, -39);
	//kanan1
    glVertex3f(25, 3, -39);// tutup kaki kiri samping
	glVertex3f(25, 0.0, -39);
	glVertex3f(25, 3.0, -36);
    glVertex3f(25, 3, -36);
    glVertex3f(24, 3, -39);// tutup kaki kiri samping 2
	glVertex3f(24, 0, -39);
	glVertex3f(24, 3, -36);
    glVertex3f(24, 3, -36);
    glVertex3f( 25, 3, -36);// tutup bawah
	glVertex3f( 24, 3, -36);
	glVertex3f( 24, 0, -39);
	glVertex3f( 25, 0, -39);
	//kanan2
	glVertex3f(21, 3, -39);// tutup kiri samping
	glVertex3f(24, 0, -39);
	glVertex3f(24, 0, -39);
    glVertex3f(24, 3, -39);
    glVertex3f(21, 3, -40);// tutup kiri samping 2
	glVertex3f(24, 0, -40);
	glVertex3f(24, 0, -40);
    glVertex3f(24, 3, -40);
    glVertex3f(21, 3, -40);// tutup bawah
	glVertex3f(24, 0, -40);
	glVertex3f(24, 0, -39);
    glVertex3f(21, 3, -39);
 glEnd();
}

void tampil(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glTranslatef(xpos, ypos, zpos);
	glRotatef(xrot + 10, 1.0f, 0.0f, 0.0f);
	glRotatef(yrot - 10, 0.0f, 1.0f, 0.0f);

    bangun1();
	bangun2();
	bangun3();
	bangun4();
	bangun6();
	bangun5();
	bangun7();
	tanah();
		glPushMatrix();
		glTranslatef(-40,0,10); //1
		tiang();
		glTranslatef(20,0,0);
		mading();
		papantulis();
		//----//
        glPushMatrix();
        glScalef(0.4f, 0.4f, 0.6f);
        glTranslatef(-8,-35,40);
        meja();
        glTranslatef(150,0,0);
        meja();
        //kiri
        glScalef(1.8f, 1.9f, 1);
        glTranslatef(-81.8,5,-17);
        glRotatef(90, 0,-10,0);
        bangku();
        glTranslatef(-5,0,-8);
        glRotatef(-180, 0,-10,0);
        bangku();
        //kanan
        glTranslatef(0,0,83);
        bangku();
        glRotatef(-180, 0,-10,0);
        glTranslatef(5,0,7);
        bangku();
        glPopMatrix();
        //----///
		glPopMatrix();
			//jendela gedung 1
			glPushMatrix();
			glTranslatef(-67,0,-12); //jendela atas1
			jendela();
			glPopMatrix();
			glPushMatrix();
			glTranslatef(-57,0,-12); //jendela atas2
			jendela();
			glPopMatrix();
			glPushMatrix();
			glTranslatef(-67,-12,-12); //jendela bawah1
			jendela();
			glPopMatrix();
			glPushMatrix();
			glTranslatef(-57,-12,-12); //jendela bawah1
			jendela();
			glPopMatrix();

			//jendela gedung 2
			glPushMatrix();
			glTranslatef(-44,-12,-23); //jendela bawah1
			jendela();
			glPopMatrix();
			glPushMatrix();
			glTranslatef(-34,-12,-23); //jendela bawah1
			jendela();
			glPopMatrix();
			glPushMatrix();
			glTranslatef(-24,-12,-23); //jendela bawah1
			jendela();
			glPopMatrix();
			//belakang
			glPushMatrix();
			glTranslatef(-24, 1.5,-37.2); //jendela bawah1
			jendela();
			glTranslatef(10, 0, 0); //jendela bawah1
			jendela();
			glTranslatef(-20, 0, 0); //jendela bawah1
			jendela();
			glTranslatef(-10, 0, 0); //jendela bawah1
			jendela();
            glPopMatrix();

			//jendela gedung ...
			glPushMatrix();
			glTranslatef(17,-12,-23); //jendela bawah1
			jendela();
			glPopMatrix();
			glPushMatrix();
			glTranslatef(27,-12,-23); //jendela bawah1
			jendela();
			glPopMatrix();
			glPushMatrix();
			glTranslatef(37,-12,-23); //jendela bawah1
			jendela();
			glPopMatrix();
			glPushMatrix();
			glTranslatef(47,-12,-23); //jendela bawah1
			jendela();
			glPopMatrix();

			//jendela gedung ...
			glPushMatrix();
			glTranslatef(32,6,-30); //jendela bawah1
			jendela();
			glPopMatrix();
			glPushMatrix();
			glTranslatef(40,6,-30); //jendela bawah1
			jendela();
			glPopMatrix();
			glPushMatrix();
			glTranslatef(48,6,-30); //jendela bawah1
			jendela();
			glPopMatrix();

			//jendela gedung ...
			glPushMatrix();
			glTranslatef(4,0,-17); //jendela bawah1
			jendela();
			glPopMatrix();
			glPushMatrix();
			glTranslatef(4,-12,-17); //jendela bawah1
			jendela();
			glPopMatrix();
			glPushMatrix();
			glTranslatef(48,6,-30); //jendela bawah1
			jendela();
			glPopMatrix();


	//----------------------------------------


    glutSwapBuffers();


}

void keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
		case 'w':
		case 'W':
		zpos += 3.0;
		glTranslatef(0.0, 0.0, 3.0);
		break;
		case 'd':
		case 'D':
		xpos += 3.0;
		glTranslatef(3.0, 0.0, 0.0);
		break;
		case 's':
		case 'S':
		zpos += -3.0;
		glTranslatef(0.0, 0.0, -3.0);
		break;
		case 'a':
		case 'A':
		xpos += -3.0;
		glTranslatef(-3.0, 0.0, 0.0);
		break;
		case 'q':
		case 'Q':
		xpos = 0.0f;
        ypos = 0.0f;
        zpos = 0.0f;
		glTranslatef(0.0, 0.0, 0.0);
		break;
		case '5':
		if (is_depth)
		{
			is_depth =0;
			glDisable(GL_DEPTH_TEST);
		} else
		{
			is_depth=1;
			glEnable(GL_DEPTH_TEST);
		}
		break;
	}
	tampil();
}

/*void idle()
{
	if (!mouseDown)
	{
		xrot += 0.3f;
		yrot += 0.4f;
	}
	glutPostRedisplay();
}*/

void mouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		mouseDown = true;
		xdiff = x - yrot;
		ydiff = -y + xrot;
	}
	else
	mouseDown = false;
}

void mouseMotion(int x, int y)
{

	if (mouseDown)
	{
		yrot = x - xdiff;
		xrot = y + ydiff;

	glutPostRedisplay();

	}
}

void ukuran(int lebar, int tinggi)
{
	if (tinggi == 0) tinggi = 1;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(50.0, lebar / tinggi, 5.0, 500.0);
	glTranslatef(0.0, -5.0, -150.0);
	glMatrixMode(GL_MODELVIEW);
}
