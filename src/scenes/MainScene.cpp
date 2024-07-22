#include "./MainScene.h"

MainScene::MainScene() = default;

MainScene::~MainScene() = default;

void MainScene::initialize() {}

void MainScene::update() {
    Renderer::clear_background(Color::BLUE);
    Game::set_title(std::string("FPS: ") + std::to_string(Time::current_fps()));
    if (Keyboard::is_key_pressed(Key::TAB)) {
        Game::toggle_fullscreen();
    }
}
