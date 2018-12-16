
String inputString = "";
boolean stringComplete = false;

void setup()
{
  for (int thisPin = 2; thisPin <= 5; thisPin++)
  {
    pinMode(thisPin, OUTPUT);
    digitalWrite(thisPin, HIGH);
  }

  Serial.begin(9600);
  inputString.reserve(200);
}

void loop()
{

  if (stringComplete)
  {
    Serial.println(inputString);
    //-----------------------------------------------------------------------------------
    if (inputString.indexOf("IP_") >= 0) //SERIAL CHAR TO CONTINUE BOOT
    {
      Serial.println("Conected");
      Serial.print("OxOUT_");
      for (int thisPin = 2; thisPin <= 5; thisPin++)
      {
        Serial.print(!digitalRead(thisPin));
      }
      Serial.println();
    }
    //-------------------------------------------------------------------------------------------
  if (inputString.indexOf("0xIN") >= 0)
  {
    int spacePosition = inputString.indexOf("0xIN");
    for (int pinN = 2; pinN <= 5; pinN ++ )
    {
      if (inputString.charAt(spacePosition + pinN + 2) == '1')
      {
        digitalWrite(pinN, LOW);
       Serial.print("1");
      }
      else if (inputString.charAt(spacePosition + pinN + 2) == '0')
      {
        digitalWrite(pinN, HIGH);
       Serial.print("0");
      }
    }
    Serial.println();
    Serial.print("OxOUT_");
      for (int thisPin = 2; thisPin <= 5; thisPin++)
      {
        Serial.print(!digitalRead(thisPin));
      }
  }
    inputString = "";
    stringComplete = false;
  }
}

//----------------------------------------------------------------------------------
void serialEvent()
{
  while (Serial.available())
  {
    char inChar = (char)Serial.read();
    inputString += inChar;
    if (inChar == '\n')
    {
      stringComplete = true;
    }
  }
}
//----------------------------------------------------------------

