from matplotlib import pyplot as plt
import matplotlib

matplotlib.use('TkAgg')
from matplotlib import animation
import numpy as np


def okay(x, y):
    rx, ry = (x, y)
    if (x < 0):
        rx += 50
    elif (x >= 50):
        rx -= 50
    if (y < 0):
        ry += 50
    elif (y >= 50):
        ry -= 50
    return (rx, ry)


def gol_step(arr):
    a = np.full([50, 50],1)
    for i in range(50):
        for j in range(50):
            cnt = 0
            for dir in range(8):
                (x, y) = okay(i + d[0][dir], j + d[1][dir])
                if (arr[x][y] == 0):
                    cnt += 1
            if (arr[i][j] == 1 and cnt == 3):
                a[i][j] = 0
            elif (arr[i][j] == 0 and (cnt == 2 or cnt == 3)):
                a[i][j] = 0
            else:
                a[i][j] = 1
    return a


def next_step(arr):
    new_arr = gol_step(arr)
    return new_arr


life_map = np.full([50, 50], 1, dtype='int32')
life_map[1][2] = 0
life_map[2][3] = 0
life_map[3][3] = 0
life_map[3][2] = 0
life_map[3][1] = 0

fig = plt.figure()
im = plt.imshow(life_map, animated=True,cmap='gray')
d = [[1, 0, -1, 0, 1, 1, -1, -1], [0, 1, 0, -1, 1, -1, 1, -1]]


def animate(i):
    _map = next_step(im.get_array())
    im.set_array(_map)
    return im,


anim = animation.FuncAnimation(fig, animate, frames=200, interval=100)
# anim.save('glider gun.gif', writer='imagemagick', fps=20, dpi=100)
plt.show()
