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
    _pos.push_back(std::make_pair(2, 2));
    _pos.push_back(std::make_pair(3, 2));
}

void Map::createDestructibleMap(std::pair<int, int> &pos_left,
    std::pair<int, int> &pos_down_right
)
{
    std::srand(std::time(nullptr));
    int tmp = 0;
    bool findPos = true;

    for (std::pair<int, int> tmp_map; tmp != 3;) {
        findPos = true;
        tmp_map.first = std::rand() % pos_down_right.first + pos_left.second;
        tmp_map.second = std::rand() % pos_down_right.second + pos_left.first;
        for (const auto &the_pos : _pos)
            if (the_pos == tmp_map) {
                findPos = false;
                break;
            }
        if (findPos == true)
            for (const auto &dest : _objectDestructibleList)
                if (dest.getPosition() == tmp_map) {
                    findPos = false;
                    break;
                }
        if (findPos == true) {
            tmp += 1;
            _objectDestructibleList.emplace_back(
                tmp_map, std::make_pair(0, 0), std::make_pair("", ""));
        }
    }
}

void Map::createContourMap(int const &xMax, int const &yMax) noexcept
{
    for (int x = 0, y = 0; x != xMax; ++x) {
        _objectNoDestructibleList.emplace_back(
            std::make_pair(x, y), std::make_pair(0, 0), std::make_pair("", ""));
    }
    for (int x = 0, y = yMax; x != xMax; ++x) {
        _objectNoDestructibleList.emplace_back(
            std::make_pair(x, y), std::make_pair(0, 0), std::make_pair("", ""));
    }
    for (int x = 0, y = 0; y != yMax; ++y) {
        _objectNoDestructibleList.emplace_back(
            std::make_pair(x, y), std::make_pair(0, 0), std::make_pair("", ""));
    }
    for (int x = xMax, y = 0; y != yMax; y++) {
        _objectNoDestructibleList.emplace_back(
            std::make_pair(x, y), std::make_pair(0, 0), std::make_pair("", ""));
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
        _objectDestructibleList.emplace_back(std::make_pair(dest.x, dest.y), std::make_pair(0, 0), std::make_pair("", "")).setLife(dest.life);
    }
    file.close();
}