
from cs1robots import *
import random
load_world('./worlds/finalMaze2.wld')


orient_dict = {0:'N', 1: 'E', 2: 'S', 3: 'W'}
initial_orient = random.randint(0,3)
gshs1 = Robot(color="light_blue", orientation=orient_dict[initial_orient], avenue=11, street=11)
gshs1.set_trace(color='blue')


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
        
def get_func(command):
    if command == 'M':
        return move
    elif command == 'L':
        return turn_left
    elif command == 'R':
        return turn_right

with open("./worlds/command2.txt", "r") as f:
    command_list = f.read().replace('\n','').strip()
command_list=[get_func(m) for m in command_list]

def isCircular(x, y, dir, path, robot):
    print("Path len: ", len(path))

    for act in path: act(robot)
    curX, curY = robot.get_pos()

    return curX==x and curY==y

print(isCircular(11,11, initial_orient, command_list, gshs1))

