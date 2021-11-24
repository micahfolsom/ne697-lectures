#!/usr/bin/env python
"""This script is for plotting *everything* in the hits file. Energy depositions
from each event are summed, and the positions are the average of the positions
where energy was deposited."""
import numpy as np
import matplotlib.pyplot as plt 

# So we can index easier
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

# Read in all of the data
#fname = "hits_cs137.csv"
fname = "hits_5keV.csv"
#fname = "hits_100keV.csv"
#fname = "hits_1000keV.csv"
with open("build/" + fname, "r") as f:
    lines = f.readlines()
    lines = [line.split(",") for line in lines]
# lines now contains a list of ['0', '1', 'gamma', ...]. Each row is a list
# where each element is a column

energies = []
pos = {"x": [], "y": [], "z": []}
ievent = 0
# Skip the header
iline = 1
while iline < len(lines):
    line = lines[iline]
    event_id = int(line[EVENT_ID])
    track_id = int(line[TRACK_ID])
    x = float(line[XPOS])
    y = float(line[YPOS])
    z = float(line[ZPOS])
    e = float(line[ENERGY])
    particle = line[PARTICLE]
    process = line[PROCESS]
    n = 1
    
    same_event = True
    inext = 1
    while same_event:
        if iline + inext > (len(lines) - 1):
            break
        next_line = lines[iline + inext]
        next_event_id = int(next_line[EVENT_ID])
        if (next_event_id != event_id):
            same_event = False
            break
        if float(next_line[ENERGY]) > 0.0:
            x += float(next_line[XPOS])
            y += float(next_line[YPOS])
            z += float(next_line[ZPOS])
            e += float(next_line[ENERGY])
            n += 1
        inext += 1

    energies.append(e)
    x /= float(n)
    y /= float(n)
    z /= float(n)
    pos["x"].append(x)
    pos["y"].append(y)
    pos["z"].append(z)
    ievent += 1
    iline += inext

print(f"{ievent} total events read")
# Make a histogram of the energies
plt.figure(figsize=(10,8))
plt.subplot(2,2,1)
# 1 keV bins
plt.hist(energies, bins=np.linspace(0, 1100, 1101))
plt.xlabel("Energy (keV)")
plt.ylabel("Counts")
plt.yscale("log")
# X
plt.subplot(2,2,2)
plt.hist(pos["x"], bins=100)
plt.xlabel("X Pos (cm)")
plt.ylabel("Counts")
# Y
plt.subplot(2,2,3)
plt.hist(pos["y"], bins=100)
plt.xlabel("Y Pos (cm)")
plt.ylabel("Counts")
# Z
plt.subplot(2,2,4)
plt.hist(pos["z"], bins=100)
plt.xlabel("Z Pos (cm)")
plt.ylabel("Counts")
plt.show()
