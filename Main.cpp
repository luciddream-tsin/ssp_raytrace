//
// Created by tsin on 2022/5/27.
//

#include "fstream"
#include "vec3.h"
#include "ray.h"

float hit_sphere(vec3 center, float radius, const ray &r){
    vec3 AC = r.start() - center;
    float b = 2 * dot(r.direc(), AC);
    float a = dot(r.direc(), r.direc());
    float c = dot(AC, AC) - radius*radius;
    float discriminant =  b*b-4*a*c;

    if (discriminant < 0){
        return -1;
    }else{
        return -b - std::sqrt(discriminant) / 2*a;
    }
}
vec3 color(const ray& r){
    float t = (hit_sphere(vec3{0, 0, -1.0}, 0.5, r));
    if (t > 0.0){
        vec3 N = make_unit(r.point_at_para(t) - vec3{0, 0, -1});
        return 0.5*vec3{N.x()+1, N.y()+1, N.z()+1};
    }
    vec3 unit_dir = make_unit(r.direc());
    t = (unit_dir.y()+1)*0.5;
    return vec3{1.0, 1.0, 1.0}*(1.0-t) + vec3{0.5, 0.7, 1.0}*t;
}

int main(){
    int nx = 200;
    int ny = 100;

    std::ofstream of("background.ppm");
    of << "P3" << std::endl << nx << " " << ny << std::endl << "255" << "\n";

    vec3 left_lower_corner{-2.0, -1.0, -1.0};
    vec3 horizontal{4.0, 0, 0};
    vec3 vertical{0, 2.0, 0};
    vec3 origin{0, 0, 0};


    for (int j = ny-1; j >=0 ; --j) {
        for (int i = 0; i < nx; ++i) {

            float u = float(i)/float(nx);
            float v = float(j)/float(ny);

            ray r{origin, left_lower_corner + u * horizontal + v*vertical};

            vec3 c = color(r);

            int cr = (int)(c[0] * 255);
            int cg = (int)(c[1] * 255);
            int cb = (int)(c[2] * 255);


            of << cr << " " << cg << " " << cb << std::endl;
        }
    }

    of.close();
    return 0;

}