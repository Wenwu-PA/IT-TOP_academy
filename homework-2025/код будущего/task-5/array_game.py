import random

def guess_number_game():
    secret = random.randint(1, 100)
    attempts = 0
    
    print("Добро пожаловать в игру 'Угадай число'!")
    print("Я загадал число от 1 до 100. Попробуй угадать!")
    
    while True:
        try:
            guess = input("Введите вашу догадку (число от 1 до 100): ")
            guess = int(guess)
            attempts += 1
            
            if guess < 1 or guess > 100:
                print("Пожалуйста, введите число от 1 до 100!")
                continue
                
            if guess < secret:
                print("Загаданное число БОЛЬШЕ!")
            elif guess > secret:
                print("Загаданное число МЕНЬШЕ!")
            else:
                print(f"Поздравляю! Вы угадали число {secret} за {attempts} попыток!")
                break
                
        except ValueError:
            print("Ошибка! Пожалуйста, введите корректное число.")
            continue

if __name__ == "__main__":
    guess_number_game()