//
// Created by tsin on 2022/5/28.
//

#ifndef RAYTRACE_WEEK1_SPHERE_H
#define RAYTRACE_WEEK1_SPHERE_H

#include "hitable.h"
#include "material.h"

class sphere : public hitable{
public:
    sphere(vec3 center, float radius, material *mat_ptr):center(center), radius(radius), mat_ptr(mat_ptr){

    };
    bool hit(const ray &r, float tmin, float tmax, hit_record &record) const override;

    vec3 center;
    float radius;
    material *mat_ptr;

    ~sphere(){
        if (mat_ptr) delete mat_ptr;
    }
};


#endif //RAYTRACE_WEEK1_SPHERE_H
