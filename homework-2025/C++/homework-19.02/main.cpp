#include <iostream>
#include "book.h"
#include "function_book.h"

int main() {
    Book library[10] = {
        {"Война и мир", "Толстой Л.Н.", "Азбука", "Роман"},
        {"Преступление и наказание", "Достоевский Ф.М.", "Эксмо", "Роман"},
        {"Мастер и Маргарита", "Булгаков М.А.", "АСТ", "Роман"},
        {"Евгений Онегин", "Пушкин А.С.", "Наука", "Поэма"},
        {"Мертвые души", "Гоголь Н.В.", "Азбука", "Поэма"},
        {"Герой нашего времени", "Лермонтов М.Ю.", "Эксмо", "Роман"},
        {"Отцы и дети", "Тургенев И.С.", "АСТ", "Роман"},
        {"Обломов", "Гончаров И.А.", "Азбука", "Роман"},
        {"Тихий Дон", "Шолохов М.А.", "АСТ", "Роман"},
        {"Анна Каренина", "Толстой Л.Н.", "Эксмо", "Роман"}
    };
    
    int choice;
    char searchStr[100];
    int bookIndex;
    
    do {
        std::cout << "\n=== БИБЛИОТЕКА ===" << std::endl;
        std::cout << "1. Редактировать книгу" << std::endl;
        std::cout << "2. Печать всех книг" << std::endl;
        std::cout << "3. Поиск книг по автору" << std::endl;
        std::cout << "4. Поиск книги по названию" << std::endl;
        std::cout << "5. Сортировка по названию" << std::endl;
        std::cout << "6. Сортировка по автору" << std::endl;
        std::cout << "7. Сортировка по издательству" << std::endl;
        std::cout << "0. Выход" << std::endl;
        std::cout << "Выберите действие: ";
        std::cin >> choice;
        
        switch(choice) {
            case 1:
                std::cout << "Введите номер книги (1-10): ";
                std::cin >> bookIndex;
                if(bookIndex >= 1 && bookIndex <= 10) {
                    editBook(&library[bookIndex-1]);
                } else {
                    std::cout << "Неверный номер книги" << std::endl;
                }
                break;
                
            case 2:
                printAllBooks(library, 10);
                break;
                
            case 3:
                std::cout << "Введите автора: ";
                std::cin.ignore();
                std::cin.getline(searchStr, 100);
                searchByAuthor(library, 10, searchStr);
                break;
                
            case 4:
                std::cout << "Введите название: ";
                std::cin.ignore();
                std::cin.getline(searchStr, 100);
                searchByTitle(library, 10, searchStr);
                break;
                
            case 5:
                sortByTitle(library, 10);
                std::cout << "Массив отсортирован по названию" << std::endl;
                break;
                
            case 6:
                sortByAuthor(library, 10);
                std::cout << "Массив отсортирован по автору" << std::endl;
                break;
                
            case 7:
                sortByPublisher(library, 10);
                std::cout << "Массив отсортирован по издательству" << std::endl;
                break;
                
            case 0:
                std::cout << "Программа завершена" << std::endl;
                break;
                
            default:
                std::cout << "Неверный выбор" << std::endl;
        }
    } while(choice != 0);
    
    return 0;
}