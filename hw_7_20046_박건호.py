
from cs1robots import *
import random
load_world('./worlds/finalMaze2.wld')

orient_dict = {0:'N', 1: 'E', 2: 'S', 3: 'W'}

initial_orient = random.randint(0,3)
gshs1 = Robot(color="light_blue", orientation=orient_dict[initial_orient], avenue=11, street=11)
gshs1.set_trace(color='blue')
gshs1.set_pause(1)

initial_orient = random.randint(0,3)
gshs2 = Robot(color="yellow", orientation=orient_dict[initial_orient], avenue=11, street=11)
gshs2.set_trace(color='blue')
gshs2.set_pause(1)

def turn_right(robot):
    for i in range(3):
        robot.turn_left()

def turn_around(robot):
    for i in range(2):
        robot.turn_left()

def turn_left(robot):
    robot.turn_left()

def move(robot):
    if robot.front_is_clear():
        robot.move()
    else:
        turn_around(robot)
        robot.move()

# command : M(move) L(turn_left) R(turn_right)

def get_func(command):
    if command == 'M': return move
    elif command == 'L': return turn_left
    elif command == 'R': return turn_right

#To Do 1
with open("./worlds/command.txt", "r") as f:
    command1 = f.readline().strip().replace(' ','')
    command2 = f.readline().strip().replace(' ','')
    f.close()

#To Do 2
command1 = [get_func(m) for m in command1]
command2 = [get_func(m) for m in command2]

# To do 3
def isCircular(x, y, dir, path, robot):
    for act in path: act(robot)
    curX, curY = robot.get_pos()

    return curX==x and curY==y

print(isCircular(11,11, initial_orient, command1, gshs1))
print(isCircular(11,11, initial_orient, command2, gshs2))

