// Задание 1: класс «Прямоугольник»
#include <iostream>

class Rectangle {
private:
    double width_;
    double height_;

public:
    Rectangle() : width_(1.0), height_(1.0) {}

    Rectangle(double width, double height) : width_(1.0), height_(1.0) {
        if (width >= 0.0 && height >= 0.0) {
            width_ = width;
            height_ = height;
        }
    }

    bool setWidth(double w) {
        if (w < 0.0) {
            return false;
        }
        width_ = w;
        return true;
    }

    bool setHeight(double h) {
        if (h < 0.0) {
            return false;
        }
        height_ = h;
        return true;
    }

    double getWidth() const { return width_; }
    double getHeight() const { return height_; }

    double area() const { return width_ * height_; }
    double perimeter() const { return 2.0 * (width_ + height_); }
};

void demo_zadanie1_rectangle() {
    std::cout << "Задание 1: Прямоугольник\n";

    Rectangle r1;
    std::cout << "По умолчанию: ширина = " << r1.getWidth() << ", высота = " << r1.getHeight() << '\n';
    std::cout << "Площадь: " << r1.area() << ", периметр: " << r1.perimeter() << "\n\n";

    Rectangle r2(5.0, 3.0);
    std::cout << "Параметры (5, 3): ширина = " << r2.getWidth() << ", высота = " << r2.getHeight() << '\n';
    std::cout << "Площадь: " << r2.area() << ", периметр: " << r2.perimeter() << "\n\n";

    std::cout << "Попытка установить отрицательную ширину -2:\n";
    double oldW = r2.getWidth();
    if (!r2.setWidth(-2.0)) {
        std::cout << "  Отказ: ширина не изменена, по-прежнему = " << r2.getWidth() << '\n';
    }
    if (r2.getWidth() != oldW) {
        std::cout << "  Ошибка: значение изменилось.\n";
    }

    std::cout << "Попытка установить корректную ширину 10:\n";
    if (r2.setWidth(10.0)) {
        std::cout << "  Успех: ширина = " << r2.getWidth() << ", площадь = " << r2.area() << '\n';
    }
}
