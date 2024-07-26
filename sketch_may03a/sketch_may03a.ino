#include <Wire.h>
 
 
void setup()
{
  Wire.begin();
 
  Serial.begin(9600);
  while (!Serial);             
  }
 
 
void loop()
{
  byte error, address;
  int nd;
 
  
  nd = 0;
  for(address = 1; address < 127; address++ )
  {
    Wire.beginTransmission(address);
    error = Wire.endTransmission();
 
    if (error == 0)
    {
      Serial.print("I2C address found :0x");
      if (address<16)
        Serial.print("0");
      Serial.print(address,HEX);
      Serial.println("");
 
      nd++;
    }
    else if (error==4)
    {
      Serial.print("Unknown error ");
      if (address<16)
        Serial.print("0");
      Serial.println(address,HEX);
    }    
  }
  if (nd == 0)
    Serial.println("No devices found");
      
 
  delay(5000);         
}
