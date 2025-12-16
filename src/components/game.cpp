#include "../headers/game.hpp"
#include <fstream>
#include <iostream>

Game::Game(const std::string& gameFile) {
    // Load main game JSON
    std::ifstream file(gameFile);
    if (!file) {
        std::cerr << "Failed to open game file: " << gameFile << "\n";
        return;
    }

    json gameData;
    file >> gameData;

    title = gameData.value("title", "Untitled");
    creator = gameData.value("creator", "Unknown");

    // Load chapter paths
    for (auto& ch : gameData["chapters"]) {
        chapters.push_back({ ch.get<std::string>(), {} });
    }
}

bool Game::loadChapters() {
    for (auto& ch : chapters) {
        std::ifstream file(ch.path);
        if (!file) {
            std::cerr << "Failed to open chapter: " << ch.path << "\n";
            return false;
        }

        file >> ch.data;
    }
    return true;
}
