from turtle import Turtle

ALIGNMENT = 'center'
FONT = ("Courier", 24, 'normal')


class Score(Turtle):
    def __init__(self):
        super().__init__()
        self.goto(200,250)
        self.score = -1
        self.refresh_score()

    def refresh_score(self):
        self.color(0,0,0)
        self.write(f"Score: {self.score} ", False, ALIGNMENT, FONT)
        self.goto(200, 250)
        self.color(1, 1, 1)
        self.score += 1
        self.write(f"Score: {self.score} ", False, ALIGNMENT, FONT)
        self.hideturtle()
        self.penup()

    """
    화면 중앙으로 이동후 게임 오버 표시
    """
    def game_over(self):
        self.goto(0,0)
        self.write(f"GAME OVER", False, ALIGNMENT, FONT)
        pass
