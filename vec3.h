//
// Created by tsin on 2022/5/27.
//

#ifndef RAYTRACE_WEEK1_VEC3_H
#define RAYTRACE_WEEK1_VEC3_H
#include "cmath"
#include "cstdlib"
#include "iostream"

class vec3 {
public:

    vec3(){e[0] = 0; e[1] = 0; e[2] = 0;}
    vec3(float e1, float e2, float e3){ e[0] = e1; e[1] = e2; e[2] = e3;}

    inline float x()const {return e[0];}
    inline float y()const {return e[1];}
    inline float z()const {return e[2];}
    inline float r()const {return e[0];}
    inline float g()const {return e[1];}
    inline float b()const {return e[2];}

    inline vec3 operator-() {return vec3{-e[0], -e[1], -e[2]};}
    inline float& operator[](int i){ return e[i];}
    inline float operator[](int i)const{return  e[i];}

    inline vec3& operator+=(const vec3& v2);
    inline vec3& operator-=(const vec3& v2);
    inline vec3& operator*=(const vec3& v2);
    inline vec3& operator/=(const vec3& v2);
    inline vec3& operator*=(const float t);
    inline vec3& operator/=(const float t);

    inline float length() const{return std::sqrt(e[0]*e[0]+e[1]*e[1]+e[2]*e[2]);}
    inline float squred_length() const{return e[0]*e[0]+e[1]*e[1]+e[2]*e[2];}
    inline void make_unit_vector();

    float e[3];
};


//----------------------------------------------------------------------------

inline std::istream& operator >> (std::istream &is, vec3& v){
    is >> v.e[0] >> v.e[1] >> v.e[2];
    return is;
}

inline std::ostream& operator << (std::ostream &os, vec3& v){
    os << v.e[0] << v.e[1] << v.e[2];
    return os;
}


vec3 &vec3::operator+=(const vec3 &v2) {
    e[0] += v2.e[0];
    e[1] += v2.e[1];

    float & x = e[2];
    float t = v2.e[2];

    return *this;
}

vec3 &vec3::operator-=(const vec3 &v2) {
    e[0] -= v2.e[0];
    e[1] -= v2.e[1];
    e[2] -= v2.e[2];

    return *this;

}

vec3 &vec3::operator*=(const vec3 &v2) {
    e[0] *= v2.e[0];
    e[1] *= v2.e[1];
    e[2] *= v2.e[2];
    return *this;

}

vec3 &vec3::operator/=(const vec3 &v2) {
    e[0] /= v2.e[0];
    e[1] /= v2.e[1];
    e[2] /= v2.e[2];
    return *this;

}

vec3 &vec3::operator*=(const float t) {
    e[0] *= t;
    e[1] *= t;
    e[2] *= t;
    return *this;

}

vec3 &vec3::operator/=(const float t) {
    e[0] /= t;
    e[1] /= t;
    e[2] /= t;
    return *this;

}




//----------------------------------------------------------------------------
void vec3::make_unit_vector() {
    float k = 1.0 / std::sqrt(e[0]*e[0]+ e[1]*e[1]+ e[2]*e[2]);
    e[0] *= k;
    e[1] *= k;
    e[2] *= k;
}



inline vec3 operator+(const vec3& v1, const vec3& v2){
    return vec3{v1.e[0]+v2.e[0],v1.e[1]+v2.e[1],v1.e[2]+v2.e[2]};
}
inline vec3 operator-(const vec3& v1, const vec3& v2){
    return vec3{v1.e[0]-v2.e[0],v1.e[1]-v2.e[1],v1.e[2]-v2.e[2]};
}

inline vec3 operator*(const vec3& v1, const vec3& v2){
    return vec3{v1.e[0]*v2.e[0],v1.e[1]*v2.e[1],v1.e[2]*v2.e[2]};
}
inline vec3 operator/(vec3& v1, vec3& v2){
    return vec3{v1.e[0]/v2.e[0],v1.e[1]/v2.e[1],v1.e[2]/v2.e[2]};
}

inline vec3 operator+(const vec3& v, float t){
    return vec3{v.e[0]+t, v.e[1]+t, v.e[2]+t};
}
inline vec3 operator+(float t,const vec3& v){
    return vec3{v.e[0]+t, v.e[1]+t, v.e[2]+t};
}

inline vec3 operator*(const vec3& v, float t){
    return vec3{v.e[0]*t, v.e[1]*t, v.e[2]*t};
}
inline vec3 operator*(float t,const vec3& v){
    return vec3{v.e[0]*t, v.e[1]*t, v.e[2]*t};
}
inline vec3 operator/(vec3& v, float t){
    return vec3{v.e[0]/t, v.e[1]/t, v.e[2]/t};
}

inline float dot(const vec3& v1, const vec3& v2){
    return v1.e[0]*v2.e[0]+ v1.e[1]*v2.e[1]+ v1.e[2]*v2.e[2];
}
inline vec3 cross(const vec3& v1, const vec3& v2){
    return vec3{
            +(v1.e[1]*v2.e[2] - v1.e[2]*v2.e[1]),
            -(v1.e[0]*v2.e[2] - v1.e[2]*v2.e[0]),
            +(v1.e[0]*v2.e[1] - v1.e[1]*v2.e[0])
    };
}

inline vec3 make_unit(vec3 v){
    return v/v.length();
}


#endif //RAYTRACE_WEEK1_VEC3_H
