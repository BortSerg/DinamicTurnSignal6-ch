void auto_tune(){
  
  uint16_t time_start = 0;
  uint16_t time_end = 0;
  byte count_flash = 0;
  
  digitalWrite(2,HIGH);                // Показываем что в режиме автотюна
  
  bool flashing_flag_1 = false;

  Serial.println("Tune mode on");
  for ( ; count_flash < cycle_autotune;){
    Serial.println("=================================");
    Serial.println("Ожидаю включения поворотника");
    for( ;flashing_flag_1 != true; ){  
        if(digitalRead(7)==LOW && flashing_flag_1 ==false) {
          Serial.println("Поворотник включен");
          time_start = millis();
          Serial.println ("*********" + String(time_start));
          flashing_flag_1 = true;
          
          if (time_end != 0){         //интервал пауз между поворотами
            Serial.print("Время паузы: ");
            Serial.println(time_start - time_end);
            Config.INTERVAL_PAUSE += time_start - time_end;
            
          }
          
          time_end = 0;
        }
    }
    
    Serial.println("Ожидаю отключения поворотника");
    for( ; flashing_flag_1 != false; ){
        if (time_start !=0 && digitalRead(7)==HIGH){
            time_end = millis();
            Serial.println("*********" + String(time_end));
            Serial.print ("Время работы поворотника: ");
            turn_signal_time[count_flash] = time_end-time_start;
            Serial.println(String(turn_signal_time[count_flash]) + " ms");
            
            flashing_flag_1 = false;
            time_start = 0;
            
        }
    }
  count_flash++;
  }
  Serial.println("=================================");
    
  for (;count_flash >0 ; count_flash-- ){
    Serial.println (turn_signal_time[count_flash-1]);
    Config.INTERVAL_FLASH += turn_signal_time[count_flash-1];
    }
    
  Config.INTERVAL_FLASH = Config.INTERVAL_FLASH / cycle_autotune;         // Среднее время работы поворотника
  Config.INTERVAL_PAUSE = Config.INTERVAL_PAUSE / cycle_autotune -1;
  Serial.print("Среднее время работы поворотника: ");
  Serial.println (Config.INTERVAL_FLASH);
  Serial.print("Среднее время выключеного поворотника: ");
  Serial.println (Config.INTERVAL_PAUSE);  
  digitalWrite(2,LOW);                          //Тушим красный диод
  for(byte i = 0; i < 3; i++){                  //Мигаем зеленым диодом
      digitalWrite(8,HIGH);
      delay(300);
      digitalWrite(8,LOW);
      delay(300);  
  }
  Serial.println ("Автотюн завершен");
  EEPROM.put(0, Config.INTERVAL_FLASH);
  EEPROM.put(2, Config.INTERVAL_PAUSE);
}
