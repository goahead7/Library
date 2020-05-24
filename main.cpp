/*Библиотека
 * Информационные объекты: Библиотека, Библиотекарь, Книги, Авторы, Посетитель
 * У книги может быть только один автор.
 * Посетитель посещает библиотеку с целью найти книгу по имени автора И/ИЛИ по названию книги.
 * В библиотеке одному автору соотсветсвует одна книга.
 * Необходимо реализовать данный функционал, придерживаясь принципов DRY, KISS, YAGNI и Single Responsibility Principle
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Book {

    string title;
    string author;

public:
    Book(const string title, const string author) {
        this->title = title;
        this->author = author;
    }

    string getTitle() const {
        return title;
    }

    string getAuthor() const {
        return author;
    }
};

class Library {

    vector <Book> books;

public:

    Library(vector <Book> book) {
        books = book;
    }

    int search(string title, string author) {
        for (int i = 0; i < books.size(); i++) {
            if ((title == books[i].getTitle()) && (author == books[i].getAuthor())) {
                return i;
            }
        }
        return -1;
    }

    int searchTitle(string title) {
        for (int i = 0; i < books.size(); i++) {
            if (title == books[i].getTitle()) {
                return i;
            }
        }
        return -1;
    }

    int searchAuthor(string author) {
        for (int i = 0; i < books.size(); i++) {
            if (author == books[i].getAuthor()) {
                return i;
            }
        }
        return -1;
    }
};

class Librarian : public Library {

public:

    Librarian(vector<Book> books) : Library(books) {

    };

    void findBook(string title, string author) {

        if (search(title, author) != -1) {
            cout << "Пожалуйста, ваша книга : " <<" "<< title << " " << author << endl;
        } else {
            cout << "К сожалению, нужной книги не нашлось." << endl;
        }
    }

    void findTitle(string title) {

        if (searchTitle(title) != -1) {
            cout << "Пожалуйста, ваша книга : " << title << endl;
        } else {
            cout << "К сожалению, нужной книги не нашлось." << endl;
        }
    }

    void findAuthor(string author) {

        if (searchAuthor(author) != -1) {
            cout << "Пожалуйста, вот книга Автора :" << " " << author << endl;
        } else {
            cout << "К сожалению, нужной книги не нашлось." << endl;
        }
    }

};

int main() {
    unsigned int find;
    string nesseseryTitle;
    string nesseseryAuthor;

    Book b1{"1984", "Orwell"};
    Book b2{"Idiot", "Dostoevsky"};
    Book b3{"Martian", "Weir"};
    Book b4{"Helper", "Stockett"};
    Book b5{"Dreamer", "Smith"};

    vector<Book> books = {b1, b2, b3, b4, b5};

    Library Lib(books);

    Librarian So(books);

    cout << " Добро пожаловать! Выберите нужную операцию " << endl;
    cout << "1.Найти книгу по Названию и Автору" << endl
         << "2.Найти книгу по Названию" << endl
         << "3.Найти книгу по Автору" << endl
         << "4.Случайно зашли в библиотеку?!" << endl;
    cin >> find ;
    switch (find) {
        case 1:
            cout << "Введите Название и Автора нужной книги" << endl;
            cin >> nesseseryTitle>>nesseseryAuthor;
            So.findBook(nesseseryTitle, nesseseryAuthor);
            break;
        case 2:
            cout << "Введите Название нужной книги" << endl;
            cin >> nesseseryTitle;
            So.findTitle(nesseseryTitle);
            break;
        case 3:
            cout << "Введите Автора нужной книги " << endl;
            cin >> nesseseryAuthor;
            So.findAuthor(nesseseryAuthor);
            break;
        case 4:
            cout << "Ждем вас снова!" << endl;
            break;
        default:
            cout << "Всего доброго!" << endl;

    }

    return 0;
}

