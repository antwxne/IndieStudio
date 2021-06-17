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

#include "Map.hpp"

Map::Map(const std::vector<std::pair<int, int>> &posTank) : _posTank(posTank)
{
}

void Map::createDestructibleMap(std::pair<int, int> const &pos_left,
    std::pair<int, int> const &pos_down_right
)
{
    bool findPos = true;
    int nbrPos = 0;
    std::random_device posRand;
    std::mt19937 e2(posRand());
    std::uniform_real_distribution<> theX(pos_left.first, pos_down_right.first);
    std::uniform_real_distribution<> theY(pos_left.second,
        pos_down_right.second);

    for (std::pair<int, int> tmpMap; nbrPos != 3;) {
        findPos = true;
        tmpMap.first = std::round(theX(e2));
        tmpMap.second = std::round(theY(e2));

        for (const auto &thePos : _posTank)
            if (thePos == tmpMap || ((thePos.first + 1) == tmpMap.first &&
                thePos.second == tmpMap.second) ||
                ((thePos.first - 1) == tmpMap.first &&
                    thePos.second == tmpMap.second) ||
                (thePos.first == tmpMap.first &&
                    (thePos.second + 1) == tmpMap.second) ||
                (thePos.first == tmpMap.first &&
                    (thePos.second - 1) == tmpMap.second)) {
                findPos = false;
                break;
            }
        if (findPos == true)
            for (const auto &dest : _objectDestructibleList)
                if (dest.getPosition().first == tmpMap.first &&
                    dest.getPosition().third == tmpMap.second || (dest.getPosition().first + 1) == tmpMap.first &&
                    dest.getPosition().third == tmpMap.second || (dest.getPosition().first - 1) == tmpMap.first &&
                    dest.getPosition().third == tmpMap.second || dest.getPosition().first == tmpMap.first &&
                    (dest.getPosition().third + 1) == tmpMap.second || dest.getPosition().first == tmpMap.first &&
                    (dest.getPosition().third - 1) == tmpMap.second) {
                    findPos = false;
                    break;
                }
        if (findPos == true) {
            nbrPos += 1;
            _objectDestructibleList.emplace_back(
                coords(static_cast<float>(tmpMap.first), 0,
                    static_cast<float>(tmpMap.second)), std::make_pair(0, 0),
                std::make_pair("", ""));
        }
    }
}

void Map::createContourMap(std::pair<int, int> const &xAxis,
    std::pair<int, int> const &yAxis
) noexcept
{
    for (int x = xAxis.first, y = yAxis.first; x != xAxis.second; ++x) {
        _objectNoDestructibleList.emplace_back(
            coords(static_cast<float>(x), 0, static_cast<float>(y)),
            std::make_pair(0, 0), std::make_pair("", ""));
    }

    for (int x = xAxis.first, y = yAxis.second; x != xAxis.second; ++x) {
        _objectNoDestructibleList.emplace_back(
            coords(static_cast<float>(x), 0, static_cast<float>(y)),
            std::make_pair(0, 0), std::make_pair("", ""));
    }

    for (int x = xAxis.first, y = yAxis.first; y != yAxis.second; ++y) {
        _objectNoDestructibleList.emplace_back(
            coords(static_cast<float>(x), 0, static_cast<float>(y)),
            std::make_pair(0, 0), std::make_pair("", ""));
    }
    for (int x = xAxis.second, y = yAxis.first; y != yAxis.second; ++y) {
        _objectNoDestructibleList.emplace_back(
            coords(static_cast<float>(x), 0, static_cast<float>(y)),
            std::make_pair(0, 0), std::make_pair("", ""));
    }
}

void Map::writeDestructibleList() noexcept
{
    unsigned long size = _objectDestructibleList.size();
    DestructibleObject::destructible_t dest;
    std::ofstream file("destructibleList.txt",
        std::ios::out | std::ofstream::binary);
    file.write(reinterpret_cast<const char *>(&size), sizeof(unsigned long));
    for (auto &i : _objectDestructibleList) {
        dest = i.getStructSave();
        file.write(reinterpret_cast<const char *>(&dest),
            sizeof(DestructibleObject::destructible_t));
    }
    file.close();
}

void Map::readDestructibleList() noexcept
{
    unsigned long size = 0;
    DestructibleObject::destructible_t dest;
    std::ifstream file("destructibleList.txt",
        std::ios::in | std::ifstream::binary);
    file.read(reinterpret_cast<char *>(&size), sizeof(unsigned long));
    for (int i = 0; i != size; i++) {
        file.read(reinterpret_cast<char *>(&dest),
            sizeof(DestructibleObject::destructible_t));
        _objectDestructibleList.emplace_back(
            coords(static_cast<float>(dest.x), 0, static_cast<float>(dest.y)),
            std::make_pair(0, 0), std::make_pair("", "")).setLife(dest.life);
    }
    file.close();
}