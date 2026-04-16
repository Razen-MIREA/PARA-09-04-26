#include <iostream>
#include <fstream>
#include <stdexcept>

class FileWrapper {
private:
    std::ofstream out;
public:
    FileWrapper() {
        out.open("output.txt");
    }
    ~FileWrapper() {
        out.close();
    }
    void write(const std::string& data) {
        out << data;
        std::cout << "Сообщение записано!\n";
    }
};

class DatabaseConnection {
public:
    DatabaseConnection() {
        std::cout << "Подключение к базе данных\n";
    }
    ~DatabaseConnection() {
        std::cout << "Отключение от базы данных\n";
    }
    void query(const std::string& sql) {
        throw std::runtime_error("Ошибка при передаче запроса!");
    }
};

int main() {
    try {
        FileWrapper fw;
        DatabaseConnection dc;
        fw.write("Сообщение 1\n");
        dc.query("Тест сигнала 1");
        fw.write("Сообщение 2\n");
        dc.query("Тест сигнала 2");
    } catch(std::runtime_error e) {
        std::cout << e.what() << '\n';
    } catch(...) {
        std::cout << "Неизвестная ошибка\n";
    }
}
