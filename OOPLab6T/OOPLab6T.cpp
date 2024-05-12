#include <iostream>

// Абстрактний базовий клас Figure
class Figure {
public:
    virtual float area() const = 0; // Віртуальна функція для обчислення площі
};

// Похідний клас Rectangle (прямокутник) від Figure
class Rectangle : public Figure {
private:
    float length; // Довжина
    float width;  // Ширина
public:
    Rectangle(float l, float w) : length(l), width(w) {} // Конструктор

    // Реалізація віртуальної функції для обчислення площі прямокутника
    float area() const override {
        return length * width; // Площа = довжина * ширина
    }
};

// Похідний клас Circle (коло) від Figure
class Circle : public Figure {
private:
    float radius;      // Радіус
    const float pi = 3.14159; // Приблизне значення числа Пі
public:
    Circle(float r) : radius(r) {} // Конструктор

    // Реалізація віртуальної функції для обчислення площі кола
    float area() const override {
        return pi * radius * radius; // Площа = Пі * радіус^2
    }
};

// Похідний клас RightTriangle (прямокутний трикутник) від Figure
class RightTriangle : public Figure {
private:
    float base;   // Основа
    float height; // Висота
public:
    RightTriangle(float b, float h) : base(b), height(h) {} // Конструктор

    // Реалізація віртуальної функції для обчислення площі прямокутного трикутника
    float area() const override {
        return 0.5 * base * height; // Площа = 0.5 * основа * висота
    }
};

// Похідний клас Trapezoid (трапеція) від Figure
class Trapezoid : public Figure {
private:
    float base1;  // Перша основа
    float base2;  // Друга основа
    float height; // Висота
public:
    Trapezoid(float b1, float b2, float h) : base1(b1), base2(b2), height(h) {} // Конструктор

    // Реалізація віртуальної функції для обчислення площі трапеції
    float area() const override {
        return 0.5 * (base1 + base2) * height; // Площа = 0.5 * (перша основа + друга основа) * висота
    }
};

// Основна функція
int main() {
    // Створення об'єктів кожного класу та обчислення їх площі
    Rectangle rectangle(5, 4);
    Circle circle(3);
    RightTriangle triangle(4, 5);
    Trapezoid trapezoid(3, 7, 4);

    // Виведення результатів
    std::cout << "Area of Rectangle: " << rectangle.area() << std::endl;
    std::cout << "Area of Circle: " << circle.area() << std::endl;
    std::cout << "Area of Right Triangle: " << triangle.area() << std::endl;
    std::cout << "Area of Trapezoid: " << trapezoid.area() << std::endl;

    return 0;
}

/*#include <iostream>
#include <string>

// Батьківський клас Entity (сутність)
class Entity {
protected:
    std::string name;
public:
    Entity(const std::string& n) : name(n) {} // Конструктор

    virtual ~Entity() {} // Віртуальний деструктор

    virtual void printInfo() const = 0; // Віртуальна функція для виведення інформації
};

// Клас Student (студент), успадковується від Entity
class Student : public Entity {
private:
    int studentID;
public:
    Student(const std::string& n, int id) : Entity(n), studentID(id) {} // Конструктор

    // Перевантаження віртуальної функції для виведення інформації про студента
    void printInfo() const override {
        std::cout << "Student Name: " << name << ", Student ID: " << studentID << std::endl;
    }
};

// Клас FamilyHead (батько сімейства), успадковується від Entity
class FamilyHead : public Entity {
private:
    int familyID;
public:
    FamilyHead(const std::string& n, int id) : Entity(n), familyID(id) {} // Конструктор

    // Перевантаження віртуальної функції для виведення інформації про батька сімейства
    void printInfo() const override {
        std::cout << "Family Head Name: " << name << ", Family ID: " << familyID << std::endl;
    }
};

// Клас StudentFamilyHead (студент-батько сімейства), успадковується від Student і FamilyHead
class StudentFamilyHead : public Student, public FamilyHead {
public:
    StudentFamilyHead(const std::string& n, int studentID, int familyID)
        : Student(n, studentID), FamilyHead(n, familyID), Entity(n) {} // Конструктор

    // Перевизначення віртуальної функції для виведення інформації про студента-батька сімейства
    void printInfo() const override {
        std::cout << "Student-Family Head Name: " << name << ", Student ID: " << Student::studentID
                  << ", Family ID: " << FamilyHead::familyID << std::endl;
    }
};

int main() {
    // Створення об'єктів кожного класу і виклик функції виведення інформації
    Student student("John", 123);
    FamilyHead father("Smith", 456);
    StudentFamilyHead studentFather("David", 789, 456);

    student.printInfo();
    father.printInfo();
    studentFather.printInfo();

    return 0;
}
*/