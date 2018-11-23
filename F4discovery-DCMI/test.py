#!/usr/bin/python

import serial
import struct
import time

s = serial.Serial()
s.port = "/dev/ttyUSB0"
s.baudrate = 460800
s.bytesize = serial.EIGHTBITS
s.parity = serial.PARITY_NONE
s.stopbits = serial.STOPBITS_ONE
s.timeout = 2
s.xonxoff = False
s.rtscts = False
s.dsrdtr = False

s.open()



while True:
	r = s.readline().strip()
	if r[:4] == "ffd8":
		try:
			b = r.decode("hex")
			print "len = %d" % len(b)

			with open("test.jpg", "w") as f:
				f.write(b)


		except Exception, e:
			print "decoding failed " + str(e)

