#serial is used to communicate with the COM4 to which the Arduino is connected.

#Note: For detailed [LOG] and [INFO] have a look at the Stable_Movement.cpp code.

#------------------------------------------------------------------------------#

import serial
def byte_sender(var,ser):
	var_bytes=str.encode(var)
	print(type(var_bytes))
	ser.write(var_bytes)