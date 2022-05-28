//
// Created by tsin on 2022/5/28.
//

#ifndef RAYTRACE_WEEK1_CAMERA_H
#define RAYTRACE_WEEK1_CAMERA_H
#include "vec3.h"
#include "random"
#include "ray.h"

class camera {
public:
    camera(

            vec3 lookfrom,
            vec3 lookat,
            vec3   vup,

            double vfov, // vertical field-of-view in degrees
            double aspect_ratio
    ) {
        auto theta = (vfov/180.0) * M_PI;
        auto h = tan(theta/2);
        auto viewport_height = 2.0 * h;
        auto viewport_width = aspect_ratio * viewport_height;


        auto w = make_unit(lookfrom - lookat);
        auto u = make_unit(cross(vup, w));
        auto v = cross(w, u);

        origin = lookfrom;
        horizontal = viewport_width * u;
        vertical = viewport_height * v;
        left_lower_corner = origin - horizontal/2 - vertical/2 - w;
    }
    ray get_ray(float u, float v){
        vec3 b = (left_lower_corner + u * horizontal + v*vertical - origin);
        return ray{origin, b};
    }

    vec3 left_lower_corner{-2.0, -1.0, -1.0};
    vec3 horizontal{4.0, 0, 0};
    vec3 vertical{0, 2.0, 0};
    vec3 origin{0, 0, 0};
};


#endif //RAYTRACE_WEEK1_CAMERA_H
