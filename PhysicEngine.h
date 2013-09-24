#ifndef PHYSICENGINE_H
#define PHYSICENGINE_H

const float GRAVITY = 9.8f;
const float ELASTICITY = 0.9f;
const float FRICTION = 0.001f;
const float RADIUS = 1.0;
const float TIME_BETWEEN_UPDATES = 0.005f;
const float dt = 1.0f / 60.0f;
const int SCENE_SIZE = 50;
const int CAMERA_DIST_START = SCENE_SIZE*5; //initial camera placement at start of program
const int PI = 3.1459694;
const int MAX_PROJECTILE = 5; //maximum # of projectiles in a scene at any one time
enum Wall { WALL_LEFT, WALL_RIGHT, WALL_FAR, WALL_NEAR, WALL_TOP, WALL_BOTTOM };

inline float Random( float lo, float hi ) {
	return ( ( float( rand() ) / float( RAND_MAX ) ) * ( hi - lo ) ) + lo;
}

inline void ApplyGravity( Projectile* proj ) {
	/* Decrement the Y velocity_component of projectile if
	   projectile has not reached the scene floor. */
	if( proj->pos[1] - proj->radius >= -SCENE_SIZE)
		proj->vel -= Vec3f( 0, GRAVITY * TIME_BETWEEN_UPDATES, 0 );
}

inline void ApplyVelocity( Projectile* proj ) {
	proj->pos += proj->vel * dt;
}

inline Vec3f WallDirection( Wall wall ) {
	switch( wall ) {
		case WALL_LEFT:
			return Vec3f( -1, 0, 0 );
		case WALL_RIGHT:
			return Vec3f( 1, 0, 0 );
		case WALL_FAR:
			return Vec3f( 0, 0, -1 );
		case WALL_NEAR:
			return Vec3f( 0, 0, 1 );
		case WALL_TOP:
			return Vec3f( 0, 1, 0 );
		case WALL_BOTTOM:
			return Vec3f( 0, -1, 0 );
		default:
			return Vec3f( 0, 0, 0 );
	}
}

inline bool CheckForCollision( Projectile* proj, Wall wall ) {
	Vec3f dir = WallDirection( wall );
	return proj->pos.Dot( dir ) + proj->radius > SCENE_SIZE && proj->vel.Dot( dir ) > 0;
}


inline void ProcessCollisions( std::vector< Projectile * > proStack ){
	Wall walls[] = { WALL_LEFT, WALL_RIGHT, WALL_FAR, WALL_NEAR, WALL_TOP, WALL_BOTTOM };

	//Cycle through projectile objects and check if the object has collided with a wall.
	for( unsigned int i = 0 ; i < proStack.size() ; ++i ) {
		for( int j = 0 ; j < 6 ; j++ ) {
			if( CheckForCollision( proStack[i], walls[j] ) ) {
				Vec3f dir = ( WallDirection( walls[j] )).Normalize();
				proStack[i]->vel -= ( dir * 2 * proStack[i]->vel.Dot( dir ) ) * proStack[i]->elasticity;
				proStack[i]->vel -= proStack[i]->vel * FRICTION;
			}
		}	
	}
}
#endif