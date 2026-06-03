#include <iostream>
#include <cstdlib>
#include <ctime>

template <typename T>
class Matrix {
private:
    size_t rows;
    size_t cols;
    T** data;

public:
    Matrix(size_t r, size_t c) : rows(r), cols(c) {
        data = new T*[rows];
        for (size_t i = 0; i < rows; ++i)
            data[i] = new T[cols];
    }
    ~Matrix() {
        for (size_t i = 0; i < rows; ++i)
            delete[] data[i];
        delete[] data;
    }
    Matrix(const Matrix& other) : rows(other.rows), cols(other.cols) {
        data = new T*[rows];
        for (size_t i = 0; i < rows; ++i) {
            data[i] = new T[cols];
            for (size_t j = 0; j < cols; ++j)
                data[i][j] = other.data[i][j];
        }
    }
    Matrix& operator=(const Matrix& other) {
        if (this == &other) return *this;
        for (size_t i = 0; i < rows; ++i)
            delete[] data[i];
        delete[] data;
        rows = other.rows;
        cols = other.cols;
        data = new T*[rows];
        for (size_t i = 0; i < rows; ++i) {
            data[i] = new T[cols];
            for (size_t j = 0; j < cols; ++j)
                data[i][j] = other.data[i][j];
        }
        return *this;
    }

    void fillKeyboard() {
        std::cout << "Введите элементы матрицы (" << rows << "x" << cols << "):\n";
        for (size_t i = 0; i < rows; ++i)
            for (size_t j = 0; j < cols; ++j)
                std::cin >> data[i][j];
    }

    void fillRandom() {
        static bool seeded = false;
        if (!seeded) {
            srand((unsigned)time(nullptr));
            seeded = true;
        }
        for (size_t i = 0; i < rows; ++i)
            for (size_t j = 0; j < cols; ++j) {
                if (std::is_integral<T>::value) {
                    data[i][j] = (T)(rand() % 21 - 10);
                } else {
                    data[i][j] = (T)((rand() % 2000 - 1000) / 100.0);
                }
            }
    }

    void display() const {
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; ++j)
                std::cout << data[i][j] << "\t";
            std::cout << std::endl;
        }
    }

    T maxElement() const {
        T maxVal = data[0][0];
        for (size_t i = 0; i < rows; ++i)
            for (size_t j = 0; j < cols; ++j)
                if (data[i][j] > maxVal) maxVal = data[i][j];
        return maxVal;
    }

    T minElement() const {
        T minVal = data[0][0];
        for (size_t i = 0; i < rows; ++i)
            for (size_t j = 0; j < cols; ++j)
                if (data[i][j] < minVal) minVal = data[i][j];
        return minVal;
    }

    Matrix operator+(const Matrix& other) const {
        if (rows != other.rows || cols != other.cols) {
            std::cerr << "Ошибка: разные размеры матриц!" << std::endl;
            exit(1);
        }
        Matrix result(rows, cols);
        for (size_t i = 0; i < rows; ++i)
            for (size_t j = 0; j < cols; ++j)
                result.data[i][j] = data[i][j] + other.data[i][j];
        return result;
    }

    Matrix operator-(const Matrix& other) const {
        if (rows != other.rows || cols != other.cols) {
            std::cerr << "Ошибка: разные размеры матриц!" << std::endl;
            exit(1);
        }
        Matrix result(rows, cols);
        for (size_t i = 0; i < rows; ++i)
            for (size_t j = 0; j < cols; ++j)
                result.data[i][j] = data[i][j] - other.data[i][j];
        return result;
    }

    Matrix operator*(const Matrix& other) const {
        if (cols != other.rows) {
            std::cerr << "Ошибка: число столбцов первой матрицы не равно числу строк второй!" << std::endl;
            exit(1);
        }
        Matrix result(rows, other.cols);
        for (size_t i = 0; i < rows; ++i)
            for (size_t j = 0; j < other.cols; ++j) {
                result.data[i][j] = 0;
                for (size_t k = 0; k < cols; ++k)
                    result.data[i][j] += data[i][k] * other.data[k][j];
            }
        return result;
    }

    Matrix operator/(const Matrix& other) const {
        if (rows != other.rows || cols != other.cols) {
            std::cerr << "Ошибка: разные размеры матриц!" << std::endl;
            exit(1);
        }
        Matrix result(rows, cols);
        for (size_t i = 0; i < rows; ++i)
            for (size_t j = 0; j < cols; ++j) {
                if (other.data[i][j] == 0) {
                    std::cerr << "Ошибка: деление на ноль!" << std::endl;
                    exit(1);
                }
                result.data[i][j] = data[i][j] / other.data[i][j];
            }
        return result;
    }

    T& operator()(size_t i, size_t j) {
        return data[i][j];
    }
    const T& operator()(size_t i, size_t j) const {
        return data[i][j];
    }

    size_t getRows() const { return rows; }
    size_t getCols() const { return cols; }
};

int main() {
    Matrix<int> A(2, 2);
    Matrix<int> B(2, 2);

    std::cout << "Заполнение матрицы A случайными числами:\n";
    A.fillRandom();
    A.display();

    std::cout << "\nЗаполнение матрицы B с клавиатуры:\n";
    B.fillKeyboard();

    std::cout << "\nМатрица B:\n";
    B.display();

    Matrix<int> C = A + B;
    std::cout << "\nA + B:\n";
    C.display();

    Matrix<int> D = A - B;
    std::cout << "\nA - B:\n";
    D.display();

    Matrix<int> E = A * B;
    std::cout << "\nA * B (матричное произведение):\n";
    E.display();

    Matrix<double> X(2, 2);
    Matrix<double> Y(2, 2);
    X.fillRandom();
    Y.fillRandom();
    std::cout << "\nМатрица X (double):\n";
    X.display();
    std::cout << "\nМатрица Y (double):\n";
    Y.display();

    Matrix<double> Z = X / Y;
    std::cout << "\nX / Y (поэлементно):\n";
    Z.display();

    std::cout << "\nМаксимальный элемент в A: " << A.maxElement() << std::endl;
    std::cout << "Минимальный элемент в A: " << A.minElement() << std::endl;

    return 0;
}