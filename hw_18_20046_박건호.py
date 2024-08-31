import math
from tkinter import *
import random
import time
app = Tk()
app.title("Bouncing Ball")
canvas = Canvas(app, width=500, height=500)
canvas.pack()
canvas.update()
pixels = 30
ballnum = 10
dt = 0.01
g = 10 * pixels
e = 0.7
class Ball:
    def __init__(self):
        self.x = random.uniform(0, 500)
        self.y = random.uniform(0, 500)
        self.vx = random.uniform(-10, 10) * pixels
        self.vy = random.uniform(-10, 10) * pixels
        self.ax = 0
        self.ay = g
        self.r = random.uniform(5, 10)
        self.color = '#' + ("%02x" % random.randint(0, 255)) + ("%02x" % random.randint(0, 255)) + ("%02x" % random.randint(0, 255))
        self.object = canvas.create_oval(self.x-self.r, self.y-self.r, self.x+self.r, self.y+self.r, fill=self.color)
    def update(self):
        if not self.r < self.x < 500-self.r:
            if self.vx * (self.r-self.x) < 0:
                self.vx = -e * self.vx
        if 500-self.y < self.r:
            if self.vy * (500-self.y-self.r) < 0:
                self.vy = -e * self.vy
        coor = canvas.coords(self.object)
        self.x = 1/2 * (coor[0]+coor[2])
        self.y = 1/2 * (coor[1]+coor[3])

        canvas.move(self.object, dt*self.vx, dt*self.vy)
        self.vx += dt * self.ax
        self.vy += dt * self.ay

balls = [Ball() for i in range(ballnum)]
while True:
    for ball in balls:
        ball.update()
    time.sleep(dt)
    app.update()
app.mainloop()
sys.exit()