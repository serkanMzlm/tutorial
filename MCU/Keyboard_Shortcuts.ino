#include "DigiKeyboard.h"
int sure = 1000;
void setup() {

}

void loop() {
  DigiKeyboard.sendKeyStroke(0); // bir tuş vuruşu gönderir
  DigiKeyboard.println("ATTiny85"); //yazi yazdirir
  DigiKeyboard.delay(1000); // bekleme 

  DigiKeyboard.sendKeyStroke(0); // bir tuş vuruşu gönderir
  DigiKeyboard.sendKeyStroke (0,MOD_GUI_LEFT); // Windows tuşu 
  DigiKeyboard.delay(sure); // bekleme 
  DigiKeyboard.sendKeyStroke(KEY_A , MOD_CONTROL_LEFT); //Ctrl + A
  DigiKeyboard.delay(sure);
  DigiKeyboard.sendKeyStroke(KEY_C , MOD_CONTROL_LEFT); //Ctrl + C
  DigiKeyboard.delay(sure);
  DigiKeyboard.sendKeyStroke(KEY_V , MOD_CONTROL_LEFT); //Ctrl + V
  DigiKeyboard.delay(sure);
  DigiKeyboard.sendKeyStroke(KEY_9 , MOD_ALT_RIGHT); //Alt Gr + 9
  DigiKeyboard.delay(sure);
  DigiKeyboard.sendKeyStroke(0 , MOD_ALT_LEFT); //Alt
  DigiKeyboard.delay(sure);
  DigiKeyboard.sendKeyStroke ( KEY_A , MOD_SHIFT_RIGHT); //Shift + A
  DigiKeyboard.delay(sure);

/* 
  DigiKeyboard.sendKeyStroke(0); // Bir tane boş tuşa basar 
  DigiKeyboard.sendKeyStroke(0,MOD_GUI_LEFT); // Windows tuşu  
  DigiKeyboard.sendKeyStroke(MOD_CONTROL_LEFT);//Sol kontrol
  DigiKeyboard.sendKeyStroke(MOD_SHIFT_LEFT);//Sol shift
  DigiKeyboard.sendKeyStroke(MOD_ALT_LEFT);//Sol alt
  DigiKeyboard.sendKeyStroke(MOD_GUI_LEFT);//Windows tuşu
  DigiKeyboard.sendKeyStroke(MOD_CONTROL_RIGHT); 
  DigiKeyboard.sendKeyStroke(MOD_SHIFT_RIGHT);
  DigiKeyboard.sendKeyStroke(MOD_ALT_RIGHT);
  DigiKeyboard.sendKeyStroke(MOD_GUI_RIGHT);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);//Enter
  DigiKeyboard.sendKeyStroke(KEY_SPACE);//Space
  DigiKeyboard.sendKeyStroke(KEY_ARROW_LEFT);//Yön tuşları
  DigiKeyboard.sendKeyStroke(KEY_A);//a tuşu
  DigiKeyboard.sendKeyStroke(KEY_2);//2 tuşu 
  DigiKeyboard.sendKeyStroke(KEY_F1);//F tuşları 
  DigiKeyboard.delay(500); //bekleme
*/
}
