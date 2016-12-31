/* 
 MONSTER MOTOR SHIELD TEST CODE ARDUINO VNH2SP30

 Programa que permite el giro de un motor hacia 
 un solo lado.

                CONNECTION PINS

ARDUINO                         MONSTER MOTOR SHIELD        

  8                                      8
  7                                      7
  5                                      5
  2                                      2
  A0                                     A0
  5V                                     5V
  GND                                    GND

*/

#define MtrBrake 0
#define ClockWise   1
#define CClockWise  2
#define GndBreak 3
#define CounterSenseThresHold 100


int inApin[2] = {7};   //INA CONTRÓL DE GIRO A
int inBpin[2] = {8};   //INB CONTRÓL DE GIRO B
int pwmpin[2] = {5};   //PWM PULSO DE ENTRADA PARA MODULACIÓN
int cspin[2]  = {2};   //CS DETECCIÓN DE CORRIENTE PARA LA ENTRADA ANALÓGICA
int enpin[2]  = {0};   //EN ESTADO DE LA SALIDA DEL PIN ANALÓGICO
int i=0;
int statpin = 13;

void setup()
{
  Serial.begin(9600);
  pinMode(statpin, OUTPUT);
    {
      pinMode(inApin[i], OUTPUT);
      pinMode(inBpin[i], OUTPUT);
      pinMode(pwmpin[i], OUTPUT);
    } 
}

void loop()
{
  motorGo(0, ClockWise, 255);
  motorGo(0, CClockWise, 255);
 
  if ((analogRead(cspin[0]) < CounterSenseThresHold) && (analogRead(cspin[1]) < CounterSenseThresHold))
    digitalWrite(statpin, HIGH);
}

void motorGo(uint8_t motor, uint8_t direct, uint8_t pwm)
{

      if ((direct==0)||(direct==2))
        digitalWrite(inBpin[motor], HIGH);
     else
        digitalWrite(inBpin[motor], LOW);
        delay(1000);

        analogWrite(pwmpin[motor], pwm);
        delay(1000);
}
  

