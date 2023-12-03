#include <windows.h>
#include <glut.h>
#define PI 3.14159265358979323846

// Fungsi basic
void circle(float a, float b, float r){  // (a,b) = pusat lingkaran (x,y) dan r = radius
    int i;
    int triangleAmount = 100; // menyimpan jumlah segitiga untuk menggambar lingkaran
    GLfloat twicePi = 2.0f * PI;
    GLfloat x=a; GLfloat y=b; GLfloat radius =r;
       glBegin(GL_TRIANGLE_FAN);
       glVertex2f(x, y);
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
                x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
    glEnd(); }

void quad(float a, float b, float c, float d, float e, float f, float g, float h){ // quad untuk membuat permukaan datar berbentuk segi empat
glBegin(GL_QUADS);
    glVertex2f(a,b);
    glVertex2f(c,d);
    glVertex2f(e,f);
    glVertex2f(g,h);
    glEnd(); }

void triangle(float a, float b, float c, float d, float e, float f){
glBegin(GL_TRIANGLES);
    glVertex2f(a,b);
    glVertex2f(c,d);
    glVertex2f(e,f);
    glEnd(); }

void line(float a, float b, float c, float d){
     glBegin(GL_LINES);
     glVertex2f(a,b);
     glVertex2f(c,d);
     glEnd(); }

// Fungsi update
GLfloat cloudP = 2.0f; // awan - posisi horizontal awan
GLfloat cloudS = 0.02f; // kecepatan awan
void cloudUp(int value) { // pergerakan awan
    if(cloudP < -2.0) // jika posisi awan lebih kecil dari -2.0
        cloudP = 2.0f; // maka akan direset ke 2.0
    cloudP -= cloudS; // awan bergerak ke kiri
    glutPostRedisplay();
    glutTimerFunc(100, cloudUp, 0); }

GLfloat treeP1=0.0;GLfloat treeP2=0.0;GLfloat treeP3=0.0; // Pohon
GLfloat treeP4=0.0;GLfloat treeP5=0.0;
GLfloat treeS1=0.03;GLfloat treeS2=0.03;GLfloat treeS3=0.03;
GLfloat treeS4=0.03;GLfloat treeS5=0.03;
void treeUp(int value){ // pergerakan pohon secara vertikal
    if(treeP1 < -1.0){
        treeS1 = 0.0f;
        if(treeP2 < -1.0){
            treeS2 = 0.0f;
            if(treeP3 < -1.0){
                treeS3 = 0.0f;
                if(treeP4 < -1.0){
                    treeS4 = 0.0f;
                    if(treeP5 < -1.20){
                        treeS5 = 0.0f; }
                    treeP5 -= treeS5;}
                treeP4 -= treeS4;}
            treeP3 -= treeS3;}
         treeP2 -= treeS2;}
    treeP1 -= treeS1;
    glutPostRedisplay();
    glutTimerFunc(100, treeUp, 0); }

GLfloat sunP = 0.0f; // matahari - posisi horizontal matahari
GLfloat sunS = 0.005f; // kecepatan matahari
void sunUp(int value) {
    if(sunP >1.5) // pergerakan matahari dari kanan
        sunS = 0.0f;
    sunP += sunS;
    glutPostRedisplay();
    glutTimerFunc(100, sunUp, 0); }

GLfloat RcloudP = 3.5f; // Awan - Posisi horizaontal awan
GLfloat RcloudS = 0.02f;
void RcloudUp(int value) {
    if(RcloudP < -0.0)
        RcloudP = 1.0f;
    RcloudP -= RcloudS;
	glutPostRedisplay();
	glutTimerFunc(100, RcloudUp, 0); }

GLfloat wSpeed=0.0f; // Kincir Angin
void windmill(){
    glColor3ub(183, 188, 205); // pillar - abu kebiruan
    quad(-.01,0,-.03,-.35,.03,-.35,.01,0);
    glPushMatrix(); // menyimpan matriks transformasi saat ini dalam stack
    glRotatef(wSpeed,0.0,0.0,0.1); // rotasi objeksebesar 'wSpeed' derajat
    glColor3ub(196, 199, 212); // abu kebiruan
    quad(0,0,0,.2,-.1,.2,0,0);
    quad(0,0,0,-.2,.1,-.2,0,0);
    quad(0,0,.2,0,.2,.1,0,0);
    quad(0,0,-.2,0,-.2,-.1,0,0);
    glPopMatrix(); // mengambil transformasi terakhir pada stack
    wSpeed-=0.15f;
	glColor3ub(252, 252, 252); // tengah - putih
    circle(0.0,0.0,.015); }

GLfloat boatP = 1.2f; // perahu - posisi horizontal perahu
GLfloat boatS = 0.02f; // kecepatan perahu
void boatUp(int value) {
    if(boatP <-1.5) // Jika posisi perahu lebih kecil dari -1.5
        boatP = 1.2f; // maka akan direset ke 1.2
    boatP -= boatS;
    glutPostRedisplay();
    glutTimerFunc(100, boatUp, 0); }

void sky(){ // Langit
    glBegin(GL_QUADS);
    glVertex2f(-1,0);
    glVertex2f(1,0);
    glVertex2f(1,1);
    glVertex2f(-1,1);
    glEnd(); }

void mountain(){ // Gunung
    glColor3ub(61, 119, 135); // kanan - biru kehijauan
    triangle(.55,0,1.1,0,.8,.22);
    glColor3ub(29, 78, 92); // biru kehijauan lebih gelap
    triangle(.55,0,.65,0,.8,.22);
    glBegin(GL_QUADS); //main mountain
    glColor3ub(75, 152, 173); // biru terang
    glVertex2f(-.35,0);
    glVertex2f(.75,0);
    glVertex2f(.25,.45);
    glVertex2f(.1,.43);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 255); // putih
    glVertex2f(.25,.45);
    glVertex2f(.1,.43);
    glVertex2f(-.039,.3);
    glVertex2f(.08,.35);
    glVertex2f(.06,.25);
    glVertex2f(.17,.355); // kiri atas 2
    glVertex2f(.25,.27);
    glVertex2f(.25,.38); // kiri atas 1
    glVertex2f(.42,.3); // kanan bawah
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(61, 119, 135); // biru kehijauan
    glVertex2f(-1.1,0); //left 1
    glVertex2f(-.75,0);
    glVertex2f(-.9,.12);
    glColor3ub(29, 78, 92);
    glVertex2f(-1.1,0);
    glVertex2f(-.98,0);
    glVertex2f(-.9,.12);
    glColor3ub(61, 119, 135); //kiri2 - biru kehijauan
    glVertex2f(-.8,0);
    glVertex2f(-.3,0);
    glVertex2f(-.55,.15);
    glColor3ub(29, 78, 92);
    glVertex2f(-.8,0);
    glVertex2f(-.7,0);
    glVertex2f(-.55,.15);
    glColor3ub(61, 119, 135); //kiri besar - biru kehijauan
    glVertex2f(-.45,0);
    glVertex2f(.1,0);
    glVertex2f(-.2,.23);
    glColor3ub(29, 78, 92);
    glVertex2f(-.45,0);
    glVertex2f(-.35,0);
    glVertex2f(-.2,.23);
    glColor3ub(61, 119, 135); ////tengah - biru kehijauan
    glVertex2f(-.1,0);
    glVertex2f(.3,0);
    glVertex2f(.1,.12);
    glColor3ub(29, 78, 92);
    glVertex2f(-.1,0);
    glVertex2f(0,0);
    glVertex2f(.1,.12);
    glEnd(); }

void house(){ // Rumah
    circle(0.52,-.33,.04); // rumput rumah - kiri
    circle(0.49,-.34,.03);
    glTranslated(.4,-.005,0); // transalasi objek dipindahkan sebesar x,y
    circle(0.52,-.31,.045); // rumput rumah - kanan
    circle(0.55,-.325,.03);
    glLoadIdentity(); // mengembalikan koordinat dan transformasi ke kondisi awal
    glScalef(1.2,1.2,0); // rumah - skala objek, objek yg digambar akan diperbesar 1.2 pada x dan y
    glTranslated(.05,0.0,0);
    glBegin(GL_QUADS); // tembok rumah
    glColor3ub(250, 232, 224);
    glVertex2f(.4,-.1);
    glVertex2f(.4,-.3);
    glVertex2f(.7,-.3);
    glVertex2f(.7,-.1);
    glEnd();
    glBegin(GL_QUADS); // pintu
    glColor3ub(150, 99, 58); // coklat
    glVertex2f(.52,-.2);
    glVertex2f(.52,-.3);
    glVertex2f(.58,-.3);
    glVertex2f(.58,-.2);
    glEnd();
    glBegin(GL_QUADS); // jendela
    glColor3ub(255, 255, 255); // putih
    glVertex2f(.43,-.21);
    glVertex2f(.43,-.26);
    glVertex2f(.49,-.26);
    glVertex2f(.49,-.21);
    glVertex2f(.61,-.21); // jendela
    glVertex2f(.61,-.26);
    glVertex2f(.67,-.26);
    glVertex2f(.67,-.21);
    glEnd();
    glBegin(GL_POLYGON); // atap
    glColor3ub(196, 94, 11); // merah kecoklatan
    glVertex2f(.39,-.05);
    glVertex2f(.37,-.18);
    glVertex2f(.73,-.18);
    glVertex2f(.71,-.05);
    glEnd();
    glBegin(GL_QUADS); // bawah rumah
    glColor3ub(196, 94, 11); // merah kecoklatan
    glVertex2f(.39,-.29);
    glVertex2f(.39,-.31);
    glVertex2f(.71,-.31);
    glVertex2f(.71,-.29);
    glEnd();
    glLoadIdentity(); }

void downFlower(){ // Bunga
    glColor3ub(250, 232, 224); // kiri1 - putih
    circle(-.78,-.9f,.02);
    circle(-.72,-.9f,.02);
    circle(-.75,-.87f,.02);
    circle(-.75f,-.93,.02);
    glColor3ub(250, 197, 40); // center - putih
    circle(-.75f,-.9,.015);

    glTranslated(.25,-.03,0);
    glColor3ub(250, 232, 224); // 2 - putih
    circle(-.78,-.9,.02);
    circle(-.72,-.9,.02);
    circle(-.75,-.87,.02);
    circle(-.75,-.93,.02);
    glColor3ub(250, 197, 40); // center - kuning
    circle(-.75,-.9,.015);
    glLoadIdentity();

    glTranslated(.42,-.0,0);
    glColor3ub(255, 202, 202); // 3 - pink
    circle(-.78,-.9,.02);
    circle(-.72,-.9,.02);
    circle(-.75,-.87,.02);
    circle(-.75,-.93,.02);
    glColor3ub(250, 197, 40); // center - kuning
    circle(-.75,-.9,.015);
    glLoadIdentity();

    glTranslated(.7,-.01,0);
    glColor3ub(255, 202, 202); // 4 - pink
    circle(-.78,-.9,.02);
    circle(-.72,-.9,.02);
    circle(-.75,-.87,.02);
    circle(-.75,-.93,.02);
    glColor3ub(250, 197, 40); // center - kuning
    circle(-.75,-.9,.015);
    glLoadIdentity();

    glTranslated(.87,.07,0);
    glColor3ub(250, 232, 224); // 5 - putih
    circle(-.78,-.9,.02);
    circle(-.72,-.9,.02);
    circle(-.75,-.87,.02);
    circle(-.75,-.93,.02);
    glColor3ub(250, 197, 40); // center - kuning
    circle(-.75,-.9,.015);
    glLoadIdentity();

    glTranslated(1.12,-.03,0);
    glColor3ub(250, 232, 224); // 6 - putih
    circle(-.78,-.9,.02);
    circle(-.72,-.9,.02);
    circle(-.75,-.87,.02);
    circle(-.75,-.93,.02);
    glColor3ub(250, 197, 40); // center - kuning
    circle(-.75,-.9,.015);
    glLoadIdentity();

    glTranslated(1.5,.04,0);
    glColor3ub(255, 202, 202); // 7 - pink
    circle(-.78,-.9,.02);
    circle(-.72,-.9,.02);
    circle(-.75,-.87,.02);
    circle(-.75,-.93,.02);
    glColor3ub(250, 197, 40); // center - kuning
    circle(-.75,-.9,.015);
    glLoadIdentity();

    glTranslated(1.36,-.0,0);
    glColor3ub(255, 202, 202); // 8 - pink
    circle(-.78,-.9,.02);
    circle(-.72,-.9,.02);
    circle(-.75,-.87,.02);
    circle(-.75,-.93,.02);
    glColor3ub(250, 197, 40); // center - kuning
    circle(-.75,-.9,.015);
    glLoadIdentity(); }

void tree(){ // Pohon
    glBegin(GL_POLYGON);
    glColor3ub(69, 30, 14); // coklat
    glVertex2f(-.67,-.2);
    glVertex2f(-.84,-.85);
    glVertex2f(-.73,-.85);
    glVertex2f(-.6,-.2);
    glEnd();
    quad(-.6,-.22,-.4,-.29,-.39,-.28,-.55,-.2); //kanan bawah
    quad(-.63,-.18,-.65,-.28,-.4,-.1,-.33,-.09); // kanan tengah
    quad(-.6,-.18,-.55,-.18,-.55,-.01,-.56,-.02); // kanan atas
    quad(-.75,-.16,-.68,-.18,-.78,.02,-.8,.03); // kiri atas
    quad(-.63,-.18,-.62,-.28,-.9,-.14,-.89,-.12); // kiri bawah
    glBegin(GL_QUADS);
    //root
    glVertex2f(-.83,-.82);
    glVertex2f(-.95,-.88);
    glVertex2f(-.81,-.85);
    glVertex2f(-.81,-.82);
    glVertex2f(-.81,-.82);
    glVertex2f(-.83,-.84);
    glVertex2f(-.63,-.89);
    glVertex2f(-.73,-.82);
    glEnd(); }

void downGrass(){ // Rumput / semak depan
    glColor3ub(30, 74, 15);
    circle(-.9,-.9,.2);
    glColor3ub(30, 74, 15);
    circle(-.33,-.93,.115);
    glColor3ub(63, 163, 20);
    circle(-.7,-.9,.15);
    glColor3ub(63, 163, 20);
    circle(-.5,-.95,.1);
    glColor3ub(63, 163, 20);
    circle(-.18,-.95,.08);
    glColor3ub(63, 163, 20);
    circle(-.03,-.95,.11);
    glTranslated(.87,.0,0);
    glColor3ub(49, 128, 15);
    circle(-.7,-.9,.15);
    glColor3ub(49, 128, 15);
    circle(-.5,-.95,.1);
    glLoadIdentity();
    glColor3ub(63, 163, 20);
    circle(.52,-.95,.09);
    glColor3ub(30, 74, 15);
    circle(0.9,-.9,.19);
    glColor3ub(63, 163, 20);
    circle(.7,-.93,.13); }

void river(){ // Sungai
    glScalef(0.25,.2,0);
    glTranslated(2.,.86,0);
    glLoadIdentity();
    glBegin(GL_QUADS);
    glColor3ub(150, 201, 38); // tepi sungai - hijau
    glVertex2f(-1,-.00);
    glVertex2f(1,-.00);
    glVertex2f(1,-.01);
    glVertex2f(-1,-.01);
    glColor3ub(43, 155, 207); // biru
    glVertex2f(-1,-.01);
    glVertex2f(1,-.01);
    glVertex2f(1,-.1);
    glVertex2f(-1,-.1);
    glEnd();
    glColor3ub(109, 170, 199); // aliran sungai - biru
    glLineWidth(.05);
    line(-0.85,-.06,-0.95,-.06);
    line(-0.5,-.035,-.56,-.035);
    line(0.0,-.06,-0.1,-.06);
    line(0.8,-.03,0.9,-.03); }

void longGrass(){ // Rumput panjang
    glScalef(0.24,.2,0);
    glTranslated(0.8,.49,0);
    glColor3ub(68, 173, 47); // kanan - hijau
    triangle(-.5,-1.0,-.45,-1.0,-.35,-.65);
    triangle(-.5,-1.0,-.45,-1.0,-.6,-.65);
    triangle(-.2,-1.0,-.15,-1.0,-.35,-.65);
    triangle(-.2,-1.0,-.15,-1.0,-.0,-.65);
    triangle(-.45,-1.0,-.4,-1.0,-.2,-.65);
    triangle(.15,-1.0,.2,-1.0,.35,-.65);
    triangle(.15,-1.0,.2,-1.0,.05,-.65);
    triangle(.45,-1.0,.5,-1.0,.35,-.65);
    triangle(.55,-1.0,.6,-1.0,.55,-.65);
    triangle(.6,-1.0,.65,-1.0,.8,-.65);
    triangle(.85,-1.0,.9,-1.0,1.0,-.65);
    glLoadIdentity();
    glScalef(0.25,.2,0);
    glTranslated(0.0,.49,0);
    glColor3ub(68, 173, 47); // tengah - hijau
    triangle(-.5,-1.0,-.45,-1.0,-.35,-.65);
    triangle(-.5,-1.0,-.45,-1.0,-.6,-.65);
    triangle(-.2,-1.0,-.15,-1.0,-.35,-.65);
    triangle(-.2,-1.0,-.15,-1.0,-.0,-.65);
    triangle(-.45,-1.0,-.4,-1.0,-.2,-.65);
    triangle(.15,-1.0,.2,-1.0,.35,-.65);
    triangle(.15,-1.0,.2,-1.0,.05,-.65);
    triangle(.45,-1.0,.5,-1.0,.35,-.65);
    triangle(.55,-1.0,.6,-1.0,.55,-.65);
    triangle(.6,-1.0,.65,-1.0,.8,-.65);
    triangle(.85,-1.0,.9,-1.0,1.0,-.65);
    glLoadIdentity();
    glScalef(0.25,.2,0);
    glTranslated(-2.5,.49,0);
    glColor3ub(68, 173, 47); // kiri - hijau
    triangle(-.5,-1.0,-.45,-1.0,-.35,-.65);
    triangle(-.5,-1.0,-.45,-1.0,-.6,-.65);
    triangle(-.2,-1.0,-.15,-1.0,-.35,-.65);
    triangle(-.2,-1.0,-.15,-1.0,-.0,-.65);
    triangle(-.45,-1.0,-.4,-1.0,-.2,-.65);
    triangle(.15,-1.0,.2,-1.0,.35,-.65);
    triangle(.15,-1.0,.2,-1.0,.05,-.65);
    triangle(.45,-1.0,.5,-1.0,.35,-.65);
    triangle(.55,-1.0,.6,-1.0,.55,-.65);
    triangle(.6,-1.0,.65,-1.0,.8,-.65);
    triangle(.85,-1.0,.9,-1.0,1.0,-.65);
    glLoadIdentity(); }

void boat(){ // Perahu
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(250, 232, 224); // putih - tali tiang
    glVertex2f(-.01,-.04);
    glVertex2f(-.01,.3);
    glVertex2f(-.1,-.04);
    glVertex2f(-.01,.28);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(252, 25, 0); // merah - bendera
    glVertex2f(-.01,.28);
    glVertex2f(-.01,-.0);
    glVertex2f(.14,-.0);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(196, 94, 11); // coklat - bawah perahu
    glVertex2f(-.12,-.03);
    glVertex2f(-.1,-.06);
    glVertex2f(.1,-.06);
    glVertex2f(.12,-.03);
    glEnd(); }

void cloud(){ // Awan
    circle(.625,.58,.05);
    circle(.7,.6,.08);
    circle(.79,.582,.06);
    circle(.85,.58,.04);
    circle(-.425,.585,.04); // Kiri
    circle(-.5,.6,.07);
    circle(-.59,.592,.05);
    circle(-.64,.58,.03); }

void ground(){ // dataran berbentuk jalan
    glBegin(GL_QUADS);
    glVertex2f(-1,-1);
    glVertex2f(1,-1);
    glVertex2f(1,0);
    glVertex2f(-1,0);
    glEnd(); }

void field(){
    triangle(-.5,-.2,1,-.4,1,-.1);
    triangle(-1,-.4,-1,-.7,0,-.5); }

void treeLeaf(){ // dauh pohon
    glColor3ub(41, 140, 42); // Kanan besar - hijau
    circle(-0.36,-0.02,.22);
    glColor3ub(95, 168, 47); // kanan kecil - hijau
    circle(-0.4,-0.3f,.13);
    glColor3ub(30, 74, 34); // kiri kecil - hijau
    circle(-0.895,-0.13,.15);
    glColor3ub(41, 140, 42); // kiri besar - hijau
    circle(-0.77,0.07,.2);
    glColor3ub(105, 184, 53); // tengah - hijau
    circle(-0.54,0.1,.22); }

void roadGrass(){ // Rumput tepi sungai
    circle(0.1,.005,.07); //left
    circle(0.2,.002,.04);
    circle(0.8,.005,.035); //right
    circle(0.88,.005,.065);}

void rainCloud(){ // awan mendung
    circle(-2.03,.95,.1);
    circle(-1.84,.93,.15);
    circle(-1.54,.93,.18);
    circle(-1.28,.93,.15);
    circle(-1.0,.93,.17);
    circle(-.93,.95,.1);
    circle(-.72,.93,.15);
    circle(-.5,.93,.18);
    circle(-.28,.93,.15);
    circle(0.0,.95,.17);
    circle(.2,.93,.15);
    circle(.43,.93,.2);
    circle(.65,.93,.13);
    circle(.8,.95,.15);
    circle(.95,.95,.08); }

// Fungsi display
void summer();
void summer_rain();
void rainDay();
void dry();

void Idle() { // untuk melakukan render kembali atau redisplay
    glutPostRedisplay(); }

void display_summer_rain(int b) { // fungsi callback tampilan summer rain
    glutDisplayFunc(summer_rain); }

void display_rainyDay(int b) { // fungsi callback tampilan rainy day
    glutDisplayFunc(rainDay); }

void display_dry(int b) { // fungsi callback dry (kemarau)
    glutDisplayFunc(dry); }

void summer() { // summer
    glClearColor(1.0f,1.0f,1.0f,1.0f); // putih
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3ub(148, 208, 242); //  langit - biru
    sky();
    mountain();
    glColor3ub(242, 245, 243); // awan - putih
    glPushMatrix();
    glTranslatef(cloudP, 0.0f,0.0f);
    cloud();
    glPopMatrix();
    glLoadIdentity();
    glColor3ub(247, 232, 99); // matahari - kuning
    circle(0.0,.75,.09);
    glColor3ub(242, 245, 243); // awan matahari - putih
    circle(-.08,.7,.04);
    circle(-.00,.71,.07);
    circle(0.09,.71,.05);
    glColor3ub(150, 201, 38); // dataran berbentuk jalan - hijau
    ground();
    glColor3ub(178, 227, 79); // field - hijau
    field();
    glColor3ub(47, 158, 68); // rumput tepi sungai - hijau
    roadGrass();
    river();
    glPushMatrix(); // perahu
    glTranslatef(boatP, 0.0f,0.0f);
    boat();
    glPopMatrix();
    glLoadIdentity();
    longGrass();
    glScalef(0.7,0.7,0); // kincir angin
    glTranslated(0.9,0.2,0);
    windmill();
    glLoadIdentity();
    glColor3ub(41, 140, 42); // rumah - rumput rumah hijau
    house();
    treeLeaf();
    tree();
    downGrass();
    downFlower();
    glutTimerFunc(20000,display_summer_rain,0);
    Idle();
    glFlush(); }

void summer_rain() { // SUMMER_RAIN
    glClearColor(1.0f,1.0f,1.0f,1.0f); // putih
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3ub(153, 197, 222); // langit - biru
    sky();
    mountain();
    glPushMatrix(); // matahari
    glTranslatef(0.0f,sunP,0.0f);
    glColor3ub(247, 232, 99); // kuning
    circle(0.0,.75,.09);
    glColor3ub(242, 245, 243); // awan matahari - putih
    circle(-.08,.7,.04);
    circle(-.00,.71,.07);
    circle(0.09,.71,.05);
    glPopMatrix();
    glLoadIdentity();
    glColor3ub(175, 182, 186); // awan hujan abu abu
    glPushMatrix();
    glTranslatef(RcloudP, 0.0f,0.0f);
    rainCloud();
    glPopMatrix();
    glLoadIdentity();
    glColor3ub(150, 201, 38); // dataran - hijau
    ground();
    glColor3ub(178, 227, 79); // field - hijau
    field();
    glColor3ub(47, 158, 68); // rumput tepi sungai - hijau
    roadGrass();
    river();
    glPushMatrix(); // perahu
    glTranslatef(boatP, 0.0f,0.0f);
    boat();
    glPopMatrix();
    glLoadIdentity();
    longGrass();
    glScalef(0.7,0.7,0); // kincir angin
    glTranslated(0.9,0.2,0);
    windmill();
    glLoadIdentity();
    glColor3ub(47, 158, 68); // rumput rumah - hijau
    house();
    treeLeaf();
    tree();
    downGrass();
    downFlower();
    glutTimerFunc(20000,display_rainyDay,0);
    Idle();
    glFlush(); }

void rainDay() { // RAINY_DAY
    glClearColor(1.0f,1.0f,1.0f,1.0f); // putih
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3ub(129, 153, 164); // langit - biru abu
    sky();
    mountain();
    glColor3ub(158, 161, 163); // awan mendung - abu abu
    glPushMatrix();
    glTranslatef(RcloudP, 0.0f,0.0f);
    rainCloud();
    glPopMatrix();
    glColor3ub(130, 179, 82); // daratan berbentuk jalan -  hijau
    ground();
    glColor3ub(162, 201, 83); // field - hijau
    field();
    glColor3ub(47, 158, 68); // semak tepi sungai - hijau
    roadGrass();
    river();
    glPushMatrix();
    glTranslatef(boatP, 0.0f,0.0f);
    boat();
    glPopMatrix();
    glLoadIdentity();
    longGrass();
    glScalef(0.7,0.7,0); // kincir angin
    glTranslated(0.9,0.2,0);
    windmill();
    glLoadIdentity();
    glColor3ub(47, 158, 68); // rumput rumah - hijau
    house();
    treeLeaf();
    tree();
    downGrass();
    downFlower();
    glLoadIdentity();
    glutTimerFunc(20000,display_dry,0);
    Idle();
    glFlush(); }

// dry
void dry(){
    glClearColor(1.0f,1.0f,1.0f,1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3ub(193, 234, 255); // langit
    sky();
    mountain();
    glColor3ub(242, 245, 243); // awan
    glPushMatrix();
    glTranslatef(cloudP, 0.0f,0.0f);
    cloud();
    glPopMatrix();
    glLoadIdentity();
    glColor3ub(247, 232, 99); // sun
    circle(0.0,.75,.09);
    glColor3ub(242, 245, 243); // awannya matahari
    circle(-.08,.7,.04);
    circle(-.00,.71,.07);
    circle(0.09,.71,.05);
    glColor3ub(192, 219, 39); //ground
    ground();
    glColor3ub(209, 237, 52); //filed
    field();
    glColor3ub(141, 212, 59); //grass road
    roadGrass();
    river();
    glPushMatrix();
    glTranslatef(boatP, 0.0f,0.0f); //boat
    boat();
    glPopMatrix();
    glLoadIdentity();
    longGrass();
    glScalef(0.7,0.7,0); //windmill
    glTranslated(0.9,0.2,0);
    windmill();
    glLoadIdentity();
    glColor3ub(141, 212, 59); // semak rumah
    house();
    glPushMatrix(); // daun pohon - kanan besar
    glTranslatef(0.0f,treeP3,0.0f);
    glColor3ub(138, 163, 54);
    circle(-0.36,-0.05,.13);
    glPopMatrix();
    glLoadIdentity();
    glPushMatrix(); // daun pohon - kanan kecil
    glTranslatef(0.0f,treeP2,0.0f);
    glColor3ub(159, 173, 50);
    circle(-0.4,-0.3f,.08);
    glPopMatrix();
    glLoadIdentity();
    glPushMatrix(); // daun pohon - kiri kecil
    glTranslatef(0.0f,treeP1,0.0f);
    glColor3ub(99, 112, 39);
    circle(-0.895,-0.13,.08);
    glPopMatrix();
    glLoadIdentity();
    glPushMatrix(); // daun pohon - kiri besar
    glTranslatef(0.0f,treeP4,0.0f);
    glColor3ub(138, 163, 54);
    circle(-0.77,0.07,.15);
    glPopMatrix();
    glLoadIdentity();
    glPushMatrix(); // daun pohon - tengah
    glTranslatef(0.0f,treeP5,0.0f);
    glColor3ub(176, 191, 57);
    circle(-0.54,0.1,.16);
    glPopMatrix();
    glLoadIdentity();
    tree();
    downGrass();
    Idle();
    glFlush(); }

void SpecialInput(int key, int x, int y){ // untuk mempercepat atau memperlambat perahu
    switch(key) {
        case GLUT_KEY_UP:
        break;
        case GLUT_KEY_DOWN:
        break;
        case GLUT_KEY_LEFT: // tekan tombol arah kiri maka perahu semakin cepat
        boatS=0.025f;
        break;
        case GLUT_KEY_RIGHT: // tekan tombol arah kanan maka perahu semakin lambat
        boatS=0.01f;
        break; }
    glutPostRedisplay(); }

void handleMouse(int button, int state, int x, int y) { // mengontrol awan
	if (button == GLUT_LEFT_BUTTON) { // memberhentikan awan
        cloudS=0.0f;
	    RcloudS=0.0f; }
    if (button == GLUT_RIGHT_BUTTON) { // menjalankan awan kembali
	    cloudS=0.02f;
	    RcloudS=0.03f; }
	glutPostRedisplay(); }

int main(int argc, char *argv[]) {
    //glutIdleFunc(Idle);
    glutInit(&argc,argv);
    glutInitWindowPosition(300,30);
    glutCreateWindow("Pergantian Musim");
    glutReshapeWindow(800,700);
    glutDisplayFunc(summer);
    glutTimerFunc(100, cloudUp, 0);
    glutTimerFunc(20510, RcloudUp, 0);
    glutTimerFunc(70505,treeUp,0);
    glutTimerFunc(10, boatUp, 0);
    glutTimerFunc(20000, sunUp, 0);
    glutSpecialFunc(SpecialInput);
    glutMouseFunc(handleMouse);

    glutMainLoop();
    return 0;}
