#include <iostream>
#include <vector>
#include <stdexcept>

class LibraryException : public std::exception {
protected:
    int errorCode;
public:
    virtual std::string what() {
        return "Ошибка";
    }
};

class BookNotFoundException : public LibraryException {
private:
    std::string bookName;
public:
    BookNotFoundException(std::string a) : bookName(a) {}
    std::string what() override {
        return bookName+" - не найдена!";
    }
};

class BookAlreadyBorrowedException : public LibraryException {
private:
    std::string bookName;
};

class ReaderNotFoundException : public LibraryException {
private:
    std::string name;
public:
    ReaderNotFoundException(std::string a) : name(a) {}
    std::string what() override {
        return name+" - не найден!";
    }
};

class MaxBooksReachedException : public LibraryException {
private:
    int countLimit;
};

class InvalidReturnDateException : public LibraryException {
private:
    int day, month, year;
};


class Book {
public:
    std::string bookName;
};

class Person {
public:
    std::string name;
};

class Library {
public:
    std::vector<Person*> personList;
    std::vector<Book*> bookList;
    
    void giveBook(std::string pname, std::string bname) {
        for(auto& p : personList) {
            if(p->name == pname) {
               for(auto& b : bookList) {
                    if(b->bookName == bname) {
                        std::cout << pname << "у выдана книга(" << bname << ").\n";
                        return;
                    }
                }
                throw BookNotFoundException(bname);
            }
        }
        throw ReaderNotFoundException(pname);
    }
};

int main() {
    try {
        Library L;
        
        Book* b = new Book;
        b->bookName = "Война и мир";
        
        Person* p = new Person;
        p->name = "Иван";
        
        L.bookList.push_back(b);
        L.personList.push_back(p);
        
        L.giveBook("Иван", "Война и мир");
        //L.giveBook("Иван", "Преступление и наказание");
        L.giveBook("Вася", "Война и мир");
    } catch(BookNotFoundException e) {
        std::cout << e.what();
    } catch(ReaderNotFoundException e) {
        std::cout << e.what();
    } catch(...) {
        std::cout << "Неизвестная ошибка";
    }
}
