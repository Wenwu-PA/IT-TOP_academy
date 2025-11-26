with open('24.txt', 'r') as file:
    content = file.read().strip()

max_length = 1
current_length = 1

for i in range(1, len(content)):
    if content[i] == content[i-1]:
        current_length += 1
        max_length = max(max_length, current_length)
    else:
        current_length = 1

print(max_length)