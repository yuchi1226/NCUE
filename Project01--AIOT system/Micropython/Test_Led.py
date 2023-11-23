from machine import Pin
import time
led = Pin(2, Pin.OUT)

while True:
    led.value(0) #on
    time.sleep(1)
    led.value(1) #off
    time.sleep(1)
