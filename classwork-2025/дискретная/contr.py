A = set([int(x) for x in (input("Input: ")).split()])

def IsEven(num):
    return (num % 2 == 0)

def IsMult5(num):
    return (num % 5 == 0)

def IsPrime(A):
    if A <= 1:
        return False
    if A <= 3:
        return True
    if A % 2 == 0 or A % 3 == 0:
        return False
    i = 5
    while i * i <= A:
        if A % i == 0 or A % (i + 2) == 0:
            return False
        i += 6
    return True
def CreateEven(A):
    B = set()
    for i in A:
        if IsEven(i):
            B.add(i)
    return B
def Create5(A):
    B = set()
    for i in A:
        if IsMult5(i):
            B.add(i)
    return B
def CreatePrime(A):
    B = set()
    for i in A:
        if IsPrime(i):
            B.add(i)
    return B

B = CreateEven(A)
C = Create5(A)
D = CreatePrime(A)
def notM(M1,M2):
    return M1.difference(M2)

def Implec(A,B):
    return B.difference(A).union(B)
def Equ(A,B):
    return len(A) == len(B)

def And(A,B):
    return A.difference(B)

def OR(A,B):
    return A.union(B)

notB = notM(A,B)
notC = notM(A,C)
notD = notM(A,D)

print(f"A = {A}\nB = {B}\nC= {C} \nD = {D}\nnotC = {notC}\nnotB = {notB}\nnotD = {notD}")
print(f"funcAnd: {And(A,B)}\nfuncOr: {OR(A,B)}\nfuncImp: {Implec(A,B)}\nfuncEq: {Equ(A,B)}")