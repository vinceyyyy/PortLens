#include <print>
#include <saucer/smartview.hpp>

coco::stray start(saucer::application* app)
{
    auto window = saucer::window::create(app).value();

    auto webview = saucer::smartview::create({
        .window = window
        });

    window->set_title("PortLens");

    window->set_size({ .w = 900, .h = 600 });

    webview->set_url("http://127.0.0.1:5173");

    window->show();

    co_await app->finish();

}

int main()
{
    return saucer::application::create({
        .id = "hello-world"
        })->run(start);
}
