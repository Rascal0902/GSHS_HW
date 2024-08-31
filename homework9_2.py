

from cs1robots import *
import random

load_world('worlds/hwmap9.wld')

gshs = Robot(color="light_blue", avenue=1, street=1, beepers=100000)

n = 20
trials = 100
deadEnds = 0

move = [(1, 0), (0, 1), (-1, 0), (0, -1)]

def init_gshs(x, y):
    for i in range(x):
        gshs.move()
    gshs.turn_left()
    for i in range(y):
        gshs.move()


def end_gshs(x, y):
    while not gshs.facing_north():
        gshs.turn_left()
    gshs.turn_left()
    gshs.turn_left()
    for i in range(y):
        gshs.move()
    gshs.turn_left()
    gshs.turn_left()
    gshs.turn_left()
    for i in range(x):
        gshs.move()
    gshs.turn_left()
    gshs.turn_left()

def move_gshs(dx, dy, robotDir):
    if robotDir == (0, 0):
        if dx == -1:
            gshs.turn_left()
        elif dy == -1:
            gshs.turn_left()
            gshs.turn_left()
        elif dx == 1:
            gshs.turn_left()
            gshs.turn_left()
            gshs.turn_left()
        else:
            pass
        gshs.move()
        return

    robotDirNum = -1
    nextDirNum = -1

    for i in range(4):
        if robotDir == move[i]:
            robotDirNum = i
        if (dx, dy) == move[i]:
            nextDirNum = i

    if robotDirNum == nextDirNum:
        gshs.move()
    elif robotDirNum == (nextDirNum+3) % 4:
        gshs.turn_left()
        gshs.move()
    else:
        gshs.turn_left()
        gshs.turn_left()
        gshs.turn_left()
        gshs.move()


def can_move_dir(x, y, check):
    res = []
    for i in range(4):
        dx, dy = move[i]
        if x+dx < 0 or x+dx >= n or y+dy < 0 or y+dy >= n:
            continue
        if not check[x+dx][y+dy]:
            res.append(move[i])
    return res


def is_edge(x, y):
    if x == 0 or y == 0 or x == n-1 or y == n-1:
        return True
    else:
        return False


for t in range(trials):
    gshs.set_trace(color='blue')
    check = [[False for __ in range(n)] for _ in range(n)]
    x = n//2 - 1
    y = n//2 - 1
    init_gshs(x, y)
    robotDir = (0, 0)

    while True:
        gshs.drop_beeper()
        if is_edge(x, y):
            break

        check[x][y] = True
        dir = can_move_dir(x, y, check)

        if len(dir) == 0:
            deadEnds += 1
            break

        dx, dy = dir[random.randint(0, len(dir)-1)]
        move_gshs(dx, dy, robotDir)
        x += dx
        y += dy
        robotDir = (dx, dy)
    end_gshs(x, y)
    clear_beeper_trace(gshs)


print(str(100*deadEnds//trials) + '% dead ends')

