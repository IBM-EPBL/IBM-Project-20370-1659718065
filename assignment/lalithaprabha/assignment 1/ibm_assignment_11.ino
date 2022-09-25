const int rl1 = 13, rl2 = 12, buzz = 11,motor = 10, trig = 3, echo = 4;
const int ldr = A1, pir = A2, tmp = A0;

int prev_state=0;


void setup()
{
  Serial.begin(9600);
  pinMode(motor, OUTPUT);
  pinMode(rl1,OUTPUT);
  pinMode(rl2,OUTPUT);
  pinMode(buzz,OUTPUT);
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  pinMode(ldr,INPUT);
  pinMode(pir,INPUT);
  pinMode(tmp,INPUT);

}

void loop()
{
 float temperature = analogRead(tmp);
  temperature = map(temperature,20,258,0,100);
 float light = analogRead(ldr);
 light = map(light,6,679,0,255);
 float motion = analogRead(pir);
 long duration;
 int distance;
 digitalWrite(trig, LOW);
 delayMicroseconds(2);
 digitalWrite(trig, HIGH);
 delayMicroseconds(10);
 digitalWrite(trig, LOW);
 duration = pulseIn(echo, HIGH);
 distance = duration * 0.034 / 2;
 
 if(distance <14)
 {
   digitalWrite(buzz,HIGH);
 }
  else
  {
    digitalWrite(buzz,LOW);
  }
  
   if(motion)
 {
   digitalWrite(rl1,HIGH);
 }
  else
  {
    digitalWrite(rl1,LOW);
  }
  
  if(light <128)
 {
   digitalWrite(rl2,HIGH);
 }
  else
  {
    digitalWrite(rl2,LOW);
  }
  if(temperature >30)
 {
   digitalWrite(motor,HIGH);
 }
  else
  {
    digitalWrite(motor,LOW);
  }
}