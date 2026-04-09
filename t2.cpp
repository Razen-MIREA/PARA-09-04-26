#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>

void input(std::string& cmd) {
    std::cout << "Введите 'exit' или '(число) (число) (+-*/)': ";
    std::getline(std::cin, cmd);
}

int main() {
    std::cout << "Для выхода введите \'exit\'.\n";

    std::string cmd;
    input(cmd);
    while(cmd != "exit") {
        std::stringstream ss(cmd);

        double a,b; char op;
        ss >> a >> b >> op;
        
        try {
            switch(op) {
                case '+':
                    std::cout << a + b;
                    break;
                case '-':
                    std::cout << a - b;
                    break;
                case '*':
                    std::cout << a * b;
                    break;
                case '/':
                    if(b == 0) throw std::runtime_error("Деление на ноль");
                    std::cout << a / b;
                    break;
                default:
                    throw std::invalid_argument("Некорректная операция");
            }
            std::cout << std::endl;
        } catch(const std::runtime_error& e) {
            std::cout << "Ошибка: " << e.what() << std::endl;
        } catch(const std::invalid_argument& e) {
            std::cout << "Ошибка: " << e.what() << std::endl;
        } catch(...) {
            std::cout << "Неизвестная ошибка" << std::endl;
        }

        input(cmd);
    }

    std::cout <<"\nЗакрытие калькулятора...";
    return 0;
}
