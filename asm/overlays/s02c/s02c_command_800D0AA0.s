	opt	c+, at+, e+, n-
	section overlay.text

	xdef s02c_command_800D0AA0
s02c_command_800D0AA0:
	dw 0x3C02800E ; 800D0AA0
	dw 0x03E00008 ; 800D0AA4
	dw 0xAC443CF8 ; 800D0AA8
