#include "ESP8266WiFi.h"

WiFiServer server(80);
const char* ssid = "SUPRA3";
const char* password = "anita123";

const char* host = "www.dweet.io";
const char* thing = "incubator001";
const char* data = "noise";

int led_vermelho = D0;
int led_amarelo = D2;
int led_verde = D4;


int entrada_analog_som = A0;

int valor_A0 = 0;

void setup() {
  Serial.begin(115200);

  pinMode(entrada_analog_som, INPUT);
  pinMode(led_vermelho, OUTPUT);
  pinMode(led_amarelo, OUTPUT);
  pinMode(led_verde, OUTPUT);

  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  
  WiFi.begin(ssid,password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("Tentando conectar...");
  }
  Serial.println("");
  Serial.println("Conectado a WiFi com sucesso");
 
}

void loop() {
  valor_A0 = analogRead(entrada_analog_som);

  if (valor_A0 < 45) { //Alterado de 35 para 45 para fins de apresentação
    digitalWrite(led_vermelho, LOW);
    digitalWrite(led_amarelo, LOW);
    digitalWrite(led_verde, HIGH);
  } else if (valor_A0 >= 45 && valor_A0 <= 55) { //Alterado de entre 35-45 para 45-55
    digitalWrite(led_vermelho, LOW);
    digitalWrite(led_amarelo, HIGH);
    digitalWrite(led_verde, HIGH);
  } else if (valor_A0 > 55) { //Alterado para >55
     digitalWrite(led_vermelho, HIGH);
    digitalWrite(led_amarelo, HIGH);
    digitalWrite(led_verde, HIGH);
  }

  Serial.print("Conectando-se ao host: ");
  Serial.println(host);
  
  // Abrindo conexão para enviar o Dweet
  WiFiClient client;
  const int httpPort = 80;
  if (!client.connect(host, httpPort)) {
    Serial.println("Falha ao conectar-se ao host");
    return;
  }
  
  // Construindo URL
  String url = "/dweet/for/";
  url += thing;
  url += "?";
  url += data;
  url += "=";
  url += valor_A0;
  
  Serial.print("URL: ");
  Serial.println(url);
  
  // Enviando requisição
  client.print(String("GET ") + url + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" + 
               "Connection: close\r\n\r\n");
  int timeout = millis() + 5000;
  while (client.available() == 0) {
    if (timeout - millis() < 0) {
      Serial.println("Falha: Timeout da requisiçao");
      client.stop();
      return;
    }
  }
  
  // Imprimindo a resposta do servidor
  while(client.available()){
    String line = client.readStringUntil('\r');
    Serial.print(line);
  }
  
  Serial.println();
  Serial.println("Fechando a conexao");
  delay(250);
  
 
}
