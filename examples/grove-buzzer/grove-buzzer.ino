// BOARD Seeed Wio 3G
// GROVE D38 <-> Grove - Buzzer (SKU#107020000)

#include <MjGrove.h>

#define BUZZER_ON_TIME  (200)
#define BUZZER_OFF_TIME (800)

GroveBoard Board;
GroveBuzzer Buzzer(&Board.D38);

void setup() {
  delay(200);

  Board.D38.Enable();
  Buzzer.Init();
}

void loop() {
  Buzzer.On();
  delay(BUZZER_ON_TIME);

  Buzzer.Off();
  delay(BUZZER_OFF_TIME);
}
