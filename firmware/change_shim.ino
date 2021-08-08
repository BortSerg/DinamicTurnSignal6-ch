void change_shim(){
byte flag = 0;
  if (digitalRead(A2) == LOW){
    shim ++;
    if(shim >= max_pwm){
      shim = max_pwm;
      shim_min_max();
      //Serial.println(shim);
    }
    
  }
  

  if(digitalRead(A3) == LOW){
    shim --;
    if (shim <=1) {
      shim = 1;
      shim_min_max();
      //Serial.println(shim);
    }
    
  }
  analogWrite(11, shim);
  analogWrite(10, shim);
  analogWrite(9, shim);
  analogWrite(6, shim);
  analogWrite(5, shim);
  analogWrite(3, shim);
  delay(50);
}

void shim_min_max(){
  for (int i = 0; i<=3; i++)
      {
      analogWrite(11, 0);
      analogWrite(10, 0);
      analogWrite(9, 0);
      analogWrite(6, 0);
      analogWrite(5, 0);
      analogWrite(3, 0);
      delay(200);
      analogWrite(11, shim);
      analogWrite(10, shim);
      analogWrite(9, shim);
      analogWrite(6, shim);
      analogWrite(5, shim);
      analogWrite(3, shim);
      delay(200);
      }
}
