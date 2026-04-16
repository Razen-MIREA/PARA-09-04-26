#include <iostream>
#include <algorithm>
#include <stdexcept>

class DynamicArray {
private:
    int* data;
    int size;
public:
    DynamicArray(int _size) {
        if(_size <= 0) throw std::invalid_argument("Неверный размер массива!");
        data = new int[_size]();
        size = _size;
    }
    ~DynamicArray() {
        delete[] data;
    }
    
    int get(int index) {
        if(index < 0 || index > size-1) throw std::out_of_range("Доступ вне диапазона массива");
        return data[index];
    }
    void set(int index, int value) {
        if(index < 0 || index > size-1) throw std::out_of_range("Доступ вне диапазона массива");
        data[index] = value;
    }
    void resize(int newSize) {
        if(newSize == size || newSize < 0) return;
        
        int* newData = new int[newSize]();
        if(newSize != 0) {
            int copySize = std::min(size, newSize);
            std::copy(data, data + copySize, newData);
        }
        
        delete[] data;
        data = newData;
        size = newSize;
    }
};

int main() {
    try {
        DynamicArray arr(5);
        arr.set(0, 123);
        std::cout << arr.get(0);
    } catch(std::invalid_argument e) {
        std::cout << e.what();
    } catch(std::out_of_range e) {
        std::cout << e.what();
    } catch(std::bad_alloc e) {
        std::cout << e.what();
    } catch(...) {
        std::cout << "Неизвестная ошибка";
    }
}
