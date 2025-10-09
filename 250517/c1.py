import sys

t=int(input())

for _ in range(t):
    n=int(input())
    sys.stdout.flush("digit")
    _=int(input())
    sys.stdout.flush("digit") 
    n=int(input())
    sys.stdout.flush("add -8")
    n=int(input())
    sys.stdout.flush("add -4") 
    n=int(input())
    sys.stdout.flush("add -2") 
    n=int(input())
    sys.stdout.flush("add -1")
    n=int(input())
    sys.stdout.flush("add "+str(n-1))
    n=int(input())
    sys.stdout.flush("!") 
    n=int(input())