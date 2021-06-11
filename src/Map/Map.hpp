//
// Created by clement on 03/06/2021.
//

#pragma once
#include "Object/Collisionable/Destructible/DestructibleWall.hpp"
#include "Object/Collisionable/Wall.hpp"
#include <utility>
#include <vector>
#include <map>

class Map {
public:
    Map();
    ~Map() = default;
    void createDestructibleMap(std::pair<int, int> pos_left, std::pair<int, int> pos_down_right);
    void createContourMap(int xMax, int yMax) noexcept;
    void writeDestructibleList() noexcept;
    void readDestructibleList() noexcept;

    public:
    std::vector<DestructibleWall> _objectDestructibleList;
    std::vector<std::pair<int, int>> _pos;
    std::vector<Wall> _objectNoDestructibleList;
};