	opt	c+, at+, e+, n-
	section overlay.text

	xdef s02c_command_800CD1EC
s02c_command_800CD1EC:
	dw 0x24020007 ; 800CD1EC
	dw 0xA4820B22 ; 800CD1F0
	dw 0x2402000E ; 800CD1F4
	dw 0xA4820B24 ; 800CD1F8
	dw 0x03E00008 ; 800CD1FC
	dw 0xAC800B28 ; 800CD200
