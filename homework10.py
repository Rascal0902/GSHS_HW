
import turtle

gshs = turtle.Turtle()
win = turtle.Screen()
gshs.color(1,0,0)

def drawtree(gshs, lineLen,R,G,B):
    if lineLen > 0:
        gshs.color(R, G, B)
        gshs.forward(lineLen)
        gshs.right(30)
        drawtree(gshs,lineLen-10,R-0.1,G,B+0.1)
        gshs.color(R, G, B)
        gshs.back(lineLen - 10)
        gshs.left(30)
        gshs.left(30)
        drawtree(gshs,lineLen-10,R-0.1,G,B+0.1)
        gshs.color(R, G, B)
        gshs.back(lineLen - 10)
        gshs.right(30)

gshs.left(90)
drawtree(gshs,70,1,0,0)
gshs.color(1,0,0)
gshs.back(70)
win.exitonclick()