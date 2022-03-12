#include "pch.h"
#include "Graph.h"
using namespace sf;

int main() {
    // Create Window
    sf::ContextSettings settings;
    // This is so the shapes look smooth
    settings.antialiasingLevel = 8;

    int width = 800;
    int height = 600;
    RenderWindow window(VideoMode(width, height), "SFML Graph Generator", Style::Default, settings);
    window.setFramerateLimit(60);

    // Create Data for graph
    std::vector<float> data;
    for (int i = 0; i < 25; i++) {
        data.push_back((std::cos((3.1415f / 25.f) * i) + 1)*50 + (std::cos(3.1415f / 15.f * i)+1) * 50 + 80);
    }
    // Create graph
    Graph graph = Graph(width, height);
    graph.setData(data);
    graph.setDataCeil(298);
    graph.setDataFloor(100);
    graph.setNumYLabels(20); // 10 labels between beginning and top of maximum data
    graph.setXLabelInterval(1); // Show every 2 labels
    graph.setFGLineThickness(4);
    graph.setGraphLineColor(sf::Color(196, 64, 32));
    graph.setGraphColor(sf::Color(196, 64, 32, 128));
    graph.setXLabelText("Days Passed");
    graph.setYLabelText("Money made per Day");
    graph.setTitleLabel("This is a Graph");

    graph.generateGraph();

    //TODO Add title to graph

    bool screenshot = false;
    while (window.isOpen()) {
        Event event;

        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }
        }

        window.clear(sf::Color(255, 255, 255));
        graph.drawGraph(&window);

        window.display();

        if (screenshot) {
            sf::Texture texture;
            std::string filename = "Graph.png";
            texture.create(window.getSize().x, window.getSize().y);
            texture.update(window);
            if (texture.copyToImage().saveToFile(filename)) {
                std::cout << "screenshot saved to " << filename << std::endl;
            }
            screenshot = false;
        }
    }
}