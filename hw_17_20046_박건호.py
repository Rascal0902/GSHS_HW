import numpy as np
import matplotlib
matplotlib.use('TkAgg')
import matplotlib.pyplot as plt
import matplotlib.animation as animation
from scipy.integrate import *

g = 9.8  # 중력가속도
theta = np.radians(60)  # 각도
l = 1  # 길이
b = 1  # 상수
m = 1  # 질량

def dU_dx(U, t):  #미분 결과 반환
    return [U[1], -b/m*U[1] - g/l*np.sin(U[0])]

U0 = [theta, 0]  # 초기 조건
xs = np.arange(0, 10, 0.05)
Us = odeint(dU_dx, U0, xs)
ys = Us[:, 0]

#기본 설정
fig, ax = plt.subplots()
ax.set(xlim=[-l-0.5, l+0.5], ylim=[-l-0.5, l+0.5])
ax.set_aspect('equal', adjustable='box')
ax.grid(True, linestyle='--')
line, = ax.plot([], [], color='b', linewidth=2)
obj, = ax.plot([], [], 'bo')
time_text = ax.text(-l-0.2, -l-0.2, '')

def init():
    line.set_data([], [])
    return line,

# update
def iterr(i):
    theta = ys[i]
    x = l*np.sin(theta)
    y = -l*np.cos(theta)
    line.set_data([0, x], [0, y])
    obj.set_data([x], [y])
    time_text.set_text('time = {:.1f}'.format(xs[i]))
    return line, obj, time_text

anim = animation.FuncAnimation(fig, iterr, init_func=init, frames=len(ys),interval=0.05*1000, blit=True)
plt.show()