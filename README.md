# Haptic-feedback-as-sensory-substitution
The following repository is a project attempting to create an open source solution for using haptics as sensory substitution for people with peripheral neuropathy.
I have noticed that the solution of haptic feedback is something which has been proposed in literature for a while. However, offering up designs and code to build forward with is something that has been lacking. That's why I created this repository, to try and create a starting point for more creators to have a basis to start from. 

# Current system information
The system consists of a sensorpad that measures the pressure of the device and relays this through a wired connection to the controller board. 
The components used for the system are: 
- 6x Force sensitive resistors 
- 6x 100kOhm Resistors
- Teensy 3.2


The connections of the controller board can be seen on the schematic below
![Schematic](https://github.com/max-1200/Haptic-feedback-as-sensory-substitution/blob/main/Schematics/Print%20Schematic.png)

Image of the soldered and connected controller board in casing
![Schematic](https://github.com/max-1200/Haptic-feedback-as-sensory-substitution/blob/main/Pictures/IMG_20250605_113526931.png)

Image of the insole with the inlayed wires
![Schematic](https://github.com/max-1200/Haptic-feedback-as-sensory-substitution/blob/main/Pictures/IMG_20250605_105818688.png)

# Future development
- Testing various placements of the haptic feedback on the body
- Creating smaller electronics solutions
- Easier to distinguish haptics
- Creating a wireless connection between sensors and insole.
