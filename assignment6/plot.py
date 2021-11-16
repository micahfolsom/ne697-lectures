#!/usr/bin/env python
import numpy as np
import matplotlib.pyplot as plt

EVENT_ID = 0
TRACK_ID = 1
PARENT_ID = 2
PARTICLE = 3
PROCESS = 4
VOLUME = 5
XPOS = 6 # cm
YPOS = 7 # cm
ZPOS = 8 # cm
ENERGY = 9 # keV
TIME = 10 # ns

data = np.genfromtxt("build/hits.csv", delimiter=",")
print(f"Read in {len(data)} lines")
# Grab 1 hit from each event
curr_eid = -1
x = []
z = []
counted = False
for i, line in enumerate(data):
    # Only capture 1 hit per event ID
    if curr_eid != line[EVENT_ID]:
        curr_eid = line[EVENT_ID]
        counted = False
    if not counted:
        x.append(line[XPOS])
        z.append(line[ZPOS])
        counted = True
    if (i % 10000) == 0:
        print(f"Processing line {i}")

plt.figure(figsize=(9,6))
_ = plt.hist2d(x, z, bins=100)
plt.xlabel("X Position (cm)")
plt.ylabel("Z Position (cm)")
plt.show()
