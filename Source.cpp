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
        data.push_back((std::cos((3.1415f / 25.f) * i) + 1)*50 + 80);
    }
    std::vector<float> data2;
    for (int i = 0; i < 25; i++) {
        data2.push_back((std::sin(3.1415f / 25.f * i + 3.1415f * 1.5f) + 1) * 50 + 80);
    }
    // Create graph
    Graph graph = Graph(width, height);
    graph.setDataCeil(200);
    graph.setDataFloor(50);
    graph.setNumYLabels(20); // 10 labels between beginning and top of maximum data
    graph.setXLabelInterval(2); // Show every 2 labels
    graph.setFGLineThickness(4);
    graph.setXLabelText("X Axis Label");
    graph.setYLabelText("Y Axis Label");
    graph.setTitleLabel("Graph Title");
    // 1st Set of Data
    graph.setGraphLineColor(sf::Color(32, 64, 196));
    graph.setGraphColor(sf::Color(32, 64, 196, 60));
    graph.generateGraph(data2);
    // 2nd Set of Data
    graph.setGraphLineColor(sf::Color(196, 64, 32));
    graph.setGraphColor(sf::Color(196, 64, 32, 60));
    graph.generateGraph(data);
    
    
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