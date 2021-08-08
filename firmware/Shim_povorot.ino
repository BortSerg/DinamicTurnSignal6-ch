#include <EEPROM.h>
 
byte shim = 0;                             //pwm125 - 6.6V 150mA    >190 - 6.6V 340mA
byte test = 0;
byte count = 0;
byte max_pwm = 192;
const byte cycle_autotune = 5;
uint16_t turn_signal_time[cycle_autotune];  //массив времен работы поворотника
bool work = false;

struct Atmega_Config{                          //структура для хранения настроек в EEPROM памяти. Переменные структуры записаны большими буквами, для их отличия от других глобальных переменных
  uint16_t INTERVAL_FLASH = 0;
  uint16_t INTERVAL_PAUSE = 0;
  byte SHIM = 0;
} Config;


void setup() {
  
if (EEPROM.get(0,test) == 0xFF){                //проверка первого включения. если в памяти FF, то записать параметры поумолчанию
Config.INTERVAL_FLASH = 500;
Config.INTERVAL_PAUSE = 500;
Config.SHIM = 3;
EEPROM.put(0, Config);
}
  
pins_mode();

if (digitalRead(12) == LOW) {
  auto_tune()  ;
}

read_Config();
shim = Config.SHIM;

      analogWrite(11, shim);
      delay (Config.INTERVAL_FLASH/6);
     
      analogWrite(10, shim);
      delay (Config.INTERVAL_FLASH/6);
      
      analogWrite(9, shim);
      delay (Config.INTERVAL_FLASH/6);
      
      analogWrite(6, shim);
      delay (Config.INTERVAL_FLASH/6);
      
      analogWrite(5, shim);
      delay (Config.INTERVAL_FLASH/6);
      
      analogWrite(3, shim);
      delay (Config.INTERVAL_FLASH/6);
}
void loop() {
      
      change_shim();
      
      
      if (digitalRead(12) == LOW) {
        if (shim != Config.SHIM){
          EEPROM.put(4, shim);
          EEPROM.get(0, Config);
          for (byte i=0; i<=3; i++){
            digitalWrite(1, HIGH);  
            delay (300);
            digitalWrite(1, LOW);
            delay (300);    
          }
          

        }
    
  }
}
