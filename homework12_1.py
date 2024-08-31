import random
from turtle import *
from random import *
class Disc(Turtle):
    def __init__(self, n, position):
        super().__init__()
        self.speed(2)
        self.color(random(),random(),random())
        self.shape("square")
        self.shapesize(stretch_wid=2,stretch_len=2*n)
        self.penup()
        self.goto(position)
        self.n=n


class Tower():
    def __init__(self, x):
        self.x=x
        self.top=-200
        self.list=[]

    def push(self, d):
        d.goto(self.x,self.top)
        self.list.append(d)
        self.top+=50

    def pop(self):
        d=self.list[len(self.list)-1]
        self.list.pop()
        d.goto(self.x,200)
        self.top-=50
        return d;

def hanoi(n, a, b, c):
    if n > 0:
        hanoi(n-1,a,c,b)
        d=a.pop()
        d.goto(c.x,200)
        c.push(d)
        hanoi(n-1,b,a,c)

size = 6 #원판의 갯수
screen=Screen()

screen.screensize(600,600)
screen.listen()
t1 = Tower(-250)
t2 = Tower(0)
t3 = Tower(250)

for i in range(size, 0, -1):
    d=Disc(i,(t1.x,t1.top))
    t1.push(d)

def main():
    hanoi(size, t1, t2, t3)

screen.onkeypress(main,'space')
screen.exitonclick()