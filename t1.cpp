#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>

double divide(int a, int b) {
    if(b == 0) throw std::invalid_argument("Деление на ноль");
    return (double)a/(double)b;
}

int main() {
    std::cout << "Для выхода введите \"/exit\"\n";

    std::stringstream ss;
    try {
        std::string word;
        while(word != "/exit") {
            std::cout << "Введите два числа (через пробел): ";
            std::cin >> word;
            ss << word;

            std::string sa,sb;
            ss >> sa >> sb;
            int a,b = stoi(sa), stoi(sb);
            std::cout << divide(a, b) << std::endl;
        }
    } catch(const std::invalid_argument& e) {
        std::cout << "Ошибка: " << e.what() << std::endl;
    } catch(...) {
        std::cout << "Неизвестная ошибка" << std::endl;
    }

    return 0;
}
