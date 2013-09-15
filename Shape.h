#ifndef SHAPE_H
#define SHAPE_H

class Shape{
	public:
		Shape();
		virtual Shape *Clone( void ) const = 0;
		virtual void Draw( void ) = 0;
		Entity *entity;
		float radius; //for projectile shape
		float size; //for vehicle shape

};

class Projectile : public Shape{
	public:
		Projectile( float rad );
		void Draw( void ) const;
};

class Vehicle : public Shape{
	public:
		Vehicle( float size );
		void Draw( void ) const;
};
#endif