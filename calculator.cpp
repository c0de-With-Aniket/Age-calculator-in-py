#include <iostream>
#include <cmath>
#include <stdexcept>
#include <limits>

class Calculator {
public:
    void run() {
        char operation;
        double num1, num2;
        bool running = true;

        while (running) {
            printMenu();
            std::cout << "Enter an operation (+, -, *, /, ^, %, r for root, q to quit): ";
            std::cin >> operation;

            if (operation == 'q') {
                running = false;
                break;
            }

            if (operation != 'r') {
                std::cout << "Enter first number: ";
                num1 = getNumber();
                std::cout << "Enter second number: ";
                num2 = getNumber();
            } else {
                std::cout << "Enter the number: ";
                num1 = getNumber();
            }

            try {
                switch (operation) {
                    case '+':
                        std::cout << "Result: " << add(num1, num2) << std::endl;
                        break;
                    case '-':
                        std::cout << "Result: " << subtract(num1, num2) << std::endl;
                        break;
                    case '*':
                        std::cout << "Result: " << multiply(num1, num2) << std::endl;
                        break;
                    case '/':
                        std::cout << "Result: " << divide(num1, num2) << std::endl;
                        break;
                    case '^':
                        std::cout << "Result: " << power(num1, num2) << std::endl;
                        break;
                    case '%':
                        std::cout << "Result: " << fmod(num1, num2) << std::endl;
                        break;
                    case 'r':
                        std::cout << "Result: " << sqrt(num1) << std::endl;
                        break;
                    default:
                        std::cerr << "Unknown operation!" << std::endl;
                }
            } catch (const std::exception& e) {
                std::cerr << e.what() << std::endl;
            }

            std::cout << std::endl;
        }
    }

private:
    void printMenu() {
        std::cout << "Superb Calculator" << std::endl;
        std::cout << "=================" << std::endl;
        std::cout << "Available operations:" << std::endl;
        std::cout << "Addition: +" << std::endl;
        std::cout << "Subtraction: -" << std::endl;
        std::cout << "Multiplication: *" << std::endl;
        std::cout << "Division: /" << std::endl;
        std::cout << "Power: ^" << std::endl;
        std::cout << "Modulo: %" << std::endl;
        std::cout << "Square Root: r" << std::endl;
        std::cout << "Quit: q" << std::endl;
    }

    double getNumber() {
        double number;
        while (!(std::cin >> number)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cerr << "Invalid input. Please enter a number: ";
        }
        return number;
    }

    double add(double a, double b) {
        return a + b;
    }

    double subtract(double a, double b) {
        return a - b;
    }

    double multiply(double a, double b) {
        return a * b;
    }

    double divide(double a, double b) {
        if (b == 0) {
            throw std::invalid_argument("Error: Division by zero!");
        }
        return a / b;
    }

    double power(double a, double b) {
        return pow(a, b);
    }
};

int main() {
    Calculator calc;
    calc.run();
    return 0;
}
