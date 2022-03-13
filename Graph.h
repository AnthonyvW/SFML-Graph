#pragma once
#include "pch.h"

class Graph {
private:
    int width;
    int height;
    int xOffset;
    int yOffset;
    sf::VertexArray graph;
    sf::VertexArray graphLines;
    sf::VertexArray graphFGLines;
    float FGLineThickness;

    // Data Properties
    //std::vector<float> data;
    float dataCeil;
    float dataFloor;
    float max;
    float min;
    // Section of Data to View
    int dataStart;
    int dataEnd;
    int dataXPad;
    // Multiplies the X axis labels by this
    int dataInterval;

    // Colors
    sf::Color lineColor;
    sf::Color graphColor;
    sf::Color graphLineColor;
    sf::Color labelColor;

    // Text
    sf::Font font;
    std::string fontStyle;
    sf::Text labels;
    sf::Text xLabel;
    sf::Text yLabel;
    sf::Text titleLabel;

    int numYLabels;
    int xLabelInterval;
    int xPad;
    int rightXPad;
    int yPad;

public:
    // Constructors
    Graph();
    Graph(int setWidth, int setHeight);
    Graph(int setWidth, int setHeight, int setXOffset, int setYOffset);

    // Getters
    sf::VertexArray getGraphLines() { return graphLines; };
    sf::VertexArray getGraph() { return graph; };
    //std::vector<float> getData() { return data; };
    sf::Color getLineColor() { return lineColor; };
    sf::Color getGraphColor() { return graphColor; };
    sf::Color getGraphLineColor() { return graphLineColor; };
    sf::Text getLabels() { return labels; };
    sf::Text getXLabel() { return xLabel; };
    sf::Text getYLabel() { return yLabel; };
    sf::Text getTitleLabel() { return titleLabel; };
    float getDataCeil() { return dataCeil; };
    float getDataFloor() { return dataFloor; };
    float getLineThickness() { return FGLineThickness; };
    int getNumYLabels() { return numYLabels; };
    int getDataStart() { return dataStart; };
    int getDataEnd() { return dataEnd; };
    int getDataInteval() { return dataInterval; };
    int getXLabelInterval() { return xLabelInterval; };
    int getDataXPad() { return dataXPad; };

    // Setters
    //void setData(std::vector<float> dataToSet);

    void setLineColor(sf::Color color) { lineColor = color; };
    void setGraphColor(sf::Color color) { graphColor = color; };
    void setGraphLineColor(sf::Color color) { graphLineColor = color; };
    void setWidth(int x) { width = x; };
    void setHeight(int y) { height = y; };
    void setXOffset(int x) { xOffset = x; };
    void setYOffset(int y) { yOffset = y; };
    void setLabels(sf::Text labelToSet) { labels = labelToSet; };
    void setXLabel(sf::Text labelToSet) { xLabel = labelToSet; };
    void setYLabel(sf::Text labelToSet) { yLabel = labelToSet; };
    void setTitleLabel(sf::Text labelToSet) { titleLabel = labelToSet; };
    void setXLabelText(std::string text) { xLabel.setString(text); };
    void setYLabelText(std::string text) { yLabel.setString(text); };
    void setTitleLabel(std::string text) { titleLabel.setString(text); };
    void setDataCeil(float dataRoof) { dataCeil = dataRoof; };
    void setDataFloor(float dataGround) { dataFloor = dataGround; };
    void setNumYLabels(int numLabels) { numYLabels = numLabels; };
    void setDataStart(int start) { dataStart = start; };
    void setDataEnd(int end) { dataEnd = end; };
    void setXLabelInterval(int interval) { xLabelInterval = interval; };
    void setDataInterval(int interval) { dataInterval = interval; };
    void setFGLineThickness(float thickness) { FGLineThickness = thickness; };
    void setDataXPad(int xPad) { dataXPad = xPad; };

    // Generates Graph
    float normalizeDataPoint(float lowerBound, float upperBound, float dataLowerBound, float dataUpperBound, float dataPoint);
    void setDataMinMax(float dataMin, float dataMax);
    void findDataMinMax(std::vector<float> data);
    void generateGraph(std::vector<float> data);

    // Draw Graph
    void drawGraphLines(sf::RenderWindow* Window);
    void drawGraphLabels(sf::RenderWindow* Window);
    void drawGraphChart(sf::RenderWindow* Window);
    void drawGraph(sf::RenderWindow* Window);

};





