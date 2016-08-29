//
//  main.cpp
//  first_GL
//
//  Created by liuzhiwei on 16/7/27.
//  Copyright © 2016年 liuzhiwei. All rights reserved.
//

#include <iostream>

#include <GLUT/GLUT.h>

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POLYGON);
    glVertex2f(-0.5, -0.5);
    glVertex2f(-0.5, 0.5);
    glVertex2f(0.5, 0.5);
    glVertex2f(0.5, -0.5);
    glEnd();
    glFlush();
}

int main_1(int argc, char * argv[]) {
    // insert code here...
//    std::cout << "Hello, World!\n";
    glutInit(&argc, argv);
    glutCreateWindow("Xcide glut demo ");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
