#pragma once

#include "hittable.h"

#include <vector>

class HittableList : public Hittable
{
public:
    HittableList() = default;
    HittableList(const std::vector<Hittable*>* list) : list_(list) {}

    auto Hit(const Ray& ray, float t_min, float t_max, HitRecord* rec) const -> bool override;
    auto List() -> const std::vector<Hittable*>* { return list_; }

private:
    const std::vector<Hittable*>* list_;
};