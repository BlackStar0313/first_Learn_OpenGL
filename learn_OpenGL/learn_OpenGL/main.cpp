//
//  main.cpp
//  learn_OpenGL
//
//  Created by liuzhiwei on 16/7/27.
//  Copyright © 2016年 liuzhiwei. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <GLUT/glut.h>
#include <math.h>

//第四章   输出图元


//画线
//void init()
//{
//    glClearColor(1.0, 1.0, 1.0, 0.0);
//    glMatrixMode(GL_PROJECTION);
//    gluOrtho2D(0, 200, 0,150);
//}
//
//void linSegment()
//{
//    glClear(GL_COLOR_BUFFER_BIT);
//    glColor3f(0.0 , 0.4, 0.2);
//    
//    //画点 GL_POINTS   画线GL_LINES 画折线 GL_LINE_STRIP     封闭折线 GL_LINE_LOOP
//    glBegin(GL_POINTS);
//    glVertex2i(180, 15);
//    glVertex2i(10 , 145);
//    glEnd();
//    glFlush();
//}
//
//int main(int argc , char* argv[])
//{
//    glutInit(&argc , argv);
//    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//    glutInitWindowPosition(50, 100);
//    glutInitWindowSize(400, 300);
//    glutCreateWindow("As Example OpenGL program");
//    
//    init();
//    glutDisplayFunc(linSegment);
//    glutMainLoop();
//    return 0;
//}



//画包围图元
const double  TWO_PI  = 3.141592653 * 2 ;

GLsizei winWidth = 640 , winHeight = 960 ;
GLuint regHex ;

class screentPt
{
private:
    GLint x , y ;
    
public:
    screentPt() {
        x = y = 0 ;
    }
    
    void setCoords(GLint xCoord , GLint yCoord) {
        x = xCoord ;
        y = yCoord;
    }
    
    GLint getx() const {
        return x ;
    }
    
    GLint gety() const {
        return y ;
    }
};


static void init () {
    screentPt hexVertex , cirCtr ;
    GLdouble theta ;
    GLint k ;
    
    cirCtr.setCoords(winWidth/2 , winHeight/2);
    
    glClearColor(0.0, 1.0, 1.0, 1.0);
    
    regHex = glGenLists(1);
    glNewList(regHex, GL_COMPILE);
        glColor3f(1.0, 0.0, 0.0);
        glBegin(GL_POLYGON);
            for (k = 0 ; k < 6 ; ++k) {
                theta = TWO_PI * k / 6.0;
                hexVertex.setCoords(cirCtr.getx() + 150*cos(theta), cirCtr.gety() + 150 * sin(theta));
                glVertex2i(hexVertex.getx(), hexVertex.gety());
            }
        glEnd();
    glEndList();
}

void regHexagon(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glCallList(regHex);
    glFlush();
}

void winReshapFcn (int newWidth , int newHeight) {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, (GLdouble)newWidth, 0.0, (GLdouble) newHeight) ;
    glClear(GL_COLOR_BUFFER_BIT);
}


int main (int argc , char** argv ) {
    glutInit (& argc , argv );
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(winWidth, winHeight);
    glutCreateWindow("display list exp ");
    
    init();
    glutDisplayFunc(regHexagon);
    glutReshapeFunc(winReshapFcn);
    
    glutMainLoop();
    return 0 ;
}