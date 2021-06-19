//
// Created by clement on 14/06/2021.
//

#pragma once
#include "Object/AObject.hpp"

/**
 * @class Ground
 * @brief class for Ground
 * 
 */
class Ground : public AObject {
    public:
    /**
     * @brief Construct a new Ground object
     * 
     * @param pos 
     * @param size 
     * @param path 
     */
    Ground(const coords &pos, const std::pair<int, int> &size, const std::pair<std::string, std::string> &path);
    /**
     * @brief Destroy the Ground object
     * 
     */
    ~Ground() = default;
    /**
     * @brief Get the Texture object
     * 
     * @return const std::string& 
     */
    [[nodiscard]] const std::string &getTexture() const noexcept;
    /**
     * @brief Get the Model object
     * 
     * @return const std::string& 
     */
    [[nodiscard]] const std::string &getModel() const noexcept;
    protected:
        /**
         * @brief path to model
         * 
         */
        std::pair<std::string, std::string> _path;
};