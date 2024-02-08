int analogPin = A5; // analog port pin of left motor
int ADval = 0; // A/D value of left motor
int Vin = 1; // reference voltage
float Vout = 0; // measured voltage of left motor
float R2 = 10000; // resistance of R2 for left motor
float R1 = 1; // resistance of the photoresistor for left motor
float buffer = 0; // variable for temporary storage
int wheel = 3; // left motor
int wheel1 = 6;// right motor
int analogPin1 = A2; // analog port pin of right motor
int ADval1 = 0; // A/D value of right motor
int Vin1 = 1; // reference voltage
float Vout1 =0; // measured voltage of right motor
float R4 = 10000; // resistance of R4
float R3 = 0; // resistance of the photoresistor for right motor
float buffer1 = 0; // variable for temporary storage


// setup function
void setup()
{
 Serial.begin(9600);
 pinMode(wheel, OUTPUT);
 pinMode(wheel1, OUTPUT);
}
// infinite loop function
void loop(){
 ADval = analogRead(analogPin); //read the analog input of left motor
 ADval1 = analogRead(analogPin1); //  read analog input of righjt motor
 if(ADval)
 {
 Serial.print("ADval: "); //print AD value of left motor
 Serial.println(ADval); 
 buffer = ADval * Vin;
 Vout = (buffer)/1024.0; // 10 bit AD conversion to get Vmeasured
 R1 = ((Vin*R2)-(R2*Vout))/Vout; // photocell resistance for left motor
 delay(0);
 Serial.print("Vout: "); //print voltage value of left motor
 Serial.println(Vout);
Serial.print("R1: "); //print resistor value of left motor
 Serial.println(R1);
 }
 if(ADval1)
 {
 Serial.print("ADval1: "); //print AD value of right motor
 Serial.println(ADval1);
 buffer1 = ADval1 * Vin1;
 Vout1 = (buffer1)/1024.0; // 10 bit AD conversion to get Vmeasured
 R3 = ((Vin1*R4)-(R4*Vout1))/Vout1; // photocell resistance of right motor
 Serial.print("Vout1: "); //print voltage value of right motor
 Serial.println(Vout1);
 Serial.print("R3: "); //print resistor value
 Serial.println(R3);
 }
 //pause statement
 if(Vout < 0.30 && Vout1 < 0.30) { // when both photocells detect light 
    digitalWrite(wheel1, HIGH); // left motor goes
    digitalWrite(wheel, HIGH); // right motor goes
    delay(20);
    digitalWrite(wheel, LOW); // left motor stops
    digitalWrite(wheel1, LOW); // right motor stops
    delay(60);
    digitalWrite(wheel, HIGH); // left motor goes
    digitalWrite(wheel1, HIGH); // right motor goes
    delay(20);
} else if (Vout < 0.30 && Vout1>0.25) { // when right photocell detects darkness but left detects light
    digitalWrite(wheel, HIGH); // left motor goes
    delay(20);
    digitalWrite(wheel1, LOW); // right motor stops
    delay(40);
    digitalWrite(wheel, LOW); // left motor stops
    delay(20);
  
} else if (Vout1 < 0.25 && Vout> 0.30) { // when left photocell detects darkness but right detects light
    digitalWrite(wheel1, HIGH); // right motor goes
    delay(20);
    digitalWrite(wheel, LOW); // left motor stops
    delay(40);
    digitalWrite(wheel1, LOW); // right motor goes
    delay(20);
} else { // when both  photocells detect darkness
    digitalWrite(wheel, LOW); // left motor stops
    digitalWrite(wheel1, LOW); //right motor stops
    delay(40);
}
 }
 









