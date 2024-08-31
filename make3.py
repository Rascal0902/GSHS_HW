from cs1robots import *
load_world("worlds/gooverthewalls.wld")
gshs = Robot(orientation='E')
gshs.set_trace('red')

def go_back():
    gshs.turn_left()
    gshs.turn_left()
    gshs.move()
    gshs.turn_left()
    gshs.turn_left()

def dash():
    if not gshs.front_is_clear():
        pause(0.25)
        (x1,y1) = gshs.get_pos()
        go_back()
        pause(0.5)
        (x2,y2) = gshs.get_pos()
        gshs.move()
        gshs.set_trace('blue')
        if x1 == x2+1 and y1 == y2:   # 오른쪽으로
            row = 2 * x1
            col = 2 * y1 - 1
            makewall(row,col)
            gshs.move()
        elif x1 == x2-1 and y1 == y2:  # 왼쪽으로
            row = 2 * x1 - 2
            col = 2 * y1 - 1
            makewall(row, col)
            gshs.move()
        elif x1 == x2 and y1 == y2+1:   # 위쪽으로
            row = 2 * x1 - 1
            col = 2 * y1
            makewall(row, col)
            gshs.move()
        elif x1 == x2 and y1 == y2-1:  # 아래쪽으로
            row = 2 * x1 - 1
            col = 2 * y1 - 2
            makewall(row, col)
            gshs.move()
        else:
            print("I can't jump!")
        gshs.set_trace('red')
    else:
        gshs.move()

def turn_right():
    gshs.turn_left()
    gshs.turn_left()
    gshs.turn_left()

###############################################

gshs.turn_left()
for _ in range(3):
 dash()
turn_right()

for _ in range(13):
 dash()
 if gshs.on_beeper():
     gshs.pick_beeper()
gshs.turn_left()

for _ in range(5):
 dash()
gshs.turn_left()

for _ in range(10):
 if gshs.on_beeper():
     gshs.pick_beeper()
 dash()
if gshs.on_beeper():
  gshs.pick_beeper()
turn_right()

for _ in range(5):
 dash()
turn_right()

for _ in range(10):
 if gshs.on_beeper():
     gshs.pick_beeper()
 dash()
if gshs.on_beeper():
  gshs.pick_beeper()

print("I did it !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!")
