int ledPin = 13;
int photoPin = A0;
int A0Voltage;

int ledState = LOW;
double conversionFactor = 0.00488758;
double threshold = 2.5;
double voltage;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  pinMode(photoPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  A0Voltage = analogRead(photoPin);   //returns a value between 0-1023
  voltage = A0Voltage*conversionFactor;
  
  //Serial.println( A0Voltage*conversionFactor );

  if( voltage < threshold )   //photoresistor has been covered
  {
    if( ledState == LOW )
    {
      digitalWrite( ledPin, HIGH );
      ledState = HIGH;
    }else if( ledState == HIGH )
    {
      digitalWrite( ledPin, LOW );
      ledState = LOW;
    }
  }
  delay(1000);
}
