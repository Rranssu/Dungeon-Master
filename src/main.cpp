#include <iostream>
#include "headers/game.hpp"

int main() {
    Game game("data/gameDat.json");

    std::cout << "Game: " << game.title << " by " << game.creator << "\n";

    if (!game.loadChapters()) {
        std::cerr << "Error loading chapters.\n";
        return 1;
    }

    std::cout << "Chapters loaded: " << game.chapters.size() << "\n";

    // Example access to first chapter
    auto& firstChapter = game.chapters[0].data;
    std::cout << "First scene text: " 
              << firstChapter["scenes"]["intro"]["text"] << "\n";

    return 0;
}
