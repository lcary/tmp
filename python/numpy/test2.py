
import numpy as np
import matplotlib.pyplot as plt

# set the data
x_data = np.linspace(0, 10)
y_data_1 = np.sin(x_data)
y_data_2 = np.cos(x_data)
y_data_3 = [i / 2 for i in y_data_1]
y_data_4 = [j / 2 for j in y_data_2]

# make the plot
ax1 = plt.subplot(2,3,1)
plt.plot(x_data, y_data_1)
plt.setp(ax1.get_xticklabels(), visible=False)

ax2 = plt.subplot(2,3,2, sharey=ax1)
plt.plot(x_data, y_data_1)
plt.plot(x_data, y_data_2)
plt.setp(ax2.get_xticklabels(), visible=False)
plt.setp(ax2.get_yticklabels(), visible=False)

ax3 = plt.subplot(1,3,3)
plt.plot(x_data)

ax4 = plt.subplot(2,3,4, sharex=ax1)
plt.plot(x_data, y_data_1)
plt.plot(x_data, y_data_2)
plt.plot(x_data, y_data_3)

ax5 = plt.subplot(2,3,5, sharex=ax2, sharey=ax4)
plt.plot(x_data, y_data_1)
plt.plot(x_data, y_data_2)
plt.plot(x_data, y_data_3)
plt.plot(x_data, y_data_4)
plt.setp(ax5.get_yticklabels(), visible=False)

plt.show()
