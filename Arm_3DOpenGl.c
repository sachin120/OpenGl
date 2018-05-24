/*
3D Arm OpenGl.
g++ Arm_3DOpenGl.c -lm -lglut -lGL -lGLU -o Arm_3D
*/
#include<stdio.h>
#include <stdarg.h>
#include <math.h>
#define GL_GLEXT_PROTOTYPES
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

void display();
void specialKeys();

double rotate_y = 0;                              		//Global Variables
double rotate_x = 0;


/*Callback function*/
void display(){

   glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);      	//Clear Screen and z-buffer
								// GL_COLOR_BUFFER_BIT, GL_DEPTH_BUFFER_BIT are the constants
   
   glLoadIdentity();                  				//Reset Transformations    			
   glRotatef(rotate_x, 1.0, 0.0, 0.0);				/*With user changes*/
   glRotatef(rotate_y, 0.0, 1.0, 0.0);				// (angle, x, y, z)
	
   ///////////////////////////// Forearm START ////////////////////////////////
   // Forearm Back-Face
   glBegin(GL_POLYGON);
   glColor4f( 1.0 , 1.0, 1.0, 1.0);

   glVertex3f(-0.02 , 0.06, 0.03);
   glVertex3f(0.06, 0.04, 0.03);
   glVertex3f(0.04, -0.4, 0.04);
   glVertex3f(-0.08, -0.4, 0.04);
   glEnd();

   // Forearm Front-Face
   glBegin(GL_POLYGON);
   glColor4f(1.0, 1.0, 0.0, 1.0);

   glVertex3f(-0.02 , 0.06, -0.03);
   glVertex3f(0.06, 0.04, -0.03);
   glVertex3f(0.04, -0.4, -0.04);
   glVertex3f(-0.08, -0.4, -0.04);
   glEnd();

   // Forearm Left-Face
   glBegin(GL_POLYGON);
   glColor4f(0.0, 1.0, 1.0, 1.0);

   glVertex3f(-0.02 , 0.06, 0.03);
   glVertex3f(-0.02 , 0.06, -0.03);
   glVertex3f(-0.08, -0.4, -0.04);
   glVertex3f(-0.08, -0.4, 0.04);
   glEnd();

   // Forearm Right-Face
   glBegin(GL_POLYGON);
   glColor4f(0.0, 1.0, 1.0, 1.0);

   glVertex3f(0.06, 0.04, -0.03);
   glVertex3f(0.06, 0.04, 0.03);
   glVertex3f(0.04, -0.4, 0.04);
   glVertex3f(0.04, -0.4, -0.04);
   glEnd();
   ///////////////////////////// Forearm END ////////////////////////////////

   ///////////////////////////// Palm START ////////////////////////////////
   // Palm Back-Face
   glBegin(GL_POLYGON);
   glColor4f(1.0, 1.0, 1.0, 1.0);
   glVertex3f(-0.02 , 0.09, 0.03);
   glVertex3f(0.06, 0.07, 0.03);
   glVertex3f(0.1, 0.23, 0.01);
   glVertex3f(-0.01, 0.27, 0.01);
   glVertex3f(-0.04, 0.25, 0.01);
   glVertex3f(-0.05, 0.19, 0.01);
   glEnd();

   // Palm Front-Face
   glBegin(GL_POLYGON);
   glColor4f(1.0, 1.0, 0.0, 1.0);
   glVertex3f(-0.02 , 0.09, -0.03);
   glVertex3f(0.06, 0.07, -0.03);
   glVertex3f(0.1, 0.23, -0.01);
   glVertex3f(-0.01, 0.27, -0.01);
   glVertex3f(-0.04, 0.25, -0.01);
   glVertex3f(-0.05, 0.19, -0.04);
   glEnd();

   // Palm 2nd-Face
   glBegin(GL_POLYGON);
   glColor4f(0.0, 1.0, 1.0, 1.0);
   glVertex3f(0.1, 0.23, -0.01);
   glVertex3f(0.1, 0.23, 0.01);
   glVertex3f(0.06, 0.07, 0.03);
   glVertex3f(0.06, 0.07, -0.03);
   glEnd();

   // Palm 6th-Face
   glBegin(GL_POLYGON);
   glColor4f(0.0, 1.0, 1.0, 1.0);
   glVertex3f(-0.05, 0.19, 0.01);
   glVertex3f(-0.05, 0.19, -0.04);
   glVertex3f(-0.02 , 0.09, -0.03);
   glVertex3f(-0.02 , 0.09, 0.03);
   glEnd();
   ///////////////////////////// Palm END ////////////////////////////////

   ///////////////////////////// Baby-Finger START ////////////////////////////////
   // Baby-Finger Back-Face
   glBegin(GL_POLYGON);
   glColor4f(1.0, 1.0, 1.0, 1.0);
   glVertex3f(0.1, 0.24, 0.01);	// 3rd pnt of Palm Back-Face + .01 up y-axis
   glVertex3f(0.12, 0.35, 0.01);
   glVertex3f(0.11, 0.36, 0.01);
   glVertex3f(0.08, 0.25, 0.01);	// 1st point x,y change
   glEnd();

   // Baby-Finger Front-Face
   glBegin(GL_POLYGON);
   glColor4f(1.0, 1.0, 0.0, 1.0);
   glVertex3f(0.1, 0.24, -0.01);	
   glVertex3f(0.12, 0.35, -0.01);
   glVertex3f(0.11, 0.36, -0.01);
   glVertex3f(0.08, 0.25, -0.01);
   glEnd();

   // Baby-Finger Top-Face
   glBegin(GL_POLYGON);
   glColor4f(1.0, 0.0, 0.0, 1.0);
   glVertex3f(0.12, 0.35, -0.01);
   glVertex3f(0.12, 0.35, 0.01);
   glVertex3f(0.11, 0.36, 0.01);
   glVertex3f(0.11, 0.36, -0.01);
   glEnd();
   
   // Baby-Finger Right-Face
   glBegin(GL_POLYGON);
   glColor4f(0.0, 1.0, 1.0, 1.0);
   glVertex3f(0.12, 0.35, -0.01);
   glVertex3f(0.12, 0.35, 0.01);
   glVertex3f(0.1, 0.24, 0.01);
   glVertex3f(0.1, 0.24, -0.01);
   glEnd();

   // Baby-Finger Left-Face
   glBegin(GL_POLYGON);
   glColor4f(0.0, 1.0, 1.0, 1.0);
   glVertex3f(0.11, 0.36, -0.01);
   glVertex3f(0.08, 0.25, -0.01);
   glVertex3f(0.08, 0.25, 0.01);
   glVertex3f(0.11, 0.36, 0.01);
   glEnd();
   ///////////////////////////// Baby-Finger END ////////////////////////////////

   ///////////////////////////// Ring-Finger START ////////////////////////////////
   // Ring-Finger Back-Face
   glBegin(GL_POLYGON);
   glColor4f(1.0, 1.0, 1.0, 1.0);
   glVertex3f(0.07, 0.26, 0.01);  // Baby-Finger 4th pnt -x(0.02), +y(0.01)
   glVertex3f(0.09, 0.38, 0.01);  // Baby-Finger 3rd pnt-x(0.01), +y(0.03)
   glVertex3f(0.07, 0.40, 0.01);
   glVertex3f(0.04, 0.27, 0.01);  // 1st point x,y change
   glEnd();

   // Ring-Finger Front-Face
   glBegin(GL_POLYGON);
   glColor4f(1.0, 1.0, 0.0, 1.0);
   glVertex3f(0.07, 0.26, -0.01);  
   glVertex3f(0.09, 0.38, -0.01);  
   glVertex3f(0.07, 0.40, -0.01);
   glVertex3f(0.04, 0.27, -0.01);
   glEnd();

   // Ring-Finger Top-Face
   glBegin(GL_POLYGON);
   glColor4f(1.0, 0.0, 0.0, 1.0);
   glVertex3f(0.07, 0.40, -0.01);
   glVertex3f(0.07, 0.40, 0.01);
   glVertex3f(0.09, 0.38, 0.01);
   glVertex3f(0.09, 0.38, -0.01);
   glEnd();

   // Ring-Finger Right-Face
   glBegin(GL_POLYGON);
   glColor4f(0.0, 1.0, 1.0, 1.0);
   glVertex3f(0.07, 0.26, -0.01);  
   glVertex3f(0.09, 0.38, -0.01);
   glVertex3f(0.09, 0.38, 0.01);
   glVertex3f(0.07, 0.26, 0.01);
   glEnd();

   // Ring-Finger Left-Face
   glBegin(GL_POLYGON);
   glColor4f(0.0, 1.0, 1.0, 1.0);
   glVertex3f(0.07, 0.40, -0.01);
   glVertex3f(0.04, 0.27, -0.01);
   glVertex3f(0.04, 0.27, 0.01);
   glVertex3f(0.07, 0.40, 0.01);
   glEnd();
   ///////////////////////////// Ring-Finger END ////////////////////////////////

   ///////////////////////////// Middle-Finger START ////////////////////////////////
   // Middle-Finger Back-Face
   glBegin(GL_POLYGON);
   glColor4f(1.0, 1.0, 1.0, 1.0);
   glVertex3f(0.03, 0.28, 0.01);  // Ring-Finger 4th pnt -x(0.02), +y(0.01)
   glVertex3f(0.04, 0.42, 0.01);  // Ring-Finger 3rd pnt-x(0.01), +y(0.03)
   glVertex3f(0.02, 0.43, 0.01);
   glVertex3f(0.0, 0.29, 0.01);  // 1st point x,y change
   glEnd();

   // Middle-Finger Front-Face
   glBegin(GL_POLYGON);
   glColor4f(1.0, 1.0, 0.0, 1.0);
   glVertex3f(0.03, 0.28, -0.01);  
   glVertex3f(0.04, 0.42, -0.01);  
   glVertex3f(0.02, 0.43, -0.01);
   glVertex3f(0.0, 0.29, -0.01);  
   glEnd();

   // Middle-Finger Right-Face
   glBegin(GL_POLYGON);
   glColor4f(0.0, 1.0, 1.0, 1.0);
   glVertex3f(0.03, 0.28, -0.01); 
   glVertex3f(0.04, 0.42, -0.01); 
   glVertex3f(0.04, 0.42, 0.01); 
   glVertex3f(0.03, 0.28, 0.01);
   glEnd();

   // Middle-Finger Left-Face
   glBegin(GL_POLYGON);
   glColor4f(0.0, 1.0, 1.0, 1.0);
   glVertex3f(0.02, 0.43, -0.01);
   glVertex3f(0.0, 0.29, -0.01);
   glVertex3f(0.0, 0.29, 0.01);
   glVertex3f(0.02, 0.43, 0.01);
   glEnd();

   // Middle-Finger Top-Face
   glBegin(GL_POLYGON);
   glColor4f(1.0, 0.0, 0.0, 1.0);
   glVertex3f(0.02, 0.43, -0.01);
   glVertex3f(0.02, 0.43, 0.01);
   glVertex3f(0.04, 0.42, 0.01);
   glVertex3f(0.04, 0.42, -0.01);
   glEnd();
   ///////////////////////////// Middle-Finger END ////////////////////////////////

   ///////////////////////////// Index-Finger START ////////////////////////////////
   // Index-Finger Back-Face
   glBegin(GL_POLYGON);
   glColor4f(1.0, 1.0, 1.0, 1.0);
   glVertex3f(-0.02, 0.30, 0.01);  // Ring-Finger 4th pnt -x(0.02), +y(0.01)
   glVertex3f(-0.02, 0.43, 0.01);   // Ring-Finger 3rd pnt-x(0.01), +y(0.03)
   glVertex3f(-0.04, 0.42, 0.01);
   glVertex3f(-0.045, 0.29, 0.01);    // 1st point x,y change
   glEnd();

   // Index-Finger Front-Face
   glBegin(GL_POLYGON);
   glColor4f(1.0, 1.0, 0.0, 1.0);
   glVertex3f(-0.02, 0.30, -0.01);
   glVertex3f(-0.02, 0.43, -0.01);
   glVertex3f(-0.04, 0.42, -0.01);
   glVertex3f(-0.045, 0.29, -0.01);
   glEnd();

   // Index-Finger Right-Face
   glBegin(GL_POLYGON);
   glColor4f(0.0, 1.0, 1.0, 1.0);
   glVertex3f(-0.02, 0.30, -0.01);
   glVertex3f(-0.02, 0.43, -0.01);
   glVertex3f(-0.02, 0.43, 0.01);
   glVertex3f(-0.02, 0.30, 0.01);
   glEnd();

   // Index-Finger Left-Face
   glBegin(GL_POLYGON);
   glColor4f(0.0, 1.0, 1.0, 1.0);
   glVertex3f(-0.04, 0.42, -0.01);
   glVertex3f(-0.045, 0.29, -0.01);
   glVertex3f(-0.045, 0.29, 0.01);
   glVertex3f(-0.04, 0.42, 0.01);
   glEnd();

   // Index-Finger Top-Face
   glBegin(GL_POLYGON);
   glColor4f(1.0, 0.0, 0.0, 1.0);
   glVertex3f(-0.04, 0.42, -0.01);
   glVertex3f(-0.04, 0.42, 0.01);
   glVertex3f(-0.02, 0.43, 0.01);
   glVertex3f(-0.02, 0.43, -0.01);
   glEnd();

   ///////////////////////////// Index-Finger END ////////////////////////////////

   // Thumb-Finger Leftside-Face
   glBegin(GL_POLYGON);
   glColor4f(0.0, 1.0, 1.0, 1.0);
   glVertex3f(-0.06, 0.2, -0.01);  
   glVertex3f(-0.055, 0.24, -0.01);
   glVertex3f(-0.08, 0.30, -0.01);
   glVertex3f(-0.1, 0.30, -0.01);
   glVertex3f(-0.08, 0.22, -0.01); 
   glEnd();

   // Thumb-Finger Rightside-Face
   glBegin(GL_POLYGON);
   glColor4f(0.0, 1.0, 1.0, 1.0);
   glVertex3f(-0.06, 0.2, 0.01);  
   glVertex3f(-0.055, 0.24, 0.01);
   glVertex3f(-0.08, 0.30, 0.01);
   glVertex3f(-0.1, 0.30, 0.01);
   glVertex3f(-0.08, 0.22, 0.01); 
   glEnd();

   glFlush();
   glutSwapBuffers();
}

void specialKeys(int key, int x, int y){
    if(key == GLUT_KEY_RIGHT)
        rotate_y += 5;
    else if(key == GLUT_KEY_LEFT)
        rotate_y -= 5;
    else if(key == GLUT_KEY_UP)
        rotate_x += 5;
    else if(key == GLUT_KEY_DOWN)
        rotate_x -= 5;

    glutPostRedisplay();
}

int main(int argc, char* argv[]){

   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
   glutInitWindowPosition(300, 100);
   glutInitWindowSize(800, 600);
   glutCreateWindow("Human Arm");
   glEnable(GL_BLEND);
   glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
   glClearColor(0.0, 0.0, 0.0, 0.0);
   glEnable(GL_DEPTH_TEST);
   glutDisplayFunc(display);
   glutSpecialFunc(specialKeys);
   glutMainLoop();

   return 0;
}
