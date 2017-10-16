from scipy.interpolate import spline
from scipy.interpolate import interp1d
import matplotlib.pyplot as plt
import numpy as np
import collections
from matplotlib.ticker import ScalarFormatter, FormatStrFormatter

t1 = np.arange(1, 35, 1)
t2 = [479772,479772,479772,479772,479772,479772,479772,479772,
     479772,479772,479772,479772,479772,479772,479772,479772,479772,
     479772,479772,479772,479772,479772,479772,479819,479819,479819,
     479819,479819,479819,479878,479878,479878,479878,479878]

P = t2
T = t1

xnew = np.linspace(T.min(),T.max(),33)

P_smooth = spline(T,P,xnew)

f = interp1d(t1, t2, kind='cubic')

fig = plt.figure()
ax = fig.add_subplot(111)
fig.set_size_inches(7, 4, forward=True)
plt.ticklabel_format(useOffset=False)
plt.plot(t1, t2, 'o', xnew, f(xnew), '-')
plt.xlabel('$w$')
plt.ylabel('z')
plt.show()