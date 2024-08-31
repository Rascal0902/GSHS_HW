from cs1robots import *
load_world("worlds/getbeepers.wld")
gshs = Robot(orientation='E')
gshs.set_trace('red')

def turn_right():
    gshs.turn_left()
    gshs.turn_left()
    gshs.turn_left()

gshs.turn_left()
for _ in range(3):
 gshs.move()
turn_right()

for _ in range(13):
 gshs.move()
 if gshs.on_beeper():
     gshs.pick_beeper()
gshs.turn_left()

for _ in range(5):
 gshs.move()
gshs.turn_left()

for _ in range(10):
 if gshs.on_beeper():
     gshs.pick_beeper()
 gshs.move()
if gshs.on_beeper():
  gshs.pick_beeper()
turn_right()

for _ in range(5):
 gshs.move()
turn_right()

for _ in range(10):
 if gshs.on_beeper():
     gshs.pick_beeper()
 gshs.move()
if gshs.on_beeper():
  gshs.pick_beeper()

print("I did it !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!")