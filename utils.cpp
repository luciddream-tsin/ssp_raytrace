//
// Created by tsin on 2022/5/28.
//

#include "utils.h"
vec3 reflect(const vec3& v, const vec3& n){
    //说明: 看doc文档 关于reflect函数
    return  - 2 * n * dot(n, v) + v;
}
#include "random"
double get_random(){
    std::random_device rd;
    std::mt19937 mt(rd());//() is override function.
    std::uniform_real_distribution<double> dist(0.0, 1.0);
    return dist(mt);
}
vec3 random_in_unit_shpere(){
    vec3 p;
    do{
        p = 2.0*vec3{(float)get_random(), (float)get_random(), (float )get_random()} - vec3{1,1,1};
    } while (p.squred_length() >= 1.0);
    return p;
}


