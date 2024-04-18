#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <Network/Http.hpp>

// used the font from https://www.fontspace.com/category/ttf;

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

    Text input;
    input.setFont(Font); // need help with the font
    input.setCharacterSize(24);
    input.setFillColor(Color::Red);
    input.setPosition(270.0f, 100.0f);

    Text input_2;
    input_2.setFont(Font); // need help with the font
    input_2.setCharacterSize(24);
    input_2.setFillColor(Color::Red);
    input_2.setPosition(270.0f, 275.0f);

    string name_1 = "";
    string name_2 = "";
    char ASCII = '0';



    while (window.isOpen()){
        Event event;
        while (window.pollEvent(event)){
            if (event.type == Event::Closed){
                window.close();
                return 0;
            }
            if (event.type == Event::TextEntered && name_1.size() < 30){
                if(event.text.unicode < 128){
                    ASCII = static_cast<char>(event.text.unicode);
                }
                if(isalpha(ASCII)){
                    if (name_1.length() == 0){
                        name_1 += toupper(ASCII);
                        //setText(Font, input, 270.0f, 275.0f);
                    }
                    else if (name_1.length() > 0){
                        name_1 += toupper(ASCII);
                    }
                }
            }
            /*if(event.type == Event::KeyPressed){
                if (event.key.code == Keyboard::Enter){
                    Event event_2;
                    if (event_2.type == Event::TextEntered && name_2.size() < 30){
                        if(event_2.text.unicode < 128){
                            ASCII = static_cast<char>(event_2.text.unicode);
                        }
                        if(isalpha(ASCII)){
                            if (name_2.length() == 0){
                                name_2 += toupper(ASCII);
                                //setText(Font, input, 270.0f, 275.0f);
                            }
                            else if (name_2.length() > 0){
                                name_2 += toupper(ASCII);
                            }
                        }
                    }


                }
            }*/
            if(Mouse::isButtonPressed(Mouse::Left)){
                Vector2i click;
                click = Mouse::getPosition(window);
                if(Mario.getGlobalBounds().contains(window.mapPixelToCoords(click))){
                    window.close();
                }
            }

        }
        input.setString(name_1);
        input_2.setString(name_1);
        window.clear(Color(173, 216, 230));
        window.draw(title);
        window.draw(header_2);
        window.draw(header);
        window.draw(Mario);
        window.draw(input);
        window.draw(input_2);
        window.display();
    }

}