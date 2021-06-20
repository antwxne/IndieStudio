//
// Created by clement on 03/06/2021.
//

#pragma once

#include "Object/Collisionable/Destructible/DestructibleWall.hpp"
#include "Object/Collisionable/Wall/Wall.hpp"
#include <utility>
#include <vector>
#include <map>
/**
 * @class Map
 * @brief Class to generate map with procedural generation
 */
class Map {
public:
    /**
     * @brief Construct a new Map object
     * 
     * @param posTank 
     */
    Map(const std::vector<std::pair<float, float>> &posTank);
    ~Map() = default;
    /**
     * @brief Create a Destructible Map object
     *
     * @param pos_left
     * @param pos_down_right
     */
    void createDestructibleMap(std::pair<float, float> const &pos_left, std::pair<float, float> const &pos_down_right);
    /**
     * @brief Create a Contour Map object
     *
     * @param xAxis
     * @param yAxis
     */
    void createContourMap(std::pair<float, float> const &xAxis,std::pair<float, float> const &yAxis) noexcept;
    /**
     * @brief write object in save file
     *
     */
    void writeDestructibleList(std::vector<DestructibleWall> _destructibleWall) noexcept;
    /**
     * @brief read object from file
     *
     */
    void readDestructibleList();

    public:
    /**
     * @brief vector with all the destructible walls
     * 
     */
    std::vector<DestructibleWall> _objectDestructibleList;
    /**
     * @brief procedural generation for obstacles
     * 
     */
    void initTheObstacle() noexcept;
    /**
     * @brief store tanks positions
     * 
     */
    std::vector<std::pair<float, float>> _posTank;
    /**
     * @brief store Walls
     * 
     */
    std::vector<Wall> _objectNoDestructibleList;

};
/**
 * @brief store position for Wall in map
 * 
 */
static const std::vector<std::pair<int, int>> _basePositionObject {
        std::make_pair(0, -5),
        std::make_pair(-8, 0),
        std::make_pair(8, 0),
        std::make_pair(0, 5)
};