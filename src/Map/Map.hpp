//
// Created by clement on 03/06/2021.
//

#pragma once

#include "Object/Collisionable/Destructible/DestructibleWall.hpp"
#include "Object/Collisionable/Wall/Wall.hpp"
#include <utility>
#include <vector>
#include <map>

class Map {
public:
    Map(const std::vector<std::pair<int, int>> &posTank);
    ~Map() = default;
    /**
     * @brief Create a Destructible Map object
     *
     * @param pos_left
     * @param pos_down_right
     */
    void createDestructibleMap(std::pair<int, int> const &pos_left, std::pair<int, int> const &pos_down_right);
    /**
     * @brief Create a Contour Map object
     *
     * @param xAxis
     * @param yAxis
     */
    void createContourMap(std::pair<int, int> const &xAxis,std::pair<int, int> const &yAxis) noexcept;
    /**
     * @brief write object in save file
     *
     */
    void writeDestructibleList() noexcept;
    /**
     * @brief read object from file
     *
     */
    void readDestructibleList() noexcept;

    public:
    std::vector<DestructibleWall> _objectDestructibleList;
    std::vector<std::pair<int, int>> _posTank;
    std::vector<Wall> _objectNoDestructibleList;
};