#include <GL/glut.h>
#include <math.h>
#include <string>
#include <stdlib.h>

float WinWid = 400.0;
float WinHei = 400.0;
int Angle = 0;
float Scale = 1.0;
char ang[7+5] = "Angle: ";
char res[7+5] = "Angle: ";
char buf[5];

void Draw()
{
    glClear(GL_COLOR_BUFFER_BIT);
    Angle %= 360;
    glPushMatrix();
    Scale = 1.0-abs(sin(3.14*Angle/90.0)/sqrt(3.0)/2);
    glRotatef(Angle, 0.0, 0.0, 1.0);
    glScalef(Scale, Scale, 1.0);
    glBegin(GL_LINES);
        for(float i = -WinWid/2; i <= WinWid/2; i += 20.0) {
            glVertex2f(i, -WinHei/2);
            glVertex2f(i, WinHei/2);
        }
        for(float i = -WinHei/2; i <= WinHei/2; i += 20.0) {
            glVertex2f(-WinWid/2, i);
            glVertex2f(WinWid/2, i);
        }
    glEnd();

    sprintf(buf, "%d", Angle);

    for (int i = 7; i < 12 ; i++) {
        res[i] = buf[i-7];
    }

    glutSetWindowTitle(res);

    glPopMatrix();
    glutSwapBuffers();


}

void Timer(int value)
{

    Draw();
    glutPostRedisplay();
    glutTimerFunc(20, Timer, 0);
}

void Keyboard(unsigned char key, int x, int y)
{
    switch(key)
    {
        case 'a': Angle++;
            break;
        case 'd': Angle--;
            break;
    }
}

void SKeyboard(int key, int x, int y)
{
    switch(key)
    {
        case GLUT_KEY_LEFT: Angle++;
        break;
        case GLUT_KEY_RIGHT: Angle--;
        break;
    }
}

void Initialize() 
{
    glClearColor(0.0,0.0,0.0,1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-WinWid/2, WinWid/2, -WinHei/2, WinHei/2, -200.0, 200.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
    glutInitWindowSize(WinWid, WinHei);
    glutInitWindowPosition(100, 200);
    glutCreateWindow("test");

    //reg
    glutDisplayFunc(Draw);
    glutTimerFunc(50, Timer, 0);
    glutKeyboardFunc(Keyboard);
    glutSpecialFunc(SKeyboard);
    Initialize();

    glutMainLoop();
    return 0;
}