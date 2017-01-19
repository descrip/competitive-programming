#no heads up about big numbers? cool

import sys

first = True
for line in sys.stdin:
    if not first:
        print("")
    first = False
    y = int(line)
    leap = False
    ordi = True
    if (y%4 == 0 and y%100 != 0) or y%400 == 0:
        leap = True
        ordi = False
        print("This is leap year.")
    if y%15 == 0:
        ordi = False
        print("This is huluculu festival year.")
    if leap and y%55 == 0:
        ordi = False
        print("This is bulukulu festival year.")
    if ordi:
        print("This is an ordinary year.")
