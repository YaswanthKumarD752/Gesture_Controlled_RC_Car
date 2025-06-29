#include <WiFi.h>

const char* ssid = "SSID";
const char* password = "PASSWORD";

WiFiServer server(80);

// Motor pins
int in1 = 16;
int in2 = 17;
int in3 = 18;
int in4 = 19;

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }

  Serial.print("Connected. IP: ");
  Serial.println(WiFi.localIP());

  server.begin();

  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
}

void loop() {
  WiFiClient client = server.available();
  if (client) {
    String req = client.readStringUntil('\r');
    client.flush();

    if (req.indexOf("/forward") != -1) {
      forward();
    } else if (req.indexOf("/backward") != -1) {
      backward();
    } else if (req.indexOf("/left") != -1) {
      left();
    } else if (req.indexOf("/right") != -1) {
      right();
    } else if (req.indexOf("/stop") != -1) {
      stopMotors();
    }

    client.print("HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\nOK");
    client.stop();
  }
}

void forward() {
  digitalWrite(in1, HIGH); digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH); digitalWrite(in4, LOW);
}

void backward() {
  digitalWrite(in1, LOW); digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW); digitalWrite(in4, HIGH);
}

void left() {
  digitalWrite(in1, LOW); digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH); digitalWrite(in4, LOW);
}

void right() {
  digitalWrite(in1, HIGH); digitalWrite(in2, LOW);
  digitalWrite(in3, LOW); digitalWrite(in4, HIGH);
}

void stopMotors() {
  digitalWrite(in1, LOW); digitalWrite(in2, LOW);
  digitalWrite(in3, LOW); digitalWrite(in4, LOW);
}
