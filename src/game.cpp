#include "./scenes/MainScene.h"

void main([[maybe_unused]] std::vector<std::string> args) {
    GameConfig config;
    config.icon = "textures/icon.png";
    file::set_working_directory("resources");
    Game::launch<MainScene>(config);
}
