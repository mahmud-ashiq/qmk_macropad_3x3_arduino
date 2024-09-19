# 3X3 Macropad with Arduino Pro Micro and QMK Firmware

<p style="font-size:20px;">A rotary encoder is included in this 3X3 macropad.  Every key has a unique set of functions. The macropad is built with an Arduino which is operating using <a href="https://github.com/qmk/qmk_firmware">QMK Firmware.</a> </p>

## Component List
<p style="font-size:20px;">
1. Arduino Pro Micro <br>
2. Push Buttons <br>
3. 1N4148 Diode <br>
4. 360 Rotary Encoder <br>
5. LED <br>
6. Resistor
</p>

![plot](./pictures/components.png)

<br>

## 3X3 Key Matrix Schematic
<p style="font-size:20px;"> To lower the pin count, every switch is connected in a matrix. Every switch uses a switching diode (1N4148) to prevent conflicts. </p>

<br>

![plot](./pictures/key_matrix_schematic.png)

<br>

## Arduino Connection Schematic
<p style="font-size:20px;"> Pins of ROWs, COLs and Encoder is connected to Arduino. Additionally, there is a linked LED that shows whether the second layer of the macropad is on or off. To flash the firmware the reset switch will be needed. </p>

<br>

![plot](./pictures/arduino_connection_schematic.png)
