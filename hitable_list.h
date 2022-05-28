//
// Created by tsin on 2022/5/28.
//

#ifndef RAYTRACE_WEEK1_HITABLE_LIST_H
#define RAYTRACE_WEEK1_HITABLE_LIST_H

#include "hitable.h"
class hitable_list : public hitable{
public:
    hitable_list(){};
    hitable_list(hitable** list, int size): list(list), size(size){}
    bool hit(const ray &r, float tmin, float tmax, hit_record &record) const override;
    hitable**  list;
    int size;
};


#endif //RAYTRACE_WEEK1_HITABLE_LIST_H
