int up = 0;
int down = 0;
int right = 0;
int left = 0;
bool button;

long int valX = 0;
long int valY = 0;

bool flag = true;

void setup()
{
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
  Serial.begin(9600);
  Serial1.begin(9600);
  Serial1.print("CONNECTED");
  Serial1.print("#");
}

void loop()
{
  Joystick();

  Serial.print(up);
  Serial.print("   ");
  Serial.print(down);
  Serial.print("   ");
  Serial.print(left);
  Serial.print("   ");
  Serial.print(right);
  Serial.print("   ");
  Serial.println(button);
}

void Joystick() {
  if (Serial1.available())
  {
    int data = Serial1.read();
    if (data <= 100) {
      if (flag) {
        valX = data;
        valX = valX - 50;
        if (valX > 0) {
          right = valX;
          left = 0;
        }
        else if (valX < 0) {
          right = 0;
          left = valX * (-1);
        }
        else {
          right = 0;
          left = 0;
        }
        left = map(left, 0, 50, 0, 255);
        right = map(right, 0, 50, 0, 255);
        flag = false;
      }
      else {
        valY = data;
        valY = (valY - 50) * -1;
        if (valY > 0) {
          up = valY;
          down = 0;
        }
        else if (valY < 0) {
          up = 0;
          down = valY * (-1);
        }
        else {
          up = 0;
          down = 0;
        }
        up = map(up, 0, 50, 0, 255);
        down = map(down, 0, 50, 0, 255);
        flag = true;
      }
    }
    else{
      if(data == 105){
        button = 1;
        digitalWrite(13,HIGH);
      }
      if(data == 106){
        button = 0;
        digitalWrite(13,LOW);
      }
    }
  }
}

