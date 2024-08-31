from cs1robots import *
load_world('worlds/foru.wld')
gshs = Robot(beepers=10000)
gshs.set_trace(color='blue')

list = [0]
for i in range(10000):
    list.append(1)
list[1] = 0
for i in range(1,10000):
    if list[i] == 1:
        for j in range(i, 10000):
            if i*j > 10000:
                break
            list[i*j] = 0
prime = []
for i in range(1,10000):
    if list[i] == 1:
        prime.append(i)

def turn_right():
    for i in range(3):
        gshs.turn_left()


def Uturn_left():
    gshs.turn_left()
    gshs.move()
    gshs.turn_left()


def Uturn_right():
    turn_right()
    gshs.move()
    turn_right()


def drop(x):
    for i in range(x):
        gshs.drop_beeper()


def move(x):
    gshs.move()
    drop(x)


def ten_move(p):
     drop(prime[p])
     for i in range(9):
        p = p + 1
        move(prime[p])


point = 0
for i in range(1):
    ten_move(point)
    point = point + 10
    Uturn_left()
    ten_move(point)
    point = point + 10
    Uturn_right()
ten_move(point)
gshs.turn_left()
gshs.move()
gshs.turn_left()