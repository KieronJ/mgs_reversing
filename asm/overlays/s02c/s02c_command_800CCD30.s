	opt	c+, at+, e+, n-
	section overlay.text

	xdef s02c_command_800CCD30
s02c_command_800CCD30:
	dw 0x27BDFFB0 ; 800CCD30
	dw 0xAFB40038 ; 800CCD34
	dw 0x0080A021 ; 800CCD38
	dw 0x26850020 ; 800CCD3C
	dw 0xAFBF004C ; 800CCD40
	dw 0xAFBE0048 ; 800CCD44
	dw 0xAFB70044 ; 800CCD48
	dw 0xAFB60040 ; 800CCD4C
	dw 0xAFB5003C ; 800CCD50
	dw 0xAFB30034 ; 800CCD54
	dw 0xAFB20030 ; 800CCD58
	dw 0xAFB1002C ; 800CCD5C
	dw 0xAFB00028 ; 800CCD60
	dw 0x8E82004C ; 800CCD64
	dw 0x2406FFFF ; 800CCD68
	dw 0x8C570008 ; 800CCD6C
	dw 0x0000A821 ; 800CCD70
	dw 0x0C0171B1 ; 800CCD74
	dw 0x02E02021 ; 800CCD78
	dw 0x305100FF ; 800CCD7C
	dw 0x02E02021 ; 800CCD80
	dw 0x02202821 ; 800CCD84
	dw 0x27A60010 ; 800CCD88
	dw 0x00111040 ; 800CCD8C
	dw 0x8EE30000 ; 800CCD90
	dw 0x00511021 ; 800CCD94
	dw 0x8C630014 ; 800CCD98
	dw 0x000210C0 ; 800CCD9C
	dw 0x0C01745A ; 800CCDA0
	dw 0x0062F021 ; 800CCDA4
	dw 0x24030001 ; 800CCDA8
	dw 0x0220B021 ; 800CCDAC
	dw 0x00409821 ; 800CCDB0
	dw 0x1A600051 ; 800CCDB4
	dw 0xAE830AEC ; 800CCDB8
	dw 0x86820020 ; 800CCDBC
	dw 0x00000000 ; 800CCDC0
	dw 0x0053001A ; 800CCDC4
	dw 0x16600002 ; 800CCDC8
	dw 0x00000000 ; 800CCDCC
	dw 0x0007000D ; 800CCDD0
	dw 0x2401FFFF ; 800CCDD4
	dw 0x16610004 ; 800CCDD8
	dw 0x3C018000 ; 800CCDDC
	dw 0x14410002 ; 800CCDE0
	dw 0x00000000 ; 800CCDE4
	dw 0x0006000D ; 800CCDE8
	dw 0x00009010 ; 800CCDEC
	dw 0x00000000 ; 800CCDF0
	dw 0x06410002 ; 800CCDF4
	dw 0x02B3102A ; 800CCDF8
	dw 0x00129023 ; 800CCDFC
	dw 0x1040003F ; 800CCE00
	dw 0x02802021 ; 800CCE04
	dw 0x00121080 ; 800CCE08
	dw 0x03A21021 ; 800CCE0C
	dw 0x8E83004C ; 800CCE10
	dw 0x8C510010 ; 800CCE14
	dw 0x8C630008 ; 800CCE18
	dw 0x00111040 ; 800CCE1C
	dw 0x8C630000 ; 800CCE20
	dw 0x00511021 ; 800CCE24
	dw 0x8C630014 ; 800CCE28
	dw 0x000210C0 ; 800CCE2C
	dw 0x00628021 ; 800CCE30
	dw 0x0C033211 ; 800CCE34
	dw 0x02002821 ; 800CCE38
	dw 0x14400024 ; 800CCE3C
	dw 0x24040001 ; 800CCE40
	dw 0x86020016 ; 800CCE44
	dw 0x0C00C589 ; 800CCE48
	dw 0x00442004 ; 800CCE4C
	dw 0x10400012 ; 800CCE50
	dw 0x00000000 ; 800CCE54
	dw 0x94420006 ; 800CCE58
	dw 0x00000000 ; 800CCE5C
	dw 0x14400006 ; 800CCE60
	dw 0x00000000 ; 800CCE64
	dw 0x87C30016 ; 800CCE68
	dw 0x86020016 ; 800CCE6C
	dw 0x00000000 ; 800CCE70
	dw 0x14620016 ; 800CCE74
	dw 0x00000000 ; 800CCE78
	dw 0x02802021 ; 800CCE7C
	dw 0x02C02821 ; 800CCE80
	dw 0x0C033313 ; 800CCE84
	dw 0x02203021 ; 800CCE88
	dw 0x10400006 ; 800CCE8C
	dw 0x00000000 ; 800CCE90
	dw 0x080333B5 ; 800CCE94
	dw 0x26520001 ; 800CCE98
	dw 0x3C04800E ; 800CCE9C
	dw 0x0C022EE8 ; 800CCEA0
	dw 0x248432F4 ; 800CCEA4
	dw 0x0C034292 ; 800CCEA8
	dw 0x02202021 ; 800CCEAC
	dw 0x14400008 ; 800CCEB0
	dw 0x26520001 ; 800CCEB4
	dw 0x82840B78 ; 800CCEB8
	dw 0x02202821 ; 800CCEBC
	dw 0x0C03428C ; 800CCEC0
	dw 0xAE800AEC ; 800CCEC4
	dw 0x080333C0 ; 800CCEC8
	dw 0x00000000 ; 800CCECC
	dw 0x26520001 ; 800CCED0
	dw 0x0253102A ; 800CCED4
	dw 0x14400002 ; 800CCED8
	dw 0x02C08821 ; 800CCEDC
	dw 0x00009021 ; 800CCEE0
	dw 0x26B50001 ; 800CCEE4
	dw 0x02B3102A ; 800CCEE8
	dw 0x1440FFC6 ; 800CCEEC
	dw 0x02802021 ; 800CCEF0
	dw 0x080333C0 ; 800CCEF4
	dw 0x00000000 ; 800CCEF8
	dw 0xAE800AEC ; 800CCEFC
	dw 0x8EE30000 ; 800CCF00
	dw 0x00111200 ; 800CCF04
	dw 0x8C630014 ; 800CCF08
	dw 0x00511025 ; 800CCF0C
	dw 0xAE820BF4 ; 800CCF10
	dw 0x00111040 ; 800CCF14
	dw 0x00511021 ; 800CCF18
	dw 0x000210C0 ; 800CCF1C
	dw 0x00621821 ; 800CCF20
	dw 0x94620000 ; 800CCF24
	dw 0x00000000 ; 800CCF28
	dw 0xA6820BE0 ; 800CCF2C
	dw 0x94620004 ; 800CCF30
	dw 0x00000000 ; 800CCF34
	dw 0xA6820BE2 ; 800CCF38
	dw 0x3C02800E ; 800CCF3C
	dw 0x8C423CF4 ; 800CCF40
	dw 0x94630002 ; 800CCF44
	dw 0xAE820BF8 ; 800CCF48
	dw 0xA6830BE4 ; 800CCF4C
	dw 0x8FBF004C ; 800CCF50
	dw 0x8FBE0048 ; 800CCF54
	dw 0x8FB70044 ; 800CCF58
	dw 0x8FB60040 ; 800CCF5C
	dw 0x8FB5003C ; 800CCF60
	dw 0x8FB40038 ; 800CCF64
	dw 0x8FB30034 ; 800CCF68
	dw 0x8FB20030 ; 800CCF6C
	dw 0x8FB1002C ; 800CCF70
	dw 0x8FB00028 ; 800CCF74
	dw 0x03E00008 ; 800CCF78
	dw 0x27BD0050 ; 800CCF7C
