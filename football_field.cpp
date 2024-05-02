#include<windows.h>
#ifdef _APPLE_
#include<GLUT/glut.h>
#else
#include<GL/glut.h>
#endif // _APPLE_
#include<stdlib.h>
#include<math.h>

void init()
{
    glClearColor(0,1,0,0);//RGBA where a means alpha that declares the opacity of color
    glOrtho(-20,+20,-10,+10,-1,+1);//left+right=x axis, bottom+top=y axis, zNear+zFar=z axis
}

float bx=0, ball_angle=0.0;

void field()
{
    glColor3f(1, 1, 1);
    glBegin(GL_LINE_LOOP);
        glVertex2d(18,9);
        glVertex2d(-18,9);
        glVertex2d(-18,-9);
        glVertex2d(18,-9);
    glEnd();
}

void middle_line()
{
    glColor3f(1, 1, 1);
    glBegin(GL_LINES);
        glVertex2d(0,9);
        glVertex2d(0,-9);
    glEnd();
}

void field_circle(float r)
{
    int i=0;
    float angle=0.0;
    glColor3f(1, 1, 1);
    glBegin(GL_LINES);
        for(i=0; i<=500; i++)
        {
            angle=(360*i)/500;
            glVertex2d(r*cos(angle), r*sin(angle));
        }
    glEnd();
}

void field_box1()
{
    glColor3f(1, 1, 1);
    glBegin(GL_LINE_LOOP);
        glVertex2d(18,1);
        glVertex2d(16,1);
        glVertex2d(16,-1);
        glVertex2d(18,-1);
    glEnd();
}

void field_box2()
{
    glColor3f(1, 1, 1);
    glBegin(GL_LINE_LOOP);
        glVertex2d(18,2);
        glVertex2d(14,2);
        glVertex2d(14,-2);
        glVertex2d(18,-2);
    glEnd();
}

void field_box3()
{
    glColor3f(1, 1, 1);
    glBegin(GL_LINE_LOOP);
        glVertex2d(18,0.5);
        glVertex2d(19,0.5);
        glVertex2d(19,-0.5);
        glVertex2d(18,-0.5);
    glEnd();
}

void field_box4()
{
    glColor3f(1, 1, 1);
    glBegin(GL_LINE_LOOP);
        glVertex2d(-18,1);
        glVertex2d(-16,1);
        glVertex2d(-16,-1);
        glVertex2d(-18,-1);
    glEnd();
}

void field_box5()
{
    glColor3f(1, 1, 1);
    glBegin(GL_LINE_LOOP);
        glVertex2d(-18,2);
        glVertex2d(-14,2);
        glVertex2d(-14,-2);
        glVertex2d(-18,-2);
    glEnd();
}

void field_box6()
{
    glColor3f(1, 1, 1);
    glBegin(GL_LINE_LOOP);
        glVertex2d(-18,0.5);
        glVertex2d(-19,0.5);
        glVertex2d(-19,-0.5);
        glVertex2d(-18,-0.5);
    glEnd();
}

void field_points(float r)
{
    int i=0;
    float angle=0.0;
    glColor3f(1, 1, 1);
    glBegin(GL_POLYGON);
        for(i=0; i<=500; i++)
        {
            angle=(360*i)/500;
            glVertex2d(r*cos(angle), r*sin(angle));
        }
    glEnd();
}

void ball(float r)
{
    int i=0;
    float angle=0.0;
    glColor3f(1, 1, 1);
    glBegin(GL_POLYGON);
        for(i=0; i<=500; i++)
        {
            angle=(360*i)/500;
            glVertex2d(r*cos(angle), r*sin(angle));
        }
    glEnd();
}

void myDisplay()
{
    glClear(GL_COLOR_BUFFER_BIT);//this function enables color
    glPushMatrix();
        field();
        middle_line();
        field_circle(2.0);
        field_box1();
        field_box2();
        field_box3();
        field_box4();
        field_box5();
        field_box6();
        field_points(0.25);
        glTranslated(15, 0, 0);
            field_points(0.25);
        glTranslated(-30, 0, 0);
            field_points(0.25);
        glTranslated(15, 0, 0);
        glPushMatrix();
            glTranslated(bx, 0, 0);
            glTranslated(-10, -4, 0);
            glRotated(ball_angle, 0, 1, 0);
                ball(1.5);
        glPopMatrix();
    glPopMatrix();
    glFlush();
}

void move_right()
{
    bx=bx+0.01;//if we increase value of bx, then it will move to +x
    ball_angle=ball_angle+1;
    if(bx>=30.5)
    {
        bx=-20.5;
    }
    glutPostRedisplay();
}

void specialKey(int key, int x, int y)
{
    switch(key)//as we want to use keys as parameters
    {
    case GLUT_KEY_RIGHT:
        glutIdleFunc(move_right);//this function will run a command till other command is given
        break;
    default:
        break;
    }
}

int main()
{
    //glutInit(&argc, &argv);
    glutInitWindowSize(1100, 700);//display size in height and width in pixel
    glutInitWindowPosition(0,0);//display position from x & y axis
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    //glut_rgb is color mode
    //glut_single is 2D mode & glut_double is 3D mode
    glutCreateWindow("GLUT Football Field");//this function give window a name
    init();
    glutDisplayFunc(myDisplay);
    glutSpecialFunc(specialKey);//use keys to modify display style
    glutMainLoop();//use to loop the display
    //if we don't use loop in the display, then the display will occur only once
    return 0;
}
