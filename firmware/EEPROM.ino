void save_Config(){
  EEPROM.put(0, Config.INTERVAL_FLASH);
  EEPROM.put(2, Config.INTERVAL_PAUSE);
  EEPROM.put(4, Config.INTERVAL_PAUSE);
  /*
  Serial.println("Даные записаны: ");
  Serial.println (Config.INTERVAL_FLASH);
  Serial.println (Config.INTERVAL_PAUSE); 
     */
}

void read_Config(void){                                   //чтение конфига из EEPROM памяти
  EEPROM.get(0, Config); 
  /*
  Serial.println("Даные прочитаны: ");
  Serial.println (Config.INTERVAL_FLASH);
  Serial.println (Config.INTERVAL_PAUSE);
  Serial.println (Config.SHIM);
  */
}
