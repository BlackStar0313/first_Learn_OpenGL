//
//  main.cpp
//  learn_OpenGL
//
//  Created by liuzhiwei on 16/7/27.
//  Copyright © 2016年 liuzhiwei. All rights reserved.
//

#include <stdio.h>

#include <GLUT/glut.h>

//void init()
//{
//    glClearColor(1.0, 1.0, 1.0, 0.0);
//    glMatrixMode(GL_PROJECTION);
//    gluOrtho2D(0, 200, 0,150);
//}
//
//void lineSegment()
//{
//    glClear(GL_COLOR_BUFFER_BIT);
//    glColor3f(0.0 , 0.4, 0.2);
//    glBegin(GL_LINES);
//        glVertex2i(180, 15);
//        glVertex2i(10 , 145);
//    glEnd();
//    glFlush();
//}
//
//int main_22(int argc , char* argv[])
//{
//    glutInit(&argc , argv);
//    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//    glutInitWindowPosition(50, 100);
//    glutInitWindowSize(400, 300);
//    glutCreateWindow("As Example OpenGL program");
//    
//    init();
//    glutDisplayFunc(lineSegment);
//    glutMainLoop();
//    return 0;
//}