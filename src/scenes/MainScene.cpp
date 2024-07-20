#include "./MainScene.h"

MainScene::MainScene() = default;

MainScene::~MainScene() = default;

void MainScene::initialize() {}

void MainScene::update() {
    // Clearing background

    Renderer::clear_background(Color::BLUE);

    // Changing window title

    Game::set_title(std::string("FPS: ") + std::to_string(Time::current_fps()));

    // Fullscreen toggle

    if (Keyboard::is_key_pressed(Key::TAB)) {
        Game::toggle_fullscreen();
    }

    // Moving mouse

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
    direction = direction.normalize();
    const auto new_position = Mouse::get_position() + direction * speed;
    if (direction != Vector2::ZERO) {
        Mouse::set_position(new_position);
    }

    // Changing cursor

    const auto cursor = Mouse::get_cursor();
    for (int32_t i = 0; i < static_cast<int32_t>(Key::NINE) + 1 - static_cast<int32_t>(Key::ZERO); i++) {
        if (Keyboard::is_key_pressed(static_cast<Key>(static_cast<int32_t>(Key::ZERO) + i))) {
            Mouse::set_cursor(static_cast<Cursor>(i + 1));
        }
    }

    if (Keyboard::is_key_pressed(Key::BACKSPACE)) {
        Mouse::set_cursor(Cursor::NONE);
    }

    if (Mouse::get_cursor() != cursor) {
        std::cout << "Cursor: " << magic_enum::enum_name(Mouse::get_cursor()) << '\n';
    }
}
