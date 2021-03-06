#pragma once

#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<cmath>
#include<algorithm>
#include<GL/glut.h>

using std::cin;
using std::cout;
using std::getline;
using std::endl;
using std::swap;
using std::vector;
using std::string;
using std::ifstream;

class Color {
	float red, green, blue;

public:
	Color();
	Color(float r, float g, float b);
	void setRed(const float r) { red = r; }
	void setGreen(const float g) { green = g; }
	void setBlue(const float b) { blue = b; }

	float getRed() { return red; }
	float getGreen() { return green; }
	float getBlue() { return blue; }
};

class Light {
	float xVal, yVal, zVal;
	Color color;

public:
	Light(const float r, const float g, const float b, const float x, const float y, const float z);
	void setXVal(const float x) { xVal = x; }
	void setYVal(const float y) { yVal = y; }
	void setZVal(const float z) { zVal = z; }
	void setColor(const Color& c) { color = c; }

	float getXVal() { return xVal; }
	float getYVal() { return yVal; }
	float getZVal() { return zVal; }
	Color getColor() { return color; }
};

class Point {
private:
	float xVal, yVal, zVal;
	Color color;

public:
	Point(const float x, const float y, const float z);
	Point(const float r, const float g, const float b, const float x, const float y, const float z);
	void setXVal(const float x) { xVal = x; }
	void setYVal(const float y) { yVal = y; }
	void setZVal(const float z) { zVal = z; }
	void setColor(const Color& c) { color = c; }

	float getXVal() { return xVal; }
	float getYVal() { return yVal; }
	float getZVal() { return zVal; }
	Color getColor() { return color; }
};

class Point2D {
private:
	int xVal, yVal;
	double depth;
	Color color;

public:
	Point2D(const int x, const int y, const double d);
	void setXVal(const int x) { xVal = x; }
	void setYVal(const int y) { yVal = y; }
	void setDepth(const double d) { depth = d; }
	void setColor(const Color& c) { color = c; }

	int getXVal() { return xVal; }
	int getYVal() { return yVal; }
	double getDepth() { return depth; }
	Color getColor() { return color; }

	void colorThreshold();
};

class SpaceVector {
private:
	float xVal, yVal, zVal;

public:
	SpaceVector(const float x, const float y, const float z);
	void setXVal(const float x) { xVal = x; }
	void setYVal(const float y) { yVal = y; }
	void setZVal(const float z) { zVal = z; }

	float getXVal() { return xVal; }
	float getYVal() { return yVal; }
	float getZVal() { return zVal; }

	void normalization();
};

class Line {
private:
	float xStart, yStart, xEnd, yEnd, slope;
	double depthStart, depthEnd;
	bool vertical;

	void setSlope();
public:
	Line(const float x1, const float y1, const double d1, const float x2, const float y2, const double d2);
	void setXStart(const float x1) { xStart = x1, setSlope(); }
	void setYStart(const float y1) { yStart = y1, setSlope(); }
	void setDepthStart(const double d1) { depthStart = d1; }
	void setXEnd(const float x2) { xEnd = x2, setSlope(); }
	void setYEnd(const float y2) { yEnd = y2, setSlope(); }
	void setDepthEnd(const double d2) { yStart = d2; }

	float getXStart() { return xStart; }
	float getYStart() { return yStart; }
	double getDepthStart() { return depthStart; }
	float getXEnd() { return xEnd; }
	float getYEnd() { return yEnd; }
	double getDepthEnd() { return depthEnd; }
	float getSlope() { return slope; }
	bool isVertical() { return vertical; }

	void swapPoints();
	void drawLine(vector<Point2D>& drawList);
};

class ASC {
private:
	float ksVal, kdVal, nVal;
	Color color;
	vector<vector<float>> ascMatrix;
	vector<vector<float>> worldMatrix;
	vector<Point> ascVertices;
	vector<vector<int>> ascSurfaces;

	void addMatrix();
public:
	ASC(const float r, const float g, const float b, const float kd, const float ks, const float n);
	void setKdVal(const float kd) { kdVal = kd; }
	void setKsVal(const float ks) { ksVal = ks; }
	void setNVal(const float n) { nVal = n; }
	void setColor(const Color& c) { color = c; }
	void setMatrix(const vector<vector<float>>& matrix) { ascMatrix = matrix; }
	void setWorldMatrix() { worldMatrix = ascMatrix; }
	
	float getKdVal() { return kdVal; }
	float getKsVal() { return ksVal; }
	float getNVal() { return nVal; }
	Color getColor() { return color; }
	const vector<vector<float>>& getMatrix() { return ascMatrix; }
	const vector<Point>& getVertices() { return ascVertices; }
	const vector<vector<int>>& getSurfaces() { return ascSurfaces; }
	const vector<vector<float>>& getWorldMatrix() { return worldMatrix; }

	void addVertices(const Point& p);
	void addSurface(const vector<int>& vertices);
	void reserveVector(const int vertexAmount, const int surfaceAmount);
	void resetMatrix() { ascMatrix = worldMatrix; }
};
