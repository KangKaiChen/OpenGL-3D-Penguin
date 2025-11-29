#include <gl/glut.h>
#include <iostream>
#include"SMFLoader.h"
#include<cmath>
#include <Windows.h>
#define SOLID 1
#define WIRE 2
#define PI 3.141592

using namespace std;
SMFLoader loader;   //(2) declare SMFLoader
char filename[] = "rubber_duck.smf", ALL;	//鴨鴨SMF檔
float red, green, blue;	//RGB
void cubelight(float, float, float);
static float c = PI / 180.0f; //弧度和角度转换参数
bool mousetate = false;
static int du = 90, Oldy = -1, Oldx = -1, state = 0; //du是视点绕y轴的角度,opengl里默认y轴是上方向
static float r = 2.0f, h = 20.0f, spin, spin1, Lspin, lspin, Rspin, rspin, lhspin, rhspin, tx, zshift, xshift, shift, xRotate, yRotate = 0.0, spin2 = 0;
static float Xshift = -380, Zshift = 0, mode = SOLID, spot_red = 1.0f, spot_green = 1.0f, spot_blue = 1.0f, light_x = 0.0f, light_z = 0.0f;


void init(void)
{
    glClearColor(0, 0, 0, 0);
    glShadeModel(GL_SMOOTH);
}


void reshape(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-800.0, 800.0, -600.0, 600.0, -600.0, 600.0);
}

void duck(void)
{
    float* vertex = NULL;
    float* color = NULL;
    glPushMatrix();
    cubelight(0.8, 0.8, 0);

    glScalef(0.8, 0.8, 0.8);
    glTranslatef(0, 5, 0);
    for (int i = 0; i < loader.getFaceSize(); i++)	//每一迴圈畫一個三角面
    {
        // 得到一個面上的3個點  總共9個數值
        // { x1,y1,z1,x2,y2,z2,x3,y3,z3 } 	
        vertex = loader.getFace(i);

        // 得到一個面上的每個點的顏色 總共9個數值
        // { r1,g1,b1,r2,g2,b2,r3,g3,b3 } 
        color = loader.getFaceColor(i);

        glBegin(GL_TRIANGLES);
        glVertex3f(vertex[0], vertex[1], vertex[2]);
        glVertex3f(vertex[3], vertex[4], vertex[5]);
        glVertex3f(vertex[6], vertex[7], vertex[8]);
        glEnd();
        delete vertex;
        delete color;
    }
    glPopMatrix();
}


void floor()
{
    glPushMatrix();
    cubelight(0.0, 0.8, 0.0);
    glTranslatef(0, -135, 0);
    glScalef(15.0, 1.0, 10.0);
    glColor3f(0.0, 0.0, 1.0);
    glutSolidCube(100.0);
    glPopMatrix();
}

void leftfoot(int MODE)
{
    glPushMatrix();
    glTranslatef(30, -30, 0);
    glRotatef(Lspin, 1, 0, 0);
    glTranslatef(0, -25, 0);
    glColor3f(1.0, 0, 0);
    cubelight(1.0, 0, 0);
    glScalef(4, 10, 1.5);
    if (MODE == SOLID)
        glutSolidCube(5);
    else if (MODE == WIRE)
        glutWireCube(5);
    else if (MODE == ALL)
    {
        glutSolidCube(5);
        glutWireCube(5);
    }
    glTranslatef(0, -2.5, 0);
    glRotatef(lspin, 1, 0, 0);
    glTranslatef(0, 0, 16.67);
    glColor3f(0.8, 0.8, 0);
    cubelight(0.8, 0.8, 0);
    glScalef(2, 0.15, 6.67);
    if (MODE == SOLID)
        glutSolidCube(5);
    else if (MODE == WIRE)
        glutWireCube(5);
    else if (MODE == ALL)
    {
        glutSolidCube(5);
        glutWireCube(5);
    }
    glPopMatrix();

}

void rightfoot(int MODE)
{
    glPushMatrix();
    glTranslatef(-30, -30, 0);
    glRotatef(Rspin, 1, 0, 0);
    glTranslatef(0, -25, 0);
    glColor3f(1.0, 0, 0);
    cubelight(1.0, 0, 0);
    glScalef(4, 10, 1.5);
    if (MODE == SOLID)
        glutSolidCube(5);
    else if (MODE == WIRE)
        glutWireCube(5);
    else if (MODE == ALL)
    {
        glutSolidCube(5);
        glutWireCube(5);
    }
    glTranslatef(0, -2.5, 0);
    glRotatef(rspin, 1, 0, 0);
    glTranslatef(0, 0, 16.67);
    glColor3f(0.8, 0.8, 0);
    cubelight(0.8, 0.8, 0);
    glScalef(2, 0.15, 6.67);
    if (MODE == SOLID)
        glutSolidCube(5);
    else if (MODE == WIRE)
        glutWireCube(5);
    else if (MODE == ALL)
    {
        glutSolidCube(5);
        glutWireCube(5);
    }
    glPopMatrix();

}

void cube(float size, double x, double y, double z, double r, double g, double b, int ox, int oy, int oz, int MODE)
{
    glPushMatrix();
    glTranslatef(ox, oy, oz);
    cubelight(r, g, b);
    glScalef(x, y, z);
    if (MODE == SOLID)
        glutSolidCube(size);
    else if (MODE == WIRE)
        glutWireCube(size);
    else if (MODE == ALL)
    {
        glutSolidCube(size);
        glutWireCube(size);
    }
    glPopMatrix();
}

void lefthand(int MODE)
{
    glPushMatrix();
    glTranslatef(95, 108, 0);
    glRotatef(45, 0, 0, 1);
    glRotatef(lhspin, 1, 0, 0);
    glTranslatef(0, -38, 0);
    cubelight(0.4, 0.4, 1.0);
    //glColor3f(r, g, b);
    glScalef(1.5, 15, 10);
    if (MODE == SOLID) {
        glutSolidCube(5);
    }
    else if (MODE == WIRE) {
        glutWireCube(5);
    }
    else if (MODE == ALL)
    {
        glutSolidCube(5);
        glutWireCube(5);
    }
    glTranslatef(0, -3.8, 0);
    glRotatef(0, 1, 0, 0);
    glTranslatef(0, 0, 0);
    cubelight(1.0, 0.4, 0.4);
    glScalef(1, 0.53, 1);
    if (MODE == SOLID) {
        glutSolidCube(5);
    }
    else if (MODE == WIRE) {
        glutWireCube(5);
    }
    else if (MODE == ALL)
    {
        glutSolidCube(5);
        glutWireCube(5);
    }
    glPopMatrix();
}


void righthand(int MODE)
{
    glPushMatrix();
    glTranslatef(-95, 108, 0);
    glRotatef(-45, 0, 0, 1);
    glRotatef(rhspin, 1, 0, 0);
    glTranslatef(0, -38, 0);
    cubelight(0.4, 0.4, 1.0);
    //glColor3f(r, g, b);
    glScalef(1.5, 15, 10);
    if (MODE == SOLID) {
        glutSolidCube(5);
    }
    else if (MODE == WIRE) {
        glutWireCube(5);
    }
    else if (MODE == ALL)
    {
        glutSolidCube(5);
        glutWireCube(5);
    }
    glTranslatef(0, -3.8, 0);
    glRotatef(0, 1, 0, 0);
    glTranslatef(0, 0, 0);
    cubelight(1.0, 0.4, 0.4);
    glScalef(1, 0.53, 1);
    if (MODE == SOLID) {
        glutSolidCube(5);
    }
    else if (MODE == WIRE) {
        glutWireCube(5);
    }
    else if (MODE == ALL)
    {
        glutSolidCube(5);
        glutWireCube(5);
    }
    glPopMatrix();
}

void drawBall(double R, double x, double y, double z, int MODE)
{
    glPushMatrix();
    glTranslated(x, y, z);
    cubelight(0.15, 0.15, 0.8);
    if (MODE == SOLID) {
        glutSolidSphere(R, 20, 20);
    }
    else if (MODE == WIRE) {
        glutWireSphere(R, 20, 20);
    }
    else if (MODE == ALL)
    {
        glutSolidSphere(R, 20, 20);
        glutWireSphere(R, 20, 20);
    }

    glPopMatrix();
}

void draweye(double R, double x, double y, double z, int MODE, float r, float g, float b)
{
    glPushMatrix();
    glTranslated(x, y, z);
    cubelight(r, g, b);
    if (MODE == SOLID) {
        glutSolidSphere(R, 20, 20);
    }
    else if (MODE == WIRE) {
        glutWireSphere(R, 20, 20);
    }
    else if (MODE == ALL)
    {
        glutSolidSphere(R, 20, 20);
        glutWireSphere(R, 20, 20);
    }
    glPopMatrix();
}

void head(int MODE)
{
    glPushMatrix();
    glTranslatef(0, 200, 0);
    glRotatef(spin1, 0, 1, 0);
    cubelight(0.15, 0.15, 0.8);
    //glColor3f(0.15, 0.15, 0.8);
    if (MODE == SOLID) {
        glutSolidSphere(80, 20, 20);
    }
    else if (MODE == WIRE) {
        glutWireSphere(80, 20, 20);
    }
    else if (MODE == ALL)
    {
        glutSolidSphere(80, 20, 20);
        glutWireSphere(80, 20, 20);
    }
    draweye(20, -30, 20, 80, mode, 1, 1, 1);
    draweye(10, -30, 20, 91, mode, 0, 0, 0);
    draweye(20, 30, 20, 80, mode, 1, 1, 1);
    draweye(10, 30, 20, 91, mode, 0, 0, 0);
    cube(5, 4, 1.5, 15, 0.8, 0.8, 0, 0, -10 - tx, 115, mode);//上嘴巴
    cube(5, 4, 1.5, 15, 0.8, 0.8, 0, 0, -30 + tx, 110, mode);//下嘴巴
    glPopMatrix();
}

void ambient(void)
{
    GLfloat light_position[] = { 0,400,400,0 };//光源位置齊次座標(x,y,z,w)
    GLfloat light_ambient[] = { 0.0,0.0,0.0,1.0 };//RGBA模式下環境光
    GLfloat light_diffuse[] = { 0.2,0.2,0.2,1.0 };//RGBA模式下漫反射光
    GLfloat light_specular[] = { 0.2, 0.2, 0.2, 1.0 };//RGBA模式下鏡面光
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    //開啟燈光
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHTING);
    glEnable(GL_DEPTH_TEST);
}

void cubelight(float r, float g, float b)
{
    GLfloat ambient[] = { r, g, b, 1.0f };  //定義材質的環境光顏色，騙藍色
    GLfloat diffuse[] = { r, g, b, 0.0f };  //定義材質的漫反射光顏色，偏藍色
    GLfloat specular[] = { r * 1.5, g * 1.5, b * 1.5, 1.0f };   //定義材質的鏡面反射光顏色，紅色
    GLfloat emission[] = { r * 0.4, g * 0.4, b * 0.4, 1.0f };   //定義材質的輻射光顏色，為0
    GLfloat shininess = 1.0f;
    glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
    glMaterialfv(GL_FRONT, GL_EMISSION, emission);
    glMaterialf(GL_FRONT, GL_SHININESS, shininess);
}
void spot_light(float r, float g, float b)
{
    GLfloat Spot_position[] = { Xshift, 400, Zshift, 1.0f };
    GLfloat spotlight[] = { r,g ,b, 0 };
    GLfloat Spot_Direction[] = { light_x , -1.0f, light_z };
    cout << "R: " << r << "G: " << g << "B: " << b << endl;
    glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, Spot_Direction);
    glLightfv(GL_LIGHT1, GL_POSITION, Spot_position);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, spotlight);
    glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 0.8f);
    glEnable(GL_LIGHT1);
    glEnable(GL_LIGHTING);
    glEnable(GL_DEPTH_TEST);
}

void display(void)
{
    glClearColor(0.0, 0.0, 0.0, 0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  //清理顏色和深度快取 
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    //gluLookAt(r * cos(c * du), h, -32+r * sin(c * du),0, 0, 0,0, 1, 0);
    gluLookAt(0, 20, 30, 0, 0, 0, 0, 1, 0);
    glRotatef(xRotate, 1, 0, 0);
    glRotatef(yRotate, 0, 1, 0);
    ambient();
    spot_light(spot_red, spot_green, spot_blue);
    duck();
    floor();
    glPushMatrix();
    glTranslatef(Xshift, 0, Zshift);
    glRotatef(spin, 0, 1, 0);
    head(mode);
    drawBall(100, 0, 65, 0, mode);//身體
    leftfoot(mode);
    rightfoot(mode);
    lefthand(mode);
    righthand(mode);
    glPopMatrix();
    glutSwapBuffers();
}

void KeyBoards(unsigned char key, int x, int y)
{
    int i = 1;
    int k = 0;
    switch (key)
    {
    case 'W'://整體旋轉
        spin += i;
        glutPostRedisplay();				//標記當前視窗需要重繪，否則不會旋轉
        Sleep(10);
        break;
    case 'w'://頭部旋轉
        spin1 += i;
        glutPostRedisplay();				//標記當前視窗需要重繪，否則不會旋轉
        Sleep(10);
        break;
    case 'e'://嘴巴閉合
        if (state)
        {
            tx += i;
            if (tx == 5)state = 0;
        }
        else
        {
            tx -= i;
            if (tx == -5)state = 1;
        }
        glutPostRedisplay();				//標記當前視窗需要重繪，否則不會旋轉
        Sleep(10);
        break;
    case 'q':
        shift = 2;
        xshift = sin(spin * c) * (shift);
        zshift = cos(spin * c) * (shift);
        Xshift += xshift;
        Zshift += zshift;
        //printf("spin=%f,xshift=%f,zshift=%f\n", spin, xshift, zshift);
        if (state)
        {
            Lspin += i;
            Rspin -= i;
            if (Lspin == 30 && Rspin == -30)
                state = 0;
        }
        else
        {
            Lspin -= i;
            Rspin += i;
            if (Lspin == -30 && Rspin == 30)
                state = 1;
        }
        if (state)
        {
            lhspin += i;
            rhspin -= i;
            if (lhspin == 30 && rhspin == -30)
                state = 0;
        }
        else
        {
            lhspin -= i;
            rhspin += i;
            if (lhspin == -30 && rhspin == 30)
                state = 1;
        }

        printf("Lspin = %f,Rspin = %f\n", Lspin, Rspin);
        glutPostRedisplay();
        Sleep(10);
        break;
    case 'i':
        if (mode == SOLID)
            mode = WIRE;
        else if (mode == WIRE)
            mode = ALL;
        else if (mode == ALL)
            mode = SOLID;
        glutPostRedisplay();
        Sleep(10);
        break;
    case 'r':
        spot_red = 1.0f;
        spot_green = 0.0f;
        spot_blue = 0.0f;
        glutPostRedisplay();
        Sleep(10);
        break;
    case 'g':
        spot_red = 0.0f;
        spot_green = 1.0f;
        spot_blue = 0.0f;
        glutPostRedisplay();
        Sleep(10);
        break;
    case 'b':
        spot_red = 0.0f;
        spot_green = 0.0f;
        spot_blue = 1.0f;
        glutPostRedisplay();
        Sleep(10);
        break;
    case 'n':
        light_x += 1;
        light_z += 1;
        glutPostRedisplay();
        Sleep(10);
        break;
    case 'm':
        light_x += 1;
        light_z += 1;
        glutPostRedisplay();
        Sleep(10);
        break;
    case 'z':
        Xshift = -380;
        Zshift = 0;
        Lspin = 0;
        Rspin = 0;
        lspin = 0;
        rspin = 0;
        spin = 0;
        spin1 = 0;
        lhspin = 0;
        rhspin = 0;
        printf("ZZZ");
        glutPostRedisplay();
        Sleep(10);
        break;
    }
}

void myMouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        mousetate = true;
        Oldx = x;
        Oldy = y;
    }
    if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)
        mousetate = false;
    glutPostRedisplay();
}
void onMouseMove(int x, int y) {

    if (mousetate) {

        yRotate += (x - Oldx) / 10;
        Oldx = x;
        xRotate += (y - Oldy) / 10;
        Oldy = y;
    }
    glutPostRedisplay();
}

int main(int argc, char* argv[])
{
    loader.load(filename);	// (3) Load model file contant
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(800, 600);
    glutCreateWindow("OpenGL");
    init();
    glutKeyboardFunc(KeyBoards);
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMouseFunc(myMouse);
    glutMotionFunc(onMouseMove);
    glutMainLoop();
    return 0;
}