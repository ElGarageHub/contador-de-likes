/*
   This file is part of contador-de-likes.

   contador-de-likes is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   contador-de-likes is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with contador-de-likes.  If not, see <http://www.gnu.org/licenses/>.
*/

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
