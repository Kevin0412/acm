a=[
    [0,0,0],
    [0,0,0],
    [0,0,0]
]
b=[
    [1,1,1],
    [1,1,1],
    [1,1,1]
]

import random

for x in range(3):
    for y in range(3):
        i=random.randint(0,1)
        a[x][y]=i

b[1][1]=1-a[1][1]
corners=[[0,0],[2,0],[2,2],[0,2]]
edges=[[0,1],[1,2],[2,1],[1,0]]
ci=4
for c in corners:
    ci-=a[c[0]][c[1]]
cn=4
for c in corners:
    if(random.randint(1,cn)<=ci):
        b[c[0]][c[1]]=1
        ci-=1
    else:
        b[c[0]][c[1]]=0
    cn-=1

ei=4
for e in edges:
    ei-=a[e[0]][e[1]]
en=4
for e in edges:
    if(random.randint(1,en)<=ei):
        b[e[0]][e[1]]=1
        ei-=1
    else:
        b[e[0]][e[1]]=0
    en-=1

e=[
    [0,0,0],
    [0,0,0],
    [0,0,0]
]

step=0
while 1:
    sum=0
    for x in range(3):
        for y in range(3):
            sum+=a[x][y]
    print(step)
    if(sum==0):
        break
    for x in range(3):
        print(a[x],b[x])
    c=input()
    if(c[0]=="C"):
        d=int(c[1])-1
        for x in range(3):
            temp=b[x][d]
            b[x][d]=a[x][d]
            a[x][d]=temp
    elif(c[0]=="A"):
        if(c[1]=="L"):
            n=3
        else:
            n=1
        for _ in range(n):
            for x in range(3):
                for y in range(3):
                    e[x][y]=a[x][y]
            for x in range(3):
                for y in range(3):
                    a[x][y]=e[2-y][x]
    elif(c[0]=="B"):
        if(c[1]=="L"):
            n=3
        else:
            n=1
        for _ in range(n):
            for x in range(3):
                for y in range(3):
                    e[x][y]=b[x][y]
            for x in range(3):
                for y in range(3):
                    b[x][y]=e[2-y][x]
    else:
        step-=1
    step+=1