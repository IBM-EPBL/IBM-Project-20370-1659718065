import winsound
import random
import time
def temperature(n):
    key=90
    if(n>key):
        for i in range(3):
            winsound.Beep(500, 100)
        return "high temperature"
def humidity(k):
    val=30
    if(k>val):
        return "rainy"
    else:
        return "cold"
i=0
while True:
    n=random.randint(0,670)
    k=random.randint(5,100)
    print(humidity(k))
    print(temperature(n))
    time.sleep(1)