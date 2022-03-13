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
    for (int i = 0; i < 30; i++) {
        data.push_back((std::cos((3.1415f / 25.f) * i) + 1)*50);
    }
    std::vector<float> data2;
    for (int i = 0; i < 30; i++) {
        data2.push_back((std::sin(3.1415f / 25.f * i + 3.1415f * 1.f) + 1) * 30);
    }
    std::vector<float> data3;
    for (int i = 0; i < 20; i++) {
        data3.push_back((std::sin(3.1415f / 50.f * i + 3.1415f) + 1) * 50);
    }
    // Create graph
    Graph graph = Graph(width, height);
    graph.setDataCeil(130);
    graph.setDataFloor(0);
    graph.setNumYLabels(20); // 10 labels between beginning and top of maximum data
    graph.setXLabelInterval(1); // Show every 2 labels
    graph.setFGLineThickness(4);
    graph.setXLabelText("X Axis Label");
    graph.setYLabelText("Y Axis Label");
    graph.setTitleLabel("Graph Title");

    // 4th and 1st set of Data
    graph.generateAggregateGraph(data2, sf::Color(160, 100, 32, 60), sf::Color(160, 100, 32), data, sf::Color(32, 64, 196, 60), sf::Color(32, 64, 196), 0);

    // 2nd Set of Data
    graph.setGraphLineColor(sf::Color(196, 64, 32));
    graph.setGraphColor(sf::Color(196, 64, 32, 60));
    graph.generateTrueColorGraph(data2, 0);

    // 3rd Set of Data
    graph.setGraphLineColor(sf::Color(64, 110, 32));
    graph.setGraphColor(sf::Color(64, 110, 32, 60));
    graph.generateGraph(data3, 5);
    
    bool screenshot = true;
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