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
#include "material.h"


vec3 ray_color(const ray& r, hitable_list &world, int depth){

    hit_record record;
    record.mat_ptr = nullptr;
    if (world.hit(r, 0.0001, FLT_MAX, record)){
        ray scattered;

        material * m = record.mat_ptr;
        m->get_albedo();

        if(depth > 0 && record.mat_ptr->scatter(r,record, scattered)){
            return record.mat_ptr->get_albedo() * ray_color(scattered, world, depth - 1);
        }else {
            return vec3{0, 0, 0};
        }

        //return (record.normal+1.0)*0.5;
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
    float sample_freq = 20;

    hitable* list[4];
    list[0] = new sphere(vec3{0, 0, -1}, 0.5, new lambertian(vec3{0.6, 0.2, 0.5}));
    list[1] = new sphere(vec3{0, -100.5, -1}, 100., new lambertian(vec3{0.5, 0.5, 0.5}));
    list[2] = new sphere(vec3{-1, 0, -1}, 0.5, new metal(vec3{0.5, 0.9, 0.5}));
    list[3] = new sphere(vec3{1, 0, -1}, 0.5, new metal(vec3{0.5, 0.5, 0.5}));

    hitable_list world{list, 4};


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
            c = vec3{std::sqrt(c[0]), std::sqrt(c[1]), std::sqrt(c[2])};
            int cr = (int)(c[0] * 255);
            int cg = (int)(c[1] * 255);
            int cb = (int)(c[2] * 255);
            of << cr << " " << cg << " " << cb << std::endl;
        }
    }

    of.close();
    return 0;

}