// Задание 2: класс Person (имя, фамилия, отчество, возраст, пол; строки — динамические char*)
#include <cstring>
#include <iostream>

class Person {
private:
    char* firstName_;
    char* lastName_;
    char* patronymic_;
    int age_;
    char* gender_;

    static char* duplicateString(const char* src) {
        if (src == nullptr) {
            char* empty = new char[1];
            empty[0] = '\0';
            return empty;
        }
        const std::size_t len = std::strlen(src);
        char* dest = new char[len + 1];
        std::memcpy(dest, src, len + 1);
        return dest;
    }

    void release() {
        delete[] firstName_;
        delete[] lastName_;
        delete[] patronymic_;
        delete[] gender_;
        firstName_ = lastName_ = patronymic_ = gender_ = nullptr;
        age_ = 0;
    }

public:
    Person()
        : firstName_(duplicateString("")),
          lastName_(duplicateString("")),
          patronymic_(duplicateString("")),
          age_(0),
          gender_(duplicateString("")) {}

    Person(const char* firstName, const char* lastName, const char* patronymic, int age, const char* gender)
        : firstName_(duplicateString(firstName)),
          lastName_(duplicateString(lastName)),
          patronymic_(duplicateString(patronymic)),
          age_(age < 0 ? 0 : age),
          gender_(duplicateString(gender)) {}

    Person(const Person& other)
        : firstName_(duplicateString(other.firstName_)),
          lastName_(duplicateString(other.lastName_)),
          patronymic_(duplicateString(other.patronymic_)),
          age_(other.age_),
          gender_(duplicateString(other.gender_)) {}

    ~Person() { release(); }

    Person& operator=(const Person& other) {
        if (this == &other) {
            return *this;
        }
        release();
        firstName_ = duplicateString(other.firstName_);
        lastName_ = duplicateString(other.lastName_);
        patronymic_ = duplicateString(other.patronymic_);
        age_ = other.age_;
        gender_ = duplicateString(other.gender_);
        return *this;
    }

    void print() const {
        std::cout << "Фамилия: " << (lastName_ ? lastName_ : "") << '\n';
        std::cout << "Имя: " << (firstName_ ? firstName_ : "") << '\n';
        std::cout << "Отчество: " << (patronymic_ ? patronymic_ : "") << '\n';
        std::cout << "Возраст: " << age_ << '\n';
        std::cout << "Пол: " << (gender_ ? gender_ : "") << '\n';
    }
};

void demo_zadanie2_person() {
    std::cout << "Задание 2: Person\n\n";

    std::cout << "1) Пустой конструктор:\n";
    Person p0;
    p0.print();
    std::cout << '\n';

    std::cout << "2) Конструктор с параметрами:\n";
    Person p1("Артур", "Бронников", "Сергеевич", 18, "мужской");
    p1.print();
    std::cout << '\n';

    std::cout << "3) Конструктор копирования (копия p1):\n";
    Person p2(p1);
    p2.print();
    std::cout << '\n';

    std::cout << "4) Ещё один человек:\n";
    Person p3("Иван", "Коршунов", "Александрович", 24, "мужской");
    p3.print();
}
