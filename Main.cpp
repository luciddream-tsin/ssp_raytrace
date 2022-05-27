//
// Created by tsin on 2022/5/27.
//

#include "fstream"



int main(){
    int nx = 400;
    int ny = 300;

    std::ofstream of("out.ppm");
    of << "P3" << std::endl;
    of << nx << " " << ny << "\n";
    of << "255" << "\n";

    for (int i = 0; i < ny; ++i) {
        for (int j = 0; j < nx; ++j) {
            float pr = float(i)/float(ny);
            float pg = float(j)/float(nx);
            float pb = 0.2;

            int r = pr * 255;
            int g = pg * 255;
            int b = pb * 255;

            of << r << " " << g << " " << b << std::endl;
        }
    }

    of.close();
    return 0;

}