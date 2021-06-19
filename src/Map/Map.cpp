//
// Created by clement on 03/06/2021.
//

#include <cstdlib>
#include <ctime>
#include <fstream>
#include <array>
#include <iostream>
#include <random>
#include <iomanip>
#include <string>
#include <map>
#include <cmath>
#include "Raylib.hpp"
#include "Map.hpp"

Map::Map(const std::vector<std::pair<float, float>> &posTank) : _posTank(posTank)
{
}

void Map::initTheObstacle() noexcept
{
    for(auto const &j : _basePositionObject) {
        _objectNoDestructibleList.emplace_back(
            coords(static_cast<float>(j.first), 0, static_cast<float>(j.second)),
            coords(1, 1, 1), std::make_pair("", ""));
    }
}

void Map::createDestructibleMap(std::pair<float, float> const &pos_left,
    std::pair<float, float> const &pos_down_right
)
{
    bool findPos = true;
    int nbrPos = 0;
    std::random_device posRand;
    std::mt19937 e2(posRand());
    std::uniform_real_distribution<> theX(pos_left.first, pos_down_right.first);
    std::uniform_real_distribution<> theY(pos_left.second,
        pos_down_right.second);

    for (std::pair<float, float> tmpMap; nbrPos != 3;) {
        findPos = true;
        tmpMap.first = std::round(theX(e2));
        tmpMap.second = std::round(theY(e2));

        if (findPos == true) {
            for (const auto &dest : _objectDestructibleList) {
                if (Raylib::collabsWall(std::make_pair(dest.getPosition().first,dest.getPosition().third),coords(1,1,1) , tmpMap,coords(1,1,1)) == true) {
                    findPos = false;
                    break;
                }
            }
            for (const auto &dest : _objectNoDestructibleList) {
                if (Raylib::collabsWall(std::make_pair(dest.getPosition().first,dest.getPosition().third),coords(1,1,1) , tmpMap,coords(1,1,1)) == true) {
                    findPos = false;
                    break;
                }
            }
        }
        if (findPos == true) {
            nbrPos += 1;
            _objectDestructibleList.emplace_back(
                coords(static_cast<float>(tmpMap.first), 0,
                    static_cast<float>(tmpMap.second)), coords(1, 1, 1),
                std::make_pair("", ""));
        }
    }
}

void Map::createContourMap(std::pair<float, float> const &xAxis,
    std::pair<float, float> const &yAxis
) noexcept
{
    for (int x = xAxis.first, y = yAxis.first; x != xAxis.second; ++x) {
        _objectNoDestructibleList.emplace_back(
            coords(static_cast<float>(x), 0, static_cast<float>(y)),
           coords(1, 1, 1), std::make_pair("", ""));
    }

    for (int x = xAxis.first, y = yAxis.second; x != xAxis.second; ++x) {
        _objectNoDestructibleList.emplace_back(
            coords(static_cast<float>(x), 0, static_cast<float>(y)),
            coords(1, 1, 1), std::make_pair("", ""));
    }

    for (int x = xAxis.first, y = yAxis.first; y != yAxis.second; ++y) {
        _objectNoDestructibleList.emplace_back(
            coords(static_cast<float>(x), 0, static_cast<float>(y)),
            coords(1, 1, 1), std::make_pair("", ""));
    }
    for (int x = xAxis.second, y = yAxis.first; y != yAxis.second; ++y) {
        _objectNoDestructibleList.emplace_back(
            coords(static_cast<float>(x), 0, static_cast<float>(y)),
            coords(1, 1, 1), std::make_pair("", ""));
    }
}

void Map::writeDestructibleList() noexcept
{
    unsigned long size = _objectDestructibleList.size();
    DestructibleObject::destructible_t dest;
    std::remove("destructibleList.txt");
    std::ofstream file("destructibleList.txt",
        std::ios::out | std::ofstream::binary | std::ofstream::trunc);
    file.write(reinterpret_cast<const char *>(&size), sizeof(unsigned long));
    for (auto &i : _objectDestructibleList) {
        dest = i.getStructSave();
        file.write(reinterpret_cast<const char *>(&dest),
            sizeof(DestructibleObject::destructible_t));
    }
}

void Map::readDestructibleList()
{
    unsigned long size = 0;
    DestructibleObject::destructible_t dest;
    std::ifstream file("destructibleList.txt",
        std::ios::in | std::ifstream::binary);
    if (file.is_open() == false)
        throw std::runtime_error("No Save File");
    std::cout << size << std::endl;
    file.read(reinterpret_cast<char *>(&size), sizeof(unsigned long));
    for (int i = 0; i != size; i++) {
        file.read(reinterpret_cast<char *>(&dest),
            sizeof(DestructibleObject::destructible_t));
        _objectDestructibleList.emplace_back(
            coords(static_cast<float>(dest.x), 0, static_cast<float>(dest.y)),
            coords(1, 1, 1), std::make_pair("", "")).setLife(dest.life);
    }
    std::cout << "finish map" << std::endl;
}