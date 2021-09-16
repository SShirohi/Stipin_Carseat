# Test Plans

| ID | Description  | I/P  | O/P  | Status |
|---|---|---|---|---|
| TEST_01  | Person on chair | push button=1| push button=1| PASS  |
| TEST_02  | Person not on chair  | push button=0| push button=0 | PASS  |
| TEST_03 | DEVICE OFF| DATA Inputed |NO result|PASS|
| TEST_04  | LED BLINK | Heater=1, Push Button=1| LED=1 | PASS  |
| TEST_05  | LED NOT BLINK | Heater=0,Push Button=0  | LED=0 | PASS  |
|TEST_06  | LCD Display | Inputed| Displayed correctly| PASS  |
| TEST_07  | Potentiometer  | Temp=0| heater=Off | PASS  |
| TEST_08  | Potentiometer | Temp=20| heater=20 degree generation | PASS  |
| TEST_09  | Potentiometer  | Temp=33| heater=30 degree generation | FAIL |
