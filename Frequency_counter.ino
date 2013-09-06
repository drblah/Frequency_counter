//Set how many samples you want the Arduino to base the reading on.
//This will increase the time it takes to measure a frequency but the output will be more even.
unsigned int sample = 500;

void setup()
{
  Serial.begin(9600);
  pinMode(2, INPUT);
}

void loop()
{
  unsigned long highTime = 0;
  unsigned long lowTime = 0;
  

  //Sample the time it takes for the high period of the signal.
  for(unsigned int times = 0; times < sample; times++)
  {
    highTime += pulseIn(2, HIGH);
  }
  
  //Sample the time it takes for the low period of the signal.
  for(unsigned int times = 0; times < sample; times++)
  {
    lowTime += pulseIn(2, LOW);
  }
  
  //Find the average high period of the signal.
  highTime = highTime/sample;
  
  //Find the average high period of the signal.
  lowTime = lowTime/sample;
  
  float period = highTime + lowTime;
  
  //Calculate the frequency from the period time.
  float result = 1/(period/1000000);
  
  Serial.print("High time: ");
  Serial.println(highTime);
  
  Serial.print("Low time: ");
  Serial.println(lowTime);
  
  Serial.print("Frequency: ");
  Serial.print(result);
  Serial.print("Hz\n");
  
}
