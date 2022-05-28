//
// Created by tsin on 2022/5/28.
//

#ifndef RAYTRACE_WEEK1_SPHERE_H
#define RAYTRACE_WEEK1_SPHERE_H

#include "hitable.h"

class sphere : public hitable{
public:
    sphere(vec3 center, float radius):center(center), radius(radius){

    };
    bool hit(const ray &r, float tmin, float tmax, hit_record &record) const override;
    vec3 center;
    float radius;
};


#endif //RAYTRACE_WEEK1_SPHERE_H
