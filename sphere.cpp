//
// Created by tsin on 2022/5/28.
//

#include "sphere.h"

bool sphere::hit(const ray &r, float tmin, float tmax, hit_record &record) const {
    vec3 AC = r.start() - center;
    float b = 2 * dot(r.direc(), AC);
    float a = r.direc().squred_length();
    float c = dot(AC, AC) - radius*radius;
    float discriminant =  b*b-4*a*c;

    if (discriminant > 0){
        float t1 = (-b - std::sqrt(discriminant) )/ (2 * a);
        if (tmin < t1 && t1 < tmax){
            record.t = t1;
            record.p = r.point_at_para(t1);
            record.normal = (record.p - center);
            record.normal.make_unit_vector();
            record.mat_ptr = mat_ptr;
            return true;
        }

        float t2 = (-b + std::sqrt(discriminant)) / (2 * a);
        if (tmin < t2 && t2 < tmax) {
            record.t = t2;
            record.p = r.point_at_para(t2);
            record.normal = (record.p - center) ;
            record.normal.make_unit_vector();
            record.mat_ptr = mat_ptr;
            return true;
        }
    }
    return false;
}