//
// Created by tsin on 2022/5/27.
//

#ifndef RAYTRACE_WEEK1_RAY_H
#define RAYTRACE_WEEK1_RAY_H
#include "vec3.h"

class ray {
public:
    ray(){};
    ray(const vec3& a, const vec3& b){A=a;B=b;}

    vec3 start()const {return A;}
    vec3 direc()const {return B;}
    vec3 point_at_para(float t)const{return A + (t * B);}


    vec3 A;
    vec3 B;

};


#endif //RAYTRACE_WEEK1_RAY_H
