

int sensorPin = A0;    
int ledPin = 11;      
int sensorValue = 0;  
float averageValue = 0;
int count=0;
void setup() {
 
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);  
  digitalWrite(sensorPin, HIGH);
  
}

void loop() {
  // read the value from the sensor:
  sensorValue = analogRead(sensorPin);  
  
  if(millis()<2000)
  {
      averageValue +=((float)sensorValue-averageValue)/10.f; 
      
      digitalWrite(ledPin,HIGH);
    
 
      
  }else 
  {
    
    if(sensorValue>averageValue +4){
      count++;
      Serial.println(count);
      averageValue =sensorValue+10;

      digitalWrite(ledPin,HIGH);
      delay(1000);
    }
    else 
    {
    
        digitalWrite(ledPin,LOW);
        averageValue +=((float)sensorValue-averageValue)/100.f; 
    }
       
  }
}
