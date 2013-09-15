#ifndef VEC3F_H
#define VEC3F_H

class Vec3f{
	public:
		Vec3f();
		Vec3f(float x, float y, float z);
		float &operator[](int index);
		float operator[](int index) const;

		const Vec3f &operator*=(float scale);
		const Vec3f &operator-=( const Vec3f &rightSide );
	private:
		float v[3];
};
Vec3f operator*(float scale, const Vec3f &v);
std::ostream &operator<<(std::ostream &output, const Vec3f &v);

#endif