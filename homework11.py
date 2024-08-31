import turtle
import random
random.seed(10)

turtle.screensize(canvwidth=1000, canvheight=1000)
win = turtle.Screen()
go = 20
tt = []

for i in range(50):
 temp = turtle.Turtle()
 temp.color(random.random(),random.random(),random.random())
 temp.speed(0)
 tt.append(temp)

print("init finished")

while True:
 for i in range(50):
  angle = int(random.random()*4)*90
  tt[i].left(angle)
  tt[i].forward(go)

win.exitonclick()