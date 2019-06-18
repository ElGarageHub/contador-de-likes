#include <Adafruit_LEDBackpack_RK.h>
#include "Particle.h"
#include "Adafruit_GFX_RK.h"

Adafruit_7segment matrix = Adafruit_7segment();
Adafruit_7segment matrix2 = Adafruit_7segment();

void setup() {
	matrix.begin(0x73);
	matrix2.begin(0x71);
	Particle.subscribe("hook-response/fbLikesEvent", myHandler, MY_DEVICES);
}

void loop() {
	Particle.publish("fbLikesEvent", "", PRIVATE);
	delay(10000);
}

void myHandler(const char *event, const char *data) {
    int n = atoi(data);
    matrix2.print(n / 10000);
    matrix.print(n % 10000);
    matrix.writeDisplay();
    matrix2.writeDisplay();
}
