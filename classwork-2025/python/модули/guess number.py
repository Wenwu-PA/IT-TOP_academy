from random import randint
while True:
    # начальное меню и определние условий игры
    print ("/Вас приветствует игра - 'угадай игру'\ \n|- напишите 1 для начала игры         |")
    plChoice = int(input("Введите число: "))
    print ("|Выберите уровень сложности: 1 , 2    | \n| 1 - 5 попыток     2 - 2 попытки     |")
    attChoice = int(input("Ваш выбор: "))
    attempts = 0
    randNumPC = randint(0,100)

    #условия для выбора сложности
    if attChoice == 1:
        attempts = 5
    elif attChoice == 2:
        attempts = 2
    else:
        print ("Может быть только 1 и 2 уровень")

    #основаная логика игры
    if plChoice == 1:
        while attempts != 0:
            print (f"|Компьютер загадал число, у вас {attempts} попытка|")
            ChoicePl = int(input("|испытайте удачу: "))
            if ChoicePl != randNumPC:
                attempts-=1
            elif ChoicePl == randNumPC:
                print("| Вы выиграли ! ")
    elif plChoice != 1:
        print("Ошибка, пока что только 1 вариант :(")

    print(f"|Вы проиграли, ответ был:{randNumPC}")






