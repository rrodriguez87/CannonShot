#ifndef PROJECTILE_H
#define PROJECTILE_H

class Projectile{
public:
	Projectile();
	void Draw();
	float radius;
	float elasticity;
	int count;
	Vec3f pos; //Position (x, y, z)
	Vec3f col; //Color (Red, Green, Blue)
	Vec3f vel; //Velocity
};
#endif