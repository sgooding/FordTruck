
int inByte = 0;         // incoming serial byte
int pins[4] = {2,3,4,5};
void setup()
{
  // start serial port at 9600 bps:
  Serial.begin(38400);

  for(int i = 0; i < 4; i++ )
    pinMode(pins[i], OUTPUT);   // digital sensor is on digital pin 2
}
unsigned long pin_timeout[4] = { 0, 0, 0, 0 };
void loop()
{
  // if we get a valid byte, read analog ins:
  if (Serial.available() > 0) {
    // get incoming byte:
    inByte = Serial.read();          
    //Serial.println(inByte,DEC); 
    switch(inByte)
    { case 49: // 1
      pin_timeout[0] = millis()+50;
      break;
      case 50: // 2
      pin_timeout[1] = millis()+50;
      break;
      case 51: // 3
      pin_timeout[2] = millis()+50;
      break;
      case 52: // 4
      pin_timeout[3] = millis()+50;
      break;  
    }
  }
  
  
  for(int i = 0; i < 4; i++)
  {
    if( pin_timeout[i] > millis() )
    {
      digitalWrite(pins[i],HIGH);
      //Serial.print(i,DEC);
      //Serial.println(" HIGH");
    }
    else
    {
      digitalWrite(pins[i],LOW);
    }
  }
}




