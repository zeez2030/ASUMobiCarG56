//ex:1-sheet1
const int LED = 10;
void setup() 
{
  pinMode(LED,OUTPUT);
}

void loop() 
{
  digitalWrite(LED,HIGH);
  delay(2000);
  digitalWrite(LED,LOW);
  delay(6000);
}
