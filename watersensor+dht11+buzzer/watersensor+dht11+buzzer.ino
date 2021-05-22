// 201813172069 Yasin Seven Mikrodenetleyiciler dersi Su seviye sensörü ve DHT Sıcaklık , nem sensörü ile buzzer hoperlör çalıştırma projesi
#include "DHT.h"
#define DHTPIN D2     
#define DHTTYPE DHT11
int buzzerPin = D3;

DHT dht(DHTPIN, DHTTYPE);


void setup() {
  Serial.begin(9600); 
  dht.begin();
  pinMode(D3,OUTPUT);
  
}

void loop() {
  float nem = dht.readHumidity();
  float sicaklik = dht.readTemperature();
  
  


  Serial.print("Nem %: "); 
  Serial.println(nem);
  Serial.print("Sıcaklık: "); 
  Serial.println(sicaklik);
  int su_seviyesi=analogRead(A0);
  Serial.print("Su Seviyesi 0 ila 1000 arasında : ");
  Serial.println(su_seviyesi);
  if(su_seviyesi  > 100 ){
     digitalWrite(D3,HIGH);
     delay(2000);
  }
  else{
    digitalWrite(D3,LOW);
  }
  
  Serial.print(" Buzzer Ses : " ) ;
  Serial.println(su_seviyesi);
  delay(2000);

  

}
