	opt	c+, at+, e+, n-
	section overlay.text

	xdef s02c_command_800D0A30
s02c_command_800D0A30:
	dw 0x3C02800E ; 800D0A30
	dw 0x24423B70 ; 800D0A34
	dw 0x00042080 ; 800D0A38
	dw 0x00822021 ; 800D0A3C
	dw 0x03E00008 ; 800D0A40
	dw 0xAC850148 ; 800D0A44
