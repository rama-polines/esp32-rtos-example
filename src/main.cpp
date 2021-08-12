#include <Arduino.h>
#define M_A 16
#define M_B 4
#define M_PWM 17
#define EN_A 26
#define EN_B 35

void toggleLED(void *parameters)
{
  pinMode(LED_BUILTIN, OUTPUT);
  for (;;)
  {
    digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
    vTaskDelay(500 / portTICK_PERIOD_MS);
  }
}

void printMessage(void *parameters)
{
  for (;;)
  {
    Serial.println("Halllooo => " + (String)millis());
    vTaskDelay(1000 / portTICK_PERIOD_MS);
  }
}

void setup()
{
  Serial.begin(115200);

  xTaskCreate(
      toggleLED,    // Fungsi yang akan dipanggil
      "Toggle LED", // Nama task
      1000,         // Alokasi stack/memori (bytes)
      NULL,         // Parameter yg akan diberikan
      0,            // Prioritas task
      NULL          // Task handler
  );

  xTaskCreate(
      printMessage,    // Fungsi yang akan dipanggil
      "Print Message", // Nama task
      1000,            // Alokasi stack/memori (bytes)
      NULL,            // Parameter yg akan diberikan
      0,               // Prioritas task
      NULL             // Task handler
  );
}

void loop()
{
  vTaskDelay(1);
}