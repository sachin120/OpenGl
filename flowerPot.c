//g++ flowerPot.c -lm -lglut -lGL -lGLU -o flowers

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
   glRotatef(rotate_y, 0.0, 1.0, 0.0);// (angle, x, y, z)
	
 	
	glBegin(GL_POLYGON);	
   	glColor4f( 1.0 , 1.0, 1.0, 0.3);
	glVertex3f(-0.01 , 0.8, 0.0);
        glVertex3f(0.01, 0.8, 0.0);
	glVertex3f(0.01,-0.69, 0.0);
	glVertex3f(-0.01,-0.69, 0.0);
	glEnd();
 	
	glBegin(GL_POLYGON);	
   	glColor4f( 1.0 , 1.0, 1.0, 0.3);
	glVertex3f(-0.21 , 0.75, 0.0);
	glVertex3f(-0.19 , 0.75, 0.0);
       	glVertex3f(0.0 , 0.0, 0.0);
	glEnd();

	glBegin(GL_POLYGON);	
   	glColor4f( 1.0 , 1.0, 1.0, 0.3);
	glVertex3f( 0.28 , 0.75, 0.0);
	glVertex3f( 0.31 , 0.75, 0.0);
       	glVertex3f(0.0 , 0.2, 0.0);
	glEnd();

	glBegin(GL_POLYGON);	
   	glColor4f( 1.0 , 1.0, 1.0, 0.3);
	glVertex3f(-0.21 , 0.75, 0.0);
	glVertex3f(-0.19 , 0.75, 0.0);
       	glVertex3f(0.0 , 0.0, 0.0);
	glEnd();
	
   glBegin(GL_POLYGON);						//Front-T
   glColor4f(1.0, 0.0, 0.0, 0.3	);
   glVertex3f(-0.05,0.05, -0.3);
   glVertex3f(-0.3,0.5, -0.2);
   glVertex3f(0.3,0.5, -0.2);
   glVertex3f(0.05,0.05, -0.3);
   glEnd();

   glBegin(GL_POLYGON);						//Front-B
   glColor4f( 1.0, 0.0, 0.0, 0.6);
   glVertex3f(-0.3,-0.7, -0.2);
   glVertex3f(-0.05, -0.05, -0.3);
   glVertex3f(0.05,-0.05, -0.3);
   glVertex3f(0.3,-0.7, -0.2);
   glEnd();

   glBegin(GL_POLYGON);						//Front-R
   glColor4f( 0.76, 0.0, 0.0, 0.6);
   glVertex3f(0.05, 0.05, -0.3);
   glVertex3f(0.3, 0.5, -0.2);
   glVertex3f(0.3,-0.7, -0.2);
   glVertex3f(0.05,-0.05, -0.3);
   glEnd();

   glBegin(GL_POLYGON);		
   glColor4f( 0.76, 0.0, 0.0, 0.6);				//Front-L
   glVertex3f(-0.3,0.5, -0.2);
   glVertex3f(-0.05,0.05, -0.3);
   glVertex3f(-0.05,-0.05, -0.3);
   glVertex3f(-0.3,-0.7, -0.2);
   glEnd();

   glBegin(GL_POLYGON);						//RIGHT-T
   glColor4f( 1.0, 0.0, 0.0, 0.3);
   glVertex3f(0.4,0.05, -0.05);
   glVertex3f(0.3,0.5, -0.2);
   glVertex3f(0.3,0.5, 0.2);
   glVertex3f(0.4,0.05, 0.05);
   glEnd();

   glBegin(GL_POLYGON);						//RIGHT-B
   glColor4f( 1.0, 0.0, 0.0, 0.6);
   glVertex3f(0.3,-0.7, -0.2);
   glVertex3f(0.4,-0.05, -0.05);
   glVertex3f(0.4,-0.05, 0.05);
   glVertex3f(0.3,-0.7, 0.2);
   glEnd();

   glBegin(GL_POLYGON);						//RIGHT-R
   glColor4f( 0.76, 0.0, 0.0, 0.6);
   glVertex3f(0.4,0.05, 0.05);
   glVertex3f(0.3,0.5, 0.2);
   glVertex3f(0.3,-0.7, 0.2);
   glVertex3f(0.4,-0.05, 0.05);
   glEnd();

   glBegin(GL_POLYGON);		
   glColor4f( 0.76, 0.0, 0.0, 0.6);				//RIGHT-L
   glVertex3f(0.3,0.5, -0.2);
   glVertex3f(0.4,0.05, -0.05);
   glVertex3f(0.4,-0.05, -0.05);
   glVertex3f(0.3,-0.7, -0.2);
   glEnd();

   glBegin(GL_POLYGON);						//BACK-T
   glColor4f( 1.0, 0.0, 0.0, 0.3);
   glVertex3f(-0.05,0.05, 0.3);
   glVertex3f(-0.3,0.5, 0.2);
   glVertex3f(0.3,0.5, 0.2);
   glVertex3f(0.05,0.05, 0.3);
   glEnd();

   glBegin(GL_POLYGON);						//BACK-B
   glColor4f( 1.0, 0.0, 0.0, 0.6);
   glVertex3f(-0.3,-0.7, 0.2);
   glVertex3f(-0.05, -0.05, 0.3);
   glVertex3f(0.05,-0.05, 0.3);
   glVertex3f(0.3,-0.7, 0.2);
   glEnd();

   glBegin(GL_POLYGON);						//BACK-R
   glColor4f( 0.76, 0.0, 0.0, 0.6);
   glVertex3f(0.05, 0.05, 0.3);
   glVertex3f(0.3, 0.5, 0.2);
   glVertex3f(0.3,-0.7, 0.2);
   glVertex3f(0.05,-0.05, 0.3);
   glEnd();

   glBegin(GL_POLYGON);		
   glColor4f( 0.76, 0.0, 0.0, 0.6);				//BACK-L
   glVertex3f(-0.3,0.5, 0.2);
   glVertex3f(-0.05,0.05, 0.3);
   glVertex3f(-0.05,-0.05, 0.3);
   glVertex3f(-0.3,-0.7, 0.2);
   glEnd();


   glBegin(GL_POLYGON);						//LEFT-T
   glColor4f( 1.0, 0.0, 0.0, 0.3);
   glVertex3f(-0.4,0.05, -0.05);
   glVertex3f(-0.3,0.5, -0.2);
   glVertex3f(-0.3,0.5, 0.2);
   glVertex3f(-0.4,0.05, 0.05);
   glEnd();

   glBegin(GL_POLYGON);						//LEFT-B
   glColor4f( 1.0, 0.0, 0.0, 0.6);
   glVertex3f(-0.3,-0.7, -0.2);
   glVertex3f(-0.4,-0.05, -0.05);
   glVertex3f(-0.4,-0.05, 0.05);
   glVertex3f(-0.3,-0.7, 0.2);
   glEnd();

   glBegin(GL_POLYGON);						//LEFT-R
   glColor4f( 0.76, 0.0, 0.0, 0.6);
   glVertex3f(-0.4,0.05, 0.05);
   glVertex3f(-0.3,0.5, 0.2);
   glVertex3f(-0.3,-0.7, 0.2);
   glVertex3f(-0.4,-0.05, 0.05);
   glEnd();

   glBegin(GL_POLYGON);		
   glColor4f( 0.76, 0.0, 0.0, 0.6);				//LEFT-L
   glVertex3f(-0.3,0.5, -0.2);
   glVertex3f(-0.4,0.05, -0.05);
   glVertex3f(-0.4,-0.05, -0.05);
   glVertex3f(-0.3,-0.7, -0.2);
   glEnd();

   glBegin(GL_POLYGON);	
   glColor4f( 0.4, 0.13, 0.245, 1.0);	   				//BASE
   glVertex3f(-0.3,-0.7, -0.2);
   glVertex3f(-0.3,-0.7, 0.2);
   glVertex3f(0.3,-0.7, 0.2);
   glVertex3f(0.3,-0.7, -0.2);
   glEnd();
        // Flower one ---
        glColor3f(0.1, 0.72, 0.32);
        glPushMatrix();
        glTranslatef(0.25,0.7,0.0);
	glutSolidSphere(0.07,30,30);
        glPopMatrix();
    
	glColor3f(0.34, 0.21, 0.52);
        glPushMatrix();
        glTranslatef(0.3,0.76,0.0);
	glutSolidSphere(0.03,30,30);
        glPopMatrix();

        glPushMatrix();
        glTranslatef(0.2,0.76,0.0);
	glutSolidSphere(0.03,30,30);
        glPopMatrix();

        glPushMatrix();
        glTranslatef(0.25,0.76,0.0);
	glutSolidSphere(0.03,30,30);
        glPopMatrix();
 								//Flower two
        glBegin(GL_POLYGON);	
   	glColor4f( 0.35, 0.13, 0.245, 1.0);	   				
	glVertex3f(-0.35,0.75,0.0);
	glVertex3f(-0.3,0.8,-0.02);
	glVertex3f(-0.2,0.75,0.0);
	glVertex3f(-0.3,0.7,-0.02);
   	glEnd();

        glBegin(GL_POLYGON);
   	glColor4f( 0.4, 0.13, 0.245, 1.0);	   				
	glVertex3f(-0.2,0.75,0.0);
	glVertex3f(-0.1,0.8,-0.02);
	glVertex3f(-0.05,0.75,0.0);
	glVertex3f(-0.1,0.7,-0.02);
   	glEnd();

        glBegin(GL_POLYGON);
   	glColor4f( 0.45, 0.13, 0.245, 1.0);	   				
	glVertex3f(-0.2,0.75,0.0);
	glVertex3f(-0.25,0.85,-0.02);
	glVertex3f(-0.2,0.9,0.0);
	glVertex3f(-0.15,0.85,-0.02);
   	glEnd();

	glColor4f(0.0, 0.72, 0.32,0.2);
        glPushMatrix();
        glTranslatef(0.0,0.9,0.0);
	glutSolidSphere(0.1,90,90);
        glPopMatrix();
   
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
   glutCreateWindow("Flower Pot");
   glEnable(GL_BLEND);
   glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
   glClearColor(0.0, 0.0, 0.0, 0.0);
   glEnable(GL_DEPTH_TEST);
   glutDisplayFunc(display);
   glutSpecialFunc(specialKeys);
   glutMainLoop();

   return 0;
}
