#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

using namespace std;
using namespace sf;

void setText(Font font, Text title, string name, int size){
    font.loadFromFile("font_space_font.ttf");
    title.setFont(font);
    title.setString(name);
    title.setCharacterSize(size);
}

int main() {
    int window_width = 700;
    int header_height = 1000;
    sf::RenderWindow window(VideoMode(window_width, window_width), "Vertically Challenged Link", Style::Close);
    window.setFramerateLimit(60);
    Font Font;
    Text title;
    Font.loadFromFile("font_space_font.ttf");
    title.setFont(Font);
    title.setString("Vertically Challenged Link");
    title.setCharacterSize(26);
    title.setFillColor(Color::Black);
    title.setPosition(235.0f, 20.0f);

    Text header;
    header.setString("Enter First Word:");
    header.setFont(Font); // need help with the font
    header.setCharacterSize(24);
    header.setFillColor(Color::Magenta);
    header.setStyle(Text::Bold);
    header.setPosition(270.0f, 75.0f);

    Text header_2;
    header_2.setString("Enter Second Word:");
    header_2.setFont(Font); // need help with the font
    header_2.setCharacterSize(24);
    header_2.setFillColor(Color::Red);
    header_2.setStyle(Text::Bold);
    header_2.setPosition(270.0f, 250.0f);

    Texture mario;
    mario.loadFromFile("images_1/mario.png");
    Sprite Mario;
    Mario.setTexture(mario);
    Mario.setPosition(300, 450);
    Mario.setScale(0.1f, 0.1f);


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
        window.draw(header_2);
        window.draw(header);
        window.draw(Mario);
        window.display();
    }

}
