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
{}

void Map::createDestructibleMap(std::pair<int, int> const &pos_left, std::pair<int, int> const &pos_down_right)
{
    int tmp = 0;
    bool findPos = true;
    std::cout << "la pos left = " << pos_left.first << " second = " << pos_left.second << "\n";
    std::cout << "pos_down_right = " << pos_down_right.first << " second = " << pos_down_right.second << "\n";
    // std::random_device r;
    // std::random_device t;
    // std::default_random_engine el(r());
    // std::default_random_engine al(t());

    // std::cout << "random device" << "\n";
    // std::random_device r;
    // std::cout << "random seed" << "\n";
    // std::seed_seq seed{r(), r(), r(), r(), r(), r(), r(), r()};
    // std::cout << "mt19937" << "\n";
    // std::mt19937 eng(seed);

    // std::cout << "random device" << "\n";
    // std::random_device a;
    // std::cout << "random seed" << "\n";
    // std::seed_seq seed2{a(), a(), a(), a(), a(), a(), a(), a()};
    // std::cout << "mt19937" << "\n";
    // std::mt19937 eng2(seed2);

    // std::cout << "uniform_int_distribution" << "\n";
    // std::uniform_int_distribution<> distFirst(pos_left.first, pos_down_right.first - 1);
    // std::cout << "uniform_int_distribution" << "\n";
    // std::uniform_int_distribution<> distSecond(pos_down_right.second, pos_left.second - 1);


    //for (std::pair<int, int> tmpMap; tmp != 3;) {
        // findPos = true;
        // std::cout << "first distFirst" << "\n";
        // tmpMap.first = distFirst(eng);
        // std::cout << "second distFirst" << "\n";
        // tmpMap.second = distSecond(eng2);
        // std::cout << "print value" << "\n";
        // std::cout << "x:" << tmpMap.first << " y:" << tmpMap.second << "\n\n";

    //     for (const auto &the_pos : _posTank)
    //         if (the_pos == tmpMap) {
    //             findPos = false;
    //             break;
    //         }
    //     if (findPos == true)
    //         for (const auto &dest : _objectDestructibleList)
    //             if (dest.getPosition().first == tmpMap.first && dest.getPosition().third == tmpMap.second) {
    //                 findPos = false;
    //                 break;
    //             }
    //     if (findPos == true) {
    //         std::cout << "[MAP] JE PASSE\n";
    //         tmp += 1;
    //         _objectDestructibleList.emplace_back(
    //             coords(static_cast<float>(tmpMap.first), 0, static_cast<float>(tmpMap.second)), std::make_pair(0, 0), std::make_pair("", ""));
    //     }
    //}
    std::cout << "[MAP] JE SORS\n";
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