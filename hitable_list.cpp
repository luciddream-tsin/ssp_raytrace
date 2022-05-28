//
// Created by tsin on 2022/5/28.
//

#include "hitable_list.h"


bool hitable_list::hit(const ray &r, float tmin, float tmax, hit_record &record) const {
    hit_record temp_record;
    bool hit_anything = false;
    double closet_so_far = tmax;
    for (int i = 0; i < size; ++i) {
        if (list[i]->hit(r, tmin, closet_so_far,temp_record)){
            closet_so_far = temp_record.t;
            hit_anything = true;
            record = temp_record;
        }
    }
    return hit_anything;
}