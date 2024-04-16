#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

using namespace std;
using namespace sf;

void setText(int window_width, Text title){
    FloatRect titleRect = title.getLocalBounds();
    title.setOrigin(titleRect.left +titleRect.width / 2.0f,
                    titleRect.top + titleRect.height / 2.0f);
    title.setPosition(Vector2f((window_width / 2.0f), (window_width / 2.0 - 150)));
}

int main() {
    int window_width = 700;
    sf::RenderWindow window(VideoMode(window_width, window_width), "Vertically Challenged Link", Style::Close);
    window.setFramerateLimit(60);
    Font Font;
    Text title;
    Font.loadFromFile("font_space_font.ttf");
    title.setFont(Font);
    title.setString("Vertically Challened Link");
    title.setCharacterSize(26);
    title.setFillColor(Color::Black);
    setText(window_width, title);

    Text header;
    header.setString("Enter First Word:");
    header.setFont(Font); // need help with the font
    header.setCharacterSize(24);
    header.setFillColor(Color::Magenta);
    header.setStyle(Text::Bold);
    setText(window_width, header);


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
