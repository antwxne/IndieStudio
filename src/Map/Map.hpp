//
// Created by clement on 03/06/2021.
//

#pragma once
#include "Object/Collisionable/Destructible/DestructibleWall.hpp"
#include <utility>
#include <vector>
#include <map>


class Map {
public:
    Map();
    ~Map() = default;
    void createMap(std::pair<int, int> pos_left, std::pair<int, int> pos_down_right);

    protected:
    std::vector<DestructibleWall> _objectList;
    std::vector<std::pair<int, int>> _pos;
};