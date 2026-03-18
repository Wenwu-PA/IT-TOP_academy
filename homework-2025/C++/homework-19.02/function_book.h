#ifndef FUNCTION_BOOK_H
#define FUNCTION_BOOK_H

#include <iostream>
#include <cstring>
#include "book.h"

void printBook(const Book& book) {
    std::cout << "Название: " << book.title << std::endl;
    std::cout << "Автор: " << book.author << std::endl;
    std::cout << "Издательство: " << book.publisher << std::endl;
    std::cout << "Жанр: " << book.genre << std::endl;
    std::cout << "------------------------" << std::endl;
}

void printAllBooks(Book books[], int size) {
    for(int i = 0; i < size; i++) {
        std::cout << "Книга " << i+1 << ":" << std::endl;
        printBook(books[i]);
    }
}

void editBook(Book* book) {
    std::cout << "Введите новое название: ";
    std::cin.ignore();
    std::cin.getline(book->title, 100);
    
    std::cout << "Введите нового автора: ";
    std::cin.getline(book->author, 100);
    
    std::cout << "Введите новое издательство: ";
    std::cin.getline(book->publisher, 100);
    
    std::cout << "Введите новый жанр: ";
    std::cin.getline(book->genre, 50);
}

void searchByAuthor(Book books[], int size, const char author[]) {
    bool found = false;
    for(int i = 0; i < size; i++) {
        if(strcmp(books[i].author, author) == 0) {
            std::cout << "Найдена книга:" << std::endl;
            printBook(books[i]);
            found = true;
        }
    }
    if(!found) {
        std::cout << "Книги автора " << author << " не найдены" << std::endl;
    }
}

void searchByTitle(Book books[], int size, const char title[]) {
    bool found = false;
    for(int i = 0; i < size; i++) {
        if(strcmp(books[i].title, title) == 0) {
            std::cout << "Найдена книга:" << std::endl;
            printBook(books[i]);
            found = true;
            break;
        }
    }
    if(!found) {
        std::cout << "Книга с названием " << title << " не найдена" << std::endl;
    }
}

void sortByTitle(Book books[], int size) {
    for(int i = 0; i < size-1; i++) {
        for(int j = 0; j < size-i-1; j++) {
            if(strcmp(books[j].title, books[j+1].title) > 0) {
                Book temp = books[j];
                books[j] = books[j+1];
                books[j+1] = temp;
            }
        }
    }
}

void sortByAuthor(Book books[], int size) {
    for(int i = 0; i < size-1; i++) {
        for(int j = 0; j < size-i-1; j++) {
            if(strcmp(books[j].author, books[j+1].author) > 0) {
                Book temp = books[j];
                books[j] = books[j+1];
                books[j+1] = temp;
            }
        }
    }
}

void sortByPublisher(Book books[], int size) {
    for(int i = 0; i < size-1; i++) {
        for(int j = 0; j < size-i-1; j++) {
            if(strcmp(books[j].publisher, books[j+1].publisher) > 0) {
                Book temp = books[j];
                books[j] = books[j+1];
                books[j+1] = temp;
            }
        }
    }
}

#endif