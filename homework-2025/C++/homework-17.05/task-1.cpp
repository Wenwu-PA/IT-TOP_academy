#include <iostream>

template<typename T>
struct StackNode {
    T data;
    StackNode* next;
    
    StackNode(const T& value) : data(value), next(nullptr) {}
};

template<typename T>
class Stack {
private:
    StackNode<T>* top;
    int size;
    int capacity;
    
public:

    Stack(int initialCapacity = 10) : top(nullptr), size(0), capacity(initialCapacity) {}
    
    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }

    bool isEmpty() const {
        return top == nullptr;
    }

    int getSize() const {
        return size;
    }

    int getCapacity() const {
        return capacity;
    }
    void resize() {
        capacity *= 2;
        std::cout << "Стек переполнен! Увеличиваем размер до " << capacity << std::endl;
    }
    
    void push(const T& value) {
        if (size >= capacity) {
            resize();
        }
        StackNode<T>* newNode = new StackNode<T>(value);
        newNode->next = top;
        top = newNode;
        size++;
        std::cout << "Добавлен элемент: " << value << std::endl;
    }
    
    void pop() {
        if (isEmpty()) {
            std::cout << "Стек пуст! Невозможно удалить элемент." << std::endl;
            return;
        }
        StackNode<T>* temp = top;
        top = top->next;
        std::cout << "Удален элемент: " << temp->data << std::endl;
        delete temp;
        size--;
    }
    
    T peek() const {
        if (isEmpty()) {
            throw std::runtime_error("Стек пуст!");
        }
        return top->data;
    }

    void display() const {
        if (isEmpty()) {
            std::cout << "Стек пуст." << std::endl;
            return;
        }
        std::cout << "Стек (сверху вниз): ";
        StackNode<T>* current = top;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};


int main() {
    std::cout << "=== Задание 1: Стек на основе односвязного списка ===\n\n";
    
    Stack<int> stack(3);
    
    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.display();
    
    std::cout << "\nВершина стека: " << stack.peek() << std::endl;
    std::cout << "Размер: " << stack.getSize() << ", Вместимость: " << stack.getCapacity() << std::endl;
    
    std::cout << "\nДобавляем 4-й элемент (вызовет переполнение):\n";
    stack.push(40);
    stack.display();
    
    std::cout << "\nУдаляем элементы:\n";
    stack.pop();
    stack.pop();
    stack.display();
    
    return 0;
}