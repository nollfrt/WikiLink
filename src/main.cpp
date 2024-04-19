#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>
#include <Network/Http.hpp>

// used the font from https://www.fontspace.com/category/ttf;
// used SFML website for tutorials on certain commands


using namespace std;
using namespace sf;

void setText(Font font, Text title, string name, int size){
    font.loadFromFile("font_space_font.ttf");
    title.setFont(font);
    title.setString(name);
    title.setCharacterSize(size);
}

int main() {
    /*Http http;
    http.setHost("https://bridgesuncc.github.io/");
    Http::Request get;
    get.setMethod(Http::Request::Post);
    get.setUri("/tutorials/Data_IGN_Games.html");
    get.setHttpVersion(1, 1);
    Http::Response out = http.sendRequest(get);
    std::cout << "body: " << out.getBody() << std::endl;*/

    int window_width = 700;
    int header_height = 1000;
    sf::RenderWindow window(VideoMode(window_width, window_width), "Vertically Challenged Link", Style::Close);
    window.setFramerateLimit(60);
    Font Font;
    Text title;
    Font.loadFromFile("simple.ttf");
    title.setFont(Font);
    title.setString("Vertically Challenged Link");
    title.setCharacterSize(26);
    title.setFillColor(Color::Black);
    title.setPosition(225.0f, 20.0f);

    Text header;
    header.setString("Enter First Word:");
    header.setFont(Font); // need help with the font
    header.setCharacterSize(24);
    header.setFillColor(Color::Magenta);
    header.setStyle(Text::Bold);
    header.setPosition(255.0f, 75.0f);

    Text header_2;
    header_2.setString("Enter Second Word:");
    header_2.setFont(Font); // need help with the font
    header_2.setCharacterSize(24);
    header_2.setFillColor(Color::Red);
    header_2.setStyle(Text::Bold);
    header_2.setPosition(245.0f, 250.0f);

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
    input.setPosition(245.0f, 100.0f);

    Text input_2;
    input_2.setFont(Font); // need help with the font
    input_2.setCharacterSize(24);
    input_2.setFillColor(Color::Red);
    input_2.setPosition(245.0f, 275.0f);

    VertexArray square(sf::Quads, 4);
    square[0].position = Vector2f(250.0f, 400.0f);
    square[1].position = Vector2f(450.0f, 400.0f);
    square[2].position = Vector2f(450.0f, 550.0f);
    square[3].position = Vector2f(250.0f, 550.0f);
    square[0].color = Color::Red;
    square[1].color = Color::Magenta;
    square[2].color = Color::Blue;
    square[3].color = Color::Yellow;

    VertexArray text_box1(sf::Quads, 4);
    text_box1[0].position = Vector2f(245.0f, 100.0f);
    text_box1[1].position = Vector2f(450.0f, 100.0f);
    text_box1[2].position = Vector2f(450.0f, 130.0f);
    text_box1[3].position = Vector2f(245.0f, 130.0f);
    text_box1[0].color = Color::White;
    text_box1[1].color = Color::White;
    text_box1[2].color = Color::White;
    text_box1[3].color = Color::White;

    VertexArray text_box2(sf::Quads, 4);
    text_box2[0].position = Vector2f(245.0f, 275.0f);
    text_box2[1].position = Vector2f(450.0f, 275.0f);
    text_box2[2].position = Vector2f(450.0f, 305.0f);
    text_box2[3].position = Vector2f(245.0f, 305.0f);
    text_box2[0].color = Color::White;
    text_box2[1].color = Color::White;
    text_box2[2].color = Color::White;
    text_box2[3].color = Color::White;

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
                if(square.getBounds().contains(window.mapPixelToCoords(click))){
                    window.close();
                }
            }

        }
        input.setString(name_1);
        input_2.setString(name_2);
        window.clear(Color(173, 216, 230));
        window.draw(title);
        window.draw(header_2);
        window.draw(header);
        //window.draw(Mario);
        window.draw(text_box1);
        window.draw(text_box2);
        window.draw(input);
        window.draw(input_2);
        window.draw(square);
        window.display();
    }

    VertexArray graph_square(sf::Quads, 4);
    graph_square[0].position = Vector2f(50.0f, 350.0f);
    graph_square[1].position = Vector2f(650.0f, 350.0f);
    graph_square[2].position = Vector2f(650.0f, 650.0f);
    graph_square[3].position = Vector2f(50.0f, 650.0f);
    graph_square[0].color = Color::White;
    graph_square[1].color = Color::White;
    graph_square[2].color = Color::White;
    graph_square[3].color = Color::White;


    VertexArray button(sf::Quads, 4);
    button[0].position = Vector2f(300.0f, 150.0f);
    button[1].position = Vector2f(400.0f, 150.0f);
    button[2].position = Vector2f(400.0f, 250.0f);
    button[3].position = Vector2f(300.0f, 250.0f);
    button[0].color = Color::Blue;
    button[1].color = Color::White;
    button[2].color = Color::Blue;
    button[3].color = Color::White;



    sf::RenderWindow graph_window(VideoMode(window_width, window_width), "Vertically Challenged Link", Style::Close);
    window.setFramerateLimit(60);
    while (graph_window.isOpen()){
        Event new_event;
        while (graph_window.pollEvent(new_event)) {
            if (new_event.type == Event::Closed) {
                graph_window.close();
                return 0;
            }
            if (new_event.key.code == Keyboard::Enter){
                return 0;
            }
            if(Mouse::isButtonPressed(Mouse::Left)){
                Vector2i click;
                click = Mouse::getPosition(graph_window);
                if(button.getBounds().contains(graph_window.mapPixelToCoords(click))){
                    graph_window.close();
                    sf::RenderWindow window(VideoMode(window_width, window_width), "Vertically Challenged Link", Style::Close);
                    while(window.isOpen()){
                        window.draw(Mario);
                        window.display();
                        return 0;
                    }
                }
            }
        }
        graph_window.clear(Color(154, 171, 137));
        graph_window.draw(graph_square);
        graph_window.draw(button);
        graph_window.display();
    }

}