import numpy as np
import matplotlib.pyplot as plt
import re
import os


path = "my_path"
path_csv = "my_path_2"
directory = os.listdir(path)
directory_csv = os.listdir(path_csv)


x = []
y = []
z = []
h = []
oh = []
h4sio4 = []
mg = []
co3 = []
cro4 = []
ni = []

for k in directory:
    for f in directory_csv:
        if k.endswith('.gst'):
            if f.endswith('.csv'):
                full_path_gst = os.path.join(path, k)
                full_path_csv = os.path.join(path_csv, f)
                print full_path_csv
                with open(full_path_gst) as input_file_gst, open(full_path_csv) as input_file_csv:
                    x, y, z, h, oh, h4sio4, na, mg, co3, cro4, ni = np.loadtxt(input_file_gst, skiprows=3, unpack=True)
                #with open(full_path_csv) as input_file_csv:
                    Z_s, Fe_S, Al_S, Ca_S, Cl_S, Mg_S, DSi_S, K_S, F_S, NO3_S, SO4_S, pH_S, Cr_S, Ni_S, Na_S, Cr_S_BL, Ni_S_BL=np.loadtxt(input_file_csv, delimiter=",", unpack=True)

                    regex = re.compile(r'\d+')  # (r'\d+')
                a = regex.findall(k)
                b = regex.findall(f)
                plt.figure(figsize=(25, 10))
                plt.subplot(221)
                # plt.plot(mg * 10 ** (3), z)  # label='Ni^{+2}'
                plt.plot(mg, z, Mg_S, Z_s, 'ro')  # label='Ni^{+2}'
                axes = plt.gca()
                axes.set_xlim([0, 10])
                # axes.set_ylim([ymin, ymax])
                # plt.xlabel('Mg [mmol/l]')
                plt.xlabel('Mg [mol/l]')
                plt.ylabel('Height above bottom [m]')
                plt.title("Day = {0:10.9s} ".format(a))  # time = %.1f'%
                # plt.legend()
                plt.subplot(222)
                plt.plot(h4sio4, z, DSi_S, Z_s, 'ro')  # label='Ni^{+2}'
                axes = plt.gca()
                axes.set_xlim([0, 1])
                # plt.xlabel('DSi [mmol/l]')
                plt.xlabel('DSi [mol/l]')
                plt.ylabel('Height above bottom [m]')
                # plt.title(" $Day = {1:6.3f}$")#.format(0.0, i))#time = %.1f'%
                # plt.legend()
                plt.subplot(223)
                # plt.plot(ni * 10 ** (9), z)  # label='Ni^{+2}'
                plt.plot(ni, z, Ni_S, Z_s, 'ro')  # label='Ni^{+2}'
                axes = plt.gca()
                axes.set_xlim([0, 1])
                # plt.xlabel('Ni [nmol/l]')
                plt.xlabel('Ni [mol/l]')
                plt.ylabel('Height above bottom [m]')
                # plt.title(" $Day = {1:6.3f}$")#.format(0.0, i))#time = %.1f'%
                # plt.legend()
                plt.subplot(224)
                # plt.plot(cro4 * 10 ** (6), z)  # label='Ni^{+2}'
                plt.plot(cro4, z, Cr_S, Z_s, 'ro')  # label='Ni^{+2}'
                axes = plt.gca()
                axes.set_xlim([0, 1])
                plt.xlabel('CrO4-2 [mol/l]')
                # plt.xlabel('CrO4-2 [micromol/l]')
                plt.ylabel('Height above bottom [m]')
                # plt.title(" $Day = {1:6.3f}$")#.format(0.0, i))#time = %.1f'%
                # plt.legend()
                plt.savefig('Mesocosm_' + str(b) + '.png')
                plt.show(block=False)
                #time.sleep(5)
                plt.close()
