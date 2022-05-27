//
// Created by tsin on 2022/5/27.
//

#include "fstream"
#include "vec3.h"


int main(){
    int nx = 400;
    int ny = 300;

    std::ofstream of("out.ppm");
    of << "P3" << std::endl;
    of << nx << " " << ny << "\n";
    of << "255" << "\n";

    for (int i = 0; i < ny; ++i) {
        for (int j = 0; j < nx; ++j) {

            vec3 color{float(i)/float(ny), float(j)/float(nx), 0.2};

            int r = color[0] * 255;
            int g = color[1] * 255;
            int b = color[2] * 255;

            of << r << " " << g << " " << b << std::endl;
        }
    }

    of.close();
    return 0;

}