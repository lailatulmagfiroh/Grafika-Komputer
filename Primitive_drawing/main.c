#include <glut.h>
#include <stdlib.h>

void userdraw(void) {
    float xp,yp;
    for(int i=0;i<50;i++){
    xp=600*(float)rand()/RAND_MAX;
    yp=600*(float)rand()/RAND_MAX;
    glColor3f(1,1,1);
    glBegin(GL_LINES);
    glVertex2f(xp,yp);
    glVertex2f(xp+16,yp-16);
    glEnd();
}
}
void display(void) {
    //clear screen
    glClear(GL_COLOR_BUFFER_BIT) ;
    userdraw();
    glutSwapBuffers();
}
int main(int argc, char **argv){
	glutInit(&argc,argv);//Inisialisasi Toolkit
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);

	// meletakkan windows di posisi (100,100) layar komputer
	glutInitWindowPosition(100,100);

	// membuat windows dengan ukuran (640,480)
	glutInitWindowSize(640,480);

	// memberi judul pada windows
	glutCreateWindow("Program Titik");

	// definisi warna (0,0,0) = hitam
	glClearColor(0.0,0.0,0.0,0.0);

	// definisi besarnya sistem ordinat dg range sumbu x [0,640] dan sumbu y [-240,240]
	gluOrtho2D(-440.,640.,-440.,440.);

	glutIdleFunc(display);
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
