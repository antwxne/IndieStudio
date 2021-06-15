//
// Created by clement on 14/06/2021.
//

#pragma once
#include "Object/AObject.hpp"

class Ground : public AObject {
    public:
    Ground(const coords &pos, const std::pair<int, int> &size, const std::pair<std::string, std::string> &path);
    ~Ground() = default;

    [[nodiscard]] const std::string &getTexture() const noexcept;
    [[nodiscard]] const std::string &getModel() const noexcept;
    protected:
        std::pair<std::string, std::string> _path;
};