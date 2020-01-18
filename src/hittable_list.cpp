#include "hittable_list.h"

auto HittableList::Hit(const Ray& ray, float t_min, float t_max, HitRecord& rec) const -> bool
{
    HitRecord temp_rec;
    bool hit_anything    = false;
    float closest_so_far = t_max;
    for (const auto& hittable : *list_)
    {
        if (hittable->Hit(ray, t_min, closest_so_far, temp_rec))
        {
            hit_anything   = true;
            closest_so_far = temp_rec.t;

            rec = temp_rec;
        }
    }
    return hit_anything;
}
