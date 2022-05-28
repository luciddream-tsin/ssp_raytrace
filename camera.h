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
    camera(){
        left_lower_corner = {-2.0, -1.0, -1.0};
        horizontal = {4.0, 0, 0};
        vertical = {0, 2.0, 0};
        origin = {0, 0, 0};
    }
    ray get_ray(float u, float v){
        vec3 b = (left_lower_corner + u * horizontal + v*vertical);
        return ray{origin, b};
    }

    vec3 left_lower_corner{-2.0, -1.0, -1.0};
    vec3 horizontal{4.0, 0, 0};
    vec3 vertical{0, 2.0, 0};
    vec3 origin{0, 0, 0};
};


#endif //RAYTRACE_WEEK1_CAMERA_H
