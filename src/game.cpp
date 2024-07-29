#include "./scenes/MainScene.h"

int32_t main([[maybe_unused]] const std::vector<std::string> &args) {
    GameConfig config;
    config.icon = "textures/icon.png";
    file::set_working_directory("resources");
    Game::launch<MainScene>(config);
    return 0;
}
