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


vec3 color(const ray& r, hitable_list &world){
    hit_record record;
    if (world.hit(r, 0.0, FLT_MAX, record)){
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

    vec3 left_lower_corner{-2.0, -1.0, -1.0};
    vec3 horizontal{4.0, 0, 0};
    vec3 vertical{0, 2.0, 0};
    vec3 origin{0, 0, 0};

    hitable* list[2];
    list[0] = new sphere(vec3{0, 0, -1}, 0.5);
    list[1] = new sphere(vec3{0, -100.5, -1}, 100.);

    hitable_list world{list, 2};


    for (int j = ny-1; j >=0 ; --j) {
        for (int i = 0; i < nx; ++i) {

            float u = float(i)/float(nx);
            float v = float(j)/float(ny);
            vec3 b = (left_lower_corner + u * horizontal + v*vertical);
            b.make_unit_vector();
            const vec3 vvv =vec3{0,0,0};
            b+= vvv;
            ray r{origin, b};

            vec3 c = color(r, world);

            int cr = (int)(c[0] * 255);
            int cg = (int)(c[1] * 255);
            int cb = (int)(c[2] * 255);


            of << cr << " " << cg << " " << cb << std::endl;
        }
    }

    of.close();
    return 0;

}