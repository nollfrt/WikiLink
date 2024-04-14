#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

using namespace std;
using namespace sf;



int main() {
    int window_width = 700;
    sf::RenderWindow window(VideoMode(window_width, window_width), "Vertically Challenged Link", Style::Close);
    window.setFramerateLimit(60);
    Font new_font;
    Text title;
    title.setFont(new_font);
    title.setString("Vertically Challened Link");
    title.setCharacterSize(26);
    title.setFillColor(Color::Black);
    FloatRect titleRect = title.getLocalBounds();
    title.setOrigin(titleRect.left +titleRect.width / 2.0f,
                    titleRect.top + titleRect.height / 2.0f);
    title.setPosition(Vector2f((window_width / 2.0f), (window_width / 2.0 - 150)));

    while (window.isOpen()){
        Event event;
        while (window.pollEvent(event)){
            if (event.type == Event::Closed){
                window.close();
                return 0;
            }
        }
        window.clear(Color(173, 216, 230));
        window.draw(title);
        window.display();
    }

}
