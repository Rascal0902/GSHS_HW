
import sys
from tkinter import *
import random
import time
def close_window():
    global running
    running = False
    print("Close game")
app = Tk()
app.title("Simple Game")
app.protocol("WM_DELETE_WINDOW", close_window)
canvas = Canvas(app, width=500, height=500)
canvas.pack()
canvas.update()
scoreboard = Label(app, text="0")
scoreboard.pack(side="left")
class Ball:
    def __init__(self, canvas, paddle, color):
        self.canvas = canvas
        self.paddle = paddle
        self.id = self.canvas.create_oval(10, 10, 25, 25, fill=color)
        self.canvas.move(self.id, 250, 250)
        starts = [-3, -2, -1, 1, 2, 3]
        random.shuffle(starts)
        self.x = starts[0]
        self.y = -3
        self.canvas_height = self.canvas.winfo_height()
        self.canvas_width = self.canvas.winfo_width()
        self.hit_bottom = False

        self.score = 0

    def hit(self, pos):
        paddle_pos = self.canvas.coords(self.paddle.id)
        x, y = (pos[0]+pos[2]) / 2, (pos[1]+pos[3]) / 2
        if paddle_pos[0] <= x <= paddle_pos[2] and paddle_pos[1] <= y <= paddle_pos[3]:
            self.score += 1
            return True
        return False

    def draw(self):
        self.canvas.move(self.id, self.x, self.y)
        pos = self.canvas.coords(self.id)
        print(pos)
        if pos[1] <= 0:
            self.y = 3
        if pos[3] >= self.canvas_height:
            self.y = -3
        if pos[3] >= self.canvas_height:
            self.hit_bottom = True
        if self.hit(pos) == True:
            self.y = -3
        if pos[0] <= 0:
            self.x = 3
        if pos[2] >= self.canvas_width:
            self.x = -3

tim=0
class Paddle:
    def __init__(self, canvas, color):
        self.canvas = canvas
        self.id = canvas.create_rectangle(0, 0, 100, 10, fill=color)
        self.canvas.move(self.id, 150, 400)

        self.x = 0
        self.y = 0
        self.canvas_width = self.canvas.winfo_width()

        app.bind("<Right>", self.turn_right)
        app.bind("<Left>", self.turn_left)

    def turn_left(self, event):
        global tim;
        if(tim % 6 < 3):
         self.x = -10
        else:
         self.x = -5

    def turn_right(self, event):
        global tim;
        if (tim % 6 < 3):
            self.x = 10
        else:
            self.x = 5

    def draw(self):
        self.canvas.move(self.id, self.x, self.y)


paddle = Paddle(canvas, 'blue')
ball = Ball(canvas, paddle, 'red')

running = True
while running:
    if not running:
        break

    tim+=1
    if ball.hit_bottom != True:
        ball.draw()
        paddle.draw()

        score = "점수 : %d" % ball.score
        scoreboard.config(text=score)
        scoreboard.update_idletasks()

        app.update()
        time.sleep(0.01)
        continue
    running = False
    break

sys.exit()
