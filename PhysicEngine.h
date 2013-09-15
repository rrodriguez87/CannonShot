#ifndef PHYSICENGINE_H
#define PHYSICENGINE_H

const float GRAVITY = 8.0f;
const float TIME_BETWEEN_UPDATES = 0.005f;
const int SCENE_SIZE = 50;
const int CAMERA_DIST_START = SCENE_SIZE*5; //initial camera placement at start of program
const int PI = 3.1459694;
const int MAX_PROJECTILE = 100; //maximum # of projectiles in a scene at any one time
//the problem with this random function is that
//negatives numbers are not produced

inline float Random(float lo, float hi){
	return ((float(rand()) / float(RAND_MAX)) * (hi - lo)) + lo;
}
inline void ApplyGravity(Projectile* proj){
	if(proj->pos[1] > -SCENE_SIZE+1 )
		proj->pos -= Vec3f(0, GRAVITY * TIME_BETWEEN_UPDATES, 0);
}

#endif