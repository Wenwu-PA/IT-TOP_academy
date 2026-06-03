#include <iostream>

template<typename T>
struct ListNode {
    T data;
    ListNode* next;
    
    ListNode(const T& value) : data(value), next(nullptr) {}
};

template<typename T>
class LinkedList {
private:
    ListNode<T>* head;
    int count;
    
public:
    LinkedList() : head(nullptr), count(0) {}
    
    ~LinkedList() {
        clear();
    }
    
    void clear() {
        while (head != nullptr) {
            ListNode<T>* temp = head;
            head = head->next;
            delete temp;
        }
        count = 0;
    }
    
    void append(const T& value) {
        ListNode<T>* newNode = new ListNode<T>(value);
        if (head == nullptr) {
            head = newNode;
        } else {
            ListNode<T>* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
        count++;
    }
    
    void prepend(const T& value) {
        ListNode<T>* newNode = new ListNode<T>(value);
        newNode->next = head;
        head = newNode;
        count++;
    }
    
    ListNode<T>* getHead() const {
        return head;
    }
    
    int getSize() const {
        return count;
    }
    
    void display() const {
        if (head == nullptr) {
            std::cout << "Список пуст." << std::endl;
            return;
        }
        ListNode<T>* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
    
    ListNode<T>* clone() const {
        if (head == nullptr) return nullptr;
        
        ListNode<T>* newHead = new ListNode<T>(head->data);
        ListNode<T>* newCurrent = newHead;
        ListNode<T>* current = head->next;
        
        while (current != nullptr) {
            newCurrent->next = new ListNode<T>(current->data);
            newCurrent = newCurrent->next;
            current = current->next;
        }
        return newHead;
    }
    
    ListNode<T>* operator+(const LinkedList<T>& other) const {
        ListNode<T>* result = clone();
        if (result == nullptr) {
            return other.clone();
        }
        
        ListNode<T>* current = result;
        while (current->next != nullptr) {
            current = current->next;
        }
        
        ListNode<T>* otherHead = other.clone();
        if (otherHead != nullptr) {
            current->next = otherHead;
        }
        
        return result;
    }
    
    ListNode<T>* operator*(const LinkedList<T>& other) const {
        LinkedList<T> result;
        
        ListNode<T>* current = head;
        while (current != nullptr) {
            ListNode<T>* otherCurrent = other.head;
            while (otherCurrent != nullptr) {
                if (current->data == otherCurrent->data) {
                    result.append(current->data);
                    break;
                }
                otherCurrent = otherCurrent->next;
            }
            current = current->next;
        }
        
        return result.getHead();
    }
    
    static void displayFromHead(ListNode<T>* head, const char* name) {
        std::cout << name << ": ";
        if (head == nullptr) {
            std::cout << "пуст" << std::endl;
            return;
        }
        ListNode<T>* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
    
    static void deleteList(ListNode<T>* head) {
        while (head != nullptr) {
            ListNode<T>* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    std::cout << "=== Задание 2: Расширение класса односвязного списка ===\n\n";
    
    LinkedList<int> list1;
    list1.append(1);
    list1.append(2);
    list1.append(3);
    list1.append(4);
    
    std::cout << "Список 1: ";
    list1.display();
    
    LinkedList<int> list2;
    list2.append(3);
    list2.append(4);
    list2.append(5);
    list2.append(6);
    
    std::cout << "Список 2: ";
    list2.display();
    
    std::cout << "\n--- 1. Клонирование списка ---\n";
    ListNode<int>* clonedHead = list1.clone();
    LinkedList<int>::displayFromHead(clonedHead, "Клон списка 1");
    
    std::cout << "\n--- 2. Оператор + (объединение) ---\n";
    ListNode<int>* unionHead = list1 + list2;
    LinkedList<int>::displayFromHead(unionHead, "list1 + list2");
    
    std::cout << "\n--- 3. Оператор * (пересечение) ---\n";
    ListNode<int>* intersectHead = list1 * list2;
    LinkedList<int>::displayFromHead(intersectHead, "list1 * list2");
    
    LinkedList<int>::deleteList(clonedHead);
    LinkedList<int>::deleteList(unionHead);
    LinkedList<int>::deleteList(intersectHead);
    
    std::cout << "\n=== Пример для строк ===\n";
    LinkedList<std::string> names1;
    names1.append("Анна");
    names1.append("Иван");
    names1.append("Мария");
    
    LinkedList<std::string> names2;
    names2.append("Иван");
    names2.append("Петр");
    names2.append("Мария");
    
    std::cout << "Имена 1: "; names1.display();
    std::cout << "Имена 2: "; names2.display();
    
    ListNode<std::string>* intersectNames = names1 * names2;
    LinkedList<std::string>::displayFromHead(intersectNames, "Общие имена");
    LinkedList<std::string>::deleteList(intersectNames);
    
    return 0;
}