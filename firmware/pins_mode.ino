void pins_mode(){
  
//******** ШИМ пины поворотника********
  pinMode(11, OUTPUT);        // D11 как выход
  analogWrite(11, 0);
pinMode(10, OUTPUT);          // D10 как выход
  analogWrite(10, 0);
pinMode(9, OUTPUT);           // D9 как выход
  analogWrite(9, 0);
pinMode(6, OUTPUT);           // D6 как выход
  analogWrite(6, 0);
pinMode(5, OUTPUT);           // D5 как выход
  analogWrite(5, 0);
pinMode(3, OUTPUT);           // D3 как выход
  analogWrite(3, 0);
  
 //********Пины управления реле и автотюна********   

 pinMode (7, INPUT);          // D7 вход сигнала поворотника. Управление подтяжкой на землю.
  digitalWrite(7,HIGH);
 pinMode(2, OUTPUT);          // D2 вывод на красный диод (начало автотюна)
  digitalWrite(2, LOW);
 pinMode(1, OUTPUT);          // D1 вывод на синий диод (моргнет 2 раза при завершении настройки яркости)
  digitalWrite(1, LOW);       
 pinMode (8, OUTPUT);         // D8 вывод на зеленый диод (моргнет 2 раза при завершении автотюна)
  digitalWrite(8, LOW);
 pinMode(12,INPUT);           // D12 вход в режим автотюна нажатием кнопки (подтяжка к земле)
  digitalWrite(12, HIGH);

// ********Пины управления яркостью********

  pinMode(A3, INPUT);
    digitalWrite(A3, HIGH);
  pinMode(A2, INPUT);
    digitalWrite(A2, HIGH);
}
