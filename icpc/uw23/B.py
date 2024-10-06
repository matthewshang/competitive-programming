from dataclasses import dataclass
import sys
from math import gcd

@dataclass
class Frac:
    n: int
    d: int

    def whole(N: int):
        return Frac(N, 1)

    def zero():
        return Frac.whole(0)

    def __add__(self, other):
        n = self.n * other.d + other.n * self.d
        d = self.d * other.d
        g = gcd(n, d)
        return Frac(n // g, d // g)
    
    def __sub__(self, other):
        n = self.n * other.d - other.n * self.d
        d = self.d * other.d
        g = gcd(n, d)
        return Frac(n // g, d // g)

    def __mul__(self, other):
        n = self.n * other.n
        d = self.d * other.d
        g = gcd(n, d)
        return Frac(n // g, d // g)
    
    def __truediv__(self, other):
        n = self.n * other.d
        d = self.d * other.n
        g = gcd(n, d)
        return Frac(n // g, d // g)
    
    def __lt__(self, other):
        return self.n * other.d < other.n * self.d


@dataclass
class Beaker:
    cap: Frac
    A: Frac = Frac.zero()
    B: Frac = Frac.zero()


a, b, s, t = map(int, sys.stdin.readline().split())

S = Beaker(Frac.whole(s))
T = Beaker(Frac.whole(t))
log = []

def fill(x: str, y: str):
    X = S if x == "S" else T
    if y == "A":
        X.A = X.cap - X.B
    else:
        X.B = X.cap - X.A
    log.append(f"F {x} {y}")

def pour(x: str, y: str):
    X, Y = (S, T) if x == "S" else (T, S)
    rem = Y.cap - (Y.A + Y.B)
    if rem < (X.A + X.B):
        t = rem / (X.A + X.B)
        Y.A += t * X.A
        Y.B += t * X.B
        X.A -= t * X.A
        X.B -= t * X.B
    else:
        Y.A += X.A
        Y.B += X.B
        X.A = Frac.zero()
        X.B = Frac.zero()

    log.append(f"P {x} {y}")

def empty(x: str):
    X = S if x == "S" else T
    X.A = Frac.zero()
    X.B = Frac.zero()
    log.append(f"E {x}")

def seal(x: str):
    log.append(f"! {x}")

def answer():
    print(len(log))
    print("\n".join(log))

fill("T", "A")
pour("T", "S")
empty("S")
fill("T", "B")
pour("T", "S")
empty("T")
pour("S", "T")
fill("T", "A")
seal("T")
print(S, T)
answer()