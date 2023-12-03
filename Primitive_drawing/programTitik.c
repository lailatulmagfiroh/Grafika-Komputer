#include <glut.h>
#include <stdlib.h>

void userdraw (void) {
    int s; // ukuran titik
    float x, y; // posisi titik
    for(int i=0; i<1000; i++){
        s = rand()%4+1;
        glPointSize(s);
        glBegin(GL_POINTS);
        x=-100+200*(float)rand()/RAND_MAX;
        y=-100+200*(float)rand()/RAND_MAX;
        glVertex2f(x,y);
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
	glutCreateWindow("Menggambar Titik");

	// definisi warna (0,0,0) = hitam
	glClearColor(0,0,0,0);

	// definisi besarnya sistem ordinat dg range sumbu x [0,640] dan sumbu y [-240,240]
	gluOrtho2D(0.,640.,-240.,240.);

	glutIdleFunc(display);
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
