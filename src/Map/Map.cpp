//
// Created by clement on 03/06/2021.
//

#include <cstdlib>
#include <ctime>
#include <array>
#include "Map.hpp"

Map::Map()
{
    _pos.push_back(std::make_pair(2,2));
    _pos.push_back(std::make_pair(3,2));
}

void Map::createMap(std::pair<int, int> pos_left, std::pair<int, int> pos_down_right) {
    std::srand(std::time(nullptr));
    int tmp = 0;
    bool findPos = true;

    for (std::pair<int, int> tmp_map;tmp != 3;) {
        findPos = true;
        tmp_map.first = std::rand() % pos_down_right.first + pos_left.second;
        tmp_map.second = std::rand() % pos_down_right.second + pos_left.first;
        for (const auto& the_pos : _pos)
            if (the_pos == tmp_map) {
                findPos = false;
                break;
            }
        if (findPos == true)
            for (const auto& dest : _objectList)
                if (dest.getPosition() == tmp_map) {
                    findPos = false;
                    break;
                }
        if (findPos == true) {
            tmp += 1;
            _objectList.push_back(DestructibleWall(tmp_map, std::make_pair(0,0)));
        }
    }
}