#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

#define LED_PIN    6
#define LED_COUNT 60


Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);


String rstrng;

class kalman{
  private:
    float Q,R;
    float kalman_old,cov_old;
  public:
    kalman(float Q,float  R){
      this-> Q = Q;
      this-> R = R;
    }
    float kalman_filtre(float veri){
        float kalman_new = this->kalman_old; // eski değer alınır
  float cov_new = this->cov_old + this->Q; //yeni kovaryans değeri belirlenir. Q=0.50 alınmıştır
  
  float kalman_gain = cov_new / (cov_new + this->R); //kalman kazancı hesaplanır. R=0.9 alınmıştır
  float kalman_calculated = kalman_new + (kalman_gain * (veri - kalman_new)); //kalman değeri hesaplanır
  
  cov_new = (1 - kalman_gain) * this->cov_old; //yeni kovaryans değeri hesaplanır
  this->cov_old = cov_new; //yeni değerler bir sonraki döngüde kullanılmak üzere kaydedilir
  
  this->kalman_old = kalman_calculated;

  return kalman_calculated; 
    }
};


void setup() {

#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif

  Serial.begin(9600);
  strip.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  strip.show();            // Turn OFF all pixels ASAP
  strip.setBrightness(255); // Set BRIGHTNESS to about 1/5 (max = 255)
}

int red1 =0, green1=0,blue1=0;
int red =0, green=0,blue=0;

void loop() {

  kalman kalman1(0.1,0.5);
  kalman kalman2(0.1,0.5);
  kalman kalman3(0.1,0.5);
  
while (Serial.available()>1){
  

   red1 = Serial.parseInt();
   green1=Serial.parseInt();
   blue1=Serial.parseInt();
   
   red1=map(red1,0,100,0,255);
   green1=map(green1,0,100,0,255);
   blue1=map(blue1,0,100,0,255);

   red = kalman1.kalman_filtre(red1);
   green = kalman2.kalman_filtre(green1);
   blue = kalman3.kalman_filtre(blue1);
   
   if(Serial.read() != '\n'){
     
    for(int i=0 ; i<12; i++){
    strip.setPixelColor(i, strip.Color(red, green, blue))  ;      //  Set pixel's color (in RAM)
    strip.show();
   }
  }
 }
}
