from cs1robots import *
load_world("worlds/befair.wld")
gshs = Robot(orientation='E')
gshs.set_trace('red')

gshs2 = Robot(orientation='E',beepers=1000)
gshs2.set_trace('blue')

beeper=[]
target=[]
fair = 0

def turn_right():
    gshs.turn_left()
    gshs.turn_left()
    gshs.turn_left()

def turn_right2():
    gshs2.turn_left()
    gshs2.turn_left()
    gshs2.turn_left()

def givemebeepers():
    temp = 0
    for _ in range(100):
        if gshs.on_beeper():
            gshs.pick_beeper()
            temp+=1
        else:
            break
    beeper.append(temp)
    target.append(gshs.get_pos())
    return temp

def setbeepers(bp):
    for _ in range (len(target)):
        if target[_] == gshs2.get_pos():
          for i in range (int(bp)):
           gshs2.drop_beeper()

gshs.turn_left()
for _ in range(3):
 gshs.move()
turn_right()

for _ in range(13):
 gshs.move()
 if gshs.on_beeper():
     givemebeepers()
gshs.turn_left()

for _ in range(5):
 gshs.move()
gshs.turn_left()

for _ in range(10):
 if gshs.on_beeper():
     givemebeepers()
 gshs.move()
if gshs.on_beeper():
  givemebeepers()
turn_right()

for _ in range(5):
 gshs.move()
turn_right()

for _ in range(10):
 if gshs.on_beeper():
     givemebeepers()
 gshs.move()
if gshs.on_beeper():
  givemebeepers()

print(beeper)
temp = 0
length = len(beeper)
for i in range (len(beeper)):
  temp += beeper.pop()

print("beepers : ",temp)
fair = temp/length
#################################################
gshs2.turn_left()
for _ in range(3):
 gshs2.move()
turn_right2()

for _ in range(13):
 gshs2.move()
 setbeepers(fair)

gshs2.turn_left()

for _ in range(5):
 gshs2.move()
gshs2.turn_left()

for _ in range(10):
 setbeepers(fair)
 gshs2.move()
setbeepers(fair)
turn_right2()

for _ in range(5):
 gshs2.move()
turn_right2()

for _ in range(10):
 setbeepers(fair)
 gshs2.move()
setbeepers(fair)

print("I did it !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!")