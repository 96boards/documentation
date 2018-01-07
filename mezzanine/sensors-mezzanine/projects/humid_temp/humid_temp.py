import serial, pyupm_i2clcd

ard = serial.Serial('/dev/tty96B0', 9600)
lcd = pyupm_i2clcd.Jhd1313m1(0, 0x3e, 0x62)

def showTemp(humid, temp):
	lcd.clear()
	lcd.setCursor(0, 0)
	lcd.write(humid)
	lcd.setCursor(1, 0)
	lcd.write("Temp:" + temp + " C")
	lcd.setColor(255, 180, 180)

if __name__ == '__main__':
	print("Welcome to the Humidity & Temperature reader!!!")
	try:
		while True:
			ardOut = ard.readline()
			if ardOut.find("Humidity:") != -1:
				ardHumid = ardOut.split('Temperature')[0]
				ardTemp = ardOut.split('Temperature:')[1]
				showTemp(ardHumid,ardTemp)
	except KeyboardInterrupt:
		lcd.setColor(0,0,0)
		lcd.clear()
		print("CTRL-C!! Exiting...")
