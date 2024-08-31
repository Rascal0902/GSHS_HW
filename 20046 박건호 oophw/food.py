from turtle import Turtle
import random


class Food(Turtle):
    def __init__(self):
        super().__init__()
        self.shapesize(stretch_len=0.5, stretch_wid=0.5)
        self.hideturtle()
        self.penup()
        self.speed(0)
        self.refresh()

    def refresh(self):
        self.dot(20, "black")
        self.goto(250-random.random()*500, 250-random.random()*500)
        self.dot(20,"blue")