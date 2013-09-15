#include "Precompiled.h"

Projectile::Projectile(float x, float y, float z){
	pos[0] = x;
	pos[1] = y;
	pos[2] = z;
}

void Projectile::Draw(){
	glPushMatrix();
	glTranslatef( pos[0], pos[1], pos[2] );
	glutSolidSphere( .5, 5, 5 );
	glPopMatrix();
}