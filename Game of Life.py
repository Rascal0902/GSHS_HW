import numpy as np

def okay(x,y):
    rx,ry=(x,y)
    if(x<0):
        rx+=4
    elif(x>=4):
        rx-=4
    if (y<0):
        ry+=4
    elif(y>=4):
        ry-=4
    return (rx,ry)

def gol_step(arr):
    a=np.full((4,4),0)
    for i in range(4):
        for j in range(4):
            cnt=0
            for dir in range(8):
                (x,y)=okay(i + d[0][dir], j + d[1][dir])
                if(arr[x][y]==1):
                    cnt+=1
            if(arr[i][j]==0 and cnt==3):
                a[i][j]=1
            elif(arr[i][j]==1 and (cnt==2 or cnt==3)):
                a[i][j]=1
            else:
                a[i][j]=0
    return a

d=[[1,0,-1,0,1,1,-1,-1],[0,1,0,-1,1,-1,1,-1]]
current = np.array([1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0]).reshape(4, 4)
next = np.array([0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1]).reshape(4, 4)

print(np.sum(gol_step(current) - next))
