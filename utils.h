//
// Created by tsin on 2022/5/28.
//

#ifndef RAYTRACE_WEEK1_UTILS_H
#define RAYTRACE_WEEK1_UTILS_H

#include "vec3.h"
vec3 reflect(const vec3& v, const vec3& n);
vec3 refract(const vec3& v, const vec3& n, float etai_over_etat);

double get_random();
vec3 random_in_unit_shpere();
#endif //RAYTRACE_WEEK1_UTILS_H
