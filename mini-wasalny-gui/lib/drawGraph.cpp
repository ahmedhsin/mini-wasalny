#include <SFML/Graphics.hpp>

#include <chrono>

#include <thread>

#include <vector>

#include <utility>
#include <math.h>
#include <cstdlib>
#include <ctime>
#include <map>
#include <filesystem>
#include<string>
#include <fstream>
#include <iostream>
#include "Edge.h"
#include<unordered_map>
#include <sstream>




using namespace std;
std::ifstream fontFile("font.ttf", std::ios::binary);

// Cities
sf::CircleShape circle(float x, float y, float size, sf::Color color);

vector < pair < float, float >> LinePos(pair < sf::CircleShape, pair < int, int >> s1, pair < sf::CircleShape, pair < int, int >> s2);

vector < sf::Vertex > CreateLine(pair < sf::CircleShape, pair < int, int >> s1, pair < sf::CircleShape, pair < int, int >> s2);

sf::Font font;
//map < string, vector < string >> adj;
sf::Text CreateText(string cityName, float x, float y);

pair < int, int > Dimensions();

void LoadFont();

void RUN(unordered_map<string, unordered_set<Edge, EdgeHash>>& adj, vector < string >& nodes, float Speed, sf::Color NodeColor, sf::Color VisitedColor, sf::Color bgColor,sf::Color textColor, sf::Color lineColor, bool RandStyle);
















sf::CircleShape circle(float x, float y, float size, sf::Color color) {
    sf::CircleShape shape(100.0);
    shape.setFillColor(color);
    shape.setOrigin(0, 0);
    shape.setPosition(x, y);
    shape.setRadius(size);
    return shape;
}
// Edges Position
vector < pair < float, float >> LinePos(pair < sf::CircleShape, pair < int, int >> s1, pair < sf::CircleShape, pair < int, int >> s2) {
    vector < pair < float, float >> points;
    sf::FloatRect bounds = s1.first.getGlobalBounds();
    float x1 = s1.second.first, y1 = s1.second.second;
    float x2 = s2.second.first, y2 = s2.second.second;
    // calculate the position of the edge of the circle
    float cx = bounds.left + bounds.height / 2.0f;
    float cy = bounds.top + bounds.width / 2.0f;
    float r = bounds.height / 2.0f;
    float angle = atan2(y2 - cy, x2 - cx);
    float x3 = cx + r * cos(angle);
    float y3 = cy + r * sin(angle);
    points.push_back({
      x3,
      y3
        });
    bounds = s2.first.getGlobalBounds();
    cx = bounds.left + bounds.height / 2.0f;
    cy = bounds.top + bounds.width / 2.0f;
    r = bounds.height / 2.0f;
    angle = atan2(y1 - cy, x1 - cx);
    x2 = cx + r * cos(angle);
    y2 = cy + r * sin(angle);
    points.push_back({
      x2,
      y2
        });
    return points;
}
// Edges
vector < sf::Vertex > CreateLine(pair < sf::CircleShape, pair < int, int >> s1, pair < sf::CircleShape, pair < int, int >> s2) {
    vector < pair < float, float >> point = LinePos(s1, s2);
    vector < sf::Vertex > points;
    sf::Vertex lines[]{
      sf::Vertex(sf::Vector2f(point[0].first, point[0].second)),
        sf::Vertex(sf::Vector2f(point[1].first, point[1].second))
    };
    points.push_back(lines[0]);
    points.push_back(lines[1]);
    return points;
}

// Text
sf::Text CreateText(string cityName, float x, float y, sf::Color color) {

    sf::Text text;
    //if (!font.loadFromFile("fonts/Quicksand-Medium.ttf")) {
    //    cout<<"lol";
    //    return text;
    //}
    text.setFont(font);
    text.setString(cityName);
    text.setCharacterSize(24);
    text.setFillColor(color);
    // 28 35
    text.setPosition(x + 20, y + 27);
    return text;
}
pair < int, int > Dimensions() {
    /*to set automatic height and width*/
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();

    // Set the window size to a percentage of the screen size
    float widthPercent = 0.8f;
    float heightPercent = 0.8f;
    unsigned int width = static_cast <unsigned int> (desktop.width * widthPercent);
    unsigned int height = static_cast <unsigned int> (desktop.height * heightPercent);
    return {
      height,
      width
    };
}
void LoadFont();

void LoadFont() {
    font.loadFromFile("fonts/Quicksand-Medium.ttf");
}

void RUN(unordered_map<string, unordered_set<Edge, EdgeHash>>& adj, vector < string >& nodes, float Speed, sf::Color NodeColor, sf::Color VisitedColor, sf::Color bgColor, sf::Color textColor, sf::Color lineColor, bool RandStyle) {
    int height, width;
    tie(height, width) = Dimensions();
    LoadFont();

    /* screen settings */
    sf::VideoMode videoMode(width, height);
    sf::RenderWindow window(sf::VideoMode(width, height), "Graph");

    window.setVerticalSyncEnabled(true);
    sf::View view(sf::FloatRect(0, 0, window.getSize().x, window.getSize().y));
    //window.setView(view);


    /*Logic*/
    float x = width / 2, y = 15;
    srand(time(0));
    float rad = 15.0;
    map < string, pair < sf::CircleShape, pair < float, float >>> Circles;
    map < string, bool > visited;
    vector < vector < sf::Vertex >> AllLines;
    //unordered_map < string, vector < pair < string, double >>>
    for (auto city : adj) {
        if (!visited[city.first]) {
            Circles[city.first] = {
                circle(x, y, rad, NodeColor),
                {
                    x,
                    y
                }
            };
            visited[city.first] = 1;
        }
        y = y + height / 5;
        int neb = city.second.size();
        if (neb == 0)
            neb = 1;
        float div = width / neb - height / 10;
        int i = 1;
        for (auto edge : city.second) {
            int rx = rand() % 101 - 50;
            int ry = rand() % 101 - 50;
            if (!visited[edge.dest]) {
                Circles[edge.dest] = {
                    circle((div * i) + rx, y + ry, rad, NodeColor),
                    {
                        (div * i) + rx,
                        y + ry
                    }
                };
                i++;
                visited[edge.dest] = 1;
            }
            vector < sf::Vertex > lines = CreateLine(Circles[city.first], Circles[edge.dest]);
            AllLines.push_back(lines);

        }
    }

    sf::Clock clock;
    int currentCity = 0;
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    // Get the mouse position in world coordinates
                    sf::Vector2i pixelPos = sf::Mouse::getPosition(window);
                    sf::Vector2f worldPos = window.mapPixelToCoords(pixelPos);

                    // Set the view center to the mouse position
                    view.setCenter(worldPos);
                    window.setView(view);
                }
            }
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();

                // handle mouse scroll events
                if (event.type == sf::Event::MouseWheelScrolled)
                {
                    // get the current zoom level
                    float zoom = view.getSize().x / window.getSize().x;

                    // calculate the new zoom level
                    zoom += event.mouseWheelScroll.delta * 0.1f;

                    // make sure the zoom level is within reasonable bounds
                    if (zoom < 0.1f)
                        zoom = 0.1f;
                    if (zoom > 5.0f)
                        zoom = 5.0f;

                    // set the new view size based on the zoom level
                    view.setSize(window.getDefaultView().getSize() * zoom);
                    window.setView(view);

                }
            }

        }

        window.clear(bgColor);


        for (auto& node : Circles) {
            window.draw(node.second.first);
        }

        for (auto& node : Circles) {
            window.draw(CreateText(node.first, node.second.second.first, node.second.second.second, textColor));
        }

        for (auto i = 0; i < (int)(AllLines.size()); i++) {
            sf::Vertex line[2]{
              AllLines[i][0], AllLines[i][1]
            };
            AllLines[i][0].color = lineColor;
            AllLines[i][1].color = lineColor;
            window.draw(line, 5, sf::Lines);
        }

        if (clock.getElapsedTime().asSeconds() > Speed && currentCity < nodes.size()) {
            if (Speed <= 0){
                Circles[nodes[currentCity]].first.setFillColor(VisitedColor);
            }
            else if (Circles[nodes[currentCity]].first.getFillColor() == NodeColor) {
                Circles[nodes[currentCity]].first.setFillColor(VisitedColor);
            }
            else {
                Circles[nodes[currentCity]].first.setFillColor(NodeColor);
            }
            currentCity = (currentCity + 1) % nodes.size();
            clock.restart();
        }

        window.display();
    }

}
