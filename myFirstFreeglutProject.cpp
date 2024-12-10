#include <glut.h>

float
fx = 2.5, fy = 2, fz = 1.5,
tx = 0, ty = 0, tz = 0,
yp = 0;

void cameraLook()
{
    gluLookAt(fx, fy, fz,
        tx, ty, tz,
        0, 1, 0
    );

    GLfloat light_position[] = { 0, 50, 100, 0.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_COLOR_MATERIAL);
}


void draw()
{
    // Background depan
    glBegin(GL_QUADS);
    glColor3ub(255, 0, 255); // Warna biru untuk background
    glVertex3f(-3.0, 3.0, -3.0); // Kiri atas
    glVertex3f(3.0, 3.0, -3.0);  // Kanan atas
    glVertex3f(3.0, -0.5, -3.0); // Kanan bawah
    glVertex3f(-3.0, -0.5, -3.0);// Kiri bawah
    glEnd();

    // BG kiri
    glBegin(GL_QUADS);
    glColor3ub(0, 255, 255); // Warna pink untuk background
    glVertex3f(3.0, 3, 3.0);
    glVertex3f(3, 3, -3.0);
    glVertex3f(3, -0.5, -3.0);
    glVertex3f(3.0, -0.5, 3.0);
    glEnd();

    // * MEJA *
    // Permukaan meja
    glBegin(GL_QUADS);
    glColor3ub(139, 69, 19); // Warna coklat kayu
    glVertex3f(-1.0, 0.5, -1.0); // Kiri belakang
    glVertex3f(1.0, 0.5, -1.0);  // Kanan belakang
    glVertex3f(1.0, 0.5, 1.0);   // Kanan depan
    glVertex3f(-1.0, 0.5, 1.0);  // Kiri depan
    glEnd();

    // Kaki meja (4 kaki)
    glBegin(GL_QUADS);
    glColor3ub(192, 192, 192); // Warna silver

    // Kaki kiri depan
    glVertex3f(-0.9, 0.5, 0.9);
    glVertex3f(-0.8, 0.5, 0.9);
    glVertex3f(-0.8, -0.5, 0.9);
    glVertex3f(-0.9, -0.5, 0.9);

    glVertex3f(-0.9, 0.5, 0.8);
    glVertex3f(-0.8, 0.5, 0.8);
    glVertex3f(-0.8, -0.5, 0.8);
    glVertex3f(-0.9, -0.5, 0.8);

    // Kaki kiri belakang
    glVertex3f(-0.9, 0.5, -0.9);
    glVertex3f(-0.8, 0.5, -0.9);
    glVertex3f(-0.8, -0.5, -0.9);
    glVertex3f(-0.9, -0.5, -0.9);

    // Kaki kanan depan
    glVertex3f(0.8, 0.5, 0.9);
    glVertex3f(0.9, 0.5, 0.9);
    glVertex3f(0.9, -0.5, 0.9);
    glVertex3f(0.8, -0.5, 0.9);

    // Kaki kanan belakang
    glVertex3f(0.8, 0.5, -0.9);
    glVertex3f(0.9, 0.5, -0.9);
    glVertex3f(0.9, -0.5, -0.9);
    glVertex3f(0.8, -0.5, -0.9);

    glEnd();

    // * KURSI *
    // Tempat duduk
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 255); // Warna biru
    glVertex3f(-1.5, 0.2, -0.5);
    glVertex3f(-0.5, 0.2, -0.5);
    glVertex3f(-0.5, 0.2, 0.5);
    glVertex3f(-1.5, 0.2, 0.5);
    glEnd();

    // Kaki kursi (4 kaki)
    glBegin(GL_QUADS);
    glColor3ub(192, 192, 192); // Warna silver

    // Kaki kiri depan
    glVertex3f(-1.4, 0.2, 0.4);
    glVertex3f(-1.3, 0.2, 0.4);
    glVertex3f(-1.3, -0.5, 0.4);
    glVertex3f(-1.4, -0.5, 0.4);

    // Kaki kanan depan
    glVertex3f(-0.7, 0.2, 0.4);
    glVertex3f(-0.6, 0.2, 0.4);
    glVertex3f(-0.6, -0.5, 0.4);
    glVertex3f(-0.7, -0.5, 0.4);

    // Kaki kiri belakang
    glVertex3f(-1.4, 0.2, -0.4);
    glVertex3f(-1.3, 0.2, -0.4);
    glVertex3f(-1.3, -0.5, -0.4);
    glVertex3f(-1.4, -0.5, -0.4);

    // Kaki kanan belakang
    glVertex3f(-0.7, 0.2, -0.4);
    glVertex3f(-0.6, 0.2, -0.4);
    glVertex3f(-0.6, -0.5, -0.4);
    glVertex3f(-0.7, -0.5, -0.4);

    glEnd();

    // Sandaran kursi
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 255); // Warna biru
    glVertex3f(-1.5, 1.2, -0.5);
    glVertex3f(-1.5, 1.2, 0.5);
    glVertex3f(-1.5, 0.2, 0.5);
    glVertex3f(-1.5, 0.2, -0.5);
    glEnd();

    // Alas (dinaikkan ke Y = -0.5)
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255); // Warna putih untuk alas (tanah)
    glVertex3f(-3.0, -0.5, 3.0);  // Kiri depan
    glVertex3f(3.0, -0.5, 3.0);   // Kanan depan
    glVertex3f(3.0, -0.5, -3.0);  // Kanan belakang
    glVertex3f(-3.0, -0.5, -3.0); // Kiri belakang
    glEnd();

    // Papan tulis
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255); // Warna putih untuk papan tulis
    glVertex3f(1.8, 2.5, 1.8);  // Kanan atas depan
    glVertex3f(1.8, 2.5, -1.8); // Kanan atas belakang
    glVertex3f(1.8, 0.5, -1.8);   // Kanan bawah belakang
    glVertex3f(1.8, 0.5, 1.8);    // Kanan bawah depan
    glEnd();

    // Garis tepi papan tulis menggunakan GL_LINES
    glLineWidth(3.0);            // Ketebalan garis
    glBegin(GL_LINES);
    glColor3ub(139, 69, 19);     // Warna coklat untuk garis tepi

    // Garis atas
    glVertex3f(1.8, 2.5, 1.8);   // Kanan atas depan
    glVertex3f(1.8, 2.5, -1.8);  // Kanan atas belakang

    // Garis bawah
    glVertex3f(1.8, 0.5, 1.8);     // Kanan bawah depan
    glVertex3f(1.8, 0.5, -1.8);    // Kanan bawah belakang

    // Garis kiri
    glVertex3f(1.8, 2.5, -1.8);  // Kanan atas belakang
    glVertex3f(1.8, 0.5, -1.8);    // Kanan bawah belakang

    // Garis kanan
    glVertex3f(1.8, 2.5, 1.8);   // Kanan atas depan
    glVertex3f(1.8, 0.5, 1.8);     // Kanan bawah depan

    glEnd();

    //buku
   // Buku tebal berwarna merah di atas meja
    glBegin(GL_QUADS);
    glColor3ub(255, 0, 0); // Sisi merah

    // Sisi atas buku
    glVertex3f(-0.6, 0.51, 0.2);   // Kiri depan
    glVertex3f(0.2, 0.51, 0.2);    // Kanan depan
    glVertex3f(0.2, 0.51, -0.2);   // Kanan belakang
    glVertex3f(-0.6, 0.51, -0.2);  // Kiri belakang

    // Sisi samping kiri buku (putih)
    glColor3ub(255, 255, 255); // Warna putih
    glVertex3f(-0.6, 0.51, -0.2);
    glVertex3f(-0.6, 0.51, 0.2);
    glVertex3f(-0.6, 0.5, 0.2);
    glVertex3f(-0.6, 0.5, -0.2);

    // Sisi samping kanan buku (putih)
    glVertex3f(0.2, 0.51, -0.2);
    glVertex3f(0.2, 0.51, 0.2);
    glVertex3f(0.2, 0.5, 0.2);
    glVertex3f(0.2, 0.5, -0.2);

    // Sisi depan buku (putih)
    glVertex3f(-0.6, 0.51, 0.2);
    glVertex3f(0.2, 0.51, 0.2);
    glVertex3f(0.2, 0.5, 0.2);
    glVertex3f(-0.6, 0.5, 0.2);

    // Sisi belakang buku (putih)
    glVertex3f(-0.6, 0.51, -0.2);
    glVertex3f(0.2, 0.51, -0.2);
    glVertex3f(0.2, 0.5, -0.2);
    glVertex3f(-0.6, 0.5, -0.2);

    glEnd();


}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    cameraLook();
    draw();
    glutSwapBuffers();
}

void reshape(int w, int h)
{
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(75, (GLsizei)w / (GLsizei)h, 1, 300);
    glMatrixMode(GL_MODELVIEW);
}

void timer(int value)
{
    yp += 10;
    if (yp >= 360)
    {
        yp = 0;
    }
    glutPostRedisplay();
    glutTimerFunc(100, timer, 0);
}

void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'W':
    case 'w':
        fy += 2;
        break;
    case 'S':
    case 's':
        fy -= 2;
        break;
    case 'A':
    case 'a':
        fx -= 2;
        break;
    case 'D':
    case 'd':
        fx += 2;
        break;
    case 'O':
    case 'o':
        fz -= 2;
        break;
    case 'L':
    case 'l':
        fz += 2;
        break;
    }
}

void specialKey(int key, int x, int y)
{
    switch (key)
    {
    case GLUT_KEY_UP:
        ty += 2;
        break;
    case GLUT_KEY_DOWN:
        ty -= 2;
        break;
    case GLUT_KEY_LEFT:
        tx -= 2;
        break;
    case GLUT_KEY_RIGHT:
        tx += 2;
        break;
    case GLUT_KEY_PAGE_UP:
        tz -= 2;
        break;
    case GLUT_KEY_PAGE_DOWN:
        tz += 2;
        break;
    }
}

int main()
{
    glutInit(&__argc, __argv);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutCreateWindow("My Seventh Freeglut Project");
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glOrtho(-2, 2, -2, 2, -2, 2);

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(specialKey);
    glutTimerFunc(1, timer, 0);
    glutMainLoop();
}