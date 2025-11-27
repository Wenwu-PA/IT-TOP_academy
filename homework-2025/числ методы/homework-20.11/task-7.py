with open("input.txt", "r", encoding="utf-8") as f_in:
    lines = f_in.readlines()

min_len = float('inf')
shortest_lines = []

for line in lines:
    line_clean = line.rstrip('\n\r')
    length = len(line_clean)
    
    if length < min_len:
        min_len = length
        shortest_lines = [line_clean]
    elif length == min_len:
        shortest_lines.append(line_clean)

with open("output.txt", "w", encoding="utf-8") as f_out:
    for line in shortest_lines:
        f_out.write(line + '\n')