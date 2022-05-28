//
// Created by tsin on 2022/5/28.
//

#ifndef RAYTRACE_WEEK1_RANDOM_H
#define RAYTRACE_WEEK1_RANDOM_H
#include "random"
double get_random(){
    std::random_device rd;
    std::mt19937 mt(rd());//() is override function.
    std::uniform_real_distribution<double> dist(0.0, 1.0);
    return dist(mt);

}
#endif //RAYTRACE_WEEK1_RANDOM_H
