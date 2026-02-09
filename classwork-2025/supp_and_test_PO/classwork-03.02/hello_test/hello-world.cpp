#include <iostream>
#include <cstdlib>
#include <ctime>
int summ(int a, int b);
int main()
{
    setlocale(LC_ALL, "rus");

    int ans[20]; // создали массив для записи всех индексов
    int h = 0;
    int arr[20]; // создали массив на 20 элементов
    int key; // создали переменную в которой будет находиться ключ

    srand(time(NULL));

    for (int i = 0; i < 20; i++) {
        arr[i] = 1 + rand() % 20; // заполняем случайными числами ячейки

        cout << arr[i] << " "; // выводим все ячейки массива

        if (i == 9) {
            cout << endl;
        }
    }

    cout << endl << endl << "Введите ключ : "; cin >> key; // считываем ключ

    for (int i = 0; i < 20; i++) {
        if (arr[i] == key) { // проверяем равен ли arr[i] ключу
            ans[h++] = i;
        }
    }

    if (h != 0) { // проверяем были ли совпадения
        for (int i = 0; i < h; i++) {
            cout << "Ключ " << key << " находится в ячейке " << ans[i] << endl; //выводим все индексы
        }
    }
    else {
        cout << "Мы не нашли ключ " << key << " в массиве";
    }

    system("pause");
    return 0;
	int a{ 5 };
	int b{ 20 };
	std::cout << summ(a, b) << '\n';
	std::cout << "Hello World!\n";
}
int summ(int a, int b) {
	return a + b;
}
using namespace std;