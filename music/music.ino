int piezo = 8;
int duration = 250;

int notes[] = 
{261,  493, 261};

void setup() {
  pinMode(piezo, OUTPUT);
}

void loop() {
  for (int i = 0; i < 3; i++)
  {
    tone(piezo, notes[i], duration);
    delay(duration);
  }
}
