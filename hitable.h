//
// Created by tsin on 2022/5/28.
//

#ifndef RAYTRACE_WEEK1_HITABLE_H
#define RAYTRACE_WEEK1_HITABLE_H

#include "vec3.h"
#include "ray.h"

class material;
struct hit_record{
    float t;
    vec3 p;
    vec3 normal;
    material *mat_ptr;
};

class hitable {
public:
   virtual bool hit(const ray& r, float tmin, float tmax, hit_record& record)const = 0;
};


#endif //RAYTRACE_WEEK1_HITABLE_H
