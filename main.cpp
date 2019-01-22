#include <GL/glut.h>
#include <math.h>
#include <stdlib.h>

float WinWid = 400.0;
float WinHei = 400.0;
int Angle = 0;
float Scale = 1.0;
float x=0.0, y=0.0;

void Draw()
{
    glClear(GL_COLOR_BUFFER_BIT);
    Angle %= 360;
    glPushMatrix();
    Scale = 1.0-abs(sin(3.14*Angle/90.0)/sqrt(3.0)/2);
    glRotatef(Angle, 0.0, 0.0, 1.0);
    glScalef(Scale, Scale, 1.0);
    glBegin(GL_LINES);
        for(float i = 0+x; i <= WinWid+x; i += 20.0) {
            glVertex2f(i, 0+y);
            glVertex2f(i, WinHei+y);
        }
        for(float i = 0+y; i <= WinHei+y; i += 20.0) {
            glVertex2f(0+x, i);
            glVertex2f(WinWid+x, i);
        }
    glEnd();

    glPopMatrix();
    glutSwapBuffers();


}

void MouseMove(int ax, int ay)
{
    x=ax;
    y=ay;
}

void MousePressed(int button, int state, int x, int y)
{
    // switch(button)
    // {
    //     case GLUT_LEFT_BUTTON: glutSetWindowTitle("left button"); break;
    //     case GLUT_RIGHT_BUTTON: glutSetWindowTitle("right button"); break;
    //     case GLUT_MIDDLE_BUTTON: glutSetWindowTitle("mid button"); break;
    // }



}

void MousePressedMove(int ax, int ay)
{
    glutSetWindowTitle("pressmove");
}

void Timer(int value)
{
    Draw();
    glutPostRedisplay();
    glutTimerFunc(20, Timer, 0);
}

void Initialize() 
{
    glClearColor(0.0,0.0,0.0,1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    // glOrtho(-WinWid/2, WinWid/2, -WinHei/2, WinHei/2, -200.0, 200.0);
    glOrtho(0, WinWid, WinHei, 0, -200.0, 200.0);
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

    glutMotionFunc(MousePressedMove);
    glutPassiveMotionFunc(MouseMove);
    glutMouseFunc(MousePressed);

    Initialize();

    glutMainLoop();
    return 0;
}