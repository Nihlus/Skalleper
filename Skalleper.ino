//
//  Skalleper.ino
//
//  Author:
//       Jarl Gullberg <jarl.gullberg@gmail.com>
//
//  Copyright (c) 2017 Jarl Gullberg
//
//  This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program.  If not, see <http://www.gnu.org/licenses/>.
//

#include <Arduino.h>
#include "Skalleper.h"

#define LEFT_EYE_PIN 9
#define RIGHT_EYE_PIN 10
#define SERVO_PIN 11

Skalleper* skalleper;

void onLeftEyeMotionChange(bool isMotionStart)
{
	isMotionStart
		? Serial.println("Left eye motion start")
		: Serial.println("Left eye motion end");

	isMotionStart
		? digitalWrite(LED_BUILTIN, HIGH)
		: digitalWrite(LED_BUILTIN, LOW);
}

void onRightEyeMotionChange(bool isMotionStart)
{
	isMotionStart
	? Serial.println("Right eye motion start")
	: Serial.println("Right eye motion end");

	isMotionStart
	? digitalWrite(LED_BUILTIN, HIGH)
	: digitalWrite(LED_BUILTIN, LOW);
}

void setup()
{
	skalleper = new Skalleper(LEFT_EYE_PIN, RIGHT_EYE_PIN);
	skalleper->AttachMouth(SERVO_PIN);

	skalleper->AddMotionCallback(&onLeftEyeMotionChange, EyeSide::Left);
	skalleper->AddMotionCallback(&onRightEyeMotionChange, EyeSide::Right);

	pinMode(LED_BUILTIN, OUTPUT);

	Serial.begin(9600);
	skalleper->Reset();
}

void loop()
{
	skalleper->Tick();
}
