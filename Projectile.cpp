#include "Precompiled.h"

Projectile::Projectile(){
	//Initialize new projectile. Set radius and elasticity
	//Set random position, color, and velocity
	radius = RADIUS;
	elasticity = ELASTICITY;
	count = 0;
	//pos[0]: x-axis, pos[1]: y-axis, pos[2]: z-axis 
	pos[0] = Random( -SCENE_SIZE, SCENE_SIZE );
	pos[1] = Random( -SCENE_SIZE, SCENE_SIZE );
	pos[2] = Random( -SCENE_SIZE, SCENE_SIZE );
	//col[0]: Red component, col[1]: Green Component, col[2]: Blue component
	col[0] = Random( 0.0f, 1.0f );
	col[1] = Random( 0.0f, 1.0f );
	col[2] = Random( 0.0f, 1.0f );
	//vel[0]: x component, vel[1]: y component, vel[2]: z component
	vel[0] = Random( -20.0f, 20.0f );
	vel[1] = Random( -20.0f, 20.0f );
	vel[2] = Random( -20.0f, 20.0f );
}

void Projectile::Draw(){
	//Save modelview matrix up to this point.
	//Move brush to coordinates "pos", and set color 
	//according to "col". Draw sphere and restore 
	//modelview matrix to its pre function call settings
	glPushMatrix();
	glTranslatef( pos[0], pos[1], pos[2] );
	glColor3f( col[0], col[1], col[2] );
	glutSolidSphere( radius, 15, 15 );
	glPopMatrix();
}