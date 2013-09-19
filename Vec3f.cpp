#include "Precompiled.h"

Vec3f::Vec3f(){
	v[0]=0;
	v[1]=0;
	v[2]=0;
}
Vec3f::Vec3f(float x, float y, float z){
	v[0]=x;
	v[1]=y;
	v[2]=z;
}

float &Vec3f::operator[](int index){
	return v[index];
}

float Vec3f::operator[](int index) const {
	return v[index];
}

Vec3f Vec3f::operator*( float scale ) const {
	return Vec3f( v[0] * scale, v[1] * scale, v[2] * scale );
}

Vec3f Vec3f::operator=( int value ) {
	v[0] = value;
	v[1] = value;
	v[2] = value;
	return *this;
}
const Vec3f &Vec3f::operator*=(float scale){
	v[0] *= scale;
	v[1] *= scale;
	v[2] *= scale;
	return *this;
}

const Vec3f &Vec3f::operator-=( const Vec3f &rightSide ){
	v[0] -= rightSide.v[0];
	v[1] -= rightSide.v[1];
	v[2] -= rightSide.v[2];
	return *this;
}

const Vec3f &Vec3f::operator+=( const Vec3f &rightSide ){
	v[0] += rightSide.v[0];
	v[1] += rightSide.v[1];
	v[2] += rightSide.v[2];
	return *this;
}

Vec3f Vec3f::Normalize() const{
	float m = sqrt( v[0] * v[0] + v[1] * v[1] + v[2] * v[2] );
	Vec3f k( v[0] / m , v[1] / m , v[2] / m );

	//::cout << "Normalize: " << k << std::endl;
	return k;
}

float Vec3f::Dot( const Vec3f &other ) const {
	float u = v[0] * other.v[0] + v[1] * other.v[1] + v[2] * other.v[2];

	//std::cout << "Dot: " << u << std::endl;
	return u;
}

std::ostream &operator<<(std::ostream &output, const Vec3f &v){
	std::cout << "(" << v[0] << ", " << v[1] << ", " << v[2] << ")";
	return output;
}