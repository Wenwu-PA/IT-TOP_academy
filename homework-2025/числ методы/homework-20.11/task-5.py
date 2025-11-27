with open("k7c-1.txt", "r") as file:
    s = file.read().strip()

count = 0
for i in range(len(s) - 2):
    X1, X2, X3 = s[i], s[i+1], s[i+2]
    
    # Условие 1
    if X1 not in "BCD":
        continue
    
    # Условие 2
    if X2 not in "BDE" or X2 == X1:
        continue
    
    # Условие 3
    if X3 not in "BCE" or X3 == X2:
        continue
    
    count += 1

print(count)