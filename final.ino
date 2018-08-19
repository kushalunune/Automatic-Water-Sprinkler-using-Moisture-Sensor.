

void timer();

void setup()
{
  Serial.begin(9600);
  pinMode(A0, INPUT);
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  
  
}

void loop()
{
  timer();
}
void timer()
{
  int c = 0, i;
  int val = analogRead(A0);
  Serial.print("moisture");
  Serial.println(val);
  
  
  
  while (1)
  {
    delay(1000);
    c++;
    Serial.println(c);
    if (c == 30)
    {
      val = analogRead(A0);
      Serial.print("moisture value=");
      Serial.println(val);
      if (val <= 300)
      {
        digitalWrite(13, LOW);
        digitalWrite(12, LOW);
        Serial.println("sprinkler is off");
      }
      if (val > 300 && val <= 900)
      {
        digitalWrite(13, HIGH);
        digitalWrite(12, HIGH);
        Serial.println("sprinkler is on");
        //delay(5000);
        i = 0;
        while (i <= 10)
        {
          if (i == 10)
          {
            digitalWrite(13, LOW);
            digitalWrite(12, LOW);
            Serial.println("sprinkler is off");
          }
          c++;
          Serial.println(c);
          i++;
          delay(1000);
        }
      }
      if (val > 900)
      {
        digitalWrite(13, HIGH);
        digitalWrite(12, HIGH);
        Serial.println("sprinkler is on");
        i = 0;
        while (i <= 20)
        {
          if (i == 20)
          {
            digitalWrite(13, LOW);
            digitalWrite(12, LOW);
            Serial.println("sprinkler is off");
          }
          c++;
          Serial.println(c);
          i++;
          delay(1000);
        }
      }
    }
    if (c == 60)
    {
      c = 0;
      break;
    }
  }
}

