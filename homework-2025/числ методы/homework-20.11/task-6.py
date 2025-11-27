with open("input.txt", "r", encoding="utf-8") as f_in:
    lines = f_in.readlines()

with open("output.txt", "w", encoding="utf-8") as f_out:
    for i, line in enumerate(lines, 1):
        clean_line = line.rstrip('\n\r')
        char_count = len(clean_line)
        new_line = f"{i}) {clean_line} {char_count}\n"
        f_out.write(new_line)