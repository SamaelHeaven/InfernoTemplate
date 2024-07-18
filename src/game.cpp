#include "./scenes/MainScene.h"

void main() {
    GameConfig config;
    config.icon = "textures/icon.png";
    file::set_working_directory("resources");
    Game::launch<MainScene>(config);
}
