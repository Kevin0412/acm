# cf:  WA on test 4
# qoj: RE on test 4
# QWQ

import sys
import math

def solve():
    n=int(input())
    a=[]
    a1=[]
    for i in range(1001):
        a.append(0)
    for _ in range(n):
        b=input().split(" ")
        x=int(b[0])
        #y=int(b[1])
        if(a[x]==0):
            a1.append(x)
        a[x]+=1
    a1.sort()
    b=[]
    for k in range(len(a1)):
        i=a1[k]
        if(i==a1[0] or i==a1[-1]):
            if(a[i]>1):
                print("? "+str(i)+" 1")
                sys.stdout.flush()
                c=input().split(" ")
                p=int(c[0])
                q=int(c[1])
                b.append([(p,q)])
            else:
                b.append([(0,1)])
        elif(a[i]!=0):
            if(a[i]<2):
                print("? "+str(i)+" 1")
                sys.stdout.flush()
                c=input().split(" ")
                p=int(c[0])
                q=int(c[1])
                b.append([(p,q)])
            else:
                print("? "+str(i*2+a1[k-1])+" 3")
                sys.stdout.flush()
                c=input().split(" ")
                p=int(c[0])
                q=int(c[1])
                print("? "+str(i*2+a1[k+1])+" 3")
                sys.stdout.flush()
                c=input().split(" ")
                p1=int(c[0])
                q1=int(c[1])
                b.append([(p,q),(p1,q1)])
    ans=[0,1]
    for i in range(len(a1)-1):
        if(len(b[i])==len(b[i+1])):
            l1=b[i][-1]
            l2=b[i+1][0]
        elif(len(b[i])==1):
            l1=b[i][0]
            l2=[0,1]
            l2[0]=-1*b[i][0][0]*b[i+1][0][1]+3*b[i+1][0][0]*b[i][0][1]
            l2[1]=2*b[i][0][1]*b[i+1][0][1]
        else:
            l2=b[i+1][0]
            l1=[0,1]
            l1[0]=3*b[i][1][0]*b[i+1][0][1]-1*b[i+1][0][0]*b[i][1][1]
            l1[1]=2*b[i][1][1]*b[i+1][0][1]

        p=(a1[i+1]-a1[i])*(l1[0]*l2[1]+l2[0]*l1[1])
        q=l1[1]*l2[1]*2
        c=math.gcd(p,q)
        if(c==0):
            c=1
        p=int(p/c)
        q=int(q/c)
        ans[0]=ans[0]*q+ans[1]*p
        ans[1]*=q
        c=math.gcd(ans[0],ans[1])
        if(c==0):
            c=1
        ans[0]=int(ans[0]/c)
        ans[1]=int(ans[1]/c)

    print("! "+str(ans[0])+" "+str(ans[1]))
    sys.stdout.flush()
    return

t=int(input())
for i in range(t):
    #sys.stderr.write(str(i)+"\n")
    solve()

"""
2
4
0 0
1 3
1 1
3 0

2 1

3
0 0
999 1000
1000 999

1999 1000
"""

"""
3
4
0 0
6 0
3 3
3 9

6 1
2 1

8
0 0
3 0
6 0
9 0
3 3
6 3
3 6
6 6

4 1
3 1
3 1
4 1

6
0 0
9 0
3 6
6 6
3 3
6 3

4 1
4 1
5 1
2 1
"""