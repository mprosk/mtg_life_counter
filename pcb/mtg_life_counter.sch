EESchema Schematic File Version 4
LIBS:mtg_life_counter-cache
EELAYER 30 0
EELAYER END
$Descr USLedger 17000 11000
encoding utf-8
Sheet 1 1
Title "Magic: The Gathering Life Counter"
Date "2020-09-03"
Rev "2.0"
Comp "Max Proskauer"
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Switch:SW_Push B1
U 1 1 5F28CE77
P 5750 2600
F 0 "B1" H 5750 2885 50  0000 C CNN
F 1 "SW_Push" H 5750 2794 50  0000 C CNN
F 2 "mtg_life_counter:B3F_12mm" H 5750 2800 50  0001 C CNN
F 3 "~" H 5750 2800 50  0001 C CNN
	1    5750 2600
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74HC595 U2
U 1 1 5F292D64
P 10000 1650
F 0 "U2" H 9750 2250 50  0000 C CNN
F 1 "74HC595" H 10200 1000 50  0000 C CNN
F 2 "Package_SO:SOIC-16_3.9x9.9mm_P1.27mm" H 10000 1650 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/sn74hc595.pdf" H 10000 1650 50  0001 C CNN
	1    10000 1650
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74LS151 U6
U 1 1 5F293C96
P 4200 9050
F 0 "U6" H 4450 9800 50  0000 C CNN
F 1 "74LS151" H 4000 9800 50  0000 C CNN
F 2 "Package_SO:SOIC-16_3.9x9.9mm_P1.27mm" H 4200 9050 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74LS151" H 4200 9050 50  0001 C CNN
	1    4200 9050
	-1   0    0    -1  
$EndComp
$Comp
L power:+5V #PWR029
U 1 1 5F2A4AB1
P 4650 7950
F 0 "#PWR029" H 4650 7800 50  0001 C CNN
F 1 "+5V" H 4600 8100 50  0000 C CNN
F 2 "" H 4650 7950 50  0001 C CNN
F 3 "" H 4650 7950 50  0001 C CNN
	1    4650 7950
	1    0    0    -1  
$EndComp
Text Label 5450 9350 2    50   ~ 0
MUX_SEL_0
Text Label 5450 9450 2    50   ~ 0
MUX_SEL_1
Text Label 5450 9550 2    50   ~ 0
MUX_SEL_2
Wire Wire Line
	5450 9350 4700 9350
Wire Wire Line
	4700 9450 5450 9450
Wire Wire Line
	4700 9550 5450 9550
$Comp
L power:GND #PWR026
U 1 1 5F2E233A
P 4700 10050
F 0 "#PWR026" H 4700 9800 50  0001 C CNN
F 1 "GND" H 4705 9877 50  0000 C CNN
F 2 "" H 4700 10050 50  0001 C CNN
F 3 "" H 4700 10050 50  0001 C CNN
	1    4700 10050
	1    0    0    -1  
$EndComp
Wire Wire Line
	4200 10050 4700 10050
Wire Wire Line
	4700 9750 4700 10050
Connection ~ 4700 10050
$Comp
L power:+5V #PWR023
U 1 1 5F2E3AF9
P 4200 8050
F 0 "#PWR023" H 4200 7900 50  0001 C CNN
F 1 "+5V" H 4215 8223 50  0000 C CNN
F 2 "" H 4200 8050 50  0001 C CNN
F 3 "" H 4200 8050 50  0001 C CNN
	1    4200 8050
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C9
U 1 1 5F2E5300
P 4000 8050
F 0 "C9" V 3771 8050 50  0000 C CNN
F 1 "0.1uF" V 3862 8050 50  0000 C CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 4000 8050 50  0001 C CNN
F 3 "~" H 4000 8050 50  0001 C CNN
	1    4000 8050
	0    1    1    0   
$EndComp
Wire Wire Line
	4100 8050 4200 8050
Connection ~ 4200 8050
Wire Wire Line
	4200 8050 4200 8150
$Comp
L power:GND #PWR020
U 1 1 5F2E830C
P 3800 8050
F 0 "#PWR020" H 3800 7800 50  0001 C CNN
F 1 "GND" H 3805 7877 50  0000 C CNN
F 2 "" H 3800 8050 50  0001 C CNN
F 3 "" H 3800 8050 50  0001 C CNN
	1    3800 8050
	1    0    0    -1  
$EndComp
Wire Wire Line
	3800 8050 3900 8050
Text Label 3200 8450 0    50   ~ 0
MUX_RB
$Comp
L mtg_life_counter:KW4-56NX D1
U 1 1 5F369DB6
P 13000 1650
F 0 "D1" H 13000 2317 50  0000 C CNN
F 1 "KW4-56NX RED" H 13000 2226 50  0000 C CNN
F 2 "mtg_life_counter:KW4-56NX" H 13000 1050 50  0001 C CNN
F 3 "https://cdn-shop.adafruit.com/datasheets/865datasheet.pdf" H 12570 1680 50  0001 C CNN
	1    13000 1650
	1    0    0    -1  
$EndComp
NoConn ~ 14100 2050
NoConn ~ 11900 3350
$Comp
L mtg_life_counter:KW4-56NX D2
U 1 1 5F381D0D
P 13000 2950
F 0 "D2" H 13000 3617 50  0000 C CNN
F 1 "KW4-56NX GREEN" H 13000 3526 50  0000 C CNN
F 2 "mtg_life_counter:KW4-56NX" H 13000 2350 50  0001 C CNN
F 3 "https://cdn-shop.adafruit.com/datasheets/865datasheet.pdf" H 12570 2980 50  0001 C CNN
	1    13000 2950
	1    0    0    -1  
$EndComp
NoConn ~ 14100 3350
NoConn ~ 11900 2050
Wire Wire Line
	14100 1650 14500 1650
Wire Wire Line
	14500 1950 14600 1950
Wire Wire Line
	14100 1750 14400 1750
Wire Wire Line
	14400 2050 14600 2050
Wire Wire Line
	14100 1850 14300 1850
Wire Wire Line
	14300 2150 14600 2150
Wire Wire Line
	14600 2350 14200 2350
Wire Wire Line
	14200 2950 14100 2950
Wire Wire Line
	14100 3050 14300 3050
Wire Wire Line
	14300 2450 14600 2450
Wire Wire Line
	14100 3150 14400 3150
Wire Wire Line
	14400 2550 14600 2550
Wire Wire Line
	14300 1850 14300 2150
Wire Wire Line
	14400 1750 14400 2050
Wire Wire Line
	14500 1650 14500 1950
Wire Wire Line
	14200 2350 14200 2950
Wire Wire Line
	14300 2450 14300 3050
Wire Wire Line
	14400 2550 14400 3150
$Comp
L mtg_life_counter:KW4-56NX D3
U 1 1 5F50064A
P 13000 4800
F 0 "D3" H 13000 5467 50  0000 C CNN
F 1 "KW4-56NX YELLOW" H 13000 5376 50  0000 C CNN
F 2 "mtg_life_counter:KW4-56NX" H 13000 4200 50  0001 C CNN
F 3 "https://cdn-shop.adafruit.com/datasheets/865datasheet.pdf" H 12570 4830 50  0001 C CNN
	1    13000 4800
	1    0    0    -1  
$EndComp
NoConn ~ 14100 5200
NoConn ~ 11900 6500
$Comp
L mtg_life_counter:KW4-56NX D4
U 1 1 5F500652
P 13000 6100
F 0 "D4" H 13000 6767 50  0000 C CNN
F 1 "KW4-56NX BLUE" H 13000 6676 50  0000 C CNN
F 2 "mtg_life_counter:KW4-56NX" H 13000 5500 50  0001 C CNN
F 3 "https://cdn-shop.adafruit.com/datasheets/865datasheet.pdf" H 12570 6130 50  0001 C CNN
	1    13000 6100
	1    0    0    -1  
$EndComp
NoConn ~ 14100 6500
NoConn ~ 11900 5200
Wire Wire Line
	14100 4800 14500 4800
Wire Wire Line
	14500 5100 14600 5100
Wire Wire Line
	14100 4900 14400 4900
Wire Wire Line
	14400 5200 14600 5200
Wire Wire Line
	14100 5000 14300 5000
Wire Wire Line
	14300 5300 14600 5300
Wire Wire Line
	14600 5500 14200 5500
Wire Wire Line
	14200 6100 14100 6100
Wire Wire Line
	14100 6200 14300 6200
Wire Wire Line
	14300 5600 14600 5600
Wire Wire Line
	14100 6300 14400 6300
Wire Wire Line
	14400 5700 14600 5700
Wire Wire Line
	14300 5000 14300 5300
Wire Wire Line
	14500 4800 14500 5100
Wire Wire Line
	14200 5500 14200 6100
Wire Wire Line
	14300 5600 14300 6200
Wire Wire Line
	14400 5700 14400 6300
$Comp
L power:GND #PWR03
U 1 1 5F50EC61
P 6200 2100
F 0 "#PWR03" H 6200 1850 50  0001 C CNN
F 1 "GND" H 6205 1927 50  0000 C CNN
F 2 "" H 6200 2100 50  0001 C CNN
F 3 "" H 6200 2100 50  0001 C CNN
	1    6200 2100
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74HC595 U3
U 1 1 5F6D81D0
P 10000 4800
F 0 "U3" H 9750 5400 50  0000 C CNN
F 1 "74HC595" H 10250 4100 50  0000 C CNN
F 2 "Package_SO:SOIC-16_3.9x9.9mm_P1.27mm" H 10000 4800 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/sn74hc595.pdf" H 10000 4800 50  0001 C CNN
	1    10000 4800
	1    0    0    -1  
$EndComp
Wire Wire Line
	10400 5100 10500 5100
Wire Wire Line
	10400 5000 10600 5000
Wire Wire Line
	10400 4900 10700 4900
Wire Wire Line
	10400 4800 10800 4800
Wire Wire Line
	10400 4700 10900 4700
Wire Wire Line
	10400 4600 11000 4600
Wire Wire Line
	10400 4500 11100 4500
Wire Wire Line
	10400 4400 11200 4400
Wire Wire Line
	11400 6400 10500 6400
Wire Wire Line
	10500 6400 10500 5100
Connection ~ 10500 5100
Wire Wire Line
	10500 5100 11400 5100
Wire Wire Line
	11400 6300 10600 6300
Wire Wire Line
	10600 6300 10600 5000
Connection ~ 10600 5000
Wire Wire Line
	10600 5000 11400 5000
Wire Wire Line
	11400 6200 10700 6200
Wire Wire Line
	10700 6200 10700 4900
Connection ~ 10700 4900
Wire Wire Line
	10700 4900 11400 4900
Wire Wire Line
	11400 6100 10800 6100
Wire Wire Line
	10800 6100 10800 4800
Connection ~ 10800 4800
Wire Wire Line
	10800 4800 11400 4800
Wire Wire Line
	11400 6000 10900 6000
Wire Wire Line
	10900 6000 10900 4700
Connection ~ 10900 4700
Wire Wire Line
	10900 4700 11400 4700
Wire Wire Line
	11400 5900 11000 5900
Wire Wire Line
	11000 5900 11000 4600
Connection ~ 11000 4600
Wire Wire Line
	11000 4600 11400 4600
Wire Wire Line
	11100 4500 11100 5800
Wire Wire Line
	11100 5800 11400 5800
Connection ~ 11100 4500
Wire Wire Line
	11100 4500 11400 4500
Wire Wire Line
	11200 4400 11200 5700
Wire Wire Line
	11200 5700 11400 5700
Connection ~ 11200 4400
Wire Wire Line
	11200 4400 11400 4400
Wire Wire Line
	10400 1950 10500 1950
Wire Wire Line
	10400 1850 10600 1850
Wire Wire Line
	10400 1750 10700 1750
Wire Wire Line
	10400 1650 10800 1650
Wire Wire Line
	10400 1550 10900 1550
Wire Wire Line
	10400 1450 11000 1450
Wire Wire Line
	10400 1350 11100 1350
Wire Wire Line
	10400 1250 11200 1250
Wire Wire Line
	11400 3250 10500 3250
Wire Wire Line
	10500 3250 10500 1950
Wire Wire Line
	11400 3150 10600 3150
Wire Wire Line
	10600 3150 10600 1850
Wire Wire Line
	11400 3050 10700 3050
Wire Wire Line
	10700 3050 10700 1750
Wire Wire Line
	11400 2950 10800 2950
Wire Wire Line
	10800 2950 10800 1650
Wire Wire Line
	11400 2850 10900 2850
Wire Wire Line
	10900 2850 10900 1550
Wire Wire Line
	11400 2750 11000 2750
Wire Wire Line
	11000 2750 11000 1450
Wire Wire Line
	11100 1350 11100 2650
Wire Wire Line
	11100 2650 11400 2650
Wire Wire Line
	11200 1250 11200 2550
Wire Wire Line
	11200 2550 11400 2550
Connection ~ 10500 1950
Wire Wire Line
	10500 1950 11400 1950
Connection ~ 10600 1850
Wire Wire Line
	10600 1850 11400 1850
Connection ~ 10700 1750
Wire Wire Line
	10700 1750 11400 1750
Connection ~ 10800 1650
Wire Wire Line
	10800 1650 11400 1650
Connection ~ 10900 1550
Wire Wire Line
	10900 1550 11400 1550
Connection ~ 11000 1450
Wire Wire Line
	11000 1450 11400 1450
Connection ~ 11100 1350
Wire Wire Line
	11100 1350 11400 1350
Connection ~ 11200 1250
Wire Wire Line
	11200 1250 11400 1250
$Comp
L power:+5V #PWR02
U 1 1 5F917F3A
P 3800 4800
F 0 "#PWR02" H 3800 4650 50  0001 C CNN
F 1 "+5V" H 3815 4973 50  0000 C CNN
F 2 "" H 3800 4800 50  0001 C CNN
F 3 "" H 3800 4800 50  0001 C CNN
	1    3800 4800
	1    0    0    -1  
$EndComp
Wire Wire Line
	9100 1250 9600 1250
Text Label 9100 1450 0    50   ~ 0
SER_CLK
Wire Wire Line
	9100 1450 9600 1450
$Comp
L power:+5V #PWR06
U 1 1 5FAF53AB
P 10000 950
F 0 "#PWR06" H 10000 800 50  0001 C CNN
F 1 "+5V" H 10015 1123 50  0000 C CNN
F 2 "" H 10000 950 50  0001 C CNN
F 3 "" H 10000 950 50  0001 C CNN
	1    10000 950 
	1    0    0    -1  
$EndComp
Wire Wire Line
	10000 950  10100 950 
Connection ~ 10000 950 
Wire Wire Line
	10000 950  10000 1050
$Comp
L power:GND #PWR010
U 1 1 5FAF53BA
P 10400 950
F 0 "#PWR010" H 10400 700 50  0001 C CNN
F 1 "GND" H 10405 777 50  0000 C CNN
F 2 "" H 10400 950 50  0001 C CNN
F 3 "" H 10400 950 50  0001 C CNN
	1    10400 950 
	1    0    0    -1  
$EndComp
Wire Wire Line
	10300 950  10400 950 
$Comp
L power:GND #PWR07
U 1 1 5FB9488F
P 10000 2450
F 0 "#PWR07" H 10000 2200 50  0001 C CNN
F 1 "GND" H 10005 2277 50  0000 C CNN
F 2 "" H 10000 2450 50  0001 C CNN
F 3 "" H 10000 2450 50  0001 C CNN
	1    10000 2450
	1    0    0    -1  
$EndComp
Wire Wire Line
	10000 2350 10000 2450
Text Label 9100 4600 0    50   ~ 0
SER_CLK
Wire Wire Line
	9100 4600 9600 4600
$Comp
L power:+5V #PWR08
U 1 1 5FBF73D3
P 10000 4100
F 0 "#PWR08" H 10000 3950 50  0001 C CNN
F 1 "+5V" H 10015 4273 50  0000 C CNN
F 2 "" H 10000 4100 50  0001 C CNN
F 3 "" H 10000 4100 50  0001 C CNN
	1    10000 4100
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C6
U 1 1 5FBF73D9
P 10200 4100
F 0 "C6" V 10050 4100 50  0000 C CNN
F 1 "0.1uF" V 10100 4300 50  0000 C CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 10200 4100 50  0001 C CNN
F 3 "~" H 10200 4100 50  0001 C CNN
	1    10200 4100
	0    1    1    0   
$EndComp
Wire Wire Line
	10000 4100 10100 4100
Connection ~ 10000 4100
Wire Wire Line
	10000 4100 10000 4200
$Comp
L power:GND #PWR011
U 1 1 5FBF73E2
P 10400 4100
F 0 "#PWR011" H 10400 3850 50  0001 C CNN
F 1 "GND" H 10405 3927 50  0000 C CNN
F 2 "" H 10400 4100 50  0001 C CNN
F 3 "" H 10400 4100 50  0001 C CNN
	1    10400 4100
	1    0    0    -1  
$EndComp
Wire Wire Line
	10300 4100 10400 4100
$Comp
L power:GND #PWR09
U 1 1 5FC18F77
P 10000 5600
F 0 "#PWR09" H 10000 5350 50  0001 C CNN
F 1 "GND" H 10005 5427 50  0000 C CNN
F 2 "" H 10000 5600 50  0001 C CNN
F 3 "" H 10000 5600 50  0001 C CNN
	1    10000 5600
	1    0    0    -1  
$EndComp
Wire Wire Line
	10000 5500 10000 5600
Text Label 9950 5950 0    50   ~ 0
SER_LINK_3
Wire Wire Line
	9950 5950 10400 5950
Text Label 9100 4900 0    50   ~ 0
SER_LATCH
Wire Wire Line
	9100 4900 9600 4900
Text Label 9100 1750 0    50   ~ 0
SER_LATCH
Wire Wire Line
	9100 1750 9600 1750
Wire Wire Line
	9600 4700 9000 4700
$Comp
L Device:C_Small C5
U 1 1 5FAF53B1
P 10200 950
F 0 "C5" V 10050 950 50  0000 C CNN
F 1 "0.1uF" V 10100 1150 50  0000 C CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 10200 950 50  0001 C CNN
F 3 "~" H 10200 950 50  0001 C CNN
	1    10200 950 
	0    1    1    0   
$EndComp
Wire Wire Line
	9000 4700 9000 4100
Wire Wire Line
	9000 4100 10000 4100
Wire Wire Line
	9100 5000 9600 5000
Wire Wire Line
	9100 1850 9600 1850
Wire Wire Line
	10000 950  9000 950 
Wire Wire Line
	9000 950  9000 1550
Wire Wire Line
	9000 1550 9600 1550
Text Label 5050 2100 0    50   ~ 0
MODE_SW
$Comp
L power:GND #PWR04
U 1 1 60993EB2
P 6200 2600
F 0 "#PWR04" H 6200 2350 50  0001 C CNN
F 1 "GND" H 6205 2427 50  0000 C CNN
F 2 "" H 6200 2600 50  0001 C CNN
F 3 "" H 6200 2600 50  0001 C CNN
	1    6200 2600
	1    0    0    -1  
$EndComp
Wire Wire Line
	5950 2600 6200 2600
$Comp
L power:GND #PWR05
U 1 1 609B5688
P 6200 3100
F 0 "#PWR05" H 6200 2850 50  0001 C CNN
F 1 "GND" H 6205 2927 50  0000 C CNN
F 2 "" H 6200 3100 50  0001 C CNN
F 3 "" H 6200 3100 50  0001 C CNN
	1    6200 3100
	1    0    0    -1  
$EndComp
Wire Wire Line
	5950 3100 6200 3100
Text Label 5050 3100 0    50   ~ 0
ROLL_BTN
Text Label 5050 2600 0    50   ~ 0
RESET_BTN
Wire Wire Line
	5050 2600 5550 2600
Wire Wire Line
	5050 3100 5550 3100
Text Notes 6000 7850 0    100  ~ 20
Encoder Multiplexing
Text Notes 11000 900  0    100  ~ 20
Display Bank 1
Text Notes 11000 4000 0    100  ~ 20
Display Bank 2
Text Notes 950  900  0    100  ~ 20
Arduino
$Comp
L Switch:SW_SPST SW2
U 1 1 60EEF83B
P 5750 2100
F 0 "SW2" H 5750 2335 50  0000 C CNN
F 1 "SW_SPST" H 5750 2244 50  0000 C CNN
F 2 "Button_Switch_THT:SW_Slide_1P2T_CK_OS102011MS2Q" H 5750 2100 50  0001 C CNN
F 3 "~" H 5750 2100 50  0001 C CNN
	1    5750 2100
	1    0    0    -1  
$EndComp
Wire Wire Line
	5050 2100 5550 2100
Wire Wire Line
	5950 2100 6200 2100
Text Label 16100 5300 2    50   ~ 0
SER_CLK
Wire Wire Line
	15600 5300 16100 5300
Text Label 16100 5600 2    50   ~ 0
SER_LATCH
Wire Wire Line
	16100 5600 15600 5600
Wire Wire Line
	16100 5700 15600 5700
$Comp
L Device:R R3
U 1 1 617ED900
P 15900 5400
F 0 "R3" V 15900 5000 50  0000 C CNN
F 1 "10k" V 15900 5400 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 15830 5400 50  0001 C CNN
F 3 "~" H 15900 5400 50  0001 C CNN
	1    15900 5400
	0    -1   -1   0   
$EndComp
Wire Wire Line
	16200 5400 16050 5400
$Comp
L power:+5V #PWR019
U 1 1 618A0287
P 16200 5400
F 0 "#PWR019" H 16200 5250 50  0001 C CNN
F 1 "+5V" H 16215 5573 50  0000 C CNN
F 2 "" H 16200 5400 50  0001 C CNN
F 3 "" H 16200 5400 50  0001 C CNN
	1    16200 5400
	1    0    0    -1  
$EndComp
Wire Wire Line
	15600 5400 15750 5400
$Comp
L power:+5V #PWR014
U 1 1 618FE942
P 15100 4800
F 0 "#PWR014" H 15100 4650 50  0001 C CNN
F 1 "+5V" H 15115 4973 50  0000 C CNN
F 2 "" H 15100 4800 50  0001 C CNN
F 3 "" H 15100 4800 50  0001 C CNN
	1    15100 4800
	1    0    0    -1  
$EndComp
Wire Wire Line
	15100 4800 15100 4900
$Comp
L power:GND #PWR017
U 1 1 618FE949
P 15500 4800
F 0 "#PWR017" H 15500 4550 50  0001 C CNN
F 1 "GND" H 15500 4650 50  0000 C CNN
F 2 "" H 15500 4800 50  0001 C CNN
F 3 "" H 15500 4800 50  0001 C CNN
	1    15500 4800
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C8
U 1 1 618FE94F
P 15300 4800
F 0 "C8" V 15071 4800 50  0000 C CNN
F 1 "0.1uF" V 15162 4800 50  0000 C CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 15300 4800 50  0001 C CNN
F 3 "~" H 15300 4800 50  0001 C CNN
	1    15300 4800
	0    1    1    0   
$EndComp
Wire Wire Line
	15100 4800 15200 4800
Wire Wire Line
	15400 4800 15500 4800
Connection ~ 15100 4800
$Comp
L power:GND #PWR015
U 1 1 6192C3AD
P 15100 6300
F 0 "#PWR015" H 15100 6050 50  0001 C CNN
F 1 "GND" H 15100 6150 50  0000 C CNN
F 2 "" H 15100 6300 50  0001 C CNN
F 3 "" H 15100 6300 50  0001 C CNN
	1    15100 6300
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push B2
U 1 1 61D06B21
P 5750 3100
F 0 "B2" H 5750 3385 50  0000 C CNN
F 1 "SW_Push" H 5750 3294 50  0000 C CNN
F 2 "mtg_life_counter:B3F_12mm" H 5750 3300 50  0001 C CNN
F 3 "~" H 5750 3300 50  0001 C CNN
	1    5750 3100
	1    0    0    -1  
$EndComp
Wire Wire Line
	14600 2650 14500 2650
Wire Wire Line
	14500 2650 14500 3250
Wire Wire Line
	14500 3250 14100 3250
Wire Wire Line
	14600 2250 14200 2250
Wire Wire Line
	14200 2250 14200 1950
Wire Wire Line
	14200 1950 14100 1950
Wire Wire Line
	14600 5800 14500 5800
Wire Wire Line
	14500 5800 14500 6400
Wire Wire Line
	14500 6400 14100 6400
Wire Wire Line
	14600 5400 14200 5400
Wire Wire Line
	14200 5400 14200 5100
Wire Wire Line
	14200 5100 14100 5100
$Comp
L Mechanical:MountingHole_Pad H1
U 1 1 5F39CE52
P 6800 2550
F 0 "H1" H 6750 2750 50  0000 L CNN
F 1 "MountingHole_Pad" H 6900 2508 50  0001 L CNN
F 2 "MountingHole:MountingHole_3.2mm_M3_Pad_Via" H 6800 2550 50  0001 C CNN
F 3 "~" H 6800 2550 50  0001 C CNN
	1    6800 2550
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:MountingHole_Pad H4
U 1 1 5F39E86D
P 7550 2550
F 0 "H4" H 7500 2750 50  0000 L CNN
F 1 "MountingHole_Pad" H 7650 2508 50  0001 L CNN
F 2 "MountingHole:MountingHole_3.2mm_M3_Pad_Via" H 7550 2550 50  0001 C CNN
F 3 "~" H 7550 2550 50  0001 C CNN
	1    7550 2550
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:MountingHole_Pad H3
U 1 1 5F39EB49
P 7300 2550
F 0 "H3" H 7250 2750 50  0000 L CNN
F 1 "MountingHole_Pad" H 7400 2508 50  0001 L CNN
F 2 "MountingHole:MountingHole_3.2mm_M3_Pad_Via" H 7300 2550 50  0001 C CNN
F 3 "~" H 7300 2550 50  0001 C CNN
	1    7300 2550
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:MountingHole_Pad H2
U 1 1 5F39F052
P 7050 2550
F 0 "H2" H 7000 2750 50  0000 L CNN
F 1 "MountingHole_Pad" H 7150 2508 50  0001 L CNN
F 2 "MountingHole:MountingHole_3.2mm_M3_Pad_Via" H 7050 2550 50  0001 C CNN
F 3 "~" H 7050 2550 50  0001 C CNN
	1    7050 2550
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0102
U 1 1 5F39FC84
P 6800 2850
F 0 "#PWR0102" H 6800 2600 50  0001 C CNN
F 1 "GND" H 6805 2677 50  0000 C CNN
F 2 "" H 6800 2850 50  0001 C CNN
F 3 "" H 6800 2850 50  0001 C CNN
	1    6800 2850
	1    0    0    -1  
$EndComp
Wire Wire Line
	6800 2650 7050 2650
Wire Wire Line
	7050 2650 7300 2650
Connection ~ 7050 2650
Wire Wire Line
	7300 2650 7550 2650
Connection ~ 7300 2650
Wire Wire Line
	6800 2650 6800 2850
Connection ~ 6800 2650
Text Label 16100 2150 2    50   ~ 0
SER_CLK
Wire Wire Line
	15600 2150 16100 2150
Text Label 16100 2450 2    50   ~ 0
SER_LATCH
Wire Wire Line
	16100 2450 15600 2450
Text Label 16100 2550 2    50   ~ 0
~ENABLE
Wire Wire Line
	16100 2550 15600 2550
$Comp
L Device:R R2
U 1 1 5F968430
P 15900 2250
F 0 "R2" V 15900 1850 50  0000 C CNN
F 1 "10k" V 15900 2250 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 15830 2250 50  0001 C CNN
F 3 "~" H 15900 2250 50  0001 C CNN
	1    15900 2250
	0    -1   -1   0   
$EndComp
Wire Wire Line
	16200 2250 16050 2250
$Comp
L power:+5V #PWR0103
U 1 1 5F968437
P 16200 2250
F 0 "#PWR0103" H 16200 2100 50  0001 C CNN
F 1 "+5V" H 16215 2423 50  0000 C CNN
F 2 "" H 16200 2250 50  0001 C CNN
F 3 "" H 16200 2250 50  0001 C CNN
	1    16200 2250
	1    0    0    -1  
$EndComp
Wire Wire Line
	15600 2250 15750 2250
$Comp
L power:+5V #PWR0104
U 1 1 5F96843E
P 15100 1650
F 0 "#PWR0104" H 15100 1500 50  0001 C CNN
F 1 "+5V" H 15115 1823 50  0000 C CNN
F 2 "" H 15100 1650 50  0001 C CNN
F 3 "" H 15100 1650 50  0001 C CNN
	1    15100 1650
	1    0    0    -1  
$EndComp
Wire Wire Line
	15100 1650 15100 1750
$Comp
L power:GND #PWR0105
U 1 1 5F968445
P 15500 1650
F 0 "#PWR0105" H 15500 1400 50  0001 C CNN
F 1 "GND" H 15500 1500 50  0000 C CNN
F 2 "" H 15500 1650 50  0001 C CNN
F 3 "" H 15500 1650 50  0001 C CNN
	1    15500 1650
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C7
U 1 1 5F96844B
P 15300 1650
F 0 "C7" V 15071 1650 50  0000 C CNN
F 1 "0.1uF" V 15162 1650 50  0000 C CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 15300 1650 50  0001 C CNN
F 3 "~" H 15300 1650 50  0001 C CNN
	1    15300 1650
	0    1    1    0   
$EndComp
Wire Wire Line
	15100 1650 15200 1650
Wire Wire Line
	15400 1650 15500 1650
Connection ~ 15100 1650
$Comp
L power:GND #PWR0106
U 1 1 5F968454
P 15100 3150
F 0 "#PWR0106" H 15100 2900 50  0001 C CNN
F 1 "GND" H 15100 3000 50  0000 C CNN
F 2 "" H 15100 3150 50  0001 C CNN
F 3 "" H 15100 3150 50  0001 C CNN
	1    15100 3150
	1    0    0    -1  
$EndComp
Wire Wire Line
	16100 1950 15600 1950
Wire Wire Line
	4700 9150 5450 9150
Wire Wire Line
	4700 9050 5350 9050
Wire Wire Line
	4700 8950 5250 8950
Wire Wire Line
	4700 8850 5150 8850
Wire Wire Line
	5150 8350 5150 8850
Connection ~ 5150 8850
Wire Wire Line
	5250 8350 5250 8950
Connection ~ 5250 8950
Wire Wire Line
	5350 8350 5350 9050
Connection ~ 5350 9050
Wire Wire Line
	5450 8350 5450 9150
Connection ~ 5450 9150
Wire Wire Line
	14400 4900 14400 5200
Text Label 16100 5900 2    50   ~ 0
SER_LINK_1
Text Label 16100 2750 2    50   ~ 0
SER_LINK_2
NoConn ~ 3700 8550
Wire Wire Line
	3200 8450 3700 8450
$Comp
L Device:Rotary_Encoder_Switch E1
U 1 1 5F674E57
P 6900 8450
F 0 "E1" H 6900 8817 50  0000 C CNN
F 1 "Rotary_Encoder_Switch" H 6900 8726 50  0000 C CNN
F 2 "Rotary_Encoder:RotaryEncoder_Alps_EC11E-Switch_Vertical_H20mm" H 6750 8610 50  0001 C CNN
F 3 "~" H 6900 8710 50  0001 C CNN
	1    6900 8450
	1    0    0    -1  
$EndComp
$Comp
L Interface_USB:FT232RL U7
U 1 1 5F77F9F3
P 6000 5450
F 0 "U7" H 5450 6350 50  0000 C CNN
F 1 "FT232RL" H 6500 6350 50  0000 C CNN
F 2 "Package_SO:SSOP-28_5.3x10.2mm_P0.65mm" H 6000 5450 50  0001 C CNN
F 3 "http://www.ftdichip.com/Products/ICs/FT232RL.htm" H 6000 5450 50  0001 C CNN
	1    6000 5450
	1    0    0    -1  
$EndComp
Text Label 16100 5700 2    50   ~ 0
~ENABLE
Text Label 9100 5000 0    50   ~ 0
~ENABLE
Text Label 9100 1850 0    50   ~ 0
~ENABLE
Text Label 3500 5500 2    50   ~ 0
USB_DP
Text Label 3500 5300 2    50   ~ 0
USB_DM
$Comp
L power:GND #PWR0101
U 1 1 5F537739
P 2400 6400
F 0 "#PWR0101" H 2400 6150 50  0001 C CNN
F 1 "GND" H 2405 6227 50  0000 C CNN
F 2 "" H 2400 6400 50  0001 C CNN
F 3 "" H 2400 6400 50  0001 C CNN
	1    2400 6400
	1    0    0    -1  
$EndComp
Wire Wire Line
	3700 4800 3800 4800
Wire Wire Line
	3500 5500 3000 5500
Wire Wire Line
	3500 5300 3000 5300
Text Label 4850 5050 0    50   ~ 0
USB_DP
Wire Wire Line
	4850 5050 5200 5050
Wire Wire Line
	4850 5150 5200 5150
Text Label 4850 5150 0    50   ~ 0
USB_DM
NoConn ~ 5200 4750
$Comp
L mtg_life_counter:ATmega328P-AU U1
U 1 1 5F524725
P 2500 2250
F 0 "U1" H 2500 3567 50  0000 C CNN
F 1 "ATmega328P-AU" H 2500 3476 50  0000 C CNN
F 2 "Package_QFP:TQFP-32_7x7mm_P0.8mm" H 2550 2050 50  0001 C CIN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/ATmega328_P%20AVR%20MCU%20with%20picoPower%20Technology%20Data%20Sheet%2040001984A.pdf" H 2500 2000 50  0001 C CNN
	1    2500 2250
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0107
U 1 1 5F6155B4
P 1800 3400
F 0 "#PWR0107" H 1800 3150 50  0001 C CNN
F 1 "GND" H 1805 3227 50  0000 C CNN
F 2 "" H 1800 3400 50  0001 C CNN
F 3 "" H 1800 3400 50  0001 C CNN
	1    1800 3400
	1    0    0    -1  
$EndComp
Wire Wire Line
	1800 3400 1800 3300
Wire Wire Line
	1800 3200 1900 3200
Wire Wire Line
	1900 3300 1800 3300
Connection ~ 1800 3300
Wire Wire Line
	1800 3300 1800 3200
Text Label 1600 2900 0    50   ~ 0
~RESET
$Comp
L power:GND #PWR0108
U 1 1 5F64CCAE
P 1100 2300
F 0 "#PWR0108" H 1100 2050 50  0001 C CNN
F 1 "GND" H 1105 2127 50  0000 C CNN
F 2 "" H 1100 2300 50  0001 C CNN
F 3 "" H 1100 2300 50  0001 C CNN
	1    1100 2300
	1    0    0    -1  
$EndComp
Wire Wire Line
	10400 5950 10400 5300
$Comp
L Switch:SW_SPST SW1
U 1 1 5F6C1609
P 3500 4800
F 0 "SW1" H 3500 5035 50  0000 C CNN
F 1 "SW_SPST" H 3500 4944 50  0000 C CNN
F 2 "Button_Switch_THT:SW_Slide_1P2T_CK_OS102011MS2Q" H 3500 4800 50  0001 C CNN
F 3 "~" H 3500 4800 50  0001 C CNN
	1    3500 4800
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR0109
U 1 1 5F714DE6
P 1800 1200
F 0 "#PWR0109" H 1800 1050 50  0001 C CNN
F 1 "+5V" H 1815 1373 50  0000 C CNN
F 2 "" H 1800 1200 50  0001 C CNN
F 3 "" H 1800 1200 50  0001 C CNN
	1    1800 1200
	1    0    0    -1  
$EndComp
Wire Wire Line
	1800 1200 1900 1200
Wire Wire Line
	1800 1200 1800 1300
Wire Wire Line
	1800 1300 1900 1300
Connection ~ 1800 1200
NoConn ~ 1900 2100
NoConn ~ 1900 2500
NoConn ~ 1900 2600
$Comp
L power:+5V #PWR0110
U 1 1 5F7DDC41
P 1500 2200
F 0 "#PWR0110" H 1500 2050 50  0001 C CNN
F 1 "+5V" H 1515 2373 50  0000 C CNN
F 2 "" H 1500 2200 50  0001 C CNN
F 3 "" H 1500 2200 50  0001 C CNN
	1    1500 2200
	1    0    0    -1  
$EndComp
Wire Wire Line
	1500 2200 1900 2200
Text Label 16100 5100 2    50   ~ 0
SER_DATA
Wire Wire Line
	15600 5100 16100 5100
Text Label 16100 1950 2    50   ~ 0
SER_LINK_1
Text Label 9100 4400 0    50   ~ 0
SER_LINK_2
Wire Wire Line
	9100 4400 9600 4400
Text Label 9100 1250 0    50   ~ 0
SER_LINK_3
NoConn ~ 10400 2150
Text Label 6300 8350 0    50   ~ 0
E1_CLK
Text Label 6300 8550 0    50   ~ 0
E1_DIR
Wire Wire Line
	6300 8350 6600 8350
Wire Wire Line
	6300 8550 6600 8550
Text Label 7500 8350 2    50   ~ 0
E1_SW
$Comp
L power:GND #PWR0111
U 1 1 5FB2121B
P 7200 8750
F 0 "#PWR0111" H 7200 8500 50  0001 C CNN
F 1 "GND" H 7205 8577 50  0000 C CNN
F 2 "" H 7200 8750 50  0001 C CNN
F 3 "" H 7200 8750 50  0001 C CNN
	1    7200 8750
	1    0    0    -1  
$EndComp
Wire Wire Line
	7200 8350 7500 8350
Wire Wire Line
	6200 8450 6200 8750
Wire Wire Line
	6200 8750 7200 8750
Wire Wire Line
	7200 8750 7200 8550
Wire Wire Line
	6200 8450 6600 8450
Connection ~ 7200 8750
$Comp
L Device:Rotary_Encoder_Switch E2
U 1 1 5FBBE8FD
P 8400 8450
F 0 "E2" H 8400 8817 50  0000 C CNN
F 1 "Rotary_Encoder_Switch" H 8400 8726 50  0000 C CNN
F 2 "Rotary_Encoder:RotaryEncoder_Alps_EC11E-Switch_Vertical_H20mm" H 8250 8610 50  0001 C CNN
F 3 "~" H 8400 8710 50  0001 C CNN
	1    8400 8450
	1    0    0    -1  
$EndComp
Text Label 7800 8350 0    50   ~ 0
E2_CLK
Text Label 7800 8550 0    50   ~ 0
E2_DIR
Wire Wire Line
	7800 8350 8100 8350
Wire Wire Line
	7800 8550 8100 8550
Text Label 9000 8350 2    50   ~ 0
E2_SW
$Comp
L power:GND #PWR0112
U 1 1 5FBBE908
P 8700 8750
F 0 "#PWR0112" H 8700 8500 50  0001 C CNN
F 1 "GND" H 8705 8577 50  0000 C CNN
F 2 "" H 8700 8750 50  0001 C CNN
F 3 "" H 8700 8750 50  0001 C CNN
	1    8700 8750
	1    0    0    -1  
$EndComp
Wire Wire Line
	8700 8350 9000 8350
Wire Wire Line
	7700 8450 7700 8750
Wire Wire Line
	7700 8750 8700 8750
Wire Wire Line
	8700 8750 8700 8550
Wire Wire Line
	7700 8450 8100 8450
Connection ~ 8700 8750
$Comp
L Device:Rotary_Encoder_Switch E3
U 1 1 5FBDF65E
P 6900 9450
F 0 "E3" H 6900 9817 50  0000 C CNN
F 1 "Rotary_Encoder_Switch" H 6900 9726 50  0000 C CNN
F 2 "Rotary_Encoder:RotaryEncoder_Alps_EC11E-Switch_Vertical_H20mm" H 6750 9610 50  0001 C CNN
F 3 "~" H 6900 9710 50  0001 C CNN
	1    6900 9450
	1    0    0    -1  
$EndComp
Text Label 6300 9350 0    50   ~ 0
E3_CLK
Text Label 6300 9550 0    50   ~ 0
E3_DIR
Wire Wire Line
	6300 9350 6600 9350
Wire Wire Line
	6300 9550 6600 9550
Text Label 7500 9350 2    50   ~ 0
E3_SW
$Comp
L power:GND #PWR0113
U 1 1 5FBDF669
P 7200 9750
F 0 "#PWR0113" H 7200 9500 50  0001 C CNN
F 1 "GND" H 7205 9577 50  0000 C CNN
F 2 "" H 7200 9750 50  0001 C CNN
F 3 "" H 7200 9750 50  0001 C CNN
	1    7200 9750
	1    0    0    -1  
$EndComp
Wire Wire Line
	7200 9350 7500 9350
Wire Wire Line
	6200 9450 6200 9750
Wire Wire Line
	6200 9750 7200 9750
Wire Wire Line
	7200 9750 7200 9550
Wire Wire Line
	6200 9450 6600 9450
Connection ~ 7200 9750
$Comp
L Device:Rotary_Encoder_Switch E4
U 1 1 5FC01795
P 8400 9450
F 0 "E4" H 8400 9817 50  0000 C CNN
F 1 "Rotary_Encoder_Switch" H 8400 9726 50  0000 C CNN
F 2 "Rotary_Encoder:RotaryEncoder_Alps_EC11E-Switch_Vertical_H20mm" H 8250 9610 50  0001 C CNN
F 3 "~" H 8400 9710 50  0001 C CNN
	1    8400 9450
	1    0    0    -1  
$EndComp
Text Label 7800 9350 0    50   ~ 0
E4_CLK
Text Label 7800 9550 0    50   ~ 0
E4_DIR
Wire Wire Line
	7800 9350 8100 9350
Wire Wire Line
	7800 9550 8100 9550
Text Label 9000 9350 2    50   ~ 0
E4_SW
$Comp
L power:GND #PWR0114
U 1 1 5FC017A0
P 8700 9750
F 0 "#PWR0114" H 8700 9500 50  0001 C CNN
F 1 "GND" H 8705 9577 50  0000 C CNN
F 2 "" H 8700 9750 50  0001 C CNN
F 3 "" H 8700 9750 50  0001 C CNN
	1    8700 9750
	1    0    0    -1  
$EndComp
Wire Wire Line
	8700 9350 9000 9350
Wire Wire Line
	7700 9450 8100 9450
Text Label 5850 8450 2    50   ~ 0
E1_CLK
Text Label 5850 8550 2    50   ~ 0
E1_DIR
Text Label 5850 8650 2    50   ~ 0
E2_CLK
Text Label 5850 8750 2    50   ~ 0
E2_DIR
Text Label 5850 8850 2    50   ~ 0
E3_CLK
Text Label 5850 8950 2    50   ~ 0
E3_DIR
Text Label 5850 9050 2    50   ~ 0
E4_CLK
Text Label 5850 9150 2    50   ~ 0
E4_DIR
Wire Wire Line
	5150 8850 5850 8850
Wire Wire Line
	5250 8950 5850 8950
Wire Wire Line
	5350 9050 5850 9050
Wire Wire Line
	5450 9150 5850 9150
Wire Wire Line
	8700 9750 8700 9550
Wire Wire Line
	7700 9750 8700 9750
Wire Wire Line
	7700 9450 7700 9750
Connection ~ 8700 9750
Wire Wire Line
	4700 8750 5050 8750
Wire Wire Line
	4700 8650 4950 8650
Wire Wire Line
	4700 8550 4850 8550
Wire Wire Line
	4700 8450 4750 8450
Wire Wire Line
	4750 8350 4750 8450
Connection ~ 4750 8450
Wire Wire Line
	4750 8450 5850 8450
Wire Wire Line
	4850 8350 4850 8550
Connection ~ 4850 8550
Wire Wire Line
	4850 8550 5850 8550
Wire Wire Line
	4950 8350 4950 8650
Connection ~ 4950 8650
Wire Wire Line
	4950 8650 5850 8650
Wire Wire Line
	5050 8350 5050 8750
Connection ~ 5050 8750
Wire Wire Line
	5050 8750 5850 8750
Wire Wire Line
	1500 2900 1900 2900
Text Label 4050 1200 2    50   ~ 0
SER_CLK
Text Label 4050 1400 2    50   ~ 0
SER_DATA
Text Label 4050 3200 2    50   ~ 0
D1(TX)
Text Label 4050 3300 2    50   ~ 0
D0(RX)
Text Label 1700 2600 0    50   ~ 0
A7
Text Label 1700 2500 0    50   ~ 0
A6
Wire Wire Line
	1700 2500 1900 2500
Wire Wire Line
	1700 2600 1900 2600
Text Label 1700 2100 0    50   ~ 0
AREF
Wire Wire Line
	1700 2100 1900 2100
Wire Wire Line
	1100 2300 1900 2300
Wire Wire Line
	3100 1200 4050 1200
Wire Wire Line
	3100 1400 4050 1400
Wire Wire Line
	4050 3200 3100 3200
Wire Wire Line
	3100 3300 4050 3300
Text Label 7700 4850 2    50   ~ 0
D1(TX)
Text Label 7700 4750 2    50   ~ 0
D0(RX)
$Comp
L Device:R R4
U 1 1 60517BE8
P 7150 4750
F 0 "R4" V 7100 4550 50  0000 C CNN
F 1 "1k" V 7150 4750 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 7080 4750 50  0001 C CNN
F 3 "~" H 7150 4750 50  0001 C CNN
	1    7150 4750
	0    1    1    0   
$EndComp
$Comp
L Device:R R5
U 1 1 60518533
P 7150 4850
F 0 "R5" V 7100 4650 50  0000 C CNN
F 1 "1k" V 7150 4850 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 7080 4850 50  0001 C CNN
F 3 "~" H 7150 4850 50  0001 C CNN
	1    7150 4850
	0    1    1    0   
$EndComp
Wire Wire Line
	6800 4750 7000 4750
Wire Wire Line
	6800 4850 7000 4850
Wire Wire Line
	7700 4750 7300 4750
Wire Wire Line
	7300 4850 7700 4850
$Comp
L power:+5V #PWR0115
U 1 1 605CC24E
P 5900 4350
F 0 "#PWR0115" H 5900 4200 50  0001 C CNN
F 1 "+5V" H 5915 4523 50  0000 C CNN
F 2 "" H 5900 4350 50  0001 C CNN
F 3 "" H 5900 4350 50  0001 C CNN
	1    5900 4350
	1    0    0    -1  
$EndComp
Wire Wire Line
	5900 4350 5900 4450
Wire Wire Line
	5900 4450 6100 4450
Connection ~ 5900 4450
$Comp
L power:GND #PWR0116
U 1 1 6062903A
P 6200 6550
F 0 "#PWR0116" H 6200 6300 50  0001 C CNN
F 1 "GND" H 6205 6377 50  0000 C CNN
F 2 "" H 6200 6550 50  0001 C CNN
F 3 "" H 6200 6550 50  0001 C CNN
	1    6200 6550
	1    0    0    -1  
$EndComp
Wire Wire Line
	5800 6450 6000 6450
Wire Wire Line
	6000 6450 6100 6450
Connection ~ 6000 6450
Wire Wire Line
	6100 6450 6200 6450
Connection ~ 6100 6450
Wire Wire Line
	6200 6450 6200 6550
Connection ~ 6200 6450
Wire Wire Line
	5200 6150 5200 6450
Wire Wire Line
	5200 6450 5800 6450
Connection ~ 5800 6450
NoConn ~ 5200 5850
NoConn ~ 5200 5650
NoConn ~ 5200 5450
NoConn ~ 6800 5450
NoConn ~ 6800 5350
NoConn ~ 6800 5250
NoConn ~ 6800 4950
NoConn ~ 6800 5050
NoConn ~ 6800 5750
NoConn ~ 6800 5850
NoConn ~ 6800 5950
NoConn ~ 6800 6050
NoConn ~ 6800 6150
$Comp
L Device:C_Small C10
U 1 1 6099BD84
P 7150 5150
F 0 "C10" V 7300 5150 50  0000 C CNN
F 1 "0.1uF" V 7400 5150 50  0000 C CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 7150 5150 50  0001 C CNN
F 3 "~" H 7150 5150 50  0001 C CNN
	1    7150 5150
	0    1    1    0   
$EndComp
Wire Wire Line
	6800 5150 7050 5150
Wire Notes Line width 10
	4650 4000 7850 4000
Wire Notes Line width 10
	7850 4000 7850 6950
Wire Notes Line width 10
	7850 6950 4650 6950
Wire Notes Line width 10
	4650 6950 4650 4000
Text Notes 7300 6850 0    100  ~ 20
DNP
Text Label 7700 5150 2    50   ~ 0
~RESET
Wire Wire Line
	7250 5150 7700 5150
$Comp
L Connector_Generic:Conn_02x03_Odd_Even J2
U 1 1 60AE0CDA
P 5750 1200
F 0 "J2" H 5800 1517 50  0000 C CNN
F 1 "ICSP" H 5800 1426 50  0000 C CNN
F 2 "Connector:Tag-Connect_TC2030-IDC-NL_2x03_P1.27mm_Vertical" H 5750 1200 50  0001 C CNN
F 3 "~" H 5750 1200 50  0001 C CNN
	1    5750 1200
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR0117
U 1 1 60B701C5
P 6150 1100
F 0 "#PWR0117" H 6150 950 50  0001 C CNN
F 1 "+5V" H 6165 1273 50  0000 C CNN
F 2 "" H 6150 1100 50  0001 C CNN
F 3 "" H 6150 1100 50  0001 C CNN
	1    6150 1100
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0118
U 1 1 60B706FB
P 6150 1300
F 0 "#PWR0118" H 6150 1050 50  0001 C CNN
F 1 "GND" H 6155 1127 50  0000 C CNN
F 2 "" H 6150 1300 50  0001 C CNN
F 3 "" H 6150 1300 50  0001 C CNN
	1    6150 1300
	1    0    0    -1  
$EndComp
Text Label 5050 1200 0    50   ~ 0
D13(SCK)
Text Label 5050 1100 0    50   ~ 0
D12(MISO)
Text Label 6550 1200 2    50   ~ 0
D11(MOSI)
Text Label 5050 1300 0    50   ~ 0
~RESET
Wire Wire Line
	5050 1100 5550 1100
Wire Wire Line
	5050 1200 5550 1200
Wire Wire Line
	5050 1300 5550 1300
Wire Wire Line
	6150 1100 6050 1100
Wire Wire Line
	6550 1200 6050 1200
Wire Wire Line
	6150 1300 6050 1300
Wire Wire Line
	5450 7950 5450 8050
Wire Wire Line
	5350 7950 5350 8050
Connection ~ 5350 7950
Wire Wire Line
	5350 7950 5450 7950
Wire Wire Line
	5250 7950 5250 8050
Wire Wire Line
	4650 7950 4750 7950
Connection ~ 5250 7950
Wire Wire Line
	5250 7950 5350 7950
Wire Wire Line
	5150 8050 5150 7950
Connection ~ 5150 7950
Wire Wire Line
	5150 7950 5250 7950
Wire Wire Line
	5050 7950 5050 8050
Connection ~ 5050 7950
Wire Wire Line
	5050 7950 5150 7950
Wire Wire Line
	4950 8050 4950 7950
Connection ~ 4950 7950
Wire Wire Line
	4950 7950 5050 7950
Wire Wire Line
	4850 7950 4850 8050
Connection ~ 4850 7950
Wire Wire Line
	4850 7950 4950 7950
$Comp
L Device:R R1
U 1 1 5FAE2013
P 1350 2900
F 0 "R1" V 1250 2900 50  0000 C CNN
F 1 "1k" V 1350 2900 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 1280 2900 50  0001 C CNN
F 3 "~" H 1350 2900 50  0001 C CNN
	1    1350 2900
	0    1    1    0   
$EndComp
Wire Wire Line
	16100 2750 15600 2750
Wire Wire Line
	15100 3050 15100 3150
Wire Wire Line
	15100 6200 15100 6300
Wire Wire Line
	16100 5900 15600 5900
$Comp
L Device:R R50
U 1 1 5FC9A634
P 4750 8200
F 0 "R50" V 4750 7850 50  0000 C CNN
F 1 "10k" V 4750 8200 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 4680 8200 50  0001 C CNN
F 3 "~" H 4750 8200 50  0001 C CNN
	1    4750 8200
	-1   0    0    1   
$EndComp
$Comp
L Device:R R51
U 1 1 5FCF8D4C
P 4850 8200
F 0 "R51" V 4850 7850 50  0000 C CNN
F 1 "10k" V 4850 8200 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 4780 8200 50  0001 C CNN
F 3 "~" H 4850 8200 50  0001 C CNN
	1    4850 8200
	-1   0    0    1   
$EndComp
$Comp
L Device:R R52
U 1 1 5FCF907B
P 4950 8200
F 0 "R52" V 4950 7850 50  0000 C CNN
F 1 "10k" V 4950 8200 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 4880 8200 50  0001 C CNN
F 3 "~" H 4950 8200 50  0001 C CNN
	1    4950 8200
	-1   0    0    1   
$EndComp
$Comp
L Device:R R53
U 1 1 5FCF927C
P 5050 8200
F 0 "R53" V 5050 7850 50  0000 C CNN
F 1 "10k" V 5050 8200 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 4980 8200 50  0001 C CNN
F 3 "~" H 5050 8200 50  0001 C CNN
	1    5050 8200
	-1   0    0    1   
$EndComp
$Comp
L Device:R R54
U 1 1 5FCF9481
P 5150 8200
F 0 "R54" V 5150 7850 50  0000 C CNN
F 1 "10k" V 5150 8200 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 5080 8200 50  0001 C CNN
F 3 "~" H 5150 8200 50  0001 C CNN
	1    5150 8200
	-1   0    0    1   
$EndComp
$Comp
L Device:R R55
U 1 1 5FCF96F4
P 5250 8200
F 0 "R55" V 5250 7850 50  0000 C CNN
F 1 "10k" V 5250 8200 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 5180 8200 50  0001 C CNN
F 3 "~" H 5250 8200 50  0001 C CNN
	1    5250 8200
	-1   0    0    1   
$EndComp
$Comp
L Device:R R56
U 1 1 5FCF9B90
P 5350 8200
F 0 "R56" V 5350 7850 50  0000 C CNN
F 1 "10k" V 5350 8200 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 5280 8200 50  0001 C CNN
F 3 "~" H 5350 8200 50  0001 C CNN
	1    5350 8200
	-1   0    0    1   
$EndComp
$Comp
L Device:R R57
U 1 1 5FCF9DA1
P 5450 8200
F 0 "R57" V 5450 7850 50  0000 C CNN
F 1 "10k" V 5450 8200 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 5380 8200 50  0001 C CNN
F 3 "~" H 5450 8200 50  0001 C CNN
	1    5450 8200
	-1   0    0    1   
$EndComp
Wire Wire Line
	4750 8050 4750 7950
Connection ~ 4750 7950
Wire Wire Line
	4750 7950 4850 7950
$Comp
L Device:R R40
U 1 1 5FD83750
P 11550 5700
F 0 "R40" V 11600 5900 50  0000 C CNN
F 1 "390" V 11550 5700 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 11480 5700 50  0001 C CNN
F 3 "~" H 11550 5700 50  0001 C CNN
	1    11550 5700
	0    -1   -1   0   
$EndComp
Wire Wire Line
	11700 5700 11900 5700
$Comp
L Device:R R41
U 1 1 5FDB3E01
P 11550 5800
F 0 "R41" V 11600 6000 50  0000 C CNN
F 1 "390" V 11550 5800 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 11480 5800 50  0001 C CNN
F 3 "~" H 11550 5800 50  0001 C CNN
	1    11550 5800
	0    -1   -1   0   
$EndComp
$Comp
L Device:R R42
U 1 1 5FE0DE30
P 11550 5900
F 0 "R42" V 11600 6100 50  0000 C CNN
F 1 "390" V 11550 5900 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 11480 5900 50  0001 C CNN
F 3 "~" H 11550 5900 50  0001 C CNN
	1    11550 5900
	0    -1   -1   0   
$EndComp
Wire Wire Line
	11700 5900 11900 5900
$Comp
L Device:R R43
U 1 1 5FE39FDC
P 11550 6000
F 0 "R43" V 11600 6200 50  0000 C CNN
F 1 "390" V 11550 6000 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 11480 6000 50  0001 C CNN
F 3 "~" H 11550 6000 50  0001 C CNN
	1    11550 6000
	0    -1   -1   0   
$EndComp
Wire Wire Line
	11700 6000 11900 6000
$Comp
L Device:R R44
U 1 1 5FE665E4
P 11550 6100
F 0 "R44" V 11600 6300 50  0000 C CNN
F 1 "390" V 11550 6100 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 11480 6100 50  0001 C CNN
F 3 "~" H 11550 6100 50  0001 C CNN
	1    11550 6100
	0    -1   -1   0   
$EndComp
Wire Wire Line
	11700 6100 11900 6100
$Comp
L Device:R R45
U 1 1 5FE92F83
P 11550 6200
F 0 "R45" V 11600 6400 50  0000 C CNN
F 1 "390" V 11550 6200 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 11480 6200 50  0001 C CNN
F 3 "~" H 11550 6200 50  0001 C CNN
	1    11550 6200
	0    -1   -1   0   
$EndComp
Wire Wire Line
	11700 6200 11900 6200
$Comp
L Device:R R46
U 1 1 5FEBFD0C
P 11550 6300
F 0 "R46" V 11600 6500 50  0000 C CNN
F 1 "390" V 11550 6300 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 11480 6300 50  0001 C CNN
F 3 "~" H 11550 6300 50  0001 C CNN
	1    11550 6300
	0    -1   -1   0   
$EndComp
Wire Wire Line
	11700 6300 11900 6300
$Comp
L Device:R R47
U 1 1 5FEECEDC
P 11550 6400
F 0 "R47" V 11600 6600 50  0000 C CNN
F 1 "390" V 11550 6400 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 11480 6400 50  0001 C CNN
F 3 "~" H 11550 6400 50  0001 C CNN
	1    11550 6400
	0    -1   -1   0   
$EndComp
Wire Wire Line
	11700 6400 11900 6400
Wire Wire Line
	11700 5800 11900 5800
$Comp
L Device:R R30
U 1 1 5FF74498
P 11550 4400
F 0 "R30" V 11600 4600 50  0000 C CNN
F 1 "100" V 11550 4400 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 11480 4400 50  0001 C CNN
F 3 "~" H 11550 4400 50  0001 C CNN
	1    11550 4400
	0    -1   -1   0   
$EndComp
Wire Wire Line
	11700 4400 11900 4400
$Comp
L Device:R R31
U 1 1 5FFA0906
P 11550 4500
F 0 "R31" V 11600 4700 50  0000 C CNN
F 1 "100" V 11550 4500 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 11480 4500 50  0001 C CNN
F 3 "~" H 11550 4500 50  0001 C CNN
	1    11550 4500
	0    -1   -1   0   
$EndComp
Wire Wire Line
	11700 4500 11900 4500
$Comp
L Device:R R32
U 1 1 5FFF9CF8
P 11550 4600
F 0 "R32" V 11600 4800 50  0000 C CNN
F 1 "100" V 11550 4600 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 11480 4600 50  0001 C CNN
F 3 "~" H 11550 4600 50  0001 C CNN
	1    11550 4600
	0    -1   -1   0   
$EndComp
Wire Wire Line
	11700 4600 11900 4600
$Comp
L Device:R R33
U 1 1 600263EE
P 11550 4700
F 0 "R33" V 11600 4900 50  0000 C CNN
F 1 "100" V 11550 4700 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 11480 4700 50  0001 C CNN
F 3 "~" H 11550 4700 50  0001 C CNN
	1    11550 4700
	0    -1   -1   0   
$EndComp
Wire Wire Line
	11700 4700 11900 4700
$Comp
L Device:R R34
U 1 1 60052EF3
P 11550 4800
F 0 "R34" V 11600 5000 50  0000 C CNN
F 1 "100" V 11550 4800 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 11480 4800 50  0001 C CNN
F 3 "~" H 11550 4800 50  0001 C CNN
	1    11550 4800
	0    -1   -1   0   
$EndComp
Wire Wire Line
	11700 4800 11900 4800
$Comp
L Device:R R35
U 1 1 6007FEA6
P 11550 4900
F 0 "R35" V 11600 5100 50  0000 C CNN
F 1 "100" V 11550 4900 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 11480 4900 50  0001 C CNN
F 3 "~" H 11550 4900 50  0001 C CNN
	1    11550 4900
	0    -1   -1   0   
$EndComp
Wire Wire Line
	11700 4900 11900 4900
$Comp
L Device:R R36
U 1 1 600AD27A
P 11550 5000
F 0 "R36" V 11600 5200 50  0000 C CNN
F 1 "100" V 11550 5000 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 11480 5000 50  0001 C CNN
F 3 "~" H 11550 5000 50  0001 C CNN
	1    11550 5000
	0    -1   -1   0   
$EndComp
Wire Wire Line
	11700 5000 11900 5000
$Comp
L Device:R R37
U 1 1 600DA972
P 11550 5100
F 0 "R37" V 11600 5300 50  0000 C CNN
F 1 "100" V 11550 5100 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 11480 5100 50  0001 C CNN
F 3 "~" H 11550 5100 50  0001 C CNN
	1    11550 5100
	0    -1   -1   0   
$EndComp
Wire Wire Line
	11700 5100 11900 5100
$Comp
L Device:R R20
U 1 1 6013436E
P 11550 2550
F 0 "R20" V 11600 2750 50  0000 C CNN
F 1 "33" V 11550 2550 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 11480 2550 50  0001 C CNN
F 3 "~" H 11550 2550 50  0001 C CNN
	1    11550 2550
	0    -1   -1   0   
$EndComp
Wire Wire Line
	11700 2550 11900 2550
$Comp
L Device:R R21
U 1 1 601605D6
P 11550 2650
F 0 "R21" V 11600 2850 50  0000 C CNN
F 1 "33" V 11550 2650 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 11480 2650 50  0001 C CNN
F 3 "~" H 11550 2650 50  0001 C CNN
	1    11550 2650
	0    -1   -1   0   
$EndComp
Wire Wire Line
	11700 2650 11900 2650
$Comp
L Device:R R22
U 1 1 6018C9CE
P 11550 2750
F 0 "R22" V 11600 2950 50  0000 C CNN
F 1 "33" V 11550 2750 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 11480 2750 50  0001 C CNN
F 3 "~" H 11550 2750 50  0001 C CNN
	1    11550 2750
	0    -1   -1   0   
$EndComp
Wire Wire Line
	11700 2750 11900 2750
$Comp
L Device:R R23
U 1 1 601B910E
P 11550 2850
F 0 "R23" V 11600 3050 50  0000 C CNN
F 1 "33" V 11550 2850 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 11480 2850 50  0001 C CNN
F 3 "~" H 11550 2850 50  0001 C CNN
	1    11550 2850
	0    -1   -1   0   
$EndComp
Wire Wire Line
	11700 2850 11900 2850
$Comp
L Device:R R24
U 1 1 602135A8
P 11550 2950
F 0 "R24" V 11600 3150 50  0000 C CNN
F 1 "33" V 11550 2950 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 11480 2950 50  0001 C CNN
F 3 "~" H 11550 2950 50  0001 C CNN
	1    11550 2950
	0    -1   -1   0   
$EndComp
Wire Wire Line
	11700 2950 11900 2950
$Comp
L Device:R R25
U 1 1 60240563
P 11550 3050
F 0 "R25" V 11600 3250 50  0000 C CNN
F 1 "33" V 11550 3050 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 11480 3050 50  0001 C CNN
F 3 "~" H 11550 3050 50  0001 C CNN
	1    11550 3050
	0    -1   -1   0   
$EndComp
Wire Wire Line
	11700 3050 11900 3050
$Comp
L Device:R R26
U 1 1 6026D8DF
P 11550 3150
F 0 "R26" V 11600 3350 50  0000 C CNN
F 1 "33" V 11550 3150 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 11480 3150 50  0001 C CNN
F 3 "~" H 11550 3150 50  0001 C CNN
	1    11550 3150
	0    -1   -1   0   
$EndComp
Wire Wire Line
	11700 3150 11900 3150
$Comp
L Device:R R27
U 1 1 6029B077
P 11550 3250
F 0 "R27" V 11600 3450 50  0000 C CNN
F 1 "33" V 11550 3250 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 11480 3250 50  0001 C CNN
F 3 "~" H 11550 3250 50  0001 C CNN
	1    11550 3250
	0    -1   -1   0   
$EndComp
Wire Wire Line
	11700 3250 11900 3250
$Comp
L Device:R R10
U 1 1 602F4A93
P 11550 1250
F 0 "R10" V 11600 1450 50  0000 C CNN
F 1 "330" V 11550 1250 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 11480 1250 50  0001 C CNN
F 3 "~" H 11550 1250 50  0001 C CNN
	1    11550 1250
	0    -1   -1   0   
$EndComp
Wire Wire Line
	11700 1250 11900 1250
$Comp
L Device:R R11
U 1 1 6034D8BB
P 11550 1350
F 0 "R11" V 11600 1550 50  0000 C CNN
F 1 "330" V 11550 1350 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 11480 1350 50  0001 C CNN
F 3 "~" H 11550 1350 50  0001 C CNN
	1    11550 1350
	0    -1   -1   0   
$EndComp
Wire Wire Line
	11700 1350 11900 1350
$Comp
L Device:R R12
U 1 1 60379B6D
P 11550 1450
F 0 "R12" V 11600 1650 50  0000 C CNN
F 1 "330" V 11550 1450 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 11480 1450 50  0001 C CNN
F 3 "~" H 11550 1450 50  0001 C CNN
	1    11550 1450
	0    -1   -1   0   
$EndComp
Wire Wire Line
	11700 1450 11900 1450
$Comp
L Device:R R13
U 1 1 603A623D
P 11550 1550
F 0 "R13" V 11600 1750 50  0000 C CNN
F 1 "330" V 11550 1550 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 11480 1550 50  0001 C CNN
F 3 "~" H 11550 1550 50  0001 C CNN
	1    11550 1550
	0    -1   -1   0   
$EndComp
Wire Wire Line
	11700 1550 11900 1550
$Comp
L Device:R R14
U 1 1 603D2D02
P 11550 1650
F 0 "R14" V 11600 1850 50  0000 C CNN
F 1 "330" V 11550 1650 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 11480 1650 50  0001 C CNN
F 3 "~" H 11550 1650 50  0001 C CNN
	1    11550 1650
	0    -1   -1   0   
$EndComp
Wire Wire Line
	11700 1650 11900 1650
$Comp
L Device:R R15
U 1 1 603FFBD5
P 11550 1750
F 0 "R15" V 11600 1950 50  0000 C CNN
F 1 "330" V 11550 1750 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 11480 1750 50  0001 C CNN
F 3 "~" H 11550 1750 50  0001 C CNN
	1    11550 1750
	0    -1   -1   0   
$EndComp
Wire Wire Line
	11700 1750 11900 1750
$Comp
L Device:R R16
U 1 1 6042CFA3
P 11550 1850
F 0 "R16" V 11600 2050 50  0000 C CNN
F 1 "330" V 11550 1850 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 11480 1850 50  0001 C CNN
F 3 "~" H 11550 1850 50  0001 C CNN
	1    11550 1850
	0    -1   -1   0   
$EndComp
Wire Wire Line
	11700 1850 11900 1850
$Comp
L Device:R R17
U 1 1 6045A6F3
P 11550 1950
F 0 "R17" V 11600 2150 50  0000 C CNN
F 1 "330" V 11550 1950 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 11480 1950 50  0001 C CNN
F 3 "~" H 11550 1950 50  0001 C CNN
	1    11550 1950
	0    -1   -1   0   
$EndComp
Wire Wire Line
	11700 1950 11900 1950
$Comp
L Device:C_Small C3
U 1 1 605106EB
P 1250 3250
F 0 "C3" V 1021 3250 50  0000 C CNN
F 1 "0.1uF" V 1112 3250 50  0000 C CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 1250 3250 50  0001 C CNN
F 3 "~" H 1250 3250 50  0001 C CNN
	1    1250 3250
	0    1    1    0   
$EndComp
$Comp
L Device:C_Small C4
U 1 1 60510F7C
P 1400 3700
F 0 "C4" V 1171 3700 50  0000 C CNN
F 1 "1uF" V 1262 3700 50  0000 C CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 1400 3700 50  0001 C CNN
F 3 "~" H 1400 3700 50  0001 C CNN
	1    1400 3700
	0    1    1    0   
$EndComp
$Comp
L power:VBUS #PWR0119
U 1 1 6058CB52
P 3150 4700
F 0 "#PWR0119" H 3150 4550 50  0001 C CNN
F 1 "VBUS" H 3165 4873 50  0000 C CNN
F 2 "" H 3150 4700 50  0001 C CNN
F 3 "" H 3150 4700 50  0001 C CNN
	1    3150 4700
	1    0    0    -1  
$EndComp
Wire Wire Line
	3150 4700 3150 4800
Wire Wire Line
	3150 4800 3000 4800
Wire Wire Line
	3150 4800 3300 4800
Connection ~ 3150 4800
Wire Wire Line
	2100 6300 2400 6300
Wire Wire Line
	2400 6300 2400 6400
$Comp
L Connector:USB_C_Receptacle_USB2.0 J1
U 1 1 5F6AF0EA
P 2400 5400
F 0 "J1" H 2507 6267 50  0000 C CNN
F 1 "USB_C_Receptacle_USB2.0" H 2507 6176 50  0000 C CNN
F 2 "Connector_USB:USB_C_Receptacle_GCT_USB4085" H 2550 5400 50  0001 C CNN
F 3 "https://www.usb.org/sites/default/files/documents/usb_type-c.zip" H 2550 5400 50  0001 C CNN
	1    2400 5400
	1    0    0    -1  
$EndComp
NoConn ~ 3000 5000
NoConn ~ 3000 5100
NoConn ~ 3000 5900
NoConn ~ 3000 6000
Wire Wire Line
	3000 5300 3000 5400
Connection ~ 3000 5300
Wire Wire Line
	3000 5600 3000 5500
Connection ~ 3000 5500
Connection ~ 2400 6300
$Comp
L power:+5V #PWR0120
U 1 1 5FCD32C2
P 1100 2900
F 0 "#PWR0120" H 1100 2750 50  0001 C CNN
F 1 "+5V" H 1115 3073 50  0000 C CNN
F 2 "" H 1100 2900 50  0001 C CNN
F 3 "" H 1100 2900 50  0001 C CNN
	1    1100 2900
	1    0    0    -1  
$EndComp
Wire Wire Line
	1100 2900 1200 2900
$Comp
L mtg_life_counter:TPIC6B595 U4
U 1 1 5FEFBB87
P 15100 2350
F 0 "U4" H 15400 2950 50  0000 C CNN
F 1 "TPIC6B595" H 14800 1600 50  0000 C CNN
F 2 "Package_SO:SOIC-20W_7.5x12.8mm_P1.27mm" H 15750 1700 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/tpic6595.pdf" H 15100 2300 50  0001 C CNN
	1    15100 2350
	-1   0    0    -1  
$EndComp
$Comp
L mtg_life_counter:TPIC6B595 U5
U 1 1 5FF2DED4
P 15100 5500
F 0 "U5" H 15400 6100 50  0000 C CNN
F 1 "TPIC6B595" H 14850 4800 50  0000 C CNN
F 2 "Package_SO:SOIC-20W_7.5x12.8mm_P1.27mm" H 15750 4850 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/tpic6595.pdf" H 15100 5450 50  0001 C CNN
	1    15100 5500
	-1   0    0    -1  
$EndComp
Text Label 4050 2600 2    50   ~ 0
MUX_RB
Text Label 4050 2900 2    50   ~ 0
MUX_SEL_0
Text Label 4050 2800 2    50   ~ 0
MUX_SEL_1
Text Label 4050 2700 2    50   ~ 0
MUX_SEL_2
Text Label 4050 2400 2    50   ~ 0
E1_SW
Text Label 4050 2300 2    50   ~ 0
E2_SW
Text Label 4050 2100 2    50   ~ 0
E4_SW
Text Label 4050 2200 2    50   ~ 0
E3_SW
Wire Wire Line
	3100 2100 4050 2100
Wire Wire Line
	3100 2200 4050 2200
Wire Wire Line
	3100 2300 4050 2300
Wire Wire Line
	3100 2400 4050 2400
Wire Wire Line
	3100 2600 4050 2600
Wire Wire Line
	3100 2700 4050 2700
Wire Wire Line
	3100 2800 4050 2800
Wire Wire Line
	3100 2900 4050 2900
$Comp
L power:+3.3V #PWR0121
U 1 1 60154318
P 4950 4750
F 0 "#PWR0121" H 4950 4600 50  0001 C CNN
F 1 "+3.3V" H 4965 4923 50  0000 C CNN
F 2 "" H 4950 4750 50  0001 C CNN
F 3 "" H 4950 4750 50  0001 C CNN
	1    4950 4750
	1    0    0    -1  
$EndComp
Wire Wire Line
	4950 4750 5200 4750
NoConn ~ 3100 3000
NoConn ~ 3100 3100
Text Label 4050 1600 2    50   ~ 0
MODE_SW
Text Label 4050 1900 2    50   ~ 0
RESET_BTN
Text Label 4050 2000 2    50   ~ 0
ROLL_BTN
Wire Wire Line
	3100 1900 4050 1900
Wire Wire Line
	3100 2000 4050 2000
Wire Wire Line
	3100 1600 4050 1600
Text Label 4050 1500 2    50   ~ 0
SER_LATCH
Text Label 4050 1700 2    50   ~ 0
~ENABLE
Wire Wire Line
	3100 1500 4050 1500
Wire Wire Line
	3100 1700 4050 1700
$Comp
L Device:Resonator_Small Y1
U 1 1 604EEF5E
P 1600 1700
F 0 "Y1" V 1295 1650 50  0000 C CNN
F 1 "16MHz" V 1386 1650 50  0000 C CNN
F 2 "Crystal:Resonator_muRata_CSTLSxxxX-3Pin_W5.5mm_H3.0mm" H 1575 1700 50  0001 C CNN
F 3 "~" H 1575 1700 50  0001 C CNN
	1    1600 1700
	0    1    1    0   
$EndComp
Wire Wire Line
	1700 1600 1900 1600
Wire Wire Line
	1700 1800 1900 1800
Wire Wire Line
	1100 2300 1100 1700
Wire Wire Line
	1100 1700 1400 1700
Connection ~ 1100 2300
$Comp
L Device:C_Small C1
U 1 1 6055AAB7
P 1000 4100
F 0 "C1" V 771 4100 50  0000 C CNN
F 1 "4.7uF" V 862 4100 50  0000 C CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 1000 4100 50  0001 C CNN
F 3 "~" H 1000 4100 50  0001 C CNN
	1    1000 4100
	0    1    1    0   
$EndComp
Text Notes 3150 1200 0    50   ~ 0
D13(SCK)
Text Notes 3150 1400 0    50   ~ 0
D11(MOSI)
Text Notes 3150 1500 0    50   ~ 0
D10
Text Notes 3150 1600 0    50   ~ 0
D9
Text Notes 3150 1700 0    50   ~ 0
D8
Text Notes 3150 1900 0    50   ~ 0
A5
Text Notes 3150 2000 0    50   ~ 0
A4
Text Notes 3150 2100 0    50   ~ 0
A3
Text Notes 3150 2200 0    50   ~ 0
A2
Text Notes 3150 2300 0    50   ~ 0
A1
Text Notes 3150 2400 0    50   ~ 0
A0
NoConn ~ 3100 1300
Text Notes 3150 1300 0    50   ~ 0
D12(MISO)
Text Notes 3150 3000 0    50   ~ 0
D3(INT1)
Text Notes 3150 3100 0    50   ~ 0
D2(INT0)
Text Notes 3150 2600 0    50   ~ 0
D7
Text Notes 3150 2700 0    50   ~ 0
D6
Text Notes 3150 2800 0    50   ~ 0
D5
Text Notes 3150 2900 0    50   ~ 0
D4
$EndSCHEMATC
