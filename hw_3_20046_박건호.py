from cs1robots import *
load_world("worlds/finalMaze.wld")
gshs = Robot(beepers=10)
gshs.set_trace('blue')

while True:
    if gshs.on_beeper():
        gshs.pick_beeper()
        break
    else:
        if gshs.front_is_clear() and not gshs.right_is_clear():
            gshs.move()
        elif gshs.right_is_clear():
            gshs.turn_left()
            gshs.turn_left()
            gshs.turn_left()
            gshs.move()
        elif not gshs.left_is_clear() and not gshs.front_is_clear() and not gshs.right_is_clear():
            gshs.turn_left()
            gshs.turn_left()
            gshs.move()
        elif not gshs.right_is_clear() and not gshs.front_is_clear():
            gshs.turn_left()
            gshs.move()
        elif not gshs.left_is_clear() and not gshs.front_is_clear():
            gshs.turn_left()
            gshs.turn_left()
            gshs.turn_left()
            gshs.move()
        else:
            gshs.move()

print("finish")





