/****************************************
Example Sound Level Sketch for the 
Adafruit Microphone Amplifier
****************************************/

const int sampleWindow = 10; // Sample window width in mS (50 mS = 20Hz)
unsigned int sample;
int val=0;
int upperLimit=512;
int lowerLimit=0;

void setup() 
{
  analogReference(INTERNAL);
   pinMode(0, OUTPUT);
   pinMode(1, OUTPUT);
   pinMode(A1, INPUT);
}


void loop() 
{
   unsigned long startMillis= millis();  // Start of sample window
   unsigned int peakToPeak = 0;   // peak-to-peak level

   unsigned int signalMax = 0;
   unsigned int signalMin = 1024;

   // collect data for 50 mS
   while (millis() - startMillis < sampleWindow)
   {
      sample = analogRead(A1);
      
   }
   peakToPeak = sample;  // max - min = peak-peak amplitude
   constrain(peakToPeak, lowerLimit, upperLimit);
   val = map(peakToPeak, lowerLimit, upperLimit, 0, 255);
   //analogWrite(0, val);
   analogWrite(1, val);
}
