import random

random_numbers = [random.randint(-50, 50) for _ in range(15)]
print(f"Исходный список: {random_numbers}")

sorted_descending = sorted(random_numbers, reverse=True)

numbers_copy = random_numbers.copy()
numbers_copy.sort(key=lambda x: -x)
print(f"\nСортировка с помощью sorted(reverse=True): {sorted_descending}")
print(f"Сортировка с помощью sort(key=lambda x: -x): {numbers_copy}")
if sorted_descending == numbers_copy:
    print("\n✓ Результаты обеих сортировок идентичны!")
else:
    print("\n✗ Результаты сортировок отличаются!")