from cs1robots import *
load_world('worlds/frank18.wld')
gshs = Robot(color="light_blue", orientation='E', avenue=1, street=1)
gshs.set_trace(color='blue')

gshs2 = Robot(color="green", orientation='E', avenue=1, street=1, beepers=1000)
gshs2.set_trace(color='red')

beeperList = []


def list_up(way, x, y, beepers):
    if way == 1:
        beeperList.append(['E', x, y, beepers])
    elif way == -1:
        beeperList.append(['W', x, y, beepers])
    else:
        beeperList.append(['N', x, y, beepers])


def left():
    gshs.turn_left()


def right():
    for i in range(3):
        gshs.turn_left()


def pick():
    i = 0
    while gshs.on_beeper():
        gshs.pick_beeper()
        i = i + 1
    return i

def move(w, x, y):
    gshs.move()
    p = pick()
    if p != 0:
        list_up(w, x, y, p)


def Uturn_left(x, y):
    left()
    move(0, x, y + 1)
    left()


def Uturn_right(x, y):
    right()
    move(0, x, y + 1)
    right()


def ten_move(w, x, y):
    for i in range(9):
        x = x + w
        move(w, x, y)


# gshs 이동
p = pick()
if p != 0:
    list_up(1, 1, 1, p)
x = 1
y = 1
for i in range(3):
    ten_move(1, x, y)
    x += 9
    Uturn_left(x, y)
    y += 1
    ten_move(-1, x, y)
    x -= 9
    Uturn_right(x, y)
    y += 1
ten_move(1, x, y)
print(beeperList)

# gshs2
beeperLen = len(beeperList)
maxi = 0
x = 0
y = 0
for i in range(0, beeperLen - 1):
    if maxi < beeperList[i][3]:
        maxi = beeperList[i][3]
        x = beeperList[i][1]
        y = beeperList[i][2]
for i in range(x - 1):
    gshs2.move()
gshs2.turn_left()
for i in range(y - 1):
    gshs2.move()
for i in range(maxi):
    gshs2.drop_beeper()
gshs2.move()