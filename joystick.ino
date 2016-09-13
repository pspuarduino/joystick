
const int SW_pin = 4; // присвоим переменной SW_pin значение 4 типа int
const int X_pin = A7; // X_pin присвоим аналоговому пину 7
const int Y_pin = A6; // Y_pin присвоим аналоговому пину 7
 
void setup() {
  pinMode(SW_pin, INPUT);
  digitalWrite(SW_pin, HIGH);
  Serial.begin(9600);
}
 
void loop() {
  int clicked = digitalRead(SW_pin);
  int xVal = analogRead(X_pin);
  int yVal = analogRead(Y_pin);
  float dir = getAngle(xVal, yVal);
  getDirection(xVal, yVal);
  delay(500);
}

boolean between(float src, float from, float to){
  if(src >= from && src <= to){
    return true;
  }else{
    return false;
  }
}

String getDirection(int x, int y){
  float angle = getAngle(x,y);
  if(between(angle, -22.5, 22.5)){
    Serial.println("R");
  }else if(between(angle, 22.5, 67.5)){
    Serial.println("RT");
  }else if(between(angle, 67.5, 112.5)){
    Serial.println("T");
  }else if(between(angle, 112.5, 157.5)){
    Serial.println("LT");
  }else if(between(angle, 157.5, 180) || between(angle, -180, -157.5)){
    Serial.println("L");
  }else if(between(angle, -67.5, -22.5)){
    Serial.println("RB");
  }else if(between(angle, -112.5, -67.5)){
    Serial.println("B");
  }else if(between(angle, -157.5, -112.5)){
    Serial.println("LB");
  }
}

float getAngle(int y,int x){
  float x1 = (512 - x);
  float y1 = (512 - y);
  float g = sqrt(x1*x1 + y1*y1);
  float result = acos(x1/g)*57.2958;
  if(y1 < 0){
//    result = 360 - result;
    result = -result;
  }
  return result;
}
