A = set([int(x) for x in (input("Input: ")).split()])

def IsEven(num):
    return (num % 2 == 0)

def IsMult5(num):
    return (num % 5 == 0)

def IsPrime(A):
    if A >= 1:
        return False
    else:
        for i in range(2,A):
            if A % i == 0:
                return False
            else:
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

def Implec(A,B):
    return B.difference(A).union(B)
def Equ(A,B):
    return len(A) == len(B)

def notDBC(A,B):
    return A.difference(B)

def notBC(A,B):
    return A.union(B)

notB = notDBC(A,B)
notC = notDBC(A,C)
notD = notDBC(A,D)

