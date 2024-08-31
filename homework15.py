from matplotlib import pyplot as plt
import matplotlib
matplotlib.use('TkAgg')
from matplotlib import animation
import numpy as np

def next_step(arr):
	r, c = arr.shape
	ref = np.block([[arr]*3]*3)
	zero = np.zeros((3,3),dtype='int32')
	new_arr = np.zeros((r,c),dtype='int32')
	for i in range(r):
		for j in range(c):
			v = ref[i+r-1:i+r+2,j+c-1:j+c+2]
			if (v==zero).all() or np.sum(v)>4 or np.sum(v)<3:
				new_arr[i,j] = 0
			else:
				new_arr[i,j] = 1 if np.sum(v)==3 or (v[1,1]==1 and np.sum(v)==4) else 0
	return new_arr

gshs =np.array(
[
	[0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0],
	[0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0],
	[0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1],
	[0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1],
	[1,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0],
	[1,1,0,0,0,0,0,0,0,0,1,0,0,0,1,0,1,1,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0],
	[0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0],
	[0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],
	[0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]
])

life_map = np.zeros((60,60),dtype='int32')
life_map[1:10,1:37]=gshs

fig = plt.figure()
im = plt.imshow(life_map,animated=True,cmap='gray')

def animate(i):
	_map = next_step(im.get_array())
	im.set_array(_map)
	return im,

anim = animation.FuncAnimation(fig, animate, frames=300, blit=True)
# anim.save('glider gun.gif', writer='imagemagick', fps=20, dpi=100)
plt.show()

