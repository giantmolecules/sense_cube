/****************************************
Example Sound Level Sketch for the 
Adafruit Microphone Amplifier
****************************************/

const int sampleWindow = 100; // Sample window width in mS (50 mS = 20Hz)
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
      if (sample < 1024)  // toss out spurious readings
      {
         if (sample > signalMax)
         {
            signalMax = sample;  // save just the max levels
         }
         else if (sample < signalMin)
         {
            signalMin = sample;  // save just the min levels
         }
      }
   }
   peakToPeak = signalMax - signalMin;  // max - min = peak-peak amplitude
   constrain(peakToPeak, lowerLimit, upperLimit);
   val = map(peakToPeak, lowerLimit, upperLimit, 0, 255);
   //analogWrite(0, val);
   analogWrite(1, 255-val);
}
