//
// Created by tsin on 2022/5/28.
//

#ifndef RAYTRACE_WEEK1_MATERIAL_H
#define RAYTRACE_WEEK1_MATERIAL_H


#include "ray.h"
#include "hitable.h"
#include "utils.h"


class material {
public:
    virtual ~material(){};
    virtual bool scatter(const ray& in_ray, const hit_record& recd, ray&scattered) const = 0;
    virtual vec3 get_albedo() const = 0;
};

class lambertian: public material{
public:
    lambertian(const vec3& a):albedo(a){

    }
    bool scatter(const ray &in_ray, const hit_record &recd, ray &scattered) const override{
        vec3 target = recd.normal + random_in_unit_shpere();
        scattered = ray{recd.p, target};
        return true;
    };

    vec3 get_albedo() const override{
        return albedo;
    }
    vec3 albedo;
};

class metal: public material{
public:
    metal(const vec3& a):albedo(a){}
    bool scatter(const ray &in_ray, const hit_record &recd, ray &scattered) const override{
        vec3 reflected = reflect(make_unit(in_ray.direc()), recd.normal);
        scattered = ray(recd.p, reflected);
        return (dot(recd.normal, reflected) > 0);
    }

    vec3 get_albedo() const override{
        return albedo;
    }
    vec3 albedo;
};


#endif //RAYTRACE_WEEK1_MATERIAL_H
