	opt	c+, at+, e+, n-
	section overlay.text

	xdef s02c_command_800D0F90
s02c_command_800D0F90:
	dw 0x3C02800E ; 800D0F90
	dw 0x8C433B7C ; 800D0F94
	dw 0x00000000 ; 800D0F98
	dw 0x0064001A ; 800D0F9C
	dw 0x14800002 ; 800D0FA0
	dw 0x00000000 ; 800D0FA4
	dw 0x0007000D ; 800D0FA8
	dw 0x2401FFFF ; 800D0FAC
	dw 0x14810004 ; 800D0FB0
	dw 0x3C018000 ; 800D0FB4
	dw 0x14610002 ; 800D0FB8
	dw 0x00000000 ; 800D0FBC
	dw 0x0006000D ; 800D0FC0
	dw 0x00001010 ; 800D0FC4
	dw 0x03E00008 ; 800D0FC8
	dw 0x00000000 ; 800D0FCC
