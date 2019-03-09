import numpy as np
import matplotlib.pyplot as plt


# Create a grid or atlas that we will draw on
# This is also a region in the complex plane

# for each complex number in this grid, compute the number of iterations
# requires to reach the escape critera or max_iter in the case the complex number doesn't escpae (could be in mandelbrot)
# plot a colour for each pixel in the atlas in accordance with iterations required for escape.

x_values = np.linspace(-1.3, 1.3, 1000)
y_values = np.linspace(-2, 1, 1000)

def mandel(c, maxiter):
    z = complex(0, 0)
    for i in range(maxiter):
        z = (z*z) + c
        if abs(z) > 4:
            break
    return i

atlas = np.zeros((len(x_values), len(y_values)))

for x in range(len(x_values)):
    for y in range(len(y_values)):
        c = complex(x_values[x], y_values[y])
        atlas[x, y] = mandel(c, 500)

plt.imshow(atlas.T, interpolation="nearest", cmap="jet")
plt.show()
