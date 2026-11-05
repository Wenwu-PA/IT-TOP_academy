def determinant_3x3(matrix):
    a, b, c = matrix[0]
    d, e, f = matrix[1]
    g, h, i = matrix[2]
    
    return (a * (e * i - f * h) -
            b * (d * i - f * g) +
            c * (d * h - e * g))

def create_matrix_x(matrix, b):
    result = [row[:] for row in matrix]
    for i in range(3):
        result[i][0] = b[i]
    return result

def create_matrix_y(matrix, b):
    result = [row[:] for row in matrix]
    for i in range(3):
        result[i][1] = b[i]
    return result

def create_matrix_z(matrix, b):
    result = [row[:] for row in matrix]
    for i in range(3):
        result[i][2] = b[i]
    return result

def solve_system():
    try:
        # Ввод матрицы коэффициентов
        print("Введите матрицу коэффициентов 3x3 (построчно через пробел)✍️:")
        matrix_a = []
        for i in range(3):
            row = list(map(float, input(f"Строка {i+1}: ").split()))
            if len(row) != 3:
                raise ValueError("Матрица должна быть 3x3!🤪☹️")
            matrix_a.append(row)
        
        # Ввод матрицы свободных членов
        print("\nВведите матрицу свободных членов (3 числа через пробел)🤌:")
        matrix_b = list(map(float, input().split()))
        if len(matrix_b) != 3:
            raise ValueError("Матрица свободных членов должна содержать 3 элемента🤨!")
        
        # Вычисление определителей
        det_A = determinant_3x3(matrix_a)
        
        if abs(det_A) < 1e-10:
            print("\nСистема не имеет единственного решения (определитель равен нулю)😲")
            return
        
        print(f"\nОбщий определитель матрицы 🦾A: {det_A:}")
        
        # Вычисление частных определителей
        det_x = determinant_3x3(create_matrix_x(matrix_a, matrix_b))
        det_y = determinant_3x3(create_matrix_y(matrix_a, matrix_b))
        det_z = determinant_3x3(create_matrix_z(matrix_a, matrix_b))
        
        print(f"\nЧастные определители🦾:")
        print(f"Δx = {det_x:.4f}")
        print(f"Δy = {det_y:.4f}")
        print(f"Δz = {det_z:.4f}")
        
        # Вычисление неизвестных
        x = det_x / det_A
        y = det_y / det_A
        z = det_z / det_A
        
        print("\nРешение системы🦾:")
        print(f"x = {x:.4f}")
        print(f"y = {y:.4f}")
        print(f"z = {z:.4f}")
        
    except Exception as e:
        print(f"\nОшибка🤯: {str(e)}")
solve_system()
