with open('24-001.txt', 'r') as f:
    s = f.read().strip()

max_length = 1
current_length = 1

for i in range(1, len(s)):
    if s[i] == s[i-1]:
        current_length += 1
        if current_length > max_length:
            max_length = current_length
    else:
        current_length = 1

print(max_length)