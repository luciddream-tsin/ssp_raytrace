//
// Created by tsin on 2022/5/27.
//

#include <cfloat>
#include "fstream"
#include "vec3.h"
#include "ray.h"
#include "hitable.h"
#include "hitable_list.h"
#include "sphere.h"
#include "camera.h"
#include "random.h"

vec3 random_in_unit_shpere(){
    vec3 p;
    do{
        p = 2.0*vec3{(float)get_random(), (float)get_random(), (float )get_random()} - vec3{1,1,1};
    } while (p.squred_length() >= 1.0);
    return p;
}

vec3 ray_color(const ray& r, hitable_list &world, int depth){

    if (depth <= 0 )
        return vec3{0, 0, 0};

    hit_record record;
    if (world.hit(r, 0.0001, FLT_MAX, record)){
        //vec3 target = record.p + record.normal + random_in_unit_shpere();
        //return 0.5 * ray_color(ray{record.p, target}, world, depth-1);
        return (record.normal+1.0)*0.5;
    }

    vec3 unit_dir = make_unit(r.direc());
    float t = (unit_dir.y()+1)*0.5;
    return vec3{1.0, 1.0, 1.0}*(1.0-t) + vec3{0.5, 0.7, 1.0}*t;
}


int main(){
    int nx = 200;
    int ny = 100;
    std::ofstream of("background.ppm");
    of << "P3" << std::endl << nx << " " << ny << std::endl << "255" << "\n";
    float sample_freq = 4;
    hitable* list[2];
    list[0] = new sphere(vec3{0, 0, -1}, 0.5);
    list[1] = new sphere(vec3{0, -100.5, -1}, 100.);

    hitable_list world{list, 2};
    camera came{};

    for (int j = ny-1; j >=0 ; --j) {
        for (int i = 0; i < nx; ++i) {

            ray r;
            vec3 c{0,0,0};
            for (int k = 0; k < sample_freq; ++k) {
                float u = (float(i) + get_random())/float(nx);
                float v = (float(j) + get_random())/float(ny);
                r = came.get_ray(u, v);
                c += ray_color(r, world, 30);
            }
            c /= sample_freq;
            int cr = (int)(c[0] * 255);
            int cg = (int)(c[1] * 255);
            int cb = (int)(c[2] * 255);
            of << cr << " " << cg << " " << cb << std::endl;
        }
    }

    of.close();
    return 0;

}