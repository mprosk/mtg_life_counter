EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr B 17000 11000
encoding utf-8
Sheet 1 1
Title ""
Date "2020-08-03"
Rev "0.1"
Comp "Max Proskauer"
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L MCU_Module:Arduino_Nano_v3.x A?
U 1 1 5F28B68A
P 3000 5000
F 0 "A?" H 2650 5950 50  0000 C CNN
F 1 "Arduino_Nano_v3.x" H 3500 4050 50  0000 C CNN
F 2 "Module:Arduino_Nano" H 3150 4050 50  0001 L CNN
F 3 "http://www.mouser.com/pdfdocs/Gravitech_Arduino_Nano3_0.pdf" H 3000 4000 50  0001 C CNN
	1    3000 5000
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push SW?
U 1 1 5F28CE77
P 1650 4100
F 0 "SW?" H 1650 4385 50  0000 C CNN
F 1 "SW_Push" H 1650 4294 50  0000 C CNN
F 2 "" H 1650 4300 50  0001 C CNN
F 3 "~" H 1650 4300 50  0001 C CNN
	1    1650 4100
	1    0    0    -1  
$EndComp
$Comp
L mtg_life_counter:SW_SP4T SW?
U 1 1 5F291A31
P 15800 1700
F 0 "SW?" H 15800 2033 50  0000 C CNN
F 1 "SW_SP4T" H 15800 1942 50  0000 C CNN
F 2 "" H 15175 1925 50  0001 C CNN
F 3 "~" H 15175 1925 50  0001 C CNN
	1    15800 1700
	-1   0    0    -1  
$EndComp
$Comp
L 74xx:74HC595 U?
U 1 1 5F292D64
P 5950 1950
F 0 "U?" H 5950 2731 50  0000 C CNN
F 1 "74HC595" H 5950 2640 50  0000 C CNN
F 2 "" H 5950 1950 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/sn74hc595.pdf" H 5950 1950 50  0001 C CNN
	1    5950 1950
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74LS151 U?
U 1 1 5F293C96
P 14250 2150
F 0 "U?" H 14500 2900 50  0000 C CNN
F 1 "74LS151" H 14050 2900 50  0000 C CNN
F 2 "" H 14250 2150 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74LS151" H 14250 2150 50  0001 C CNN
	1    14250 2150
	-1   0    0    -1  
$EndComp
$Comp
L Interface_Expansion:TPIC6595 U?
U 1 1 5F295017
P 11050 2650
F 0 "U?" H 11400 3250 50  0000 C CNN
F 1 "TPIC6595" H 11250 1950 50  0000 C CNN
F 2 "" H 11700 2000 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/tpic6595.pdf" H 11050 2600 50  0001 C CNN
	1    11050 2650
	-1   0    0    -1  
$EndComp
$Comp
L Device:R_Network08_US RN?
U 1 1 5F29A778
P 15200 1250
F 0 "RN?" H 14900 1550 50  0000 L CNN
F 1 "1000" H 14900 1450 50  0000 L CNN
F 2 "Resistor_THT:R_Array_SIP9" V 15675 1250 50  0001 C CNN
F 3 "http://www.vishay.com/docs/31509/csc.pdf" H 15200 1250 50  0001 C CNN
	1    15200 1250
	1    0    0    -1  
$EndComp
$Comp
L mtg_life_counter:SW_SP4T SW?
U 1 1 5F2A2895
P 15800 2100
F 0 "SW?" H 15800 1850 50  0000 C CNN
F 1 "SW_SP4T" H 15800 1750 50  0000 C CNN
F 2 "" H 15175 2325 50  0001 C CNN
F 3 "~" H 15175 2325 50  0001 C CNN
	1    15800 2100
	-1   0    0    -1  
$EndComp
$Comp
L power:+5V #PWR?
U 1 1 5F2A4AB1
P 14800 950
F 0 "#PWR?" H 14800 800 50  0001 C CNN
F 1 "+5V" H 14815 1123 50  0000 C CNN
F 2 "" H 14800 950 50  0001 C CNN
F 3 "" H 14800 950 50  0001 C CNN
	1    14800 950 
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5F2A53D9
P 16100 2200
F 0 "#PWR?" H 16100 1950 50  0001 C CNN
F 1 "GND" H 16105 2027 50  0000 C CNN
F 2 "" H 16100 2200 50  0001 C CNN
F 3 "" H 16100 2200 50  0001 C CNN
	1    16100 2200
	1    0    0    -1  
$EndComp
Wire Wire Line
	16000 1700 16100 1700
Wire Wire Line
	16100 1700 16100 2100
Wire Wire Line
	16000 2100 16100 2100
Connection ~ 16100 2100
Wire Wire Line
	16100 2100 16100 2200
Wire Wire Line
	14750 1550 14800 1550
Wire Wire Line
	14750 1650 14900 1650
Wire Wire Line
	14750 1750 15000 1750
Wire Wire Line
	14750 1850 15100 1850
Wire Wire Line
	14750 1950 15200 1950
Wire Wire Line
	14750 2050 15300 2050
Wire Wire Line
	14750 2150 15400 2150
Wire Wire Line
	14750 2250 15500 2250
Wire Wire Line
	14800 950  14800 1050
Wire Wire Line
	14800 1450 14800 1550
Connection ~ 14800 1550
Wire Wire Line
	14800 1550 15600 1550
Wire Wire Line
	14900 1450 14900 1650
Connection ~ 14900 1650
Wire Wire Line
	14900 1650 15600 1650
Wire Wire Line
	15000 1450 15000 1750
Connection ~ 15000 1750
Wire Wire Line
	15000 1750 15600 1750
Wire Wire Line
	15100 1450 15100 1850
Connection ~ 15100 1850
Wire Wire Line
	15100 1850 15600 1850
Wire Wire Line
	15200 1450 15200 1950
Connection ~ 15200 1950
Wire Wire Line
	15200 1950 15600 1950
Wire Wire Line
	15300 1450 15300 2050
Connection ~ 15300 2050
Wire Wire Line
	15300 2050 15600 2050
Wire Wire Line
	15400 1450 15400 2150
Connection ~ 15400 2150
Wire Wire Line
	15400 2150 15600 2150
Wire Wire Line
	15500 1450 15500 2250
Connection ~ 15500 2250
Wire Wire Line
	15500 2250 15600 2250
Text Label 15100 2450 2    50   ~ 0
SEL_0
Text Label 15100 2550 2    50   ~ 0
SEL_1
Text Label 15100 2650 2    50   ~ 0
SEL_2
Wire Wire Line
	15100 2450 14750 2450
Wire Wire Line
	14750 2550 15100 2550
Wire Wire Line
	14750 2650 15100 2650
$Comp
L power:GND #PWR?
U 1 1 5F2E233A
P 14750 3150
F 0 "#PWR?" H 14750 2900 50  0001 C CNN
F 1 "GND" H 14755 2977 50  0000 C CNN
F 2 "" H 14750 3150 50  0001 C CNN
F 3 "" H 14750 3150 50  0001 C CNN
	1    14750 3150
	1    0    0    -1  
$EndComp
Wire Wire Line
	14250 3150 14750 3150
Wire Wire Line
	14750 2850 14750 3150
Connection ~ 14750 3150
$Comp
L power:+5V #PWR?
U 1 1 5F2E3AF9
P 14250 1150
F 0 "#PWR?" H 14250 1000 50  0001 C CNN
F 1 "+5V" H 14265 1323 50  0000 C CNN
F 2 "" H 14250 1150 50  0001 C CNN
F 3 "" H 14250 1150 50  0001 C CNN
	1    14250 1150
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C?
U 1 1 5F2E5300
P 14050 1150
F 0 "C?" V 13821 1150 50  0000 C CNN
F 1 "C_Small" V 13912 1150 50  0000 C CNN
F 2 "" H 14050 1150 50  0001 C CNN
F 3 "~" H 14050 1150 50  0001 C CNN
	1    14050 1150
	0    1    1    0   
$EndComp
Wire Wire Line
	14150 1150 14250 1150
Connection ~ 14250 1150
Wire Wire Line
	14250 1150 14250 1250
$Comp
L power:GND #PWR?
U 1 1 5F2E830C
P 13850 1150
F 0 "#PWR?" H 13850 900 50  0001 C CNN
F 1 "GND" H 13855 977 50  0000 C CNN
F 2 "" H 13850 1150 50  0001 C CNN
F 3 "" H 13850 1150 50  0001 C CNN
	1    13850 1150
	1    0    0    -1  
$EndComp
Wire Wire Line
	13850 1150 13950 1150
$Comp
L mtg_life_counter:SW_SP4T SW?
U 1 1 5F30035C
P 15800 4500
F 0 "SW?" H 15800 4833 50  0000 C CNN
F 1 "SW_SP4T" H 15800 4742 50  0000 C CNN
F 2 "" H 15175 4725 50  0001 C CNN
F 3 "~" H 15175 4725 50  0001 C CNN
	1    15800 4500
	-1   0    0    -1  
$EndComp
$Comp
L 74xx:74LS151 U?
U 1 1 5F300362
P 14250 4950
F 0 "U?" H 14500 5700 50  0000 C CNN
F 1 "74LS151" H 14050 5700 50  0000 C CNN
F 2 "" H 14250 4950 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74LS151" H 14250 4950 50  0001 C CNN
	1    14250 4950
	-1   0    0    -1  
$EndComp
$Comp
L Device:R_Network08_US RN?
U 1 1 5F300368
P 15200 4050
F 0 "RN?" H 14900 4350 50  0000 L CNN
F 1 "1000" H 14900 4250 50  0000 L CNN
F 2 "Resistor_THT:R_Array_SIP9" V 15675 4050 50  0001 C CNN
F 3 "http://www.vishay.com/docs/31509/csc.pdf" H 15200 4050 50  0001 C CNN
	1    15200 4050
	1    0    0    -1  
$EndComp
$Comp
L mtg_life_counter:SW_SP4T SW?
U 1 1 5F30036E
P 15800 4900
F 0 "SW?" H 15800 4650 50  0000 C CNN
F 1 "SW_SP4T" H 15800 4550 50  0000 C CNN
F 2 "" H 15175 5125 50  0001 C CNN
F 3 "~" H 15175 5125 50  0001 C CNN
	1    15800 4900
	-1   0    0    -1  
$EndComp
$Comp
L power:+5V #PWR?
U 1 1 5F300374
P 14800 3750
F 0 "#PWR?" H 14800 3600 50  0001 C CNN
F 1 "+5V" H 14815 3923 50  0000 C CNN
F 2 "" H 14800 3750 50  0001 C CNN
F 3 "" H 14800 3750 50  0001 C CNN
	1    14800 3750
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5F30037A
P 16100 5000
F 0 "#PWR?" H 16100 4750 50  0001 C CNN
F 1 "GND" H 16105 4827 50  0000 C CNN
F 2 "" H 16100 5000 50  0001 C CNN
F 3 "" H 16100 5000 50  0001 C CNN
	1    16100 5000
	1    0    0    -1  
$EndComp
Wire Wire Line
	16000 4500 16100 4500
Wire Wire Line
	16100 4500 16100 4900
Wire Wire Line
	16000 4900 16100 4900
Connection ~ 16100 4900
Wire Wire Line
	16100 4900 16100 5000
Wire Wire Line
	14750 4350 14800 4350
Wire Wire Line
	14750 4450 14900 4450
Wire Wire Line
	14750 4550 15000 4550
Wire Wire Line
	14750 4650 15100 4650
Wire Wire Line
	14750 4750 15200 4750
Wire Wire Line
	14750 4850 15300 4850
Wire Wire Line
	14750 4950 15400 4950
Wire Wire Line
	14750 5050 15500 5050
Wire Wire Line
	14800 3750 14800 3850
Wire Wire Line
	14800 4250 14800 4350
Connection ~ 14800 4350
Wire Wire Line
	14800 4350 15600 4350
Wire Wire Line
	14900 4250 14900 4450
Connection ~ 14900 4450
Wire Wire Line
	14900 4450 15600 4450
Wire Wire Line
	15000 4250 15000 4550
Connection ~ 15000 4550
Wire Wire Line
	15000 4550 15600 4550
Wire Wire Line
	15100 4250 15100 4650
Connection ~ 15100 4650
Wire Wire Line
	15100 4650 15600 4650
Wire Wire Line
	15200 4250 15200 4750
Connection ~ 15200 4750
Wire Wire Line
	15200 4750 15600 4750
Wire Wire Line
	15300 4250 15300 4850
Connection ~ 15300 4850
Wire Wire Line
	15300 4850 15600 4850
Wire Wire Line
	15400 4250 15400 4950
Connection ~ 15400 4950
Wire Wire Line
	15400 4950 15600 4950
Wire Wire Line
	15500 4250 15500 5050
Connection ~ 15500 5050
Wire Wire Line
	15500 5050 15600 5050
Text Label 15100 5250 2    50   ~ 0
SEL_0
Text Label 15100 5350 2    50   ~ 0
SEL_1
Text Label 15100 5450 2    50   ~ 0
SEL_2
Wire Wire Line
	15100 5250 14750 5250
Wire Wire Line
	14750 5350 15100 5350
Wire Wire Line
	14750 5450 15100 5450
$Comp
L power:GND #PWR?
U 1 1 5F3003AC
P 14750 5950
F 0 "#PWR?" H 14750 5700 50  0001 C CNN
F 1 "GND" H 14755 5777 50  0000 C CNN
F 2 "" H 14750 5950 50  0001 C CNN
F 3 "" H 14750 5950 50  0001 C CNN
	1    14750 5950
	1    0    0    -1  
$EndComp
Wire Wire Line
	14250 5950 14750 5950
Wire Wire Line
	14750 5650 14750 5950
Connection ~ 14750 5950
$Comp
L power:+5V #PWR?
U 1 1 5F3003B5
P 14250 3950
F 0 "#PWR?" H 14250 3800 50  0001 C CNN
F 1 "+5V" H 14265 4123 50  0000 C CNN
F 2 "" H 14250 3950 50  0001 C CNN
F 3 "" H 14250 3950 50  0001 C CNN
	1    14250 3950
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C?
U 1 1 5F3003BB
P 14050 3950
F 0 "C?" V 13821 3950 50  0000 C CNN
F 1 "C_Small" V 13912 3950 50  0000 C CNN
F 2 "" H 14050 3950 50  0001 C CNN
F 3 "~" H 14050 3950 50  0001 C CNN
	1    14050 3950
	0    1    1    0   
$EndComp
Wire Wire Line
	14150 3950 14250 3950
Connection ~ 14250 3950
Wire Wire Line
	14250 3950 14250 4050
$Comp
L power:GND #PWR?
U 1 1 5F3003C4
P 13850 3950
F 0 "#PWR?" H 13850 3700 50  0001 C CNN
F 1 "GND" H 13855 3777 50  0000 C CNN
F 2 "" H 13850 3950 50  0001 C CNN
F 3 "" H 13850 3950 50  0001 C CNN
	1    13850 3950
	1    0    0    -1  
$EndComp
Wire Wire Line
	13850 3950 13950 3950
$Comp
L 74xx:74LS151 U?
U 1 1 5F31B95B
P 14250 7750
F 0 "U?" H 14500 8500 50  0000 C CNN
F 1 "74LS151" H 14050 8500 50  0000 C CNN
F 2 "" H 14250 7750 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74LS151" H 14250 7750 50  0001 C CNN
	1    14250 7750
	-1   0    0    -1  
$EndComp
$Comp
L Device:R_Network08_US RN?
U 1 1 5F31B961
P 15200 6850
F 0 "RN?" H 14900 7150 50  0000 L CNN
F 1 "1000" H 14900 7050 50  0000 L CNN
F 2 "Resistor_THT:R_Array_SIP9" V 15675 6850 50  0001 C CNN
F 3 "http://www.vishay.com/docs/31509/csc.pdf" H 15200 6850 50  0001 C CNN
	1    15200 6850
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR?
U 1 1 5F31B96D
P 14800 6550
F 0 "#PWR?" H 14800 6400 50  0001 C CNN
F 1 "+5V" H 14815 6723 50  0000 C CNN
F 2 "" H 14800 6550 50  0001 C CNN
F 3 "" H 14800 6550 50  0001 C CNN
	1    14800 6550
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5F31B973
P 16000 7950
F 0 "#PWR?" H 16000 7700 50  0001 C CNN
F 1 "GND" H 16005 7777 50  0000 C CNN
F 2 "" H 16000 7950 50  0001 C CNN
F 3 "" H 16000 7950 50  0001 C CNN
	1    16000 7950
	1    0    0    -1  
$EndComp
Wire Wire Line
	14750 7150 14800 7150
Wire Wire Line
	14750 7250 14900 7250
Wire Wire Line
	14750 7350 15000 7350
Wire Wire Line
	14750 7450 15100 7450
Wire Wire Line
	14750 7550 15200 7550
Wire Wire Line
	14750 7650 15300 7650
Wire Wire Line
	14750 7750 15400 7750
Wire Wire Line
	14750 7850 15500 7850
Wire Wire Line
	14800 6550 14800 6650
Wire Wire Line
	14800 7050 14800 7150
Connection ~ 14800 7150
Wire Wire Line
	14800 7150 15600 7150
Wire Wire Line
	14900 7050 14900 7250
Connection ~ 14900 7250
Wire Wire Line
	14900 7250 15600 7250
Wire Wire Line
	15000 7050 15000 7350
Connection ~ 15000 7350
Wire Wire Line
	15000 7350 15600 7350
Wire Wire Line
	15100 7050 15100 7450
Connection ~ 15100 7450
Wire Wire Line
	15100 7450 15600 7450
Wire Wire Line
	15200 7050 15200 7550
Connection ~ 15200 7550
Wire Wire Line
	15200 7550 15600 7550
Wire Wire Line
	15300 7050 15300 7650
Connection ~ 15300 7650
Wire Wire Line
	15300 7650 15600 7650
Wire Wire Line
	15400 7050 15400 7750
Connection ~ 15400 7750
Wire Wire Line
	15400 7750 15600 7750
Wire Wire Line
	15500 7050 15500 7850
Connection ~ 15500 7850
Wire Wire Line
	15500 7850 15600 7850
Text Label 15100 8050 2    50   ~ 0
SEL_0
Text Label 15100 8150 2    50   ~ 0
SEL_1
Text Label 15100 8250 2    50   ~ 0
SEL_2
Wire Wire Line
	15100 8050 14750 8050
Wire Wire Line
	14750 8150 15100 8150
Wire Wire Line
	14750 8250 15100 8250
$Comp
L power:GND #PWR?
U 1 1 5F31B9A5
P 14750 8750
F 0 "#PWR?" H 14750 8500 50  0001 C CNN
F 1 "GND" H 14755 8577 50  0000 C CNN
F 2 "" H 14750 8750 50  0001 C CNN
F 3 "" H 14750 8750 50  0001 C CNN
	1    14750 8750
	1    0    0    -1  
$EndComp
Wire Wire Line
	14250 8750 14750 8750
Wire Wire Line
	14750 8450 14750 8750
Connection ~ 14750 8750
$Comp
L power:+5V #PWR?
U 1 1 5F31B9AE
P 14250 6750
F 0 "#PWR?" H 14250 6600 50  0001 C CNN
F 1 "+5V" H 14265 6923 50  0000 C CNN
F 2 "" H 14250 6750 50  0001 C CNN
F 3 "" H 14250 6750 50  0001 C CNN
	1    14250 6750
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C?
U 1 1 5F31B9B4
P 14050 6750
F 0 "C?" V 13821 6750 50  0000 C CNN
F 1 "C_Small" V 13912 6750 50  0000 C CNN
F 2 "" H 14050 6750 50  0001 C CNN
F 3 "~" H 14050 6750 50  0001 C CNN
	1    14050 6750
	0    1    1    0   
$EndComp
Wire Wire Line
	14150 6750 14250 6750
Connection ~ 14250 6750
Wire Wire Line
	14250 6750 14250 6850
$Comp
L power:GND #PWR?
U 1 1 5F31B9BD
P 13850 6750
F 0 "#PWR?" H 13850 6500 50  0001 C CNN
F 1 "GND" H 13855 6577 50  0000 C CNN
F 2 "" H 13850 6750 50  0001 C CNN
F 3 "" H 13850 6750 50  0001 C CNN
	1    13850 6750
	1    0    0    -1  
$EndComp
Wire Wire Line
	13850 6750 13950 6750
$Comp
L Switch:SW_Push SW?
U 1 1 5F32504E
P 15800 7850
F 0 "SW?" H 16150 7850 50  0000 C CNN
F 1 "SW_Push" H 15800 7750 50  0001 C CNN
F 2 "" H 15800 8050 50  0001 C CNN
F 3 "~" H 15800 8050 50  0001 C CNN
	1    15800 7850
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push SW?
U 1 1 5F32997B
P 15800 7750
F 0 "SW?" H 16150 7750 50  0000 C CNN
F 1 "SW_Push" H 15800 7650 50  0001 C CNN
F 2 "" H 15800 7950 50  0001 C CNN
F 3 "~" H 15800 7950 50  0001 C CNN
	1    15800 7750
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push SW?
U 1 1 5F32A062
P 15800 7650
F 0 "SW?" H 16150 7650 50  0000 C CNN
F 1 "SW_Push" H 15800 7550 50  0001 C CNN
F 2 "" H 15800 7850 50  0001 C CNN
F 3 "~" H 15800 7850 50  0001 C CNN
	1    15800 7650
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push SW?
U 1 1 5F32A75F
P 15800 7550
F 0 "SW?" H 16150 7550 50  0000 C CNN
F 1 "SW_Push" H 15800 7450 50  0001 C CNN
F 2 "" H 15800 7750 50  0001 C CNN
F 3 "~" H 15800 7750 50  0001 C CNN
	1    15800 7550
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push SW?
U 1 1 5F32AD93
P 15800 7450
F 0 "SW?" H 16150 7450 50  0000 C CNN
F 1 "SW_Push" H 15800 7350 50  0001 C CNN
F 2 "" H 15800 7650 50  0001 C CNN
F 3 "~" H 15800 7650 50  0001 C CNN
	1    15800 7450
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push SW?
U 1 1 5F32B244
P 15800 7350
F 0 "SW?" H 16150 7350 50  0000 C CNN
F 1 "SW_Push" H 15800 7250 50  0001 C CNN
F 2 "" H 15800 7550 50  0001 C CNN
F 3 "~" H 15800 7550 50  0001 C CNN
	1    15800 7350
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push SW?
U 1 1 5F32B520
P 15800 7250
F 0 "SW?" H 16150 7250 50  0000 C CNN
F 1 "SW_Push" H 15800 7150 50  0001 C CNN
F 2 "" H 15800 7450 50  0001 C CNN
F 3 "~" H 15800 7450 50  0001 C CNN
	1    15800 7250
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push SW?
U 1 1 5F32B871
P 15800 7150
F 0 "SW?" H 16150 7150 50  0000 C CNN
F 1 "SW_Push" H 15800 7050 50  0001 C CNN
F 2 "" H 15800 7350 50  0001 C CNN
F 3 "~" H 15800 7350 50  0001 C CNN
	1    15800 7150
	1    0    0    -1  
$EndComp
Wire Wire Line
	16000 7150 16000 7250
Wire Wire Line
	16000 7250 16000 7350
Connection ~ 16000 7250
Wire Wire Line
	16000 7350 16000 7450
Connection ~ 16000 7350
Wire Wire Line
	16000 7450 16000 7550
Connection ~ 16000 7450
Wire Wire Line
	16000 7550 16000 7650
Connection ~ 16000 7550
Wire Wire Line
	16000 7650 16000 7750
Connection ~ 16000 7650
Wire Wire Line
	16000 7750 16000 7850
Connection ~ 16000 7750
Wire Wire Line
	16000 7850 16000 7950
Connection ~ 16000 7850
Text Label 13350 1650 0    50   ~ 0
SW_RB_1
Wire Wire Line
	13350 1650 13750 1650
Text Label 13350 4450 0    50   ~ 0
SW_RB_2
Wire Wire Line
	13350 4450 13750 4450
Text Label 13350 7250 0    50   ~ 0
BTN_RB
Wire Wire Line
	13350 7250 13750 7250
$Comp
L mtg_life_counter:KW4-56NX D?
U 1 1 5F369DB6
P 8950 1950
F 0 "D?" H 8950 2617 50  0000 C CNN
F 1 "KW4-56NX" H 8950 2526 50  0000 C CNN
F 2 "Display_7Segment:CA56-12EWA" H 8950 1350 50  0001 C CNN
F 3 "https://cdn-shop.adafruit.com/datasheets/865datasheet.pdf" H 8520 1980 50  0001 C CNN
	1    8950 1950
	1    0    0    -1  
$EndComp
NoConn ~ 10050 2350
NoConn ~ 7850 2350
$Comp
L mtg_life_counter:KW4-56NX D?
U 1 1 5F381D0D
P 8950 3250
F 0 "D?" H 8950 3917 50  0000 C CNN
F 1 "KW4-56NX" H 8950 3826 50  0000 C CNN
F 2 "Display_7Segment:CA56-12EWA" H 8950 2650 50  0001 C CNN
F 3 "https://cdn-shop.adafruit.com/datasheets/865datasheet.pdf" H 8520 3280 50  0001 C CNN
	1    8950 3250
	1    0    0    -1  
$EndComp
NoConn ~ 10050 3650
NoConn ~ 7850 3650
Wire Wire Line
	10050 1950 10450 1950
Wire Wire Line
	10450 2250 10550 2250
Wire Wire Line
	10050 2050 10350 2050
Wire Wire Line
	10350 2350 10550 2350
Wire Wire Line
	10050 2150 10250 2150
Wire Wire Line
	10250 2450 10550 2450
Wire Wire Line
	10050 2250 10150 2250
Wire Wire Line
	10150 2550 10550 2550
Wire Wire Line
	10550 2650 10150 2650
Wire Wire Line
	10150 3250 10050 3250
Wire Wire Line
	10050 3350 10250 3350
Wire Wire Line
	10250 2750 10550 2750
Wire Wire Line
	10050 3450 10350 3450
Wire Wire Line
	10350 2850 10550 2850
Wire Wire Line
	10550 2950 10450 2950
Wire Wire Line
	10450 3550 10050 3550
$Comp
L Device:R R?
U 1 1 5F3C7638
P 7500 1550
F 0 "R?" V 7450 1350 50  0000 C CNN
F 1 "R" V 7500 1550 50  0000 C CNN
F 2 "" V 7430 1550 50  0001 C CNN
F 3 "~" H 7500 1550 50  0001 C CNN
	1    7500 1550
	0    1    1    0   
$EndComp
$Comp
L Device:R R?
U 1 1 5F3C925B
P 7500 1650
F 0 "R?" V 7450 1450 50  0000 C CNN
F 1 "R" V 7500 1650 50  0000 C CNN
F 2 "" V 7430 1650 50  0001 C CNN
F 3 "~" H 7500 1650 50  0001 C CNN
	1    7500 1650
	0    1    1    0   
$EndComp
$Comp
L Device:R R?
U 1 1 5F3C954F
P 7500 1750
F 0 "R?" V 7450 1550 50  0000 C CNN
F 1 "R" V 7500 1750 50  0000 C CNN
F 2 "" V 7430 1750 50  0001 C CNN
F 3 "~" H 7500 1750 50  0001 C CNN
	1    7500 1750
	0    1    1    0   
$EndComp
$Comp
L Device:R R?
U 1 1 5F3C97F6
P 7500 1850
F 0 "R?" V 7450 1650 50  0000 C CNN
F 1 "R" V 7500 1850 50  0000 C CNN
F 2 "" V 7430 1850 50  0001 C CNN
F 3 "~" H 7500 1850 50  0001 C CNN
	1    7500 1850
	0    1    1    0   
$EndComp
$Comp
L Device:R R?
U 1 1 5F3C9A63
P 7500 1950
F 0 "R?" V 7450 1750 50  0000 C CNN
F 1 "R" V 7500 1950 50  0000 C CNN
F 2 "" V 7430 1950 50  0001 C CNN
F 3 "~" H 7500 1950 50  0001 C CNN
	1    7500 1950
	0    1    1    0   
$EndComp
$Comp
L Device:R R?
U 1 1 5F3C9D58
P 7500 2050
F 0 "R?" V 7450 1850 50  0000 C CNN
F 1 "R" V 7500 2050 50  0000 C CNN
F 2 "" V 7430 2050 50  0001 C CNN
F 3 "~" H 7500 2050 50  0001 C CNN
	1    7500 2050
	0    1    1    0   
$EndComp
$Comp
L Device:R R?
U 1 1 5F3CA07C
P 7500 2150
F 0 "R?" V 7450 1950 50  0000 C CNN
F 1 "R" V 7500 2150 50  0000 C CNN
F 2 "" V 7430 2150 50  0001 C CNN
F 3 "~" H 7500 2150 50  0001 C CNN
	1    7500 2150
	0    1    1    0   
$EndComp
$Comp
L Device:R R?
U 1 1 5F3CA2C2
P 7500 2250
F 0 "R?" V 7450 2050 50  0000 C CNN
F 1 "R" V 7500 2250 50  0000 C CNN
F 2 "" V 7430 2250 50  0001 C CNN
F 3 "~" H 7500 2250 50  0001 C CNN
	1    7500 2250
	0    1    1    0   
$EndComp
$Comp
L Device:R R?
U 1 1 5F3CC1FA
P 7500 2850
F 0 "R?" V 7450 2650 50  0000 C CNN
F 1 "R" V 7500 2850 50  0000 C CNN
F 2 "" V 7430 2850 50  0001 C CNN
F 3 "~" H 7500 2850 50  0001 C CNN
	1    7500 2850
	0    1    1    0   
$EndComp
$Comp
L Device:R R?
U 1 1 5F3CC200
P 7500 2950
F 0 "R?" V 7450 2750 50  0000 C CNN
F 1 "R" V 7500 2950 50  0000 C CNN
F 2 "" V 7430 2950 50  0001 C CNN
F 3 "~" H 7500 2950 50  0001 C CNN
	1    7500 2950
	0    1    1    0   
$EndComp
$Comp
L Device:R R?
U 1 1 5F3CC206
P 7500 3050
F 0 "R?" V 7450 2850 50  0000 C CNN
F 1 "R" V 7500 3050 50  0000 C CNN
F 2 "" V 7430 3050 50  0001 C CNN
F 3 "~" H 7500 3050 50  0001 C CNN
	1    7500 3050
	0    1    1    0   
$EndComp
$Comp
L Device:R R?
U 1 1 5F3CC20C
P 7500 3150
F 0 "R?" V 7450 2950 50  0000 C CNN
F 1 "R" V 7500 3150 50  0000 C CNN
F 2 "" V 7430 3150 50  0001 C CNN
F 3 "~" H 7500 3150 50  0001 C CNN
	1    7500 3150
	0    1    1    0   
$EndComp
$Comp
L Device:R R?
U 1 1 5F3CC212
P 7500 3250
F 0 "R?" V 7450 3050 50  0000 C CNN
F 1 "R" V 7500 3250 50  0000 C CNN
F 2 "" V 7430 3250 50  0001 C CNN
F 3 "~" H 7500 3250 50  0001 C CNN
	1    7500 3250
	0    1    1    0   
$EndComp
$Comp
L Device:R R?
U 1 1 5F3CC218
P 7500 3350
F 0 "R?" V 7450 3150 50  0000 C CNN
F 1 "R" V 7500 3350 50  0000 C CNN
F 2 "" V 7430 3350 50  0001 C CNN
F 3 "~" H 7500 3350 50  0001 C CNN
	1    7500 3350
	0    1    1    0   
$EndComp
$Comp
L Device:R R?
U 1 1 5F3CC21E
P 7500 3450
F 0 "R?" V 7450 3250 50  0000 C CNN
F 1 "R" V 7500 3450 50  0000 C CNN
F 2 "" V 7430 3450 50  0001 C CNN
F 3 "~" H 7500 3450 50  0001 C CNN
	1    7500 3450
	0    1    1    0   
$EndComp
$Comp
L Device:R R?
U 1 1 5F3CC224
P 7500 3550
F 0 "R?" V 7450 3350 50  0000 C CNN
F 1 "R" V 7500 3550 50  0000 C CNN
F 2 "" V 7430 3550 50  0001 C CNN
F 3 "~" H 7500 3550 50  0001 C CNN
	1    7500 3550
	0    1    1    0   
$EndComp
$Comp
L Switch:SW_SPDT SW?
U 1 1 5F3E140C
P 2100 3500
F 0 "SW?" H 2100 3785 50  0000 C CNN
F 1 "SW_SPDT" H 2100 3694 50  0000 C CNN
F 2 "" H 2100 3500 50  0001 C CNN
F 3 "~" H 2100 3500 50  0001 C CNN
	1    2100 3500
	1    0    0    -1  
$EndComp
Wire Wire Line
	7650 1550 7850 1550
Wire Wire Line
	7650 1650 7850 1650
Wire Wire Line
	7650 1750 7850 1750
Wire Wire Line
	7650 1850 7850 1850
Wire Wire Line
	7650 1950 7850 1950
Wire Wire Line
	7650 2050 7850 2050
Wire Wire Line
	7650 2150 7850 2150
Wire Wire Line
	7650 2250 7850 2250
Wire Wire Line
	7650 2850 7850 2850
Wire Wire Line
	7650 2950 7850 2950
Wire Wire Line
	7650 3050 7850 3050
Wire Wire Line
	7650 3150 7850 3150
Wire Wire Line
	7650 3250 7850 3250
Wire Wire Line
	7650 3350 7850 3350
Wire Wire Line
	7650 3450 7850 3450
Wire Wire Line
	7650 3550 7850 3550
Wire Wire Line
	10150 2250 10150 2550
Wire Wire Line
	10250 2150 10250 2450
Wire Wire Line
	10350 2050 10350 2350
Wire Wire Line
	10450 1950 10450 2250
Wire Wire Line
	10150 2650 10150 3250
Wire Wire Line
	10250 2750 10250 3350
Wire Wire Line
	10350 2850 10350 3450
Wire Wire Line
	10450 2950 10450 3550
$Comp
L Interface_Expansion:TPIC6595 U?
U 1 1 5F500644
P 11050 5800
F 0 "U?" H 11400 6400 50  0000 C CNN
F 1 "TPIC6595" H 11250 5100 50  0000 C CNN
F 2 "" H 11700 5150 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/tpic6595.pdf" H 11050 5750 50  0001 C CNN
	1    11050 5800
	-1   0    0    -1  
$EndComp
$Comp
L mtg_life_counter:KW4-56NX D?
U 1 1 5F50064A
P 8950 5100
F 0 "D?" H 8950 5767 50  0000 C CNN
F 1 "KW4-56NX" H 8950 5676 50  0000 C CNN
F 2 "Display_7Segment:CA56-12EWA" H 8950 4500 50  0001 C CNN
F 3 "https://cdn-shop.adafruit.com/datasheets/865datasheet.pdf" H 8520 5130 50  0001 C CNN
	1    8950 5100
	1    0    0    -1  
$EndComp
NoConn ~ 10050 5500
NoConn ~ 7850 5500
$Comp
L mtg_life_counter:KW4-56NX D?
U 1 1 5F500652
P 8950 6400
F 0 "D?" H 8950 7067 50  0000 C CNN
F 1 "KW4-56NX" H 8950 6976 50  0000 C CNN
F 2 "Display_7Segment:CA56-12EWA" H 8950 5800 50  0001 C CNN
F 3 "https://cdn-shop.adafruit.com/datasheets/865datasheet.pdf" H 8520 6430 50  0001 C CNN
	1    8950 6400
	1    0    0    -1  
$EndComp
NoConn ~ 10050 6800
NoConn ~ 7850 6800
Wire Wire Line
	10050 5100 10450 5100
Wire Wire Line
	10450 5400 10550 5400
Wire Wire Line
	10050 5200 10350 5200
Wire Wire Line
	10350 5500 10550 5500
Wire Wire Line
	10050 5300 10250 5300
Wire Wire Line
	10250 5600 10550 5600
Wire Wire Line
	10050 5400 10150 5400
Wire Wire Line
	10150 5700 10550 5700
Wire Wire Line
	10550 5800 10150 5800
Wire Wire Line
	10150 6400 10050 6400
Wire Wire Line
	10050 6500 10250 6500
Wire Wire Line
	10250 5900 10550 5900
Wire Wire Line
	10050 6600 10350 6600
Wire Wire Line
	10350 6000 10550 6000
Wire Wire Line
	10550 6100 10450 6100
Wire Wire Line
	10450 6700 10050 6700
$Comp
L Device:R R?
U 1 1 5F50066A
P 7500 4700
F 0 "R?" V 7450 4500 50  0000 C CNN
F 1 "R" V 7500 4700 50  0000 C CNN
F 2 "" V 7430 4700 50  0001 C CNN
F 3 "~" H 7500 4700 50  0001 C CNN
	1    7500 4700
	0    1    1    0   
$EndComp
$Comp
L Device:R R?
U 1 1 5F500670
P 7500 4800
F 0 "R?" V 7450 4600 50  0000 C CNN
F 1 "R" V 7500 4800 50  0000 C CNN
F 2 "" V 7430 4800 50  0001 C CNN
F 3 "~" H 7500 4800 50  0001 C CNN
	1    7500 4800
	0    1    1    0   
$EndComp
$Comp
L Device:R R?
U 1 1 5F500676
P 7500 4900
F 0 "R?" V 7450 4700 50  0000 C CNN
F 1 "R" V 7500 4900 50  0000 C CNN
F 2 "" V 7430 4900 50  0001 C CNN
F 3 "~" H 7500 4900 50  0001 C CNN
	1    7500 4900
	0    1    1    0   
$EndComp
$Comp
L Device:R R?
U 1 1 5F50067C
P 7500 5000
F 0 "R?" V 7450 4800 50  0000 C CNN
F 1 "R" V 7500 5000 50  0000 C CNN
F 2 "" V 7430 5000 50  0001 C CNN
F 3 "~" H 7500 5000 50  0001 C CNN
	1    7500 5000
	0    1    1    0   
$EndComp
$Comp
L Device:R R?
U 1 1 5F500682
P 7500 5100
F 0 "R?" V 7450 4900 50  0000 C CNN
F 1 "R" V 7500 5100 50  0000 C CNN
F 2 "" V 7430 5100 50  0001 C CNN
F 3 "~" H 7500 5100 50  0001 C CNN
	1    7500 5100
	0    1    1    0   
$EndComp
$Comp
L Device:R R?
U 1 1 5F500688
P 7500 5200
F 0 "R?" V 7450 5000 50  0000 C CNN
F 1 "R" V 7500 5200 50  0000 C CNN
F 2 "" V 7430 5200 50  0001 C CNN
F 3 "~" H 7500 5200 50  0001 C CNN
	1    7500 5200
	0    1    1    0   
$EndComp
$Comp
L Device:R R?
U 1 1 5F50068E
P 7500 5300
F 0 "R?" V 7450 5100 50  0000 C CNN
F 1 "R" V 7500 5300 50  0000 C CNN
F 2 "" V 7430 5300 50  0001 C CNN
F 3 "~" H 7500 5300 50  0001 C CNN
	1    7500 5300
	0    1    1    0   
$EndComp
$Comp
L Device:R R?
U 1 1 5F500694
P 7500 5400
F 0 "R?" V 7450 5200 50  0000 C CNN
F 1 "R" V 7500 5400 50  0000 C CNN
F 2 "" V 7430 5400 50  0001 C CNN
F 3 "~" H 7500 5400 50  0001 C CNN
	1    7500 5400
	0    1    1    0   
$EndComp
$Comp
L Device:R R?
U 1 1 5F50069A
P 7500 6000
F 0 "R?" V 7450 5800 50  0000 C CNN
F 1 "R" V 7500 6000 50  0000 C CNN
F 2 "" V 7430 6000 50  0001 C CNN
F 3 "~" H 7500 6000 50  0001 C CNN
	1    7500 6000
	0    1    1    0   
$EndComp
$Comp
L Device:R R?
U 1 1 5F5006A0
P 7500 6100
F 0 "R?" V 7450 5900 50  0000 C CNN
F 1 "R" V 7500 6100 50  0000 C CNN
F 2 "" V 7430 6100 50  0001 C CNN
F 3 "~" H 7500 6100 50  0001 C CNN
	1    7500 6100
	0    1    1    0   
$EndComp
$Comp
L Device:R R?
U 1 1 5F5006A6
P 7500 6200
F 0 "R?" V 7450 6000 50  0000 C CNN
F 1 "R" V 7500 6200 50  0000 C CNN
F 2 "" V 7430 6200 50  0001 C CNN
F 3 "~" H 7500 6200 50  0001 C CNN
	1    7500 6200
	0    1    1    0   
$EndComp
$Comp
L Device:R R?
U 1 1 5F5006AC
P 7500 6300
F 0 "R?" V 7450 6100 50  0000 C CNN
F 1 "R" V 7500 6300 50  0000 C CNN
F 2 "" V 7430 6300 50  0001 C CNN
F 3 "~" H 7500 6300 50  0001 C CNN
	1    7500 6300
	0    1    1    0   
$EndComp
$Comp
L Device:R R?
U 1 1 5F5006B2
P 7500 6400
F 0 "R?" V 7450 6200 50  0000 C CNN
F 1 "R" V 7500 6400 50  0000 C CNN
F 2 "" V 7430 6400 50  0001 C CNN
F 3 "~" H 7500 6400 50  0001 C CNN
	1    7500 6400
	0    1    1    0   
$EndComp
$Comp
L Device:R R?
U 1 1 5F5006B8
P 7500 6500
F 0 "R?" V 7450 6300 50  0000 C CNN
F 1 "R" V 7500 6500 50  0000 C CNN
F 2 "" V 7430 6500 50  0001 C CNN
F 3 "~" H 7500 6500 50  0001 C CNN
	1    7500 6500
	0    1    1    0   
$EndComp
$Comp
L Device:R R?
U 1 1 5F5006BE
P 7500 6600
F 0 "R?" V 7450 6400 50  0000 C CNN
F 1 "R" V 7500 6600 50  0000 C CNN
F 2 "" V 7430 6600 50  0001 C CNN
F 3 "~" H 7500 6600 50  0001 C CNN
	1    7500 6600
	0    1    1    0   
$EndComp
$Comp
L Device:R R?
U 1 1 5F5006C4
P 7500 6700
F 0 "R?" V 7450 6500 50  0000 C CNN
F 1 "R" V 7500 6700 50  0000 C CNN
F 2 "" V 7430 6700 50  0001 C CNN
F 3 "~" H 7500 6700 50  0001 C CNN
	1    7500 6700
	0    1    1    0   
$EndComp
Wire Wire Line
	7650 4700 7850 4700
Wire Wire Line
	7650 4800 7850 4800
Wire Wire Line
	7650 4900 7850 4900
Wire Wire Line
	7650 5000 7850 5000
Wire Wire Line
	7650 5100 7850 5100
Wire Wire Line
	7650 5200 7850 5200
Wire Wire Line
	7650 5300 7850 5300
Wire Wire Line
	7650 5400 7850 5400
Wire Wire Line
	7650 6000 7850 6000
Wire Wire Line
	7650 6100 7850 6100
Wire Wire Line
	7650 6200 7850 6200
Wire Wire Line
	7650 6300 7850 6300
Wire Wire Line
	7650 6400 7850 6400
Wire Wire Line
	7650 6500 7850 6500
Wire Wire Line
	7650 6600 7850 6600
Wire Wire Line
	7650 6700 7850 6700
Wire Wire Line
	10150 5400 10150 5700
Wire Wire Line
	10250 5300 10250 5600
Wire Wire Line
	10350 5200 10350 5500
Wire Wire Line
	10450 5100 10450 5400
Wire Wire Line
	10150 5800 10150 6400
Wire Wire Line
	10250 5900 10250 6500
Wire Wire Line
	10350 6000 10350 6600
Wire Wire Line
	10450 6100 10450 6700
$Comp
L power:GND #PWR?
U 1 1 5F50EC61
P 2400 3600
F 0 "#PWR?" H 2400 3350 50  0001 C CNN
F 1 "GND" H 2405 3427 50  0000 C CNN
F 2 "" H 2400 3600 50  0001 C CNN
F 3 "" H 2400 3600 50  0001 C CNN
	1    2400 3600
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR?
U 1 1 5F50F18A
P 2400 3400
F 0 "#PWR?" H 2400 3250 50  0001 C CNN
F 1 "+5V" H 2415 3573 50  0000 C CNN
F 2 "" H 2400 3400 50  0001 C CNN
F 3 "" H 2400 3400 50  0001 C CNN
	1    2400 3400
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 5F5105EB
P 1600 3500
F 0 "R?" V 1550 3300 50  0000 C CNN
F 1 "1k" V 1600 3500 50  0000 C CNN
F 2 "" V 1530 3500 50  0001 C CNN
F 3 "~" H 1600 3500 50  0001 C CNN
	1    1600 3500
	0    1    1    0   
$EndComp
Wire Wire Line
	1750 3500 1900 3500
Wire Wire Line
	2300 3400 2400 3400
Wire Wire Line
	2400 3600 2300 3600
$Comp
L Switch:SW_Push SW?
U 1 1 5F56C5DB
P 1700 4650
F 0 "SW?" H 1700 4935 50  0000 C CNN
F 1 "SW_Push" H 1700 4844 50  0000 C CNN
F 2 "" H 1700 4850 50  0001 C CNN
F 3 "~" H 1700 4850 50  0001 C CNN
	1    1700 4650
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74HC595 U?
U 1 1 5F6D81D0
P 5950 5100
F 0 "U?" H 5950 5881 50  0000 C CNN
F 1 "74HC595" H 5950 5790 50  0000 C CNN
F 2 "" H 5950 5100 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/sn74hc595.pdf" H 5950 5100 50  0001 C CNN
	1    5950 5100
	1    0    0    -1  
$EndComp
Wire Wire Line
	6350 5400 6450 5400
Wire Wire Line
	6350 5300 6550 5300
Wire Wire Line
	6350 5200 6650 5200
Wire Wire Line
	6350 5100 6750 5100
Wire Wire Line
	6350 5000 6850 5000
Wire Wire Line
	6350 4900 6950 4900
Wire Wire Line
	6350 4800 7050 4800
Wire Wire Line
	6350 4700 7150 4700
Wire Wire Line
	7350 6700 6450 6700
Wire Wire Line
	6450 6700 6450 5400
Connection ~ 6450 5400
Wire Wire Line
	6450 5400 7350 5400
Wire Wire Line
	7350 6600 6550 6600
Wire Wire Line
	6550 6600 6550 5300
Connection ~ 6550 5300
Wire Wire Line
	6550 5300 7350 5300
Wire Wire Line
	7350 6500 6650 6500
Wire Wire Line
	6650 6500 6650 5200
Connection ~ 6650 5200
Wire Wire Line
	6650 5200 7350 5200
Wire Wire Line
	7350 6400 6750 6400
Wire Wire Line
	6750 6400 6750 5100
Connection ~ 6750 5100
Wire Wire Line
	6750 5100 7350 5100
Wire Wire Line
	7350 6300 6850 6300
Wire Wire Line
	6850 6300 6850 5000
Connection ~ 6850 5000
Wire Wire Line
	6850 5000 7350 5000
Wire Wire Line
	7350 6200 6950 6200
Wire Wire Line
	6950 6200 6950 4900
Connection ~ 6950 4900
Wire Wire Line
	6950 4900 7350 4900
Wire Wire Line
	7050 4800 7050 6100
Wire Wire Line
	7050 6100 7350 6100
Connection ~ 7050 4800
Wire Wire Line
	7050 4800 7350 4800
Wire Wire Line
	7150 4700 7150 6000
Wire Wire Line
	7150 6000 7350 6000
Connection ~ 7150 4700
Wire Wire Line
	7150 4700 7350 4700
Wire Wire Line
	6350 2250 6450 2250
Wire Wire Line
	6350 2150 6550 2150
Wire Wire Line
	6350 2050 6650 2050
Wire Wire Line
	6350 1950 6750 1950
Wire Wire Line
	6350 1850 6850 1850
Wire Wire Line
	6350 1750 6950 1750
Wire Wire Line
	6350 1650 7050 1650
Wire Wire Line
	6350 1550 7150 1550
Wire Wire Line
	7350 3550 6450 3550
Wire Wire Line
	6450 3550 6450 2250
Wire Wire Line
	7350 3450 6550 3450
Wire Wire Line
	6550 3450 6550 2150
Wire Wire Line
	7350 3350 6650 3350
Wire Wire Line
	6650 3350 6650 2050
Wire Wire Line
	7350 3250 6750 3250
Wire Wire Line
	6750 3250 6750 1950
Wire Wire Line
	7350 3150 6850 3150
Wire Wire Line
	6850 3150 6850 1850
Wire Wire Line
	7350 3050 6950 3050
Wire Wire Line
	6950 3050 6950 1750
Wire Wire Line
	7050 1650 7050 2950
Wire Wire Line
	7050 2950 7350 2950
Wire Wire Line
	7150 1550 7150 2850
Wire Wire Line
	7150 2850 7350 2850
Connection ~ 6450 2250
Wire Wire Line
	6450 2250 7350 2250
Connection ~ 6550 2150
Wire Wire Line
	6550 2150 7350 2150
Connection ~ 6650 2050
Wire Wire Line
	6650 2050 7350 2050
Connection ~ 6750 1950
Wire Wire Line
	6750 1950 7350 1950
Connection ~ 6850 1850
Wire Wire Line
	6850 1850 7350 1850
Connection ~ 6950 1750
Wire Wire Line
	6950 1750 7350 1750
Connection ~ 7050 1650
Wire Wire Line
	7050 1650 7350 1650
Connection ~ 7150 1550
Wire Wire Line
	7150 1550 7350 1550
Text Label 2000 5700 0    50   ~ 0
SPI_CLK
Text Label 2000 5500 0    50   ~ 0
SPI_OUT
Wire Wire Line
	2000 5500 2500 5500
Wire Wire Line
	2000 5700 2500 5700
$Comp
L power:GND #PWR?
U 1 1 5F8DE19F
P 2900 6000
F 0 "#PWR?" H 2900 5750 50  0001 C CNN
F 1 "GND" H 2905 5827 50  0000 C CNN
F 2 "" H 2900 6000 50  0001 C CNN
F 3 "" H 2900 6000 50  0001 C CNN
	1    2900 6000
	1    0    0    -1  
$EndComp
Wire Wire Line
	2900 6000 3000 6000
Wire Wire Line
	3000 6000 3100 6000
Connection ~ 3000 6000
$Comp
L power:+5V #PWR?
U 1 1 5F917F3A
P 3200 3900
F 0 "#PWR?" H 3200 3750 50  0001 C CNN
F 1 "+5V" H 3215 4073 50  0000 C CNN
F 2 "" H 3200 3900 50  0001 C CNN
F 3 "" H 3200 3900 50  0001 C CNN
	1    3200 3900
	1    0    0    -1  
$EndComp
Wire Wire Line
	3200 3900 3200 4000
NoConn ~ 2900 4000
NoConn ~ 3500 4800
Text Label 2000 5600 0    50   ~ 0
SPI_IN
Wire Wire Line
	2000 5600 2500 5600
NoConn ~ 3500 4400
NoConn ~ 3500 4500
Wire Wire Line
	10550 3150 10550 3900
Wire Wire Line
	11650 4450 11650 5400
Wire Wire Line
	11650 5400 11550 5400
$Comp
L power:+5V #PWR?
U 1 1 5F9E395A
P 11050 1950
F 0 "#PWR?" H 11050 1800 50  0001 C CNN
F 1 "+5V" H 11065 2123 50  0000 C CNN
F 2 "" H 11050 1950 50  0001 C CNN
F 3 "" H 11050 1950 50  0001 C CNN
	1    11050 1950
	1    0    0    -1  
$EndComp
Wire Wire Line
	11050 1950 11050 2050
$Comp
L power:+5V #PWR?
U 1 1 5FA01F09
P 11050 5100
F 0 "#PWR?" H 11050 4950 50  0001 C CNN
F 1 "+5V" H 11065 5273 50  0000 C CNN
F 2 "" H 11050 5100 50  0001 C CNN
F 3 "" H 11050 5100 50  0001 C CNN
	1    11050 5100
	1    0    0    -1  
$EndComp
Wire Wire Line
	11050 5100 11050 5200
Text Label 4250 5200 2    50   ~ 0
SEL_0
Text Label 4250 5300 2    50   ~ 0
SEL_1
Text Label 4250 5400 2    50   ~ 0
SEL_2
Wire Wire Line
	4250 5200 3900 5200
Wire Wire Line
	3900 5300 4250 5300
Wire Wire Line
	3900 5400 4250 5400
Text Label 4150 5850 0    50   ~ 0
BTN_RB
Text Label 4100 5700 0    50   ~ 0
SW_RB_2
Text Label 4050 5550 0    50   ~ 0
SW_RB_1
$EndSCHEMATC
