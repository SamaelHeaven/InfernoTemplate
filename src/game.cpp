#include "./scenes/MainScene.h"

void main() {
    GameConfig config;
    config.title = "Game";
    config.icon = "textures/icon.png";
    file::set_working_directory("resources");
    Game::launch<MainScene>(config);
}
