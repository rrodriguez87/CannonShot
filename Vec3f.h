#ifndef VEC3F_H
#define VEC3F_H

class Vec3f{
	public:
		Vec3f();
		Vec3f( float x, float y, float z );
		float &operator[]( int index );
		float operator[]( int index ) const;

		Vec3f operator*( float scale ) const;
		Vec3f operator=( int value );
		Vec3f operator-( const Vec3f &rightSide );
		const Vec3f &operator*=( float scale );
		const Vec3f &operator-=( const Vec3f &rightSide );
		const Vec3f &operator+=( const Vec3f &rightSide );


		Vec3f Normalize() const;
		float Dot( const Vec3f &other ) const;
	private:
		float v[3];
};
Vec3f operator*( float scale, const Vec3f &v );
std::ostream &operator<<( std::ostream &output, const Vec3f &v );

#endif