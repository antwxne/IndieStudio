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

void Map::createDestructibleMap(std::pair<int, int> pos_left,
    std::pair<int, int> pos_down_right
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
            _objectDestructibleList.push_back(
                DestructibleWall(tmp_map, std::make_pair(0, 0)));
        }
    }
}

void Map::createContourMap(int xMax, int yMax) noexcept
{
    for (int x = 0, y = 0; x != xMax; ++x) {
        _objectNoDestructibleList.push_back(
            Wall(std::make_pair(x, y), std::make_pair(0, 0)));
    }
    for (int x = 0, y = yMax; x != xMax; ++x) {
        _objectNoDestructibleList.push_back(
            Wall(std::make_pair(x, y), std::make_pair(0, 0)));
    }
    for (int x = 0, y = 0; y != yMax; ++y) {
        _objectNoDestructibleList.push_back(
            Wall(std::make_pair(x, y), std::make_pair(0, 0)));
    }
    for (int x = xMax, y = 0; y != yMax; y++) {
        _objectNoDestructibleList.push_back(
            Wall(std::make_pair(x, y), std::make_pair(0, 0)));
    }
}
/*
void Map::writeIn() noexcept
{
    std::ofstream file("fihvhier", std::ios::out);
    file.write((char *)&this[0], sizeof(this));
    file.close();
}

void Map::readIt() noexcept
{
    std::ifstream file;
    file.open("fihvhier", std::ios::in);
    file.read((char *)&this[0], sizeof(this));
    std::cout << this->_objectNoDestructibleList[0].getPosition().first;
   /* for(auto const &e: this->_objectNoDestructibleList)
        std::cout << "this new x" << e.getPosition().first << std::endl;*/
}*/