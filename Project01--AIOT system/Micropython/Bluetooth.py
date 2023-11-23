from machine import Pin
from time import sleep_ms,sleep
import ubluetooth   #导入BLE功能模块
sleep(1)
ble = ubluetooth.BLE()  #创建BLE设备
ble.active(True)  #打开BLE（此时设备将处于就绪态）
led = Pin(2, Pin.OUT) #led引脚

#创建可读可写可通知的UUID
SERVER_1_UUID = ubluetooth.UUID(0x9011)
CHAR_A_UUID = ubluetooth.UUID(0x9012)
CHAR_B_UUID = ubluetooth.UUID(0x9013)

#创建特性并设置特性的读写权限
CHAR_A = (CHAR_A_UUID, ubluetooth.FLAG_READ | ubluetooth.FLAG_WRITE | ubluetooth.FLAG_NOTIFY, )
CHAR_B = (CHAR_B_UUID, ubluetooth.FLAG_READ | ubluetooth.FLAG_NOTIFY, )

SERVER_1 = (SERVER_1_UUID, (CHAR_A , CHAR_B, ) , ) #把特性A和特性B放入服务1
SERVICES = (SERVER_1, ) #把服务1放入服务集和中
((char_a, char_b), ) = ble.gatts_register_services(SERVICES) #注册服务到gatts


#设置BLE广播数据并开始广播（开始广播后设备将处于广播态）
name = bytes("aabbcc", 'UTF-8')
print("蓝牙开始广播")
ble.gap_advertise(100, adv_data = b'\x02\x01\x06\x02\x0A\x10' + bytearray((len(name)+1,0x09))+name)

#定义一个函数，用作蓝牙事件中断
def ble_irq(event, data): # 蓝牙中断函数
    if event == 1: #蓝牙已连接（此时蓝牙将处于连接态）
      print("BLE 连接成功")
    
    elif event == 2: #蓝牙断开连接（此时蓝牙将从链接态进入就绪态）
      print("BLE 断开连接")
      ble.gap_advertise(100, adv_data = b'\x02\x01\x06\x02\x0A\x08' + bytearray((len(name)+1,0x09))+name)#再次启动广播

    elif event == 3: # 收到新write消息
      onn_handle, char_handle = data #判断是来自那个特性的消息
      buffer = ble.gatts_read(char_handle) #读取接收到的消息
      print(char_handle, buffer,str(buffer, 'UTF-8')) #打印消息内容
      if str(buffer, 'UTF-8')=="led_on":
          led.on()
          ble.gatts_notify(0, char_handle, 'led on!')
      elif str(buffer, 'UTF-8')=="led_off":
          led.off()
          ble.gatts_notify(0, char_handle, 'led off!')
      else:
          ble.gatts_notify(0, char_handle, 'Hello')#回复Hello

ble.irq(ble_irq) #注册蓝牙中断函数
