	opt	c+, at+, e+, n-
	section overlay.text

	xdef s02c_command_800CD274
s02c_command_800CD274:
	dw 0x24020001 ; 800CD274
	dw 0xA4820B20 ; 800CD278
	dw 0x24020009 ; 800CD27C
	dw 0xA4820B22 ; 800CD280
	dw 0x2402001B ; 800CD284
	dw 0xA4820B24 ; 800CD288
	dw 0x24020020 ; 800CD28C
	dw 0xAC820B28 ; 800CD290
	dw 0x24020001 ; 800CD294
	dw 0x03E00008 ; 800CD298
	dw 0xAC820B3C ; 800CD29C
