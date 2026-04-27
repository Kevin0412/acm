class seq:
    def __init__(self):
        self.seq=[-1,-1]
        self.n=-1
        self.t=0

t=int(input())
for i in range(t):
    a=[]
    b=input().split(" ")
    for j in b:
        a.append(int(j))
        if(j==-1):
            break
    a.append(-1)
    c={}
    for j in range(len(a)-3,-1,-1):
        key = a[j]
        if key not in c:               # 如果键不存在
            c[key] = seq()              
        c[a[j]].n=j
        c[a[j]].seq=[a[j+1],a[j+2]]
        c[a[j]].t=0
    for j in range(len(a)-2):
        if(c[a[j]].t>=0):
            if([a[j+1],a[j+2]]==c[a[j]].seq):
                c[a[j]].t+=1
            else:
                c[a[j]].t=-1
    ans=len(a)
    for j in range(len(a)-2):
        if(c[a[j]].t>=2):
            ans=min(ans,c[a[j]].n)
    if(ans==len(a)):
        print("NONE")
    else:
        print(str(a[ans])+" "+str(a[ans+1])+" "+str(a[ans+2]))
