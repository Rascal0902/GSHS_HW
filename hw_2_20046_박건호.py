from cs1robots import *

def turn_right():
    gshs.turn_left()
    gshs.turn_left()
    gshs.turn_left()

def U_left():
    gshs.turn_left()
    gshs.move()
    gshs.turn_left()

def U_right():
    turn_right()
    gshs.move()
    turn_right()

def ahead(num):
    if gshs.on_beeper():
        gshs.pick_beeper()
    for i in range(0,num):
        gshs.move()
        gshs.pick_beeper()

load_world("worlds/harvest1.wld")
gshs = Robot(beepers=10)
gshs.set_trace('blue')
ahead(6)
U_left()
ahead(5)
U_right()
ahead(5)
U_left()
ahead(5)
U_right()
ahead(5)
U_left()
ahead(5)
