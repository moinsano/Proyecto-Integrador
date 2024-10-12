#include <Servo.h>
Servo tapa;
Servo org;

//se declara las variables del sensor
const int s0 = 4;
const int s1 = 5;
const int s2 = 6;
const int s3 = 7;
const int out = 8;

void setup() {
  
//pines de los servomotores tapa = servo que empuja las tapas, org = servo que organiza los canales.
  tapa.attach(2);
  org.attach(3);
  
//salidas del sensor (fotodiodos)
  pinMode(s0, OUTPUT);
  pinMode(s1, OUTPUT);
  pinMode(s2, OUTPUT);
  pinMode(s3, OUTPUT);
  pinMode(out, INPUT);

  //funcionammiento al 100% s0 y s1 h, so L y s1 H 2%, s0 H y s1 L 20%

  digitalWrite(s0, HIGH);
  digitalWrite(s1, HIGH);
}

void loop() {

  // llamar a las variables de cada parte de codigo.
  int R = getRojo();
  delay(200);
  int V = getVerde();
  delay(200);
  int A = getAzul();
  delay(200);

  //ponemos los parametros para detectar cada color, en este caso el azul claro es R = 12, V = 9, A = 6
  if ( R > V && V > A && R < 14 && R > 10) {

    // org es el servo que organiza el canal y tapa es el que enpuja la tapa
    
    //angulo del medio es 90, izquierda es 40, y derecha 150
    org.write(40);
    delay (5000);

    tapa.write(10);
    delay (1000);

    org.write (90);
    delay (2000);
    tapa.write (100);
    delay (2000);
  }

  //ponemos los parametros para detectar cada color, en este caso el rojo es R = 9, V = 17, A = 11
  else if ( R < V && V > A && R < 11 && R >= 8 && V >= 16 ) {

    // org es el servo que organiza el canal y tapa es el que enpuja la tapa
    //angulo del medio es 90, izquierda es 40, y derecha 150
    org.write(90);
    delay (5000);

    tapa.write(10);
    delay (1000);

    tapa.write (100);
    delay (2000);
  }

  //ponemos los parametros para detectar cada color, en este caso el verde es R = 12, V = 10, A = 10
  else if ( R > V && R > A && R > 11 && R < 14 ) {

    // org es el servo que organiza el canal y tapa es el que enpuja la tapa
    //angulo del medio es 90, izquierda es 40, y derecha 150
    org.write(150);
    delay (5000);

    // 100 = 90 grados
    tapa.write(100);
    delay (1000);

    org.write (90);
    delay (2000);
    tapa.write (10);
    delay (2000);
  }




}

int getRojo() {

  //leer color rojo

  digitalWrite(s2, LOW);
  digitalWrite(s3, LOW);
  int Rojo = pulseIn(out, LOW);

  return Rojo;

}
int getAzul() {

  //leer color azul

  digitalWrite(s2, LOW);
  digitalWrite(s3, HIGH);
  int Azul = pulseIn(out, LOW);

  return Azul;
}

int getVerde() {

  //leer color verde

  digitalWrite(s2, HIGH);
  digitalWrite(s3, HIGH);
  int Verde = pulseIn(out, LOW);

  return Verde;

}
