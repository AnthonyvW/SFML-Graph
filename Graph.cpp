#include "pch.h"
#include "Graph.h"

Graph::Graph() {
    // Graph Size and Position
    width = 800;
    height = 600;
    xOffset = 0;
    yOffset = 0;
    // Data
    dataFloor = 0;
    dataCeil = height;
    dataStart = 0;
    dataEnd = -1;
    dataInterval = 1;
    dataXPad = 0;
    min = -1;
    max = -1;
    // Graph
    graph.setPrimitiveType(sf::TriangleStrip);
    graphLines.setPrimitiveType(sf::Lines);
    graphFGLines.setPrimitiveType(sf::TriangleStrip);
    FGLineThickness = 1;
    // Graph Colors
    lineColor = sf::Color(128, 128, 128);
    graphColor = sf::Color(56, 128, 200, 128);
    graphLineColor = sf::Color(128, 128, 128);
    // Text
    // Text Font
    fontStyle = "arial.ttf";

    if (!font.loadFromFile(fontStyle)) {
        std::cout << "Failed To Load Font arial.ttf" << std::endl;
    }
    // Text Color
    labelColor = sf::Color(0, 0, 0);
    // Small Labels
    labels.setFont(font);
    labels.setFillColor(labelColor);
    labels.setCharacterSize(15);
    // X Axis Label
    xLabel.setFont(font);
    xLabel.setFillColor(labelColor);
    xLabel.setCharacterSize(20);
    xLabel.setString("");
    xLabelInterval = 1;
    // Y Axis Label
    yLabel.setFont(font);
    yLabel.setFillColor(labelColor);
    yLabel.setCharacterSize(20);
    yLabel.setString("");
    numYLabels = 5;
    // Title Label
    titleLabel.setFont(font);
    titleLabel.setFillColor(labelColor);
    titleLabel.setCharacterSize(25);
    titleLabel.setString("");
}
Graph::Graph(int setWidth, int setHeight) {
    width = setWidth;
    height = setHeight;
    xOffset = 0;
    yOffset = 0;
    // Data
    dataFloor = 0;
    dataCeil = height;
    dataStart = 0;
    dataEnd = -1;
    dataInterval = 1;
    dataXPad = 0;
    min = -1;
    max = -1;
    // Graph
    graph.setPrimitiveType(sf::TriangleStrip);
    graphLines.setPrimitiveType(sf::Lines);
    graphFGLines.setPrimitiveType(sf::TriangleStrip);
    FGLineThickness = 1;
    // Graph Colors
    lineColor = sf::Color(128, 128, 128);
    graphColor = sf::Color(56, 128, 200, 128);
    graphLineColor = sf::Color(128, 128, 128);
    // Text
    // Text Font
    fontStyle = "arial.ttf";

    if (!font.loadFromFile(fontStyle)) {
        std::cout << "Failed To Load Font arial.ttf" << std::endl;
    }
    // Text Color
    labelColor = sf::Color(0, 0, 0);
    // Small Labels
    labels.setFont(font);
    labels.setFillColor(labelColor);
    labels.setCharacterSize(15);
    // X Axis Label
    xLabel.setFont(font);
    xLabel.setFillColor(labelColor);
    xLabel.setCharacterSize(20);
    xLabel.setString("");
    xLabelInterval = 1;
    // Y Axis Label
    yLabel.setFont(font);
    yLabel.setFillColor(labelColor);
    yLabel.setCharacterSize(20);
    yLabel.setString("");
    numYLabels = 5;
    // Title Label
    titleLabel.setFont(font);
    titleLabel.setFillColor(labelColor);
    titleLabel.setCharacterSize(25);
    titleLabel.setString("");
}
Graph::Graph(int setWidth, int setHeight, int setXOffset, int setYOffset) {
    width = setWidth;
    height = setHeight;
    xOffset = setXOffset;
    yOffset = setYOffset;
    // Data
    dataFloor = 0;
    dataCeil = height;
    dataStart = 0;
    dataEnd = -1;
    dataInterval = 1;
    dataXPad = 0;
    min = -1;
    max = -1;
    // Graph
    graph.setPrimitiveType(sf::TriangleStrip);
    graphLines.setPrimitiveType(sf::Lines);
    graphFGLines.setPrimitiveType(sf::TriangleStrip);
    FGLineThickness = 1;
    // Graph Colors
    lineColor = sf::Color(128, 128, 128);
    graphColor = sf::Color(56, 128, 200, 128);
    graphLineColor = sf::Color(128, 128, 128);
    // Text
    // Text Font
    fontStyle = "arial.ttf";

    if (!font.loadFromFile(fontStyle)) {
        std::cout << "Failed To Load Font arial.ttf" << std::endl;
    }
    // Text Color
    labelColor = sf::Color(0, 0, 0);
    // Small Labels
    labels.setFont(font);
    labels.setFillColor(labelColor);
    labels.setCharacterSize(15);
    // X Axis Label
    xLabel.setFont(font);
    xLabel.setFillColor(labelColor);
    xLabel.setCharacterSize(20);
    xLabel.setString("");
    xLabelInterval = 1;
    // Y Axis Label
    yLabel.setFont(font);
    yLabel.setFillColor(labelColor);
    yLabel.setCharacterSize(20);
    yLabel.setString("");
    numYLabels = 5;
    // Title Label
    titleLabel.setFont(font);
    titleLabel.setFillColor(labelColor);
    titleLabel.setCharacterSize(25);
    titleLabel.setString("");
}

// Setters
/*
void Graph::setData(std::vector<float> dataToSet) {
    data = dataToSet;
    dataEnd = data.size();
    for (auto& element : data) {
        if (element > max) {
            max = element;
        } else if (element < min) {
            min = element;
        }
    }
}
*/
// Other Functions
float Graph::normalizeDataPoint(float lowerBound, float upperBound, float dataLowerBound, float dataUpperBound, float dataPoint) {
    return (upperBound - lowerBound) / (dataUpperBound - dataLowerBound) * (dataPoint - dataUpperBound) + upperBound;

}
void Graph::setDataMinMax(float dataMin, float dataMax) {
    min = dataMin;
    max = dataMax;
}
void Graph::findDataMinMax(std::vector<float> data) {
    for (auto& element : data) {
        if (element > max) {
            max = element;
        } else if (element < min) {
            min = element;
        }
    }
}
void Graph::generateGraph(std::vector<float> data) {
    if (dataEnd == -1) {
        dataEnd = data.size();
    }
    if (min == -1 && max == -1) {
        Graph::findDataMinMax(data);
    }
    // Set Padding for numbers and labels
    // Setting the padding on the Y Axis
    labels.setString(std::to_string(data.size() * dataInterval));
    if (titleLabel.getString() != "") {
        yOffset += titleLabel.getLocalBounds().height + 10;
    }
    if (xLabel.getString() == "") {
        yPad = labels.getLocalBounds().width + 10 + yOffset;
    } else {
        yPad = labels.getLocalBounds().width + 20 + yOffset + xLabel.getLocalBounds().height;
    }
    // Setting the padding on the x Axis
    labels.setString(std::to_string((int)(dataCeil)));
    if (yLabel.getString() == "") {
        xPad = labels.getLocalBounds().width + 10;
    } else {
        xPad = labels.getLocalBounds().width + 20 + yLabel.getLocalBounds().height;
    }
    rightXPad = labels.getLocalBounds().width / 2;

    // Adjust height to account for padding
    height -= yPad;

    // Normalize Data so it fits on the graph
    float normMax = normalizeDataPoint(0, height, dataFloor, dataCeil, max);

    // Add Edges to Graph. Left edge is covered by the loop.
    // Top Edge
    graphLines.append(sf::Vertex(sf::Vector2f(xOffset + xPad, yOffset), lineColor));
    graphLines.append(sf::Vertex(sf::Vector2f(width + xOffset - rightXPad, yOffset), lineColor));
    // Bottom Edge
    graphLines.append(sf::Vertex(sf::Vector2f(xOffset + xPad, height + yOffset), lineColor));
    graphLines.append(sf::Vertex(sf::Vector2f(width + xOffset - rightXPad, height + yOffset), lineColor));
    // Right Edge
    graphLines.append(sf::Vertex(sf::Vector2f(width + xOffset - rightXPad, yOffset), lineColor));
    graphLines.append(sf::Vertex(sf::Vector2f(width + xOffset - rightXPad, yOffset + height), lineColor));
    // Horizontal Lines
    for (int i = 1; height - ((float)(normMax) / (float)(numYLabels)) * i + yOffset >= yOffset; i++) {
        graphLines.append(sf::Vertex(sf::Vector2f(xOffset + xPad, height - ((float)(normMax) / (float)(numYLabels)) * i + yOffset), lineColor));
        graphLines.append(sf::Vertex(sf::Vector2f(width + xOffset - rightXPad, height - ((float)(normMax) / (float)(numYLabels)) * i + yOffset), lineColor));
    }
    // Invisible line at the beginning to allow for multiple lines to be drawn on the same chart.
    float dataPoint = normalizeDataPoint(0, height, dataFloor, dataCeil, data[0]);
    graphFGLines.append(sf::Vertex(sf::Vector2f(((float)(width - xPad - rightXPad) / (float)(dataEnd - 1 - dataStart)) * (0 - dataStart) + xOffset + xPad, height - dataPoint + FGLineThickness / 2 + yOffset), sf::Color(0,0,0,0)));
    graphFGLines.append(sf::Vertex(sf::Vector2f(((float)(width - xPad - rightXPad) / (float)(dataEnd - 1 - dataStart)) * (0 - dataStart) + xOffset + xPad, height - dataPoint + FGLineThickness / 2 + yOffset), sf::Color(0, 0, 0, 0)));

    graph.append(sf::Vertex(sf::Vector2f(((float)(width - xPad - rightXPad) / (float)(dataEnd - 1 - dataStart)) * (0 - dataStart) + xOffset + xPad, height - dataPoint + yOffset), sf::Color(0, 0, 0, 0)));
    graph.append(sf::Vertex(sf::Vector2f(((float)(width - xPad - rightXPad) / (float)(dataEnd - 1 - dataStart)) * (0 - dataStart) + xOffset + xPad, height + yOffset), sf::Color(0, 0, 0, 0)));

    for (int i = dataStart; i < dataEnd; i++) {
        float dataPoint = normalizeDataPoint(0, height, dataFloor, dataCeil, data[i]);
        // Draws the area under the line
        graph.append(sf::Vertex(sf::Vector2f(((float)(width - xPad - rightXPad) / (float)(dataEnd - 1 - dataStart)) * (i - dataStart) + xOffset + xPad, height - dataPoint + yOffset), graphColor));
        graph.append(sf::Vertex(sf::Vector2f(((float)(width - xPad - rightXPad) / (float)(dataEnd - 1 - dataStart)) * (i - dataStart) + xOffset + xPad, height + yOffset), graphColor));
        
        // Draws the line
        graphFGLines.append(sf::Vertex(sf::Vector2f(((float)(width - xPad - rightXPad) / (float)(dataEnd - 1 - dataStart)) * (i - dataStart) + xOffset + xPad, height - dataPoint + FGLineThickness / 2 + yOffset), graphLineColor));
        graphFGLines.append(sf::Vertex(sf::Vector2f(((float)(width - xPad - rightXPad) / (float)(dataEnd - 1 - dataStart)) * (i - dataStart) + xOffset + xPad, height - dataPoint - FGLineThickness / 2 + yOffset), graphLineColor));

        if (i % xLabelInterval == 0) {
            // Vertical Lines in the background
            graphLines.append(sf::Vertex(sf::Vector2f(((float)(width - xPad - rightXPad) / (float)(dataEnd - dataStart - 1)) * (i - dataStart) + xOffset + xPad, yOffset), lineColor));
            graphLines.append(sf::Vertex(sf::Vector2f(((float)(width - xPad - rightXPad) / (float)(dataEnd - dataStart - 1)) * (i - dataStart) + xOffset + xPad, height + yOffset), lineColor));
        }
    }
    // Invisible line at the end to allow for multiple lines to be drawn on the same chart.
    dataPoint = normalizeDataPoint(0, height, dataFloor, dataCeil, data[dataEnd - 1]);
    graphFGLines.append(sf::Vertex(sf::Vector2f(((float)(width - xPad - rightXPad) / (float)(dataEnd - 1 - dataStart)) * (dataEnd - 1 - dataStart) + xOffset + xPad, height - dataPoint - FGLineThickness / 2 + yOffset), sf::Color(0, 0, 0, 0)));
    graphFGLines.append(sf::Vertex(sf::Vector2f(((float)(width - xPad - rightXPad) / (float)(dataEnd - 1 - dataStart)) * (dataEnd - 1 - dataStart) + xOffset + xPad, height - dataPoint - FGLineThickness / 2 + yOffset), sf::Color(0, 0, 0, 0)));

    graph.append(sf::Vertex(sf::Vector2f(((float)(width - xPad - rightXPad) / (float)(dataEnd - 1 - dataStart)) * (dataEnd - 1 - dataStart) + xOffset + xPad, height - dataPoint + yOffset), sf::Color(0, 0, 0, 0)));
    graph.append(sf::Vertex(sf::Vector2f(((float)(width - xPad - rightXPad) / (float)(dataEnd - 1 - dataStart)) * (dataEnd - 1 - dataStart) + xOffset + xPad, height + yOffset), sf::Color(0, 0, 0, 0)));

    //Adjust height and yOffset back to original value
    height += yPad;
    if (titleLabel.getString() != "") {
        yOffset -= titleLabel.getLocalBounds().height + 10;
    }
}


void Graph::drawGraphLines(sf::RenderWindow* Window) {
    // Draw Background Lines on Plot
    Window->draw(graphLines);
}
void Graph::drawGraphLabels(sf::RenderWindow* Window) {
    // Adjust height and yOffset
    if (titleLabel.getString() != "") {
        yOffset += titleLabel.getLocalBounds().height + 10;
    }
    height -= yPad;
    // Generate Labels on Y Axis
    float normMax = normalizeDataPoint(0, height, dataFloor, dataCeil, max);
    for (int i = 0; height - ((float)(normMax) / (float)(numYLabels)) * i + yOffset > yOffset; i++) {
        labels.setString(std::to_string((int)((max - dataFloor) / numYLabels * i + dataFloor)));
        labels.setPosition(xOffset + xPad - labels.getLocalBounds().width - 5, height - ((float)(normMax) / (float)(numYLabels)) * i + yOffset - labels.getLocalBounds().height);
        Window->draw(labels);
    }
    // Generate Labels on X Axis
    for (int i = dataStart; i < dataEnd; i += xLabelInterval) {
        labels.setString(std::to_string((int)(i)*dataInterval + dataXPad));
        labels.setRotation(70);
        labels.setPosition(((float)(width - xPad - rightXPad) / (float)(dataEnd - dataStart - 1)) * (i - dataStart) + xOffset + xPad + (labels.getLocalBounds().width / (2)), yOffset + height);
        Window->draw(labels);
    }
    labels.setRotation(0);
    // Adjust height and yOffset back to original values
    height += yPad;
    if (titleLabel.getString() != "") {
        yOffset -= titleLabel.getLocalBounds().height + 10;
    }
    // Draw Title Label
    titleLabel.setPosition(sf::Vector2f(xOffset + (width + xPad - rightXPad) / 2 - titleLabel.getLocalBounds().width / 2, yOffset));
    Window->draw(titleLabel);
    // Draw X Axis Label
    xLabel.setPosition(sf::Vector2f(xOffset + (width + xPad - rightXPad) / 2 - xLabel.getLocalBounds().width / 2, height - xLabel.getLocalBounds().height - yOffset - 10));
    Window->draw(xLabel);
    // Draw Y Axis Label
    yLabel.setRotation(270);
    yLabel.setPosition(sf::Vector2f(xOffset, yOffset + (height - yPad) / 2 + yLabel.getLocalBounds().width / 2 + titleLabel.getLocalBounds().height));
    Window->draw(yLabel);
}
void Graph::drawGraphChart(sf::RenderWindow* Window) {
    // Draw Graph Plot
    Window->draw(graph);
    // Draw Foreground Lines on Plot
    Window->draw(graphFGLines);
}

void Graph::drawGraph(sf::RenderWindow* Window) {
    Graph::drawGraphLines(Window);
    Graph::drawGraphChart(Window);
    Graph::drawGraphLabels(Window);
}