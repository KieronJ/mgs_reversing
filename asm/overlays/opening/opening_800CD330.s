	opt	c+, at+, e+, n-
	section overlay.text

	xdef opening_800CD330
opening_800CD330:
	dw 0x24020003 ; 800CD330
	dw 0xA0820003 ; 800CD334
	dw 0x24020060 ; 800CD338
	dw 0x03E00008 ; 800CD33C
	dw 0xA0820007 ; 800CD340
	dw 0x00000000 ; 800CD344
	dw 0x00000000 ; 800CD348
	dw 0x00000000 ; 800CD34C
