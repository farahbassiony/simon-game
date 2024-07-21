#define led1 7
#define led2 8
#define led3 9
#define led4 10

#define button1 3
#define button2 4
#define button3 5
#define button4 6 

#define buzzer 2

int score = 0;
int randomNumber;
String x = "";
int delayTime;

int in[100];
int out[100];

void setup() {
  Serial.begin(9600);
  Serial.println("START THE GAME");

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);

  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
  pinMode(button3, INPUT_PULLUP);
  pinMode(button4, INPUT_PULLUP);

    pinMode(buzzer, OUTPUT);

}

void loop() {
  Serial.println("CHOOSE ONE OF THE FOLLOWING: 1-EASY 2-INTERMEDIATE 3-HARD!!");

  bool diff = false;
  while (!diff) {
    if (Serial.available()) {
      x = Serial.readString();
      diff = true;
    }
  }

  if (x.equals("1")) {
    delayTime = 1000;
  } else if (x.equals("2")) {
    delayTime = 700;
  } else if (x.equals("3")) {
    delayTime = 300;
  } else {
    delayTime = 1000;
  }

  int flag = 0;
  for (int j = 0; j < 100; j++) {
    Serial.print("LEVEL ");
    Serial.println(j + 1);
    randomNumber = random(1, 5);
    in[j] = randomNumber;
    for (int i = 0; i <= j; i++) {
      ledLightneing(in[i], delayTime);
    }

    for (int i = 0; i <= j; i++) {
      delay(500);
      Serial.println("ENTER THE NEXT NUMBER");
      out[i] = getReading();
      Serial.println(out[i]);
      if (out[i] == in[i]) {
        Serial.println("CORRECT ANSWER");
      } else {
        Serial.println("Wrong Answer!!");
        flag = 1;
        break;
      }
    }
    if (flag) {
      Serial.print("YOU LOST AND YOUR FINAL SCORE IS ");
      Serial.println(score);
      score = 0;
       digitalWrite(led1, HIGH);
       digitalWrite(led2, HIGH);
       digitalWrite(led3, HIGH); 
       digitalWrite(led4, HIGH);
       digitalWrite(buzzer, HIGH);

       delay(2000);
       digitalWrite(led1, LOW);
       digitalWrite(led2, LOW);
       digitalWrite(led3, LOW);
       digitalWrite(led4, LOW);
       digitalWrite(buzzer, LOW);

       delay(2000);


      break;
    }
    score++;

    Serial.print("YOUR SCORE IS NOW ");
    Serial.println(score);
  }
}

int getReading() {
  bool reading = false;
  int x;
  while (!reading) {
    if (digitalRead(button1) == LOW) {
      x = 1;
      reading = true;
      return x;
    } else if (digitalRead(button2) == LOW) {
      x = 2;
      reading = true;
      return x;
    } else if (digitalRead(button3) == LOW) {
      x = 3;
      reading = true;
      return x;
    } else if (digitalRead(button4) == LOW) {
      x = 4;
      reading = true;
      return x;
    }
  }
}

void ledLightneing(int randomNumber, int delayTime) {
  if (randomNumber == 1) {
    digitalWrite(led1, HIGH);
    delay(delayTime);
    digitalWrite(led1, LOW);
  }
  if (randomNumber == 2) {
    digitalWrite(led2, HIGH);
    delay(delayTime);
    digitalWrite(led2, LOW);
  }
  if (randomNumber == 3) {
    digitalWrite(led3, HIGH);
    delay(delayTime);
    digitalWrite(led3, LOW);
  }
  if (randomNumber == 4) {
    digitalWrite(led4, HIGH);
    delay(delayTime);
    digitalWrite(led4, LOW);
  }
}