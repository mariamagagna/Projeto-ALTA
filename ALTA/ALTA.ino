#include <LiquidCrystal.h>

// ===============================
// LCD 16x2
// RS, EN, D4, D5, D6, D7
// ===============================
LiquidCrystal lcd(36, 38, 40, 42, 44, 46);

// ===============================
// Monitoramento de Nivel de Rio
// HC-SR04 + 4 LEDs + Buzzer
// ===============================

// Pinos do sensor ultrassonico
const int trigPin = 9;
const int echoPin = 8;

// LEDs
const int ledVerde = 7;
const int ledAmarelo = 6;
const int ledVermelho1 = 5;
const int ledVermelho2 = 4;

// Buzzer
const int buzzer = 3;

// Limites (em cm)
float nivelNormal = 15;
float nivelAtencao = 10;
float nivelPreocupante = 6;

long duracao;
float distancia;

void setup() {

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(ledVerde, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVermelho1, OUTPUT);
  pinMode(ledVermelho2, OUTPUT);
  pinMode(buzzer, OUTPUT);

  Serial.begin(9600);

  // Inicializa LCD
  lcd.begin(16, 2);
  lcd.clear();
}

float medirDistancia() {

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duracao = pulseIn(echoPin, HIGH);

  return duracao * 0.034 / 2;
}

void loop() {

  distancia = medirDistancia();

  Serial.print("Distancia medida: ");
  Serial.print(distancia);
  Serial.println(" cm");

  // Atualiza LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Dist:");
  lcd.print(distancia, 1);
  lcd.print(" cm");

  // Desliga tudo
  digitalWrite(ledVerde, LOW);
  digitalWrite(ledAmarelo, LOW);
  digitalWrite(ledVermelho1, LOW);
  digitalWrite(ledVermelho2, LOW);
  digitalWrite(buzzer, LOW);

  // ===============================
  // NIVEL NORMAL
  // ===============================
  if (distancia > nivelNormal) {

    digitalWrite(ledVerde, HIGH);

    Serial.println("Nivel: NORMAL");
    Serial.println("Situacao segura.");

    lcd.setCursor(0, 1);
    lcd.print("Nivel: NORMAL ");

    delay(1000);
  }

  // ===============================
  // NIVEL ATENCAO
  // ===============================
  else if (distancia > nivelAtencao) {

    digitalWrite(ledAmarelo, HIGH);

    Serial.println("Nivel: ATENCAO");
    Serial.println("O nivel do rio esta subindo.");

    lcd.setCursor(0, 1);
    lcd.print("Nivel: ATENCAO");

    delay(1000);
  }

  // ===============================
  // NIVEL PREOCUPANTE
  // ===============================
  else if (distancia > nivelPreocupante) {

    digitalWrite(ledVermelho1, HIGH);

    Serial.println("Nivel: PREOCUPANTE");
    Serial.println("Risco de enchente. Fique alerta!");

    lcd.setCursor(0, 1);
    lcd.print("PREOCUPANTE");

    delay(1000);
  }

  // ===============================
  // ALERTA MAXIMO
  // ===============================
  else {

    Serial.println("Nivel: ALERTA MAXIMO");
    Serial.println("RISCO DE ENCHENTE!");

    lcd.setCursor(0, 1);
    lcd.print("ALERTA MAXIMO");

    digitalWrite(buzzer, HIGH);

    // LEDs alternando
    digitalWrite(ledVermelho1, HIGH);
    digitalWrite(ledVermelho2, LOW);
    delay(250);

    digitalWrite(ledVermelho1, LOW);
    digitalWrite(ledVermelho2, HIGH);
    delay(250);
  }

  Serial.println("------------------------");
}