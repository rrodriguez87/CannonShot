#include "Precompiled.h"
#include "PhysicEngine.h"

Scene scene;
void initRendering(){
	glEnable( GL_DEPTH_TEST );
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
}
float CAMERA_DIST = CAMERA_DIST_START;
void Keyboard( unsigned char key, int x, int y ){
	switch( key ){
		case 27:
		{
			exit(0);
			break;
		}
		case ' ':
		{
				Projectile *proj= new Projectile( Random(-SCENE_SIZE, SCENE_SIZE), Random(-SCENE_SIZE, SCENE_SIZE), Random(-SCENE_SIZE, SCENE_SIZE) );
				//Projectile *proj = new Projectile( -SCENE_SIZE, 0, 0);
				scene.Add(proj);
		

			break;
		}
		case 'w':
		{

			break;
		}
		case 'a':
		{
			break;
		}
		case 's':
		{
			break;
		}
		case 'd':
		{
			break;
		}
	}

}

void Mouse( int state, int key, int x, int y ){
	if( state == GLUT_DOWN )
		switch(key){
			case GLUT_LEFT_BUTTON:
				{
					std::cout<< x << ", " << y <<std::endl;
					break;
				}
		}
}

void Reshape( int w, int h ){
	glViewport( 0.0f, 0.0f, (GLsizei)w, (GLsizei)h );
	glMatrixMode( GL_PROJECTION );
	glLoadIdentity();
	
	//Some Projection matrix manipulation goes here
	gluPerspective(45.0f, (double)w/(double)h, 0.001f, 500.0f);
	glMatrixMode( GL_MODELVIEW );
}
float _angle = 0.0f;
void Display( void ){
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
	glLoadIdentity();

	gluLookAt( 0.0f, 0.0f, CAMERA_DIST, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f );
	glRotatef(_angle, 0.0f, 1.0f, 0.0f);
	scene.DrawBounds(); //for easy debugging, visual aid
	scene.RenderScene();
	glutSwapBuffers();
}

void Update( int value ){
	_angle += 1.5f;
	if( _angle >= 360 )
		_angle -=360;
	glutPostRedisplay();
	glutTimerFunc(25, Update, 0);
}

int main(int argc, char **argv){
	glutInit( &argc, argv );
	glutInitDisplayMode( GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH );
	glutInitWindowSize( 800, 600 );
	initRendering();
	glutCreateWindow( "CannonShot" );

	glutDisplayFunc( Display );
	glutIdleFunc( Display );
	glutReshapeFunc( Reshape );
	glutKeyboardFunc( Keyboard );
	glutMouseFunc( Mouse );

	//glutTimerFunc(25, Update, 0);
	glutMainLoop();

	return 0;
}