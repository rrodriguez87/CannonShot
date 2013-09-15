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
std::ostream &operator<<(std::ostream &output, const Vec3f &v){
	std::cout << "(" << v[0] << ", " << v[1] << ", " << v[2] << ")";
	return output;
}