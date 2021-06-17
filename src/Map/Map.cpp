//
// Created by clement on 03/06/2021.
//

#include <cstdlib>
#include <ctime>
#include <fstream>
#include <array>
#include <iostream>
#include "Map.hpp"

Map::Map()
{
    _pos.push_back(std::make_pair(12, 6));
    _pos.push_back(std::make_pair(12, 6));
}

void Map::createDestructibleMap(std::pair<int, int> const &pos_left, std::pair<int, int> const &pos_down_right)
{
    std::srand(std::time(nullptr));
    int tmp = 0;
    bool findPos = true;

    for (std::pair<int, int> tmpMap; tmp != 3;) {
        findPos = true;
        tmpMap.first = std::rand() % pos_down_right.first + pos_left.second;
        tmpMap.second = std::rand() % pos_down_right.second + pos_left.first;
        for (const auto &the_pos : _pos)
            if (the_pos == tmpMap) {
                findPos = false;
                break;
            }
        if (findPos == true)
            for (const auto &dest : _objectDestructibleList)
                if (dest.getPosition().first == tmpMap.first && dest.getPosition().second == tmpMap.second) {
                    findPos = false;
                    break;
                }
        if (findPos == true) {
            tmp += 1;
            _objectDestructibleList.emplace_back(
                coords(static_cast<float>(tmpMap.first), 0, static_cast<float>(tmpMap.second)), std::make_pair(0, 0), std::make_pair("", ""));
        }
    }
}

void Map::createContourMap(std::pair<int, int> const &xAxis, std::pair<int, int> const &yAxis) noexcept
{
    for (int x = xAxis.first, y = yAxis.first; x != xAxis.second; ++x) {
        _objectNoDestructibleList.emplace_back(
            coords(static_cast<float>(x), 0, static_cast<float>(y)), std::make_pair(0, 0), std::make_pair("", ""));
    }

    for (int x = xAxis.first, y = yAxis.second; x != xAxis.second; ++x) {
        _objectNoDestructibleList.emplace_back(
            coords(static_cast<float>(x), 0, static_cast<float>(y)), std::make_pair(0, 0), std::make_pair("", ""));
    }

    for (int x = xAxis.first, y = yAxis.first; y != yAxis.second; ++y) {
        _objectNoDestructibleList.emplace_back(
            coords(static_cast<float>(x), 0, static_cast<float>(y)), std::make_pair(0, 0), std::make_pair("", ""));
    }
    for (int x = xAxis.second, y = yAxis.first; y != yAxis.second; ++y) {
        _objectNoDestructibleList.emplace_back(
            coords(static_cast<float>(x), 0, static_cast<float>(y)), std::make_pair(0, 0), std::make_pair("", ""));
    }
}

void Map::writeDestructibleList() noexcept
{
    unsigned long size = _objectDestructibleList.size();
    DestructibleObject::destructible_t dest;
    std::ofstream file("destructibleList.txt", std::ios::out | std::ofstream::binary);
    file.write(reinterpret_cast<const char *>(&size), sizeof(unsigned long));
    for (auto &i : _objectDestructibleList) {
        dest = i.getStructSave();
        file.write(reinterpret_cast<const char *>(&dest), sizeof(DestructibleObject::destructible_t));
    }
    file.close();
}

void Map::readDestructibleList() noexcept
{
    unsigned long size = 0;
    DestructibleObject::destructible_t dest;
    std::ifstream file("destructibleList.txt", std::ios::in | std::ifstream::binary);
    file.read(reinterpret_cast<char *>(&size), sizeof(unsigned long));
    for (int i = 0; i != size; i++) {
        file.read(reinterpret_cast<char *>(&dest), sizeof(DestructibleObject::destructible_t));
        _objectDestructibleList.emplace_back(coords(static_cast<float>(dest.x), 0, static_cast<float>(dest.y)), std::make_pair(0, 0), std::make_pair("", "")).setLife(dest.life);
    }
    file.close();
}