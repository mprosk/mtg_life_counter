EESchema Schematic File Version 4
LIBS:mtg_life_counter-cache
EELAYER 30 0
EELAYER END
$Descr USLedger 17000 11000
encoding utf-8
Sheet 1 1
Title "Magic: The Gathering Life Counter"
Date "2020-09-01"
Rev "0.2"
Comp "Max Proskauer"
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Switch:SW_Push B1
U 1 1 5F28CE77
P 13650 8000
F 0 "B1" H 13650 8285 50  0000 C CNN
F 1 "SW_Push" H 13650 8194 50  0000 C CNN
F 2 "mtg_life_counter:B3F_12mm" H 13650 8200 50  0001 C CNN
F 3 "~" H 13650 8200 50  0001 C CNN
	1    13650 8000
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
P 3000 8300
F 0 "U6" H 3250 9050 50  0000 C CNN
F 1 "74LS151" H 2800 9050 50  0000 C CNN
F 2 "Package_SO:SOIC-16_3.9x9.9mm_P1.27mm" H 3000 8300 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74LS151" H 3000 8300 50  0001 C CNN
	1    3000 8300
	-1   0    0    -1  
$EndComp
$Comp
L power:+5V #PWR029
U 1 1 5F2A4AB1
P 3450 7200
F 0 "#PWR029" H 3450 7050 50  0001 C CNN
F 1 "+5V" H 3400 7350 50  0000 C CNN
F 2 "" H 3450 7200 50  0001 C CNN
F 3 "" H 3450 7200 50  0001 C CNN
	1    3450 7200
	1    0    0    -1  
$EndComp
Text Label 4250 8600 2    50   ~ 0
MUX_SEL_0
Text Label 4250 8700 2    50   ~ 0
MUX_SEL_1
Text Label 4250 8800 2    50   ~ 0
MUX_SEL_2
Wire Wire Line
	4250 8600 3500 8600
Wire Wire Line
	3500 8700 4250 8700
Wire Wire Line
	3500 8800 4250 8800
$Comp
L power:GND #PWR026
U 1 1 5F2E233A
P 3500 9300
F 0 "#PWR026" H 3500 9050 50  0001 C CNN
F 1 "GND" H 3505 9127 50  0000 C CNN
F 2 "" H 3500 9300 50  0001 C CNN
F 3 "" H 3500 9300 50  0001 C CNN
	1    3500 9300
	1    0    0    -1  
$EndComp
Wire Wire Line
	3000 9300 3500 9300
Wire Wire Line
	3500 9000 3500 9300
Connection ~ 3500 9300
$Comp
L power:+5V #PWR023
U 1 1 5F2E3AF9
P 3000 7300
F 0 "#PWR023" H 3000 7150 50  0001 C CNN
F 1 "+5V" H 3015 7473 50  0000 C CNN
F 2 "" H 3000 7300 50  0001 C CNN
F 3 "" H 3000 7300 50  0001 C CNN
	1    3000 7300
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C9
U 1 1 5F2E5300
P 2800 7300
F 0 "C9" V 2571 7300 50  0000 C CNN
F 1 "0.1uF" V 2662 7300 50  0000 C CNN
F 2 "Capacitor_SMD:C_1206_3216Metric_Pad1.42x1.75mm_HandSolder" H 2800 7300 50  0001 C CNN
F 3 "~" H 2800 7300 50  0001 C CNN
	1    2800 7300
	0    1    1    0   
$EndComp
Wire Wire Line
	2900 7300 3000 7300
Connection ~ 3000 7300
Wire Wire Line
	3000 7300 3000 7400
$Comp
L power:GND #PWR020
U 1 1 5F2E830C
P 2600 7300
F 0 "#PWR020" H 2600 7050 50  0001 C CNN
F 1 "GND" H 2605 7127 50  0000 C CNN
F 2 "" H 2600 7300 50  0001 C CNN
F 3 "" H 2600 7300 50  0001 C CNN
	1    2600 7300
	1    0    0    -1  
$EndComp
Wire Wire Line
	2600 7300 2700 7300
Text Label 2000 7700 0    50   ~ 0
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
P 14100 7500
F 0 "#PWR03" H 14100 7250 50  0001 C CNN
F 1 "GND" H 14105 7327 50  0000 C CNN
F 2 "" H 14100 7500 50  0001 C CNN
F 3 "" H 14100 7500 50  0001 C CNN
	1    14100 7500
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
P 5800 5200
F 0 "#PWR02" H 5800 5050 50  0001 C CNN
F 1 "+5V" H 5815 5373 50  0000 C CNN
F 2 "" H 5800 5200 50  0001 C CNN
F 3 "" H 5800 5200 50  0001 C CNN
	1    5800 5200
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
F 2 "Capacitor_SMD:C_1206_3216Metric_Pad1.42x1.75mm_HandSolder" H 10200 4100 50  0001 C CNN
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
F 2 "Capacitor_SMD:C_1206_3216Metric_Pad1.42x1.75mm_HandSolder" H 10200 950 50  0001 C CNN
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
Text Label 12950 7500 0    50   ~ 0
MODE_SW
$Comp
L power:GND #PWR04
U 1 1 60993EB2
P 14100 8000
F 0 "#PWR04" H 14100 7750 50  0001 C CNN
F 1 "GND" H 14105 7827 50  0000 C CNN
F 2 "" H 14100 8000 50  0001 C CNN
F 3 "" H 14100 8000 50  0001 C CNN
	1    14100 8000
	1    0    0    -1  
$EndComp
Wire Wire Line
	13850 8000 14100 8000
$Comp
L power:GND #PWR05
U 1 1 609B5688
P 14100 8500
F 0 "#PWR05" H 14100 8250 50  0001 C CNN
F 1 "GND" H 14105 8327 50  0000 C CNN
F 2 "" H 14100 8500 50  0001 C CNN
F 3 "" H 14100 8500 50  0001 C CNN
	1    14100 8500
	1    0    0    -1  
$EndComp
Wire Wire Line
	13850 8500 14100 8500
Text Label 12950 8500 0    50   ~ 0
ROLL_BTN
Text Label 12950 8000 0    50   ~ 0
RESET_BTN
Wire Wire Line
	12950 8000 13450 8000
Wire Wire Line
	12950 8500 13450 8500
Text Notes 5000 6850 0    100  ~ 20
Encoder Multiplexing
Text Notes 11000 900  0    100  ~ 20
Display Bank 1
Text Notes 11000 4000 0    100  ~ 20
Display Bank 2
Text Notes 1100 1750 0    100  ~ 20
Arduino
$Comp
L Switch:SW_SPST SW2
U 1 1 60EEF83B
P 13650 7500
F 0 "SW2" H 13650 7735 50  0000 C CNN
F 1 "SW_SPST" H 13650 7644 50  0000 C CNN
F 2 "Button_Switch_THT:SW_Slide_1P2T_CK_OS102011MS2Q" H 13650 7500 50  0001 C CNN
F 3 "~" H 13650 7500 50  0001 C CNN
	1    13650 7500
	1    0    0    -1  
$EndComp
Wire Wire Line
	12950 7500 13450 7500
Wire Wire Line
	13850 7500 14100 7500
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
F 2 "Resistor_SMD:R_1206_3216Metric_Pad1.42x1.75mm_HandSolder" V 15830 5400 50  0001 C CNN
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
F 2 "Capacitor_SMD:C_1206_3216Metric_Pad1.42x1.75mm_HandSolder" H 15300 4800 50  0001 C CNN
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
P 13650 8500
F 0 "B2" H 13650 8785 50  0000 C CNN
F 1 "SW_Push" H 13650 8694 50  0000 C CNN
F 2 "mtg_life_counter:B3F_12mm" H 13650 8700 50  0001 C CNN
F 3 "~" H 13650 8700 50  0001 C CNN
	1    13650 8500
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
P 14700 7950
F 0 "H1" H 14650 8150 50  0000 L CNN
F 1 "MountingHole_Pad" H 14800 7908 50  0001 L CNN
F 2 "MountingHole:MountingHole_3.2mm_M3_Pad_Via" H 14700 7950 50  0001 C CNN
F 3 "~" H 14700 7950 50  0001 C CNN
	1    14700 7950
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:MountingHole_Pad H4
U 1 1 5F39E86D
P 15450 7950
F 0 "H4" H 15400 8150 50  0000 L CNN
F 1 "MountingHole_Pad" H 15550 7908 50  0001 L CNN
F 2 "MountingHole:MountingHole_3.2mm_M3_Pad_Via" H 15450 7950 50  0001 C CNN
F 3 "~" H 15450 7950 50  0001 C CNN
	1    15450 7950
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:MountingHole_Pad H3
U 1 1 5F39EB49
P 15200 7950
F 0 "H3" H 15150 8150 50  0000 L CNN
F 1 "MountingHole_Pad" H 15300 7908 50  0001 L CNN
F 2 "MountingHole:MountingHole_3.2mm_M3_Pad_Via" H 15200 7950 50  0001 C CNN
F 3 "~" H 15200 7950 50  0001 C CNN
	1    15200 7950
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:MountingHole_Pad H2
U 1 1 5F39F052
P 14950 7950
F 0 "H2" H 14900 8150 50  0000 L CNN
F 1 "MountingHole_Pad" H 15050 7908 50  0001 L CNN
F 2 "MountingHole:MountingHole_3.2mm_M3_Pad_Via" H 14950 7950 50  0001 C CNN
F 3 "~" H 14950 7950 50  0001 C CNN
	1    14950 7950
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0102
U 1 1 5F39FC84
P 14700 8250
F 0 "#PWR0102" H 14700 8000 50  0001 C CNN
F 1 "GND" H 14705 8077 50  0000 C CNN
F 2 "" H 14700 8250 50  0001 C CNN
F 3 "" H 14700 8250 50  0001 C CNN
	1    14700 8250
	1    0    0    -1  
$EndComp
Wire Wire Line
	14700 8050 14950 8050
Wire Wire Line
	14950 8050 15200 8050
Connection ~ 14950 8050
Wire Wire Line
	15200 8050 15450 8050
Connection ~ 15200 8050
Wire Wire Line
	14700 8050 14700 8250
Connection ~ 14700 8050
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
F 2 "Resistor_SMD:R_1206_3216Metric_Pad1.42x1.75mm_HandSolder" V 15830 2250 50  0001 C CNN
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
F 2 "Capacitor_SMD:C_1206_3216Metric_Pad1.42x1.75mm_HandSolder" H 15300 1650 50  0001 C CNN
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
	3500 8400 4250 8400
Wire Wire Line
	3500 8300 4150 8300
Wire Wire Line
	3500 8200 4050 8200
Wire Wire Line
	3500 8100 3950 8100
Wire Wire Line
	3950 7600 3950 8100
Connection ~ 3950 8100
Wire Wire Line
	4050 7600 4050 8200
Connection ~ 4050 8200
Wire Wire Line
	4150 7600 4150 8300
Connection ~ 4150 8300
Wire Wire Line
	4250 7600 4250 8400
Connection ~ 4250 8400
Wire Wire Line
	14400 4900 14400 5200
Text Label 16100 5850 2    50   ~ 0
SER_LINK_1
Text Label 16100 2700 2    50   ~ 0
SER_LINK_2
$Comp
L Device:Crystal_Small Y1
U 1 1 5F59D7E2
P 1850 2550
F 0 "Y1" V 1804 2638 50  0000 L CNN
F 1 "16MHz" V 1895 2638 50  0000 L CNN
F 2 "Crystal:Crystal_HC49-U_Vertical" H 1850 2550 50  0001 C CNN
F 3 "~" H 1850 2550 50  0001 C CNN
	1    1850 2550
	0    -1   1    0   
$EndComp
NoConn ~ 2500 7800
Wire Wire Line
	2000 7700 2500 7700
$Comp
L Device:Rotary_Encoder_Switch E1
U 1 1 5F674E57
P 5700 7700
F 0 "E1" H 5700 8067 50  0000 C CNN
F 1 "Rotary_Encoder_Switch" H 5700 7976 50  0000 C CNN
F 2 "Rotary_Encoder:RotaryEncoder_Alps_EC11E-Switch_Vertical_H20mm" H 5550 7860 50  0001 C CNN
F 3 "~" H 5700 7960 50  0001 C CNN
	1    5700 7700
	1    0    0    -1  
$EndComp
$Comp
L Interface_USB:FT232RL U7
U 1 1 5F77F9F3
P 6050 2950
F 0 "U7" H 5500 3850 50  0000 C CNN
F 1 "FT232RL" H 6550 3850 50  0000 C CNN
F 2 "Package_SO:SSOP-28_5.3x10.2mm_P0.65mm" H 6050 2950 50  0001 C CNN
F 3 "http://www.ftdichip.com/Products/ICs/FT232RL.htm" H 6050 2950 50  0001 C CNN
	1    6050 2950
	1    0    0    -1  
$EndComp
$Comp
L Connector:USB_B_Micro J1
U 1 1 5F8068BF
P 4700 5400
F 0 "J1" H 4757 5867 50  0000 C CNN
F 1 "USB_B_Micro" H 4757 5776 50  0000 C CNN
F 2 "Connector_USB:USB_Micro-B_Molex-105017-0001" H 4850 5350 50  0001 C CNN
F 3 "~" H 4850 5350 50  0001 C CNN
	1    4700 5400
	1    0    0    -1  
$EndComp
Text Label 16100 5700 2    50   ~ 0
~ENABLE
Text Label 9100 5000 0    50   ~ 0
~ENABLE
Text Label 9100 1850 0    50   ~ 0
~ENABLE
Text Label 5450 5400 2    50   ~ 0
USB_DP
Text Label 5450 5500 2    50   ~ 0
USB_DM
$Comp
L power:GND #PWR0101
U 1 1 5F537739
P 4700 5800
F 0 "#PWR0101" H 4700 5550 50  0001 C CNN
F 1 "GND" H 4705 5627 50  0000 C CNN
F 2 "" H 4700 5800 50  0001 C CNN
F 3 "" H 4700 5800 50  0001 C CNN
	1    4700 5800
	1    0    0    -1  
$EndComp
Wire Wire Line
	4600 5800 4700 5800
Connection ~ 4700 5800
Wire Wire Line
	5700 5200 5800 5200
Wire Wire Line
	5450 5400 5000 5400
Wire Wire Line
	5450 5500 5000 5500
Text Label 4900 2550 0    50   ~ 0
USB_DP
Wire Wire Line
	4900 2550 5250 2550
Wire Wire Line
	4900 2650 5250 2650
Text Label 4900 2650 0    50   ~ 0
USB_DM
NoConn ~ 5250 2250
$Comp
L mtg_life_counter:ATmega328P-AU U1
U 1 1 5F524725
P 2650 3100
F 0 "U1" H 2650 4417 50  0000 C CNN
F 1 "ATmega328P-AU" H 2650 4326 50  0000 C CNN
F 2 "Package_QFP:TQFP-32_7x7mm_P0.8mm" H 2700 2900 50  0001 C CIN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/ATmega328_P%20AVR%20MCU%20with%20picoPower%20Technology%20Data%20Sheet%2040001984A.pdf" H 2650 2850 50  0001 C CNN
	1    2650 3100
	1    0    0    -1  
$EndComp
Wire Wire Line
	2050 2450 1850 2450
Wire Wire Line
	1850 2650 2050 2650
$Comp
L Device:C_Small C1
U 1 1 5F5A9139
P 1450 2450
F 0 "C1" V 1250 2450 50  0000 C CNN
F 1 "18pF" V 1350 2450 50  0000 C CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 1450 2450 50  0001 C CNN
F 3 "~" H 1450 2450 50  0001 C CNN
	1    1450 2450
	0    1    1    0   
$EndComp
Wire Wire Line
	1850 2450 1550 2450
Connection ~ 1850 2450
Wire Wire Line
	1550 2650 1850 2650
Connection ~ 1850 2650
$Comp
L Device:C_Small C2
U 1 1 5F5DF9A1
P 1450 2650
F 0 "C2" V 1550 2650 50  0000 C CNN
F 1 "18pF" V 1650 2650 50  0000 C CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 1450 2650 50  0001 C CNN
F 3 "~" H 1450 2650 50  0001 C CNN
	1    1450 2650
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0107
U 1 1 5F6155B4
P 1950 4250
F 0 "#PWR0107" H 1950 4000 50  0001 C CNN
F 1 "GND" H 1955 4077 50  0000 C CNN
F 2 "" H 1950 4250 50  0001 C CNN
F 3 "" H 1950 4250 50  0001 C CNN
	1    1950 4250
	1    0    0    -1  
$EndComp
Wire Wire Line
	1950 4250 1950 4150
Wire Wire Line
	1950 4050 2050 4050
Wire Wire Line
	2050 4150 1950 4150
Connection ~ 1950 4150
Wire Wire Line
	1950 4150 1950 4050
Text Label 1750 3750 0    50   ~ 0
~RESET
$Comp
L power:GND #PWR0108
U 1 1 5F64CCAE
P 1250 3150
F 0 "#PWR0108" H 1250 2900 50  0001 C CNN
F 1 "GND" H 1255 2977 50  0000 C CNN
F 2 "" H 1250 3150 50  0001 C CNN
F 3 "" H 1250 3150 50  0001 C CNN
	1    1250 3150
	1    0    0    -1  
$EndComp
Wire Wire Line
	10400 5950 10400 5300
NoConn ~ 5000 5600
$Comp
L Switch:SW_SPST SW1
U 1 1 5F6C1609
P 5500 5200
F 0 "SW1" H 5500 5435 50  0000 C CNN
F 1 "SW_SPST" H 5500 5344 50  0000 C CNN
F 2 "Button_Switch_THT:SW_Slide_1P2T_CK_OS102011MS2Q" H 5500 5200 50  0001 C CNN
F 3 "~" H 5500 5200 50  0001 C CNN
	1    5500 5200
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR0109
U 1 1 5F714DE6
P 1950 2050
F 0 "#PWR0109" H 1950 1900 50  0001 C CNN
F 1 "+5V" H 1965 2223 50  0000 C CNN
F 2 "" H 1950 2050 50  0001 C CNN
F 3 "" H 1950 2050 50  0001 C CNN
	1    1950 2050
	1    0    0    -1  
$EndComp
Wire Wire Line
	1950 2050 2050 2050
Wire Wire Line
	1950 2050 1950 2150
Wire Wire Line
	1950 2150 2050 2150
Connection ~ 1950 2050
NoConn ~ 2050 2950
NoConn ~ 2050 3350
NoConn ~ 2050 3450
$Comp
L power:+5V #PWR0110
U 1 1 5F7DDC41
P 1650 3050
F 0 "#PWR0110" H 1650 2900 50  0001 C CNN
F 1 "+5V" H 1665 3223 50  0000 C CNN
F 2 "" H 1650 3050 50  0001 C CNN
F 3 "" H 1650 3050 50  0001 C CNN
	1    1650 3050
	1    0    0    -1  
$EndComp
Wire Wire Line
	1650 3050 2050 3050
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
Text Label 5100 7600 0    50   ~ 0
E1_CLK
Text Label 5100 7800 0    50   ~ 0
E1_DIR
Wire Wire Line
	5100 7600 5400 7600
Wire Wire Line
	5100 7800 5400 7800
Text Label 6300 7600 2    50   ~ 0
E1_SW
$Comp
L power:GND #PWR0111
U 1 1 5FB2121B
P 6000 8000
F 0 "#PWR0111" H 6000 7750 50  0001 C CNN
F 1 "GND" H 6005 7827 50  0000 C CNN
F 2 "" H 6000 8000 50  0001 C CNN
F 3 "" H 6000 8000 50  0001 C CNN
	1    6000 8000
	1    0    0    -1  
$EndComp
Wire Wire Line
	6000 7600 6300 7600
Wire Wire Line
	5000 7700 5000 8000
Wire Wire Line
	5000 8000 6000 8000
Wire Wire Line
	6000 8000 6000 7800
Wire Wire Line
	5000 7700 5400 7700
Connection ~ 6000 8000
$Comp
L Device:Rotary_Encoder_Switch E2
U 1 1 5FBBE8FD
P 7200 7700
F 0 "E2" H 7200 8067 50  0000 C CNN
F 1 "Rotary_Encoder_Switch" H 7200 7976 50  0000 C CNN
F 2 "Rotary_Encoder:RotaryEncoder_Alps_EC11E-Switch_Vertical_H20mm" H 7050 7860 50  0001 C CNN
F 3 "~" H 7200 7960 50  0001 C CNN
	1    7200 7700
	1    0    0    -1  
$EndComp
Text Label 6600 7600 0    50   ~ 0
E2_CLK
Text Label 6600 7800 0    50   ~ 0
E2_DIR
Wire Wire Line
	6600 7600 6900 7600
Wire Wire Line
	6600 7800 6900 7800
Text Label 7800 7600 2    50   ~ 0
E2_SW
$Comp
L power:GND #PWR0112
U 1 1 5FBBE908
P 7500 8000
F 0 "#PWR0112" H 7500 7750 50  0001 C CNN
F 1 "GND" H 7505 7827 50  0000 C CNN
F 2 "" H 7500 8000 50  0001 C CNN
F 3 "" H 7500 8000 50  0001 C CNN
	1    7500 8000
	1    0    0    -1  
$EndComp
Wire Wire Line
	7500 7600 7800 7600
Wire Wire Line
	6500 7700 6500 8000
Wire Wire Line
	6500 8000 7500 8000
Wire Wire Line
	7500 8000 7500 7800
Wire Wire Line
	6500 7700 6900 7700
Connection ~ 7500 8000
$Comp
L Device:Rotary_Encoder_Switch E3
U 1 1 5FBDF65E
P 5700 8700
F 0 "E3" H 5700 9067 50  0000 C CNN
F 1 "Rotary_Encoder_Switch" H 5700 8976 50  0000 C CNN
F 2 "Rotary_Encoder:RotaryEncoder_Alps_EC11E-Switch_Vertical_H20mm" H 5550 8860 50  0001 C CNN
F 3 "~" H 5700 8960 50  0001 C CNN
	1    5700 8700
	1    0    0    -1  
$EndComp
Text Label 5100 8600 0    50   ~ 0
E3_CLK
Text Label 5100 8800 0    50   ~ 0
E3_DIR
Wire Wire Line
	5100 8600 5400 8600
Wire Wire Line
	5100 8800 5400 8800
Text Label 6300 8600 2    50   ~ 0
E3_SW
$Comp
L power:GND #PWR0113
U 1 1 5FBDF669
P 6000 9000
F 0 "#PWR0113" H 6000 8750 50  0001 C CNN
F 1 "GND" H 6005 8827 50  0000 C CNN
F 2 "" H 6000 9000 50  0001 C CNN
F 3 "" H 6000 9000 50  0001 C CNN
	1    6000 9000
	1    0    0    -1  
$EndComp
Wire Wire Line
	6000 8600 6300 8600
Wire Wire Line
	5000 8700 5000 9000
Wire Wire Line
	5000 9000 6000 9000
Wire Wire Line
	6000 9000 6000 8800
Wire Wire Line
	5000 8700 5400 8700
Connection ~ 6000 9000
$Comp
L Device:Rotary_Encoder_Switch E4
U 1 1 5FC01795
P 7200 8700
F 0 "E4" H 7200 9067 50  0000 C CNN
F 1 "Rotary_Encoder_Switch" H 7200 8976 50  0000 C CNN
F 2 "Rotary_Encoder:RotaryEncoder_Alps_EC11E-Switch_Vertical_H20mm" H 7050 8860 50  0001 C CNN
F 3 "~" H 7200 8960 50  0001 C CNN
	1    7200 8700
	1    0    0    -1  
$EndComp
Text Label 6600 8600 0    50   ~ 0
E4_CLK
Text Label 6600 8800 0    50   ~ 0
E4_DIR
Wire Wire Line
	6600 8600 6900 8600
Wire Wire Line
	6600 8800 6900 8800
Text Label 7800 8600 2    50   ~ 0
E4_SW
$Comp
L power:GND #PWR0114
U 1 1 5FC017A0
P 7500 9000
F 0 "#PWR0114" H 7500 8750 50  0001 C CNN
F 1 "GND" H 7505 8827 50  0000 C CNN
F 2 "" H 7500 9000 50  0001 C CNN
F 3 "" H 7500 9000 50  0001 C CNN
	1    7500 9000
	1    0    0    -1  
$EndComp
Wire Wire Line
	7500 8600 7800 8600
Wire Wire Line
	6500 8700 6900 8700
Text Label 4650 7700 2    50   ~ 0
E1_CLK
Text Label 4650 7800 2    50   ~ 0
E1_DIR
Text Label 4650 7900 2    50   ~ 0
E2_CLK
Text Label 4650 8000 2    50   ~ 0
E2_DIR
Text Label 4650 8100 2    50   ~ 0
E3_CLK
Text Label 4650 8200 2    50   ~ 0
E3_DIR
Text Label 4650 8300 2    50   ~ 0
E4_CLK
Text Label 4650 8400 2    50   ~ 0
E4_DIR
Wire Wire Line
	3950 8100 4650 8100
Wire Wire Line
	4050 8200 4650 8200
Wire Wire Line
	4150 8300 4650 8300
Wire Wire Line
	4250 8400 4650 8400
Wire Wire Line
	7500 9000 7500 8800
Wire Wire Line
	6500 9000 7500 9000
Wire Wire Line
	6500 8700 6500 9000
Connection ~ 7500 9000
Wire Wire Line
	3500 8000 3850 8000
Wire Wire Line
	3500 7900 3750 7900
Wire Wire Line
	3500 7800 3650 7800
Wire Wire Line
	3500 7700 3550 7700
Wire Wire Line
	3550 7600 3550 7700
Connection ~ 3550 7700
Wire Wire Line
	3550 7700 4650 7700
Wire Wire Line
	3650 7600 3650 7800
Connection ~ 3650 7800
Wire Wire Line
	3650 7800 4650 7800
Wire Wire Line
	3750 7600 3750 7900
Connection ~ 3750 7900
Wire Wire Line
	3750 7900 4650 7900
Wire Wire Line
	3850 7600 3850 8000
Connection ~ 3850 8000
Wire Wire Line
	3850 8000 4650 8000
Wire Wire Line
	1750 3750 2050 3750
Text Label 4200 2050 2    50   ~ 0
SER_CLK
Text Label 4200 2250 2    50   ~ 0
SER_DATA
Text Label 3650 2050 2    50   ~ 0
D13(SCK)
Text Label 3700 2150 2    50   ~ 0
D12(MISO)
Text Label 3700 2250 2    50   ~ 0
D11(MOSI)
Text Label 3450 2350 2    50   ~ 0
D10
Text Label 3400 2450 2    50   ~ 0
D9
Text Label 3400 2550 2    50   ~ 0
D8
Text Label 3400 2750 2    50   ~ 0
A5
Text Label 3400 2850 2    50   ~ 0
A4
Text Label 3400 2950 2    50   ~ 0
A3
Text Label 3400 3050 2    50   ~ 0
A2
Text Label 3400 3150 2    50   ~ 0
A1
Text Label 3400 3250 2    50   ~ 0
A0
Text Label 3400 3450 2    50   ~ 0
D7
Text Label 3400 3550 2    50   ~ 0
D6
Text Label 3400 3650 2    50   ~ 0
D5
Text Label 3400 3750 2    50   ~ 0
D4
Text Label 3400 3850 2    50   ~ 0
D3
Text Label 3400 3950 2    50   ~ 0
D2
Text Label 3550 4050 2    50   ~ 0
D1(TX)
Text Label 3550 4150 2    50   ~ 0
D0(RX)
Text Label 1850 3450 0    50   ~ 0
A7
Text Label 1850 3350 0    50   ~ 0
A6
Wire Wire Line
	1850 3350 2050 3350
Wire Wire Line
	1850 3450 2050 3450
Text Label 1850 2950 0    50   ~ 0
AREF
Wire Wire Line
	1850 2950 2050 2950
Wire Wire Line
	1350 2450 1250 2450
Wire Wire Line
	1250 2450 1250 2650
Wire Wire Line
	1250 2650 1350 2650
Wire Wire Line
	1250 2650 1250 3150
Wire Wire Line
	1250 3150 2050 3150
Connection ~ 1250 2650
Connection ~ 1250 3150
Wire Wire Line
	3250 2050 4200 2050
Wire Wire Line
	3250 2250 4200 2250
Wire Wire Line
	3250 2350 3450 2350
Wire Wire Line
	3400 2450 3250 2450
Wire Wire Line
	3400 2550 3250 2550
Wire Wire Line
	3400 2750 3250 2750
Wire Wire Line
	3400 2850 3250 2850
Wire Wire Line
	3400 2950 3250 2950
Wire Wire Line
	3400 3050 3250 3050
Wire Wire Line
	3400 3150 3250 3150
Wire Wire Line
	3400 3250 3250 3250
Wire Wire Line
	3400 3450 3250 3450
Wire Wire Line
	3250 3550 3400 3550
Wire Wire Line
	3400 3650 3250 3650
Wire Wire Line
	3250 3750 3400 3750
Wire Wire Line
	3400 3850 3250 3850
Wire Wire Line
	3250 3950 3400 3950
Wire Wire Line
	3550 4050 3250 4050
Wire Wire Line
	3250 4150 3550 4150
Text Label 7750 2350 2    50   ~ 0
D1(TX)
Text Label 7750 2250 2    50   ~ 0
D0(RX)
$Comp
L Device:R R4
U 1 1 60517BE8
P 7200 2250
F 0 "R4" V 7150 2050 50  0000 C CNN
F 1 "1k" V 7200 2250 50  0000 C CNN
F 2 "Resistor_SMD:R_1206_3216Metric_Pad1.42x1.75mm_HandSolder" V 7130 2250 50  0001 C CNN
F 3 "~" H 7200 2250 50  0001 C CNN
	1    7200 2250
	0    1    1    0   
$EndComp
$Comp
L Device:R R5
U 1 1 60518533
P 7200 2350
F 0 "R5" V 7150 2150 50  0000 C CNN
F 1 "1k" V 7200 2350 50  0000 C CNN
F 2 "Resistor_SMD:R_1206_3216Metric_Pad1.42x1.75mm_HandSolder" V 7130 2350 50  0001 C CNN
F 3 "~" H 7200 2350 50  0001 C CNN
	1    7200 2350
	0    1    1    0   
$EndComp
Wire Wire Line
	6850 2250 7050 2250
Wire Wire Line
	6850 2350 7050 2350
Wire Wire Line
	7750 2250 7350 2250
Wire Wire Line
	7350 2350 7750 2350
$Comp
L power:+5V #PWR0115
U 1 1 605CC24E
P 5950 1850
F 0 "#PWR0115" H 5950 1700 50  0001 C CNN
F 1 "+5V" H 5965 2023 50  0000 C CNN
F 2 "" H 5950 1850 50  0001 C CNN
F 3 "" H 5950 1850 50  0001 C CNN
	1    5950 1850
	1    0    0    -1  
$EndComp
Wire Wire Line
	5950 1850 5950 1950
Wire Wire Line
	5950 1950 6150 1950
Connection ~ 5950 1950
$Comp
L power:GND #PWR0116
U 1 1 6062903A
P 6250 4050
F 0 "#PWR0116" H 6250 3800 50  0001 C CNN
F 1 "GND" H 6255 3877 50  0000 C CNN
F 2 "" H 6250 4050 50  0001 C CNN
F 3 "" H 6250 4050 50  0001 C CNN
	1    6250 4050
	1    0    0    -1  
$EndComp
Wire Wire Line
	5850 3950 6050 3950
Wire Wire Line
	6050 3950 6150 3950
Connection ~ 6050 3950
Wire Wire Line
	6150 3950 6250 3950
Connection ~ 6150 3950
Wire Wire Line
	6250 3950 6250 4050
Connection ~ 6250 3950
Wire Wire Line
	5250 3650 5250 3950
Wire Wire Line
	5250 3950 5850 3950
Connection ~ 5850 3950
NoConn ~ 5250 3350
NoConn ~ 5250 3150
NoConn ~ 5250 2950
NoConn ~ 6850 2950
NoConn ~ 6850 2850
NoConn ~ 6850 2750
NoConn ~ 6850 2450
NoConn ~ 6850 2550
NoConn ~ 6850 3250
NoConn ~ 6850 3350
NoConn ~ 6850 3450
NoConn ~ 6850 3550
NoConn ~ 6850 3650
$Comp
L Device:C_Small C10
U 1 1 6099BD84
P 7200 2650
F 0 "C10" V 7350 2650 50  0000 C CNN
F 1 "100nF" V 7450 2650 50  0000 C CNN
F 2 "Capacitor_SMD:C_1206_3216Metric_Pad1.42x1.75mm_HandSolder" H 7200 2650 50  0001 C CNN
F 3 "~" H 7200 2650 50  0001 C CNN
	1    7200 2650
	0    1    1    0   
$EndComp
Wire Wire Line
	6850 2650 7100 2650
Wire Notes Line width 10
	4700 1500 7900 1500
Wire Notes Line width 10
	7900 1500 7900 4450
Wire Notes Line width 10
	7900 4450 4700 4450
Wire Notes Line width 10
	4700 4450 4700 1500
Text Notes 7350 4350 0    100  ~ 20
DNP
Text Label 7750 2650 2    50   ~ 0
~RESET
Wire Wire Line
	7300 2650 7750 2650
$Comp
L Connector_Generic:Conn_02x03_Odd_Even J2
U 1 1 60AE0CDA
P 2800 5450
F 0 "J2" H 2850 5767 50  0000 C CNN
F 1 "ICSP" H 2850 5676 50  0000 C CNN
F 2 "Connector:Tag-Connect_TC2030-IDC-NL_2x03_P1.27mm_Vertical" H 2800 5450 50  0001 C CNN
F 3 "~" H 2800 5450 50  0001 C CNN
	1    2800 5450
	1    0    0    -1  
$EndComp
Wire Wire Line
	3250 2150 3700 2150
$Comp
L power:+5V #PWR0117
U 1 1 60B701C5
P 3200 5350
F 0 "#PWR0117" H 3200 5200 50  0001 C CNN
F 1 "+5V" H 3215 5523 50  0000 C CNN
F 2 "" H 3200 5350 50  0001 C CNN
F 3 "" H 3200 5350 50  0001 C CNN
	1    3200 5350
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0118
U 1 1 60B706FB
P 3200 5550
F 0 "#PWR0118" H 3200 5300 50  0001 C CNN
F 1 "GND" H 3205 5377 50  0000 C CNN
F 2 "" H 3200 5550 50  0001 C CNN
F 3 "" H 3200 5550 50  0001 C CNN
	1    3200 5550
	1    0    0    -1  
$EndComp
Text Label 2100 5450 0    50   ~ 0
D13(SCK)
Text Label 2100 5350 0    50   ~ 0
D12(MISO)
Text Label 3600 5450 2    50   ~ 0
D11(MOSI)
Text Label 2100 5550 0    50   ~ 0
~RESET
Wire Wire Line
	2100 5350 2600 5350
Wire Wire Line
	2100 5450 2600 5450
Wire Wire Line
	2100 5550 2600 5550
Wire Wire Line
	3200 5350 3100 5350
Wire Wire Line
	3600 5450 3100 5450
Wire Wire Line
	3200 5550 3100 5550
Wire Wire Line
	4250 7200 4250 7300
Wire Wire Line
	4150 7200 4150 7300
Connection ~ 4150 7200
Wire Wire Line
	4150 7200 4250 7200
Wire Wire Line
	4050 7200 4050 7300
Wire Wire Line
	3450 7200 3550 7200
Connection ~ 4050 7200
Wire Wire Line
	4050 7200 4150 7200
Wire Wire Line
	3950 7300 3950 7200
Connection ~ 3950 7200
Wire Wire Line
	3950 7200 4050 7200
Wire Wire Line
	3850 7200 3850 7300
Connection ~ 3850 7200
Wire Wire Line
	3850 7200 3950 7200
Wire Wire Line
	3750 7300 3750 7200
Connection ~ 3750 7200
Wire Wire Line
	3750 7200 3850 7200
Wire Wire Line
	3650 7200 3650 7300
Connection ~ 3650 7200
Wire Wire Line
	3650 7200 3750 7200
$Comp
L Device:R R1
U 1 1 5FAE2013
P 1500 3650
F 0 "R1" V 1450 3450 50  0000 C CNN
F 1 "1k" V 1500 3650 50  0000 C CNN
F 2 "Resistor_SMD:R_1206_3216Metric_Pad1.42x1.75mm_HandSolder" V 1430 3650 50  0001 C CNN
F 3 "~" H 1500 3650 50  0001 C CNN
	1    1500 3650
	0    1    1    0   
$EndComp
$Comp
L mtg_life_counter:TPIC6596 U5
U 1 1 5FB4BCEF
P 15100 5500
F 0 "U5" H 15400 6100 50  0000 C CNN
F 1 "TPIC6596" H 15350 4850 50  0000 C CNN
F 2 "Package_SO:SOIC-16_3.9x9.9mm_P1.27mm" H 15750 4850 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/tpic6596.pdf" H 15100 5450 50  0001 C CNN
	1    15100 5500
	-1   0    0    -1  
$EndComp
$Comp
L mtg_life_counter:TPIC6596 U4
U 1 1 5FB4E751
P 15100 2350
F 0 "U4" H 15400 2950 50  0000 C CNN
F 1 "TPIC6596" H 15350 1700 50  0000 C CNN
F 2 "Package_SO:SOIC-16_3.9x9.9mm_P1.27mm" H 15750 1700 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/tpic6596.pdf" H 15100 2300 50  0001 C CNN
	1    15100 2350
	-1   0    0    -1  
$EndComp
Wire Wire Line
	16100 2700 15600 2700
Wire Wire Line
	15100 3050 15100 3150
Wire Wire Line
	15100 6200 15100 6300
Wire Wire Line
	16100 5850 15600 5850
$Comp
L Device:R R50
U 1 1 5FC9A634
P 3550 7450
F 0 "R50" V 3550 7100 50  0000 C CNN
F 1 "10k" V 3550 7450 50  0000 C CNN
F 2 "Resistor_SMD:R_1206_3216Metric_Pad1.42x1.75mm_HandSolder" V 3480 7450 50  0001 C CNN
F 3 "~" H 3550 7450 50  0001 C CNN
	1    3550 7450
	-1   0    0    1   
$EndComp
$Comp
L Device:R R51
U 1 1 5FCF8D4C
P 3650 7450
F 0 "R51" V 3650 7100 50  0000 C CNN
F 1 "10k" V 3650 7450 50  0000 C CNN
F 2 "Resistor_SMD:R_1206_3216Metric_Pad1.42x1.75mm_HandSolder" V 3580 7450 50  0001 C CNN
F 3 "~" H 3650 7450 50  0001 C CNN
	1    3650 7450
	-1   0    0    1   
$EndComp
$Comp
L Device:R R52
U 1 1 5FCF907B
P 3750 7450
F 0 "R52" V 3750 7100 50  0000 C CNN
F 1 "10k" V 3750 7450 50  0000 C CNN
F 2 "Resistor_SMD:R_1206_3216Metric_Pad1.42x1.75mm_HandSolder" V 3680 7450 50  0001 C CNN
F 3 "~" H 3750 7450 50  0001 C CNN
	1    3750 7450
	-1   0    0    1   
$EndComp
$Comp
L Device:R R53
U 1 1 5FCF927C
P 3850 7450
F 0 "R53" V 3850 7100 50  0000 C CNN
F 1 "10k" V 3850 7450 50  0000 C CNN
F 2 "Resistor_SMD:R_1206_3216Metric_Pad1.42x1.75mm_HandSolder" V 3780 7450 50  0001 C CNN
F 3 "~" H 3850 7450 50  0001 C CNN
	1    3850 7450
	-1   0    0    1   
$EndComp
$Comp
L Device:R R54
U 1 1 5FCF9481
P 3950 7450
F 0 "R54" V 3950 7100 50  0000 C CNN
F 1 "10k" V 3950 7450 50  0000 C CNN
F 2 "Resistor_SMD:R_1206_3216Metric_Pad1.42x1.75mm_HandSolder" V 3880 7450 50  0001 C CNN
F 3 "~" H 3950 7450 50  0001 C CNN
	1    3950 7450
	-1   0    0    1   
$EndComp
$Comp
L Device:R R55
U 1 1 5FCF96F4
P 4050 7450
F 0 "R55" V 4050 7100 50  0000 C CNN
F 1 "10k" V 4050 7450 50  0000 C CNN
F 2 "Resistor_SMD:R_1206_3216Metric_Pad1.42x1.75mm_HandSolder" V 3980 7450 50  0001 C CNN
F 3 "~" H 4050 7450 50  0001 C CNN
	1    4050 7450
	-1   0    0    1   
$EndComp
$Comp
L Device:R R56
U 1 1 5FCF9B90
P 4150 7450
F 0 "R56" V 4150 7100 50  0000 C CNN
F 1 "10k" V 4150 7450 50  0000 C CNN
F 2 "Resistor_SMD:R_1206_3216Metric_Pad1.42x1.75mm_HandSolder" V 4080 7450 50  0001 C CNN
F 3 "~" H 4150 7450 50  0001 C CNN
	1    4150 7450
	-1   0    0    1   
$EndComp
$Comp
L Device:R R57
U 1 1 5FCF9DA1
P 4250 7450
F 0 "R57" V 4250 7100 50  0000 C CNN
F 1 "10k" V 4250 7450 50  0000 C CNN
F 2 "Resistor_SMD:R_1206_3216Metric_Pad1.42x1.75mm_HandSolder" V 4180 7450 50  0001 C CNN
F 3 "~" H 4250 7450 50  0001 C CNN
	1    4250 7450
	-1   0    0    1   
$EndComp
Wire Wire Line
	3550 7300 3550 7200
Connection ~ 3550 7200
Wire Wire Line
	3550 7200 3650 7200
$Comp
L Device:R R40
U 1 1 5FD83750
P 11550 5700
F 0 "R40" V 11600 5900 50  0000 C CNN
F 1 "390" V 11550 5700 50  0000 C CNN
F 2 "Resistor_SMD:R_1206_3216Metric_Pad1.42x1.75mm_HandSolder" V 11480 5700 50  0001 C CNN
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
F 2 "Resistor_SMD:R_1206_3216Metric_Pad1.42x1.75mm_HandSolder" V 11480 5800 50  0001 C CNN
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
F 2 "Resistor_SMD:R_1206_3216Metric_Pad1.42x1.75mm_HandSolder" V 11480 5900 50  0001 C CNN
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
F 2 "Resistor_SMD:R_1206_3216Metric_Pad1.42x1.75mm_HandSolder" V 11480 6000 50  0001 C CNN
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
F 2 "Resistor_SMD:R_1206_3216Metric_Pad1.42x1.75mm_HandSolder" V 11480 6100 50  0001 C CNN
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
F 2 "Resistor_SMD:R_1206_3216Metric_Pad1.42x1.75mm_HandSolder" V 11480 6200 50  0001 C CNN
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
F 2 "Resistor_SMD:R_1206_3216Metric_Pad1.42x1.75mm_HandSolder" V 11480 6300 50  0001 C CNN
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
F 2 "Resistor_SMD:R_1206_3216Metric_Pad1.42x1.75mm_HandSolder" V 11480 6400 50  0001 C CNN
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
F 2 "Resistor_SMD:R_1206_3216Metric_Pad1.42x1.75mm_HandSolder" V 11480 4400 50  0001 C CNN
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
F 2 "Resistor_SMD:R_1206_3216Metric_Pad1.42x1.75mm_HandSolder" V 11480 4500 50  0001 C CNN
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
F 2 "Resistor_SMD:R_1206_3216Metric_Pad1.42x1.75mm_HandSolder" V 11480 4600 50  0001 C CNN
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
F 2 "Resistor_SMD:R_1206_3216Metric_Pad1.42x1.75mm_HandSolder" V 11480 4700 50  0001 C CNN
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
F 2 "Resistor_SMD:R_1206_3216Metric_Pad1.42x1.75mm_HandSolder" V 11480 4800 50  0001 C CNN
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
F 2 "Resistor_SMD:R_1206_3216Metric_Pad1.42x1.75mm_HandSolder" V 11480 4900 50  0001 C CNN
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
F 2 "Resistor_SMD:R_1206_3216Metric_Pad1.42x1.75mm_HandSolder" V 11480 5000 50  0001 C CNN
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
F 2 "Resistor_SMD:R_1206_3216Metric_Pad1.42x1.75mm_HandSolder" V 11480 5100 50  0001 C CNN
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
F 2 "Resistor_SMD:R_1206_3216Metric_Pad1.42x1.75mm_HandSolder" V 11480 2550 50  0001 C CNN
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
F 2 "Resistor_SMD:R_1206_3216Metric_Pad1.42x1.75mm_HandSolder" V 11480 2650 50  0001 C CNN
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
F 2 "Resistor_SMD:R_1206_3216Metric_Pad1.42x1.75mm_HandSolder" V 11480 2750 50  0001 C CNN
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
F 2 "Resistor_SMD:R_1206_3216Metric_Pad1.42x1.75mm_HandSolder" V 11480 2850 50  0001 C CNN
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
F 2 "Resistor_SMD:R_1206_3216Metric_Pad1.42x1.75mm_HandSolder" V 11480 2950 50  0001 C CNN
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
F 2 "Resistor_SMD:R_1206_3216Metric_Pad1.42x1.75mm_HandSolder" V 11480 3050 50  0001 C CNN
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
F 2 "Resistor_SMD:R_1206_3216Metric_Pad1.42x1.75mm_HandSolder" V 11480 3150 50  0001 C CNN
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
F 2 "Resistor_SMD:R_1206_3216Metric_Pad1.42x1.75mm_HandSolder" V 11480 3250 50  0001 C CNN
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
F 2 "Resistor_SMD:R_1206_3216Metric_Pad1.42x1.75mm_HandSolder" V 11480 1250 50  0001 C CNN
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
F 2 "Resistor_SMD:R_1206_3216Metric_Pad1.42x1.75mm_HandSolder" V 11480 1350 50  0001 C CNN
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
F 2 "Resistor_SMD:R_1206_3216Metric_Pad1.42x1.75mm_HandSolder" V 11480 1450 50  0001 C CNN
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
F 2 "Resistor_SMD:R_1206_3216Metric_Pad1.42x1.75mm_HandSolder" V 11480 1550 50  0001 C CNN
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
F 2 "Resistor_SMD:R_1206_3216Metric_Pad1.42x1.75mm_HandSolder" V 11480 1650 50  0001 C CNN
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
F 2 "Resistor_SMD:R_1206_3216Metric_Pad1.42x1.75mm_HandSolder" V 11480 1750 50  0001 C CNN
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
F 2 "Resistor_SMD:R_1206_3216Metric_Pad1.42x1.75mm_HandSolder" V 11480 1850 50  0001 C CNN
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
F 2 "Resistor_SMD:R_1206_3216Metric_Pad1.42x1.75mm_HandSolder" V 11480 1950 50  0001 C CNN
F 3 "~" H 11550 1950 50  0001 C CNN
	1    11550 1950
	0    -1   -1   0   
$EndComp
Wire Wire Line
	11700 1950 11900 1950
$Comp
L Device:C_Small C3
U 1 1 605106EB
P 1400 4100
F 0 "C3" V 1171 4100 50  0000 C CNN
F 1 "0.1uF" V 1262 4100 50  0000 C CNN
F 2 "Capacitor_SMD:C_1206_3216Metric_Pad1.42x1.75mm_HandSolder" H 1400 4100 50  0001 C CNN
F 3 "~" H 1400 4100 50  0001 C CNN
	1    1400 4100
	0    1    1    0   
$EndComp
$Comp
L Device:C_Small C4
U 1 1 60510F7C
P 1550 4550
F 0 "C4" V 1321 4550 50  0000 C CNN
F 1 "0.1uF" V 1412 4550 50  0000 C CNN
F 2 "Capacitor_SMD:C_1206_3216Metric_Pad1.42x1.75mm_HandSolder" H 1550 4550 50  0001 C CNN
F 3 "~" H 1550 4550 50  0001 C CNN
	1    1550 4550
	0    1    1    0   
$EndComp
$Comp
L power:VBUS #PWR0119
U 1 1 6058CB52
P 5150 5100
F 0 "#PWR0119" H 5150 4950 50  0001 C CNN
F 1 "VBUS" H 5165 5273 50  0000 C CNN
F 2 "" H 5150 5100 50  0001 C CNN
F 3 "" H 5150 5100 50  0001 C CNN
	1    5150 5100
	1    0    0    -1  
$EndComp
Wire Wire Line
	5150 5100 5150 5200
Wire Wire Line
	5150 5200 5000 5200
Wire Wire Line
	5150 5200 5300 5200
Connection ~ 5150 5200
$EndSCHEMATC
