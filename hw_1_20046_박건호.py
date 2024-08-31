from cs1robots import *

def rightfunction():
    gshs.turn_left()
    gshs.turn_left()
    gshs.turn_left()

load_world("worlds/hurdles1.wld")
gshs = Robot()
gshs.set_trace('blue')
gshs.move()
for i in range(0,4):
   gshs.turn_left()
   gshs.move()
   rightfunction()
   gshs.move()
   rightfunction()
   gshs.move()
   gshs.turn_left()
   gshs.move()
gshs.pick_beeper()