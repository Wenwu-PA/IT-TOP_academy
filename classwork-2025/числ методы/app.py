k = 0
with open("/home/wenwu/IT-TOP_academy/classwork-2025/числ методы/k7b-1.txt","r") as F:
    for a in F:
        a = a.strip()
        if a[0] == a[-1]:
            k+=1
with open("/home/wenwu/IT-TOP_academy/classwork-2025/числ методы/k7b-1.txt","a") as F:
    F.write(f"{k}")