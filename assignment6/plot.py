#!/usr/bin/env python
import numpy as np
import matplotlib.pyplot as plt

# To make it easier/more readable later, the indices of each column
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

# Read in the CSV file. String columns will get messed up, but we're not using
# them right now, so it's ok
data = np.genfromtxt("build/hits.csv", delimiter=",")
print(f"Read in {len(data)} lines")
# Grab 1 hit from each event just for simplicity's sake. We want the XZ
# positions to make a nice picture
curr_eid = -1
x = []
z = []
counted = False
for i, line in enumerate(data):
    # Only capture 1 hit per eventID. We keep track of the current eventID,
    # and when we hit the first entry for a new ID, we take that info and
    # skip the rest for that eventID. This isn't the "right" way to do this,
    # but it'll give us a picture. We'll cover event reconstruction later
    if curr_eid != line[EVENT_ID]:
        curr_eid = line[EVENT_ID]
        counted = False
    # If not counted, then add to the list
    if not counted:
        x.append(line[XPOS])
        z.append(line[ZPOS])
        counted = True
    # Provide some helpful output
    if (i % 10000) == 0:
        print(f"Processing line {i}")

plt.figure(figsize=(9,6))
_ = plt.hist2d(x, z, bins=100)
plt.xlabel("X Position (cm)")
plt.ylabel("Z Position (cm)")
plt.show()
