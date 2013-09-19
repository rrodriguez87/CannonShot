#include "Precompiled.h"

Scene::Scene(){
	proCount = 0;
}

void Scene::Add(Projectile *proj){
	//MAX_PROJECTILE == 30;
	//Push 30 projectiles onto stack as a way to initialize proStack
	//after which use proCount to write over older projectiles. Keeps
	//scene from being overburdened with old projectiles.

	if( proStack.size() < MAX_PROJECTILE )
		proStack.push_back(proj);
	else{
		if( proCount >= MAX_PROJECTILE )
			proCount=0;
		*proStack[proCount++] = *proj;
	}
}

void Scene::RenderScene(){
	DrawBounds(); //visually display the boundaries of my drawing area 

	for(unsigned int i=0; i<proStack.size(); ++i){
		//move projectile with respect to its velocity,
		//then apply the effects of gravity to the object's
		//velocity. Draw projectile to window
		ApplyVelocity( proStack[i] ); 
		ApplyGravity( proStack[i] );
		ProcessCollisions( proStack );
		proStack[i]->Draw();
	}
}

void Scene::DrawBounds(){
	glBegin( GL_LINES );
		//x-axis (Green line)
		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex3f(SCENE_SIZE, 0.0f, 0.0f);
		glVertex3f(-SCENE_SIZE, 0.0f, 0.0f);

		//y-axis (Red line)
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(0.0f, SCENE_SIZE, 0.0f);
		glVertex3f(0.0f, -SCENE_SIZE, 0.0f);

		//z-axis (blue line)
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3f(0.0f, 0.0f, SCENE_SIZE);
		glVertex3f(0.0f, 0.0f, -SCENE_SIZE);

		//boundaries
		glColor3f(1.0f, 1.0f, 0.0f);

		//back
		glVertex3f(SCENE_SIZE, -SCENE_SIZE, -SCENE_SIZE);
		glVertex3f(-SCENE_SIZE, -SCENE_SIZE, -SCENE_SIZE);

		glVertex3f(-SCENE_SIZE, -SCENE_SIZE, -SCENE_SIZE);
		glVertex3f(-SCENE_SIZE, SCENE_SIZE, -SCENE_SIZE);

		glVertex3f(-SCENE_SIZE, SCENE_SIZE, -SCENE_SIZE);
		glVertex3f(SCENE_SIZE, SCENE_SIZE, -SCENE_SIZE);

		glVertex3f(SCENE_SIZE, SCENE_SIZE, -SCENE_SIZE);
		glVertex3f(SCENE_SIZE, -SCENE_SIZE, -SCENE_SIZE);

		//front
		glVertex3f(SCENE_SIZE, -SCENE_SIZE, SCENE_SIZE);
		glVertex3f(-SCENE_SIZE, -SCENE_SIZE, SCENE_SIZE);

		glVertex3f(-SCENE_SIZE, -SCENE_SIZE, SCENE_SIZE);
		glVertex3f(-SCENE_SIZE, SCENE_SIZE, SCENE_SIZE);

		glVertex3f(-SCENE_SIZE, SCENE_SIZE, SCENE_SIZE);
		glVertex3f(SCENE_SIZE, SCENE_SIZE, SCENE_SIZE);

		glVertex3f(SCENE_SIZE, SCENE_SIZE, SCENE_SIZE);
		glVertex3f(SCENE_SIZE, -SCENE_SIZE, SCENE_SIZE);

		glVertex3f(SCENE_SIZE, SCENE_SIZE, SCENE_SIZE);
		glVertex3f(SCENE_SIZE, SCENE_SIZE, -SCENE_SIZE); 
		glVertex3f(-SCENE_SIZE, -SCENE_SIZE, -SCENE_SIZE);
		glVertex3f(-SCENE_SIZE, -SCENE_SIZE, SCENE_SIZE);

		glVertex3f(-SCENE_SIZE, SCENE_SIZE, SCENE_SIZE);
		glVertex3f(-SCENE_SIZE, SCENE_SIZE, -SCENE_SIZE);
		glVertex3f(SCENE_SIZE, -SCENE_SIZE, SCENE_SIZE);
		glVertex3f(SCENE_SIZE, -SCENE_SIZE, -SCENE_SIZE);
	glEnd();
}