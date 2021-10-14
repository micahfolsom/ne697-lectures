# Lecture 16 In-Class Exercises #

October 14, 2021

## Useful Links ##

[App Dev Guide](https://geant4-userdoc.web.cern.ch/UsersGuides/ForApplicationDeveloper/html/index.html)
[Source code browser](https://geant4.kek.jp/Reference/10.07.p02/)
[Examples info](https://geant4-userdoc.web.cern.ch/UsersGuides/ForApplicationDeveloper/html/Examples/examples.html)
[Geometry documentation](https://geant4-userdoc.web.cern.ch/UsersGuides/ForApplicationDeveloper/html/Detector/Geometry/geomSolids.html)

## Example B1 Exercises ##

Running example B1 and applying light modifications.

1. Create .mac files (run3.mac, run4.mac, run5.mac)
  * Gammas, 511 keV, 100,000 particles
  * Neutrons, 2 MeV, 100,000 particles
  * e-, 1 MeV, 100,000 particles
2. Modify B1EventAction::EndOfEventAction() to output the event number every:
  * 10,000 events
  * 5% of progress
3. Change the size of the G4Cons phantom; double the value of RmaxA, RmaxB, and
  hz
  * Use the visualization to confirm that it changed
4. Change the G4Cons shape to a G4Sphere with a diameter of 10 cm
  * Use the visualization to confirm that it changed
5. Add another reported statistic: eDep^3 (cubed)

## Example B3b Exercises ##

1. Run with 100,000 particles using the default configuration and count the "Nb of good e+ annihilations"
2. Run with N-13 instead of F-18. See the example .mac files for hints on what
  the command is. Does the result change?
3. Change the material from Lu2SiO5 to NaI (use the built-in material from the
  NIST material manager) and run again. Does the result change?
