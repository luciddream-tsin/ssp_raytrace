//
// Created by tsin on 2022/5/27.
//

#include "vec3.h"


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
    e[2] += v2.e[2];
}

vec3 &vec3::operator-=(const vec3 &v2) {
    e[0] -= v2.e[0];
    e[1] -= v2.e[1];
    e[2] -= v2.e[2];
}

vec3 &vec3::operator*=(const vec3 &v2) {
    e[0] *= v2.e[0];
    e[1] *= v2.e[1];
    e[2] *= v2.e[2];
}

vec3 &vec3::operator/=(const vec3 &v2) {
    e[0] /= v2.e[0];
    e[1] /= v2.e[1];
    e[2] /= v2.e[2];
}

vec3 &vec3::operator*=(const float t) {
    e[0] *= t;
    e[1] *= t;
    e[2] *= t;
}

vec3 &vec3::operator/=(const float t) {
    e[0] /= t;
    e[1] /= t;
    e[2] /= t;
}

void vec3::make_unit_vector() {
    float k = 1.0 / std::sqrt(e[0]*e[0]+ e[1]*e[1]+ e[2]*e[2]);
    e[0] *= k;
    e[1] *= k;
    e[2] *= k;
}





