#define Sensor 5
#define Solcizgi A2
#define Sagcizgi A1
#define MotorR1 7
#define MotorR2 6
#define MotorL1 9
#define MotorL2 8
int durum=1; // sensörden gelen data
int solc=1; //sol çizgiden gelen data
int sagc=1; //sağ çizgiden gelen data

void setup() {
  pinMode(Sensor,INPUT);
  pinMode(MotorL1,OUTPUT);
  pinMode(MotorL2,OUTPUT);
  pinMode(MotorR1,OUTPUT);
  pinMode(MotorR2,OUTPUT);
  Serial.begin(9600); 
}
void loop() {
  durum=digitalRead(Sensor);
  solc=analogRead(Solcizgi);
  sagc=analogRead(Sagcizgi);
  //Sensör ortam ışığına göre değişken değerler verdiği için ölçüm sonuçlarını alıyoruz.
  //Serial.println(analogRead(Sagcizgi));
  //Serial.println(analogRead(Solcizgi)); 
  //Sensör ortam ışığına göre değişken değerler verdiği için ölçüm sonuçlarını alıyoruz.
  if(sagc<600 || solc<750){ //600 ve 750 değeri ortama göre değişmektedir.
    if(durum==0){
      ileri();
    }else if(durum==1){
      sag();
    }
  }else{
    geri();
    delay(1000);
  }
}
void ileri(){
    digitalWrite(MotorL1, HIGH);
    digitalWrite(MotorL2, LOW);

    digitalWrite(MotorR1, HIGH);
    digitalWrite(MotorR2, LOW);
}
void geri(){
    digitalWrite(MotorL1, LOW);
    digitalWrite(MotorL2, HIGH);

    digitalWrite(MotorR1, LOW);
    digitalWrite(MotorR2, HIGH);
}
void sag(){
    digitalWrite(MotorL1, LOW);
    digitalWrite(MotorL2, HIGH);

    digitalWrite(MotorR1, HIGH);
    digitalWrite(MotorR2, LOW);
}
