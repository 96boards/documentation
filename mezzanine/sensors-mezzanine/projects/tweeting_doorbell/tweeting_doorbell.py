import tweepy, serial, datetime, time, keys, pyupm_i2clcd

auth = tweepy.OAuthHandler(keys.consumer_key,
			   keys.consumer_secret)
auth.set_access_token(keys.access_token,
		      keys.access_token_secret)
api = tweepy.API(auth)
ard = serial.Serial('/dev/tty96B0', 115200)
lcd = pyupm_i2clcd.Jhd1313m1(0, 0x3e, 0x62)

def tweet():
	lcd.clear()
	today = datetime.datetime.now()
	lcd.setCursor(0, 0)
	lcd.write("Ding Dong")
	lcd.setCursor(1, 0)
	lcd.write(today.strftime('%Y/%m/%d %H:%M:%S'))
	lcd.setColor(0, 255, 0)

	msg = '(Chatty Doorbell) Ding dong! Someone was at the door at %s' % \
		today.strftime('%d/%m/%Y %H:%M')
	print(msg)
	api.update_status(msg)
	time.sleep(1)

	lcd.setColor(0,0,0)
	lcd.clear()

if __name__ == '__main__':
	lcd.clear()
	lcd.setColor(0, 0, 0)
	print("Welcome to the tweeting doorbell! To quit, press CTRL + C")
	try:
		while True:
			ardOut = ard.readline()
			if ardOut.find("tweet") != -1:
				tweet()
	except KeyboardInterrupt:
		print("CTRL-C!! Exiting...")
