#pragma once

#include <string>
#include <vector>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

struct Chapter {
    std::string path;
    json data;
};

class Game {
public:
    Game(const std::string& gameFile);

    std::string title;
    std::string creator;
    std::vector<Chapter> chapters;

    bool loadGameData();
    bool loadChapters();
};
