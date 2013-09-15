#ifndef SCENE_H
#define SCENE_H

class Scene{
	public:
		Scene();
		void RenderScene();
		void DrawBounds();
		void Add(Projectile *proj);
	private:
		int proCount; //projectile counter
		std::vector<Projectile *> proStack; //Projectile Stack
		
};
#endif