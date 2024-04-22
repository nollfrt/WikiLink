#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
//#include "Bridges.h"
//#include "LinkVisualizer.h"
//#include "DataSource.h"
//GraphAdMatrix.h"
#include <windows.h>
#include <shellapi.h>


// used the font from https://www.fontspace.com/category/ttf;
// spiderman image https://purepng.com/tags/spider-man
// mario image https://pngimg.com/image/30596
// https://www.codeproject.com/Questions/265461/Opening-A-Website-with-Cplusplus to help with opening the website
// used SFML website for tutorials on certain commands
// used similarities from my mindsweeper for SFML help


using namespace std;
using namespace sf;

int main() {
    int window_width = 700; // setting the dimentions for the window
    // creating the first window

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

    Text header; // creating first text entry
    header.setString("Enter First Word:");
    header.setFont(Font); // need help with the font
    header.setCharacterSize(24);
    header.setFillColor(Color::Blue);
    header.setStyle(Text::Bold);
    header.setPosition(255.0f, 75.0f);

    Text header_2; // second text entry
    header_2.setString("Enter Second Word:");
    header_2.setFont(Font); // need help with the font
    header_2.setCharacterSize(24);
    header_2.setFillColor(Color::Red);
    header_2.setStyle(Text::Bold);
    header_2.setPosition(245.0f, 250.0f);

    Texture mario; // chose to add creativity with Mario and Spider-Man
    mario.loadFromFile("images_1/mario.png");
    Sprite Mario;
    Mario.setTexture(mario);
    Mario.setPosition(450, 320);
    Mario.setScale(0.1f, 0.1f);

    Texture spidy;
    spidy.loadFromFile("images_1/SpiderMan.png");
    Sprite Spider;
    Spider.setTexture(spidy);
    Spider.setPosition(120, 320);
    Spider.setScale(0.5f, 0.5f);

    //created a text object to take in as the inputs for the BFS
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

    // creating the buttons for BFS or Bi-BFS

    VertexArray square(sf::Quads, 4);
    square[0].position = Vector2f(100.0f, 400.0f);
    square[1].position = Vector2f(300.0f, 400.0f);
    square[2].position = Vector2f(300.0f, 500.0f);
    square[3].position = Vector2f(100.0f, 500.0f);
    square[0].color = Color::Blue;
    square[1].color = Color::Blue;
    square[2].color = Color::Blue;
    square[3].color = Color::Blue;

    VertexArray bi_square(sf::Quads, 4);
    bi_square[0].position = Vector2f(400.0f, 400.0f);
    bi_square[1].position = Vector2f(600.0f, 400.0f);
    bi_square[2].position = Vector2f(600.0f, 500.0f);
    bi_square[3].position = Vector2f(400.0f, 500.0f);
    bi_square[0].color = Color::Red;
    bi_square[1].color = Color::Red;
    bi_square[2].color = Color::Red;
    bi_square[3].color = Color::Red;

    Text BFS;
    BFS.setString("Breadth First Search");
    BFS.setFont(Font); // need help with the font
    BFS.setCharacterSize(20);
    BFS.setFillColor(Color::White);
    BFS.setStyle(Text::Bold);
    BFS.setPosition(105.0f, 400.0f);

    Text Bi_BFS;
    Bi_BFS.setString("Depth First Search");
    Bi_BFS.setFont(Font); // need help with the font
    Bi_BFS.setCharacterSize(20);
    Bi_BFS.setFillColor(Color::White);
    Bi_BFS.setStyle(Text::Bold);
    Bi_BFS.setPosition(415.0f, 400.0f);

// creating the text box using the VertexArray of a square
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

    //starting the creation of the window and first screen
    while (window.isOpen()){
        Event event;
        bool t_b;// to get which input box they are typing in
        while (window.pollEvent(event)){
            if (event.type == Event::Closed){
                window.close();
                return 0;
            }
            if(Mouse::isButtonPressed(Mouse::Left)){
                Vector2i click;
                click = Mouse::getPosition(window);
                if(text_box1.getBounds().contains(window.mapPixelToCoords(click))){ // checking which box ha been clicked into
                    t_b = false;
                }
                else if(text_box2.getBounds().contains(window.mapPixelToCoords(click))){
                    t_b = true;
                }
            }
            if (event.type == Event::TextEntered && name_1.size() < 30 && t_b == false){
                if(event.text.unicode < 128){
                    ASCII = static_cast<char>(event.text.unicode); // similar to my implementation from my minesweeper (savannah Ogletree)
                }
                if(isalpha(ASCII)){
                    if (name_1.length() == 0){
                        name_1 += toupper(ASCII);
                    }
                    else if (name_1.length() > 0){
                        name_1 += toupper(ASCII);
                    }
                }
            }
            else if (event.type == Event::TextEntered && name_1.size() < 30 && t_b == true){
                if(event.text.unicode < 128){
                    ASCII = static_cast<char>(event.text.unicode); // same as previous one but with a different text box
                }
                if(isalpha(ASCII)){
                    if (name_2.length() == 0){
                        name_2 += toupper(ASCII);
                    }
                    else if (name_2.length() > 0){
                        name_2 += toupper(ASCII);
                    }
                }
            }
            if (event.type == Event::KeyPressed){
                if (event.key.code == Keyboard::Backspace && t_b == false){
                    name_1.pop_back();
                    input.setString(name_1);
                }
                else if(event.key.code == Keyboard::Backspace && t_b == true){ // need backspace so the user can edit what they type
                    name_2.pop_back();
                    input.setString(name_2);
                }
            }

            if(Mouse::isButtonPressed(Mouse::Left)){
                Vector2i click;
                click = Mouse::getPosition(window);
                if(square.getBounds().contains(window.mapPixelToCoords(click))){
                    window.close();
                }
                else if(bi_square.getBounds().contains(window.mapPixelToCoords(click))){
                    window.close();
                }
            }

        }
        input.setString(name_1); // draws everything!!!
        input_2.setString(name_2);
        window.clear(Color(173, 216, 230));
        window.draw(title);
        window.draw(header_2);
        window.draw(header);
        window.draw(Mario);
        window.draw(Spider);
        window.draw(text_box1);
        window.draw(text_box2);
        window.draw(input);
        window.draw(input_2);
        window.draw(square);
        window.draw(bi_square);
        window.draw(Bi_BFS);
        window.draw(BFS);
        window.display(); // then displays everything
    }

// start of the objects for the new window after the inputs and chosen BFS
    string link = "https://bridges-cs.herokuapp.com/assignments/1/salenatill22";
    Text bridges_link;
    bridges_link.setString(link);
    bridges_link.setFont(Font);
    bridges_link.setCharacterSize(20);
    bridges_link.setFillColor(Color::Red);
    bridges_link.setStyle(Text::Bold);
    bridges_link.setPosition(65.0f, 250.0f);

    VertexArray graph_square(sf::Quads, 4);
    graph_square[0].position = Vector2f(50.0f, 250.0f);
    graph_square[1].position = Vector2f(650.0f, 250.0f);
    graph_square[2].position = Vector2f(650.0f, 350.0f);
    graph_square[3].position = Vector2f(50.0f, 350.0f);
    graph_square[0].color = Color::White;
    graph_square[1].color = Color::White;
    graph_square[2].color = Color::White;
    graph_square[3].color = Color::White;

//bridges.setDataStructure(input);
//bridges.visualize();

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
                graph_window.close();
                ShellExecute(NULL, NULL, "https://bridges-cs.herokuapp.com/assignments/1/salenatill22", NULL, NULL, SW_SHOWNORMAL);
                // creates the link to then open the webpage and close the graph window
            }
        }
        graph_window.clear(Color(154, 171, 137));
        graph_window.draw(graph_square);
        graph_window.draw(bridges_link);
        graph_window.display(); // displays and draws everything
    }
}