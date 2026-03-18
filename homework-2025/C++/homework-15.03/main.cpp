#include "PhoneBook.h"
#include <iostream>

int main() {
    PhoneBook phoneBook;
    int choice;
    char filename[100];
    char searchName[200];
    
    do {
        std::cout << "\n========== ТЕЛЕФОННАЯ КНИГА ==========" << std::endl;
        std::cout << "1. Добавить абонента" << std::endl;
        std::cout << "2. Удалить абонента (по индексу)" << std::endl;
        std::cout << "3. Удалить абонента (по ФИО)" << std::endl;
        std::cout << "4. Найти абонента по ФИО" << std::endl;
        std::cout << "5. Показать всех абонентов" << std::endl;
        std::cout << "6. Сохранить в файл" << std::endl;
        std::cout << "7. Загрузить из файла" << std::endl;
        std::cout << "8. Редактировать абонента" << std::endl;
        std::cout << "0. Выход" << std::endl;
        std::cout << "Выберите действие: ";
        
        std::cin >> choice;
        
        switch(choice) {
            case 1:
                phoneBook.addAbonent();
                break;
                
            case 2: {
                if(phoneBook.getCount() == 0) {
                    std::cout << "Телефонная книга пуста!" << std::endl;
                    break;
                }
                phoneBook.displayAll();
                int index;
                std::cout << "Введите номер абонента для удаления: ";
                std::cin >> index;
                phoneBook.removeAbonent(index - 1);
                break;
            }
                
            case 3:
                if(phoneBook.getCount() == 0) {
                    std::cout << "Телефонная книга пуста!" << std::endl;
                    break;
                }
                std::cout << "Введите ФИО абонента для удаления: ";
                std::cin >> searchName;
                phoneBook.removeAbonent(searchName);
                break;
                
            case 4:
                if(phoneBook.getCount() == 0) {
                    std::cout << "Телефонная книга пуста!" << std::endl;
                    break;
                }
                std::cout << "Введите ФИО для поиска: ";
                std::cin >> searchName;
                phoneBook.searchByName(searchName);
                break;
                
            case 5:
                phoneBook.displayAll();
                break;
                
            case 6:
                std::cout << "Введите имя файла для сохранения: ";
                std::cin >> filename;
                phoneBook.saveToFile(filename);
                break;
                
            case 7:
                std::cout << "Введите имя файла для загрузки: ";
                std::cin >> filename;
                phoneBook.loadFromFile(filename);
                break;
                
            case 8: {
                if(phoneBook.getCount() == 0) {
                    std::cout << "Телефонная книга пуста!" << std::endl;
                    break;
                }
                phoneBook.displayAll();
                int index;
                std::cout << "Введите номер абонента для редактирования: ";
                std::cin >> index;
                Abonent* abonent = phoneBook.getAbonent(index - 1);
                if(abonent) {
                    abonent->edit();
                } else {
                    std::cout << "Неверный номер абонента!" << std::endl;
                }
                break;
            }
                
            case 0:
                std::cout << "Программа завершена. До свидания!" << std::endl;
                break;
                
            default:
                std::cout << "Неверный выбор. Пожалуйста, попробуйте снова." << std::endl;
        }
    } while(choice != 0);
    
    return 0;
}