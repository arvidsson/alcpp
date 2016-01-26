# alcpp
Allegro 5 C++ wrapper

### example

```c++
#include <alcpp.hpp>
using namespace alcpp;

class Game
{
public:
    Game() : timer(1.0 / 60), display(800, 600)
    {
        eventQueue.Register(Keyboard::GetEventSource());
        eventQueue.Register(timer.GetEventSource());
        eventQueue.Register(display.GetEventSource());
    }

    void Run()
    {
        bool done = false;
        bool redraw = true;
        timer.Start();

        while (!done) {
            auto event = eventQueue.WaitForEvent();

            switch (event.GetType()) {
                case Event::Type::Timer:
                    redraw = true;
                    Update();
                    break;

                case Event::Type::DisplayClose:
                    done = true;
                    break;
            }

            if (redraw && eventQueue.IsEmpty()) {
                redraw = false;
                display.Clear();
                Render();
                display.SwapBuffers();
            }
        }
    }

    void Update();
    {
        // run game logic here...
    }

    void Render()
    {
        // draw stuff here...
    }

private:
    EventQueue eventQueue;
    Timer timer;
    Display display;
}

int main()
{
    try {
        System::Initialize();
        auto game = std::make_unique<Game>();
        game->Run();
    }
    catch (const std::exception &e) {
        // handle exception
    }

    return 0;
}
```
