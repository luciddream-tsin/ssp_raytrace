//
// Created by tsin on 2022/5/28.
//

#include "utils.h"
#include "random"

vec3 reflect(const vec3& v, const vec3& n){
    //说明: 看doc文档 关于reflect函数
    return  - 2 * n * dot(n, v) + v;
}

vec3 refract(const vec3& v, const vec3& n, float etai_over_etat){
    //vec3 r = make_unit(v);
    vec3 r = v;//v have been united.
    float cos_theta = dot(-r, n);


    vec3 r_out_parallel = etai_over_etat * (r + cos_theta*n);
    vec3 r_out_vertical = -sqrt(1.0 - r_out_parallel.squred_length()) * n;
    auto refracted = r_out_parallel + r_out_vertical;
    return refracted;
}

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


