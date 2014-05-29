int in=0;
int val=0;

void setup()
{
  pinMode(A1, INPUT);
  pinMode(0, OUTPUT);
  pinMode(1, OUTPUT);
}

void loop()
{
  in = analogRead(A1);
  val = map(in, 170, 360, 0, 255);
  constrain(val, 255, 0);
  analogWrite(0, val);
  analogWrite(1, 255-val);
  delay(2);
}

