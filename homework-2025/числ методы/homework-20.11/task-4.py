with open("k7a-6.txt", "r") as file:
    s = file.read().strip()

max_len = 0
current_len = 0

for char in s:
    if char in ['B', 'C', 'D', 'F']:
        current_len += 1
        if current_len > max_len:
            max_len = current_len
    else:
        current_len = 0

print(max_len)