from cs1robots import *
load_world("worlds/ex36.rur.wld")
gshs = Robot(beepers=10)
gshs.set_trace('blue')
a =[]
temp = 0
gshs.move()
while True:
    temp = 0
    while gshs.on_beeper():
        temp+=1
        gshs.pick_beeper()
    a.append(temp)
    if not gshs.front_is_clear():
        break
    else:
        gshs.move()
gshs.turn_left()
gshs.turn_left()
a.sort(reverse=True)
while True:
    if not len(a)==0:
     for i in range (0,a[len(a)-1]):
        gshs.drop_beeper()
     a.pop()
    if not gshs.front_is_clear():
        break
    else:
        gshs.move()

print("finish")