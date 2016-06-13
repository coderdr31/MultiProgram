#include <windows.h>

#include <gl/gl.h>
#include <gl/glaux.h>

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
using namespace std;
//������3�����
#pragma comment (lib, "opengl32.lib")  
#pragma comment (lib, "glu32.lib")  
#pragma comment (lib, "glaux.lib")  

#pragma comment( linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"" ) //����ǲ��ÿ���̨������֣������Ҫ���֣�ȥ�����ɡ�

GLuint texture[5];
GLdouble viewer[3]; 
GLdouble dir[3]; 
float    VectorLength;     //��ͶӰ���ļ���۲�㣬����ȷ��ͶӰ���򣬴�С�޹أ���������Ӱ��ͶӰ���
float    alpha;   //�ӵ�ı䷽����y����ת�ĽǶ�
GLdouble viewer_man = 2.0f; 

#include "3DObject.h"
#include "Rose.h"
#include "Soccer.h"
#include "Al.h"

C3DObject* objects[20]; //����������ָ��
int m_count;//�������

CRose  rose;
CSoccer soccer;
CAl al;

float sz = 1.0f;
float sx = 0.0f;
float step = 0.0f;


float fishx = 0.0f;
float fishy = 0.8f;

float alpsco = 0.0f;
float lensco = 0.0f;
float t = 1.0f;

float Lx = 0.0f;
float Ly = 1.0f;
float Lz = 1.0f;




//���嶥���������ɫ
GLfloat vertices[][3] = {{-1.0,-1.0,-1.0},{1.0,-1.0,-1.0},{1.0,1.0,-1.0},
						{-1.0,1.0,-1.0}, {-1.0,-1.0,1.0},{1.0,-1.0,1.0}, 
                        {1.0,1.0,1.0}, {-1.0,1.0,1.0}};
GLfloat colors[][3] = {	{0.0,0.0,0.0},{1.0,0.0,0.0},{1.0,1.0,0.0}, {0.0,1.0,0.0},
						{0.0,0.0,1.0},{1.0,0.0,1.0}, {1.0,1.0,1.0}, {0.0,1.0,1.0}};

GLfloat light_pos[] = { 0.0, 0.0, 1.0, 0.0 };

GLuint LoadGLTexture( const char *filename);

void polygon(int a, int b, int c , int d)
{ 
	if (a==4 || a==1)
	{ 	
		glBindTexture(GL_TEXTURE_2D, texture[0]);
		glEnable(GL_TEXTURE_2D); 
		glColor3f(1,1,1);
		glBegin(GL_POLYGON); 
			glTexCoord2f(0,0); glVertex3fv(vertices[a]); 
			glTexCoord2f(1,0); glVertex3fv(vertices[b]); 
			glTexCoord2f(1,1); glVertex3fv(vertices[c]); 
			glTexCoord2f(0,1); glVertex3fv(vertices[d]); 
		glEnd();
		glDisable(GL_TEXTURE_2D);
		}
	else
	{
		glBindTexture(GL_TEXTURE_2D, texture[1]);
		glEnable(GL_TEXTURE_2D); 
		glColor3f(1,1,1);
		    glBegin(GL_POLYGON); 
			   glTexCoord2f(fishx, fishy); glVertex3fv(vertices[a]); 
			   glTexCoord2f(fishx + 0.2f, fishy); glVertex3fv(vertices[b]); 
			   glTexCoord2f(fishx + 0.2f, fishy + 0.2f); glVertex3fv(vertices[c]); 
			   glTexCoord2f(fishx, fishy + 0.2f); glVertex3fv(vertices[d]); 
		    glEnd();
		glDisable(GL_TEXTURE_2D);		
	}
}

void colorcube()
{
   polygon(0,3,2,1);   
   polygon(2,3,7,6);  
   polygon(7,3,0,4);
   polygon(1,2,6,5);   
   polygon(4,5,6,7);   
   polygon(5,4,0,1);
}

void DrawGround()//�������̸����
{
	int count = 0;
	int size = 64;
	float inter = 4;
	float y=0;

	glPushMatrix();

	glTranslatef(-size*inter/2,0,-size*inter/2);

	glBegin(GL_QUADS); 
	
	for (int i=0; i<size; i++)
	{
		if (i%2==0) count = 1;
		else count = 0;

		for (int j=0; j<size; j++)
		{
			if(count % 2 == 0) glColor3f(1,1,1);
			else glColor3f(0,0,0);
			
			glVertex3f(j*inter,y,i*inter);
			glVertex3f((j+1)*inter,y,i*inter);
			glVertex3f((j+1)*inter,y,(i+1)*inter);
			glVertex3f(j*inter,y,(i+1)*inter);

			count++;
		}
	}
	glEnd();

	glPopMatrix();
}

void RenderScene( )
{ 
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
    //�����ӵ�λ��
	gluLookAt(viewer[0],viewer[1],viewer[2], dir[0], dir[1], dir[2], 0.0, 1.0, 0.0);

	DrawGround();

	glPushMatrix();
	glTranslatef(3,1,0);
	colorcube(); 
	glPopMatrix();




	glEnable(GL_LIGHTING);
	//glPushMatrix();
	GLfloat light_pos[] = { Lx, Ly, Lz, 0.0 };
	glLightfv(GL_LIGHT0, GL_POSITION, light_pos);

	//glPopMatrix();	
	glEnable(GL_LIGHT0);  
	

	glPushMatrix();   //������仰�Ϳ���ʵ��õ�廨���ƶ�,�ټ��Ϻ�����Ǹ�pop,don`
	//rose
	glTranslatef(-2,1,0);
	objects[0]->Draw();

	//soccer
	glTranslatef(lensco, 0, -1.5);
    glRotatef(-alpsco / 3.14 * 180.0, 0, 0, 1);
	objects[1]->Draw();

	glPopMatrix();

	//al
	
	glTranslatef(viewer[0] - 1 * sin(alpha), viewer_man-1, viewer[2] - 4 * cos(alpha)); //�����n * sin(alpha) �����˺;�ͷ�ľ���
	glRotatef((alpha / 3.199999999f) * 180 + 180, 0, 1, 0);
	objects[2]->Draw();	


	glDisable(GL_LIGHTING);
}

void init()
{
	glClearColor(0.0f,162.0f/255.0f,232.0f/255.0f,0.0f);//����ɫ

	viewer[0] = 0.0f;
	viewer[1] = 2.0f;
	viewer[2] = 5.0f;
	VectorLength = 1;

	dir[0] = 0.0f;
	dir[1] = 2.0f;
	dir[2] = 5.0f - VectorLength;

	alpha = 0.0f;

	rose.ReadData();
	soccer.ReadData();
	al.ReadData();


	GLuint f = LoadGLTexture("data\\fish.bmp");
	texture[1] = f;

	GLuint t = LoadGLTexture("data\\1.bmp");
	texture[0] = t;



	m_count = 0;
	objects[m_count++] = &rose;
	objects[m_count++] = &soccer;
	objects[m_count++] = &al;

	glEnable(GL_DEPTH_TEST);//������Ȳ���
}

void CALLBACK draw()
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

	RenderScene(); 

	glFinish();//ǿ��֮ǰ�Ļ�ͼ����ִ��
	auxSwapBuffers();
}

void CALLBACK myReshape(GLsizei w, GLsizei h) 
{ 
	if ( 0 >= w || 0 >= h )         return;

	glViewport(0, 0, w, h); // select the full client area

      // select the projection matrix and clear it
	glMatrixMode(GL_PROJECTION); 
	glLoadIdentity(); 
 /*  if(cx<=cy) 
		glFrustum(-2.0, 2.0, -2.0 * (GLfloat) cy/ (GLfloat) cx,       
                   2.0* (GLfloat) cy / (GLfloat) cx, 2.0, 20.0); 
	else glFrustum( -2.0 * (GLfloat) cx/ (GLfloat) cy,       
                    2.0* (GLfloat) cx / (GLfloat) cy,-2.0, 2.0, 2.0, 20.0);*/
 	 gluPerspective(60.0, (GLfloat)w/h, 0.5, 120.0);
   
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity(); 
} 

void CALLBACK Key_DOWN()
{
	step = 0.50f;
}

void CALLBACK Key_UP()
{
	step = -0.50f;
}

void CALLBACK Key_LEFT()
{
	alpha  += .50f;
}

void CALLBACK Key_RIGHT()
{
	alpha -= .50f;
}

void CALLBACK Key_q()
{
	Lx += 1.0f;
}

void CALLBACK Key_w()
{
	Ly += 1.0f;
}

void CALLBACK Key_e()
{
	Lz += 1.0f;
}

void CALLBACK Key_a()
{
	Lx -= 1.0f;
}
void CALLBACK Key_s()
{
	Ly -= 1.0f;
}

void CALLBACK Key_d()
{
	Lz -= 1.0f;
}
void CALLBACK Key_j()
{
	viewer_man += 1.0f;
	viewer[1] += 1.0f;
	dir[1] += 1.0f;
}
void CALLBACK Key_k()
{
	viewer_man -= 1.0f;
	viewer[1] -= 1.0f;
	dir[1] -= 1.0f;
}
void CALLBACK Key_u()
{
	viewer[1] += 1.0f;
}
void CALLBACK Key_i()
{
	viewer[1] -= 1.0f;
}
void CALLBACK Mouse(AUX_EVENTREC *event)  
{  
	GLint x,y;  
	x=event->data[AUX_MOUSEX];  
	y=event->data[AUX_MOUSEY];  


	draw();
} 

void CALLBACK Idle()
{
	sx = step * sin(alpha);
	sz = step * cos(alpha);
	

	//***************************
	viewer[0] += sx;
	viewer[2] += sz;
	
	dir[0] = viewer[0] - sin(alpha);
	dir[2] = viewer[2] - cos(alpha);

	cout << viewer[0] << " " << viewer[2] << endl;

	fishx += 0.2f;
	if(fishx == 1.0f)
	{
		fishx = 0.0f;
		fishy -= 0.2f;
		if(fishy < 0.0f)
		    fishy = 0.8f;
	}
	//printf("%f,  %f\n", fishx, fishy);
    t -= 0.001f;
    lensco -= 0.05f * t * t; 
	if(lensco <= -20)
		lensco = -20;

	//alpsco = (20+lensco)/20.0 / 0.2f;
    alpsco = (20+lensco)*2.5;
    Sleep(10);
	//***************************



	draw(); //��������
	step = 0;
}

//������
void main()
{
	auxInitDisplayMode(AUX_DOUBLE|AUX_RGBA|AUX_DEPTH);
    auxInitPosition(100,100,500,500);
    auxInitWindow("ProjectFive");

    init();

	auxReshapeFunc (myReshape); 
	auxKeyFunc(AUX_LEFT,Key_LEFT);
	auxKeyFunc(AUX_RIGHT,Key_RIGHT);
	auxKeyFunc(AUX_DOWN,Key_DOWN);
	auxKeyFunc(AUX_UP,Key_UP);
	auxKeyFunc(AUX_q,Key_q);
	auxKeyFunc(AUX_w,Key_w);
	auxKeyFunc(AUX_e,Key_e);
	auxKeyFunc(AUX_a,Key_a);
    auxKeyFunc(AUX_s,Key_s);
    auxKeyFunc(AUX_d,Key_d);
	auxKeyFunc(AUX_j,Key_j);  //��
    auxKeyFunc(AUX_k,Key_k);
	auxKeyFunc(AUX_u,Key_u);  //����
    auxKeyFunc(AUX_i,Key_i);


    auxMouseFunc(AUX_LEFTBUTTON,AUX_MOUSEDOWN,Mouse);
	auxIdleFunc(Idle);
    auxMainLoop(draw);	
}

GLuint LoadGLTexture( const char *filename )
{
	AUX_RGBImageRec *pImage; // Create Storage Space For The Texture
	GLuint uiTexture = 0;
	
	pImage = auxDIBImageLoadA(filename);

	// Load The Bitmap, Check For Errors, If Bitmap's Not Found Quit
	if ( pImage != NULL && pImage->data != NULL )					// If Texture Image Exists
	{
		glGenTextures(1, &uiTexture);

		// Typical Texture Generation Using Data From The Bitmap
		glBindTexture(GL_TEXTURE_2D, uiTexture);

		glTexImage2D(GL_TEXTURE_2D, 0, 3, pImage->sizeX, pImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, pImage->data);

		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
                // Ҳ����ע�͵������������������д���
//		gluBuild2DMipmaps(GL_TEXTURE_2D, 4, pImage->sizeX,   pImage->sizeY, GL_RGB, GL_UNSIGNED_BYTE, pImage->data);
//		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);

		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
	    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);

		free(pImage->data);											// Free The Texture Image Memory
		free(pImage);												// Free The Image Structure
	}

	return uiTexture;	
}