import machine
import utime

# 定義IR LED的引腳
ir_led_pin = machine.Pin(23, machine.Pin.OUT)  # 替換為你的IR LED的引腳

# 定義IR信號的模式
ir_signal = [1, 0, 1, 0, 1]  # 這是一個簡單的示例，你可以根據需要修改

# 定義IR信號的頻率（Hz）和持續時間（毫秒）
ir_frequency = 38000  # 通常使用38kHz
ir_duration = 500  # 持續500毫秒

# 發射IR信號
try:
    while True:
        for _ in range(5):
            for bit in ir_signal:
                ir_led_pin.on()
                utime.sleep_us(int(1000000 / (2 * ir_frequency)))  # 開啟一半的周期
                ir_led_pin.off()
                utime.sleep_us(int(1000000 / (2 * ir_frequency)))  # 關閉一半的周期
            utime.sleep_ms(ir_duration)
        utime.sleep_ms(2000)  # 等待2秒再發射下一個信號

except KeyboardInterrupt:
    pass
