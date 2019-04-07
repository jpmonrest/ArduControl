# ArduControl
ArduControl Free - Code for Arduino

With this arduino code you will be able to receive data from ArduControl App.
The application sends 3 values: x and y coordinates for the joystick and a boolean for the button.
The example turns x and y coordinates into 4 global variables wich can be used in your code. (Up, Down, Left, Right) and also gets a 1 for button pressed and a 0 for Button release.



# Note

In the example the HC-05 Module is connected to TX1,RX1 (Serial1) if you want to change Serial Port you will have to change the pins connection and start the Serial port where you connected the module. Example: Serial2.begin() Pins 16-17.

# Important

Try to avoid using TX0, RX0 because those pins are used for uploading code to Arduino and you will have to disconnect your Bluetooth module everytime you upload your code.

# Connection HC-05 - Arduino

VCC - 5V/n
GND - GND
TX - RX
RX - TX
