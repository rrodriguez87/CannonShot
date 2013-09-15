#ifndef PROJECTILE_H
#define PROJECTILE_H

class Projectile{
public:
	Projectile(float x, float y, float z);
	void Draw();
	Vec3f pos; //Position (x, y, z)
	Vec3f color; //Color (Red, Green, Blue)
	Vec3f velo; //Velocity
};
#endif