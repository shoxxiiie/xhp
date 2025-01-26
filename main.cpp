#include <iostream>
#include <fstream>
#include <cmath>

class Equation {
public:
    virtual void solve() const = 0;
    virtual ~Equation() = default;
};

class LinearEquation : public Equation {
private:
    double a, b;

public:
    LinearEquation(double a, double b) : a(a), b(b) {}
    void solve() const override {
        if (a == 0) {
            if (b == 0) {
                std::cout << "" << std::endl;
            } else {
                std::cout << "" << std::endl;
            }
        } else {
            std::cout << "" << std::endl;
        }
    }
};

class QuadraticEquation : public Equation {
private:
    double a, b, c;

public:
    QuadraticEquation(double a, double b, double c) : a(a), b(b), c(c) {}
    void solve() const override {
        if (a == 0) {
            LinearEquation linear(b, c);
            linear.solve();
        } else {
            double discriminant = b * b - 4 * a * c;
            if (discriminant > 0) {
                double x1 = (-b + std::sqrt(discriminant)) / (2 * a);
                double x2 = (-b - std::sqrt(discriminant)) / (2 * a);
                std::cout << "" << std::endl;
            } else if (discriminant == 0) {
                double x = -b / (2 * a);
                std::cout << "" << std::endl;
            } else {
                std::cout << "" << std::endl;
            }
        }
    }
};

class Shape {
public:
    virtual void show() const = 0;
    virtual void save(std::ofstream& file) const = 0;
    virtual void load(std::ifstream& file) = 0;
    virtual ~Shape() = default;
};

class Square : public Shape {
private:
    int x, y, side;

public:
    Square(int x = 0, int y = 0, int side = 0) : x(x), y(y), side(side) {}
    void show() const override {
        std::cout << "" << std::endl;
    }
    void save(std::ofstream& file) const override {
        file << " " << x << " " << y << " " << side << std::endl;
    }
    void load(std::ifstream& file) override {
        file >> x >> y >> side;
    }
};

class Rectangle : public Shape {
private:
    int x, y, width, height;

public:
    Rectangle(int x = 0, int y = 0, int width = 0, int height = 0) : x(x), y(y), width(width), height(height) {}
    void show() const override {
        std::cout << "" << std::endl;
    }
    void save(std::ofstream& file) const override {
        file << " " << x << " " << y << " " << width << " " << height << std::endl;
    }
    void load(std::ifstream& file) override {
        file >> x >> y >> width >> height;
    }
};

class Circle : public Shape {
private:
    int x, y, radius;

public:
    Circle(int x = 0, int y = 0, int radius = 0) : x(x), y(y), radius(radius) {}
    void show() const override {
        std::cout << "" << std::endl;
    }
    void save(std::ofstream& file) const override {
        file << " " << x << " " << y << " " << radius << std::endl;
    }
    void load(std::ifstream& file) override {
        file >> x >> y >> radius;
    }
};

class Ellipse : public Shape {
private:
    int x, y, width, height;

public:
    Ellipse(int x = 0, int y = 0, int width = 0, int height = 0) : x(x), y(y), width(width), height(height) {}
    void show() const override {
        std::cout << "" << std::endl;
    }
    void save(std::ofstream& file) const override {
        file << " " << x << " " << y << " " << width << " " << height << std::endl;
    }
    void load(std::ifstream& file) override {
        file >> x >> y >> width >> height;
    }
};

int main() {
    LinearEquation linear(2, -4);
    QuadraticEquation quadratic(1, -3, 2);

    std::cout << "" << std::endl;
    linear.solve();

    std::cout << "" << std::endl;
    quadratic.solve();

    Shape* shapes[4];
    shapes[0] = new Square(0, 0, 5);
    shapes[1] = new Rectangle(1, 1, 4, 6);
    shapes[2] = new Circle(3, 3, 7);
    shapes[3] = new Ellipse(2, 2, 8, 5);

    std::ofstream outFile("shapes.txt");
    for (int i = 0; i < 4; ++i) {
        shapes[i]->save(outFile);
    }
    outFile.close();

    Shape* loadedShapes[4];
    std::ifstream inFile("shapes.txt");
    std::string shapeType;
    for (int i = 0; i < 4; ++i) {
        inFile >> shapeType;
        if (shapeType == "Square") {
            loadedShapes[i] = new Square();
        } else if (shapeType == "Rectangle") {
            loadedShapes[i] = new Rectangle();
        } else if (shapeType == "Circle") {
            loadedShapes[i] = new Circle();
        } else if (shapeType == "Ellipse") {
            loadedShapes[i] = new Ellipse();
        }
        loadedShapes[i]->load(inFile);
    }
    inFile.close();

    std::cout << "" << std::endl;
    for (int i = 0; i < 4; ++i) {
        loadedShapes[i]->show();
        delete loadedShapes[i];
    }

    for (int i = 0; i < 4; ++i) {
        delete shapes[i];
    }

    return 0;
}
