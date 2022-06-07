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
    metal(const vec3& a, float f ):albedo(a){
        fuzz = (f < 1.0)?f:1.0;
    }
    bool scatter(const ray &in_ray, const hit_record &recd, ray &scattered) const override{
        vec3 reflected = reflect(make_unit(in_ray.direc()), recd.normal);

        scattered = ray(recd.p, reflected + fuzz * random_in_unit_shpere());
        return (dot(recd.normal, reflected) > 0);
    }
    vec3 get_albedo() const override{
        return albedo;
    }
    vec3 albedo;
    float fuzz;
};

class dielectric: public material{
public:
    dielectric(const vec3& a, float etai_over_etat):albedo(a),
    etai_over_etat(etai_over_etat){

    };
    bool scatter(const ray &in_ray, const hit_record &recd, ray &scattered) const override{
        float ee;
        vec3 used_normal;
        if (dot(make_unit(in_ray.direc()), recd.normal)<0){
            used_normal = recd.normal;
            ee = 1.0 / etai_over_etat;
        } else{
            used_normal = -recd.normal;
            ee = etai_over_etat;
        }
        vec3 reflected = refract(make_unit(in_ray.direc()), used_normal, ee);
        scattered = ray(recd.p, reflected );//+  random_in_unit_shpere());
        return true;
    }
    vec3 get_albedo() const override{
        return albedo;
    }
    vec3 albedo;
    float etai_over_etat;
};

#endif //RAYTRACE_WEEK1_MATERIAL_H
