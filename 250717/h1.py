class game:
    def __init__(self,a,b):
        self.a=a
        self.b=b
        self.actions=[]
    
    def step(self,c):
        self.actions.append(c)
        e=[
            [0,0,0],
            [0,0,0],
            [0,0,0]
        ]
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
        
a=[
    [0,0,0],
    [0,0,0],
    [0,0,0]
]
b=[
    [0,0,0],
    [0,0,0],
    [0,0,0]
]

for x in range(3):
    s=input()
    for y in range(3):
        a[x][y]=int(s[y])
        
for x in range(3):
    s=input()
    for y in range(3):
        b[x][y]=int(s[y])
        
c=game(a,b)
if(c.a[1][1]==1):
    c.step("C2")
def edged(a):
    return a[0][1] and a[1][0] and a[1][2] and a[2][1]
while(not edged(c.b)):
    if(c.a[1][0]==1 and c.b[1][0]==0):
        c.step("C1")
    if(c.a[1][2]==1 and c.b[1][2]==0):
        c.step("C3")
    if(c.a[0][1]==1):
        c.step("AL")
    elif(c.a[2][1]==1):
        c.step("AR")
    if(c.b[0][1]==0):
        c.step("BL")
    elif(c.a[2][1]==0):
        c.step("BR")
    if(c.a[1][0]==0 and c.b[1][0]==0 and c.a[1][2]==1 and c.b[1][2]==1):
        c.step("BR")
        c.step("BR")
        
        
corners=[[0,0],[2,0],[2,2],[0,2]]

def cornered(a):
    return a[0][0] and a[2][0] and a[2][2] and a[0][2]

while(not cornered(c.b)):
    for ca in corners:
        if(a[ca[0]][ca[1]]==1):
            if(corners.index(ca)==2):
                c.step("AR")
            elif(corners.index(ca)==3):
                c.step("AR")
                c.step("AR")
            elif(corners.index(ca)==0):
                c.step("AL")
            for cb in corners:
                if(b[cb[0]][cb[1]]==0):
                    if(corners.index(cb)==1):
                        c.step("BR")
                    elif(corners.index(cb)==2):
                        c.step("BR")
                        c.step("BR")
                    elif(corners.index(cb)==3):
                        c.step("BL")
            c.step("C1")
            c.step("AL")
            c.step("C1")
            c.step("AR")
            c.step("C1")

print(len(c.actions),end="")
for action in c.actions:
    print()
    print(action,end="")
                        
                    