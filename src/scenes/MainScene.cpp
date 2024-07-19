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
    const auto speed = 200 * Time::delta();
    Vector2 direction;
    if (Keyboard::is_key_down(Key::UP)) {
        direction += Vector2::UP;
    }
    if (Keyboard::is_key_down(Key::DOWN)) {
        direction += Vector2::DOWN;
    }
    if (Keyboard::is_key_down(Key::LEFT)) {
        direction += Vector2::LEFT;
    }
    if (Keyboard::is_key_down(Key::RIGHT)) {
        direction += Vector2::RIGHT;
    }
    const auto new_position = Mouse::get_position() + direction * speed;
    if (direction != Vector2::ZERO) {
        Mouse::set_position(new_position);
    }
}
