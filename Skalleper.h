//
//  Skalleper.h
//
//  Author:
//       Jarl Gullberg <jarl.gullberg@gmail.com>
//
//  Copyright (c) 2017 Jarl Gullberg
//
//  This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU Lesser General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU Lesser General Public License for more details.
//
//  You should have received a copy of the GNU Lesser General Public License
//  along with this program.  If not, see <http://www.gnu.org/licenses/>.
//

#ifndef SKALLEPER_SKALLEPER_H
#define SKALLEPER_SKALLEPER_H

#include <Servo.h>
#include <Chrono.h>
#include "Eye.h"

enum class EyeSide
{
	Left,
	Right
};

class Skalleper
{
	struct Eye* LeftEye;
	struct Eye* RightEye;

	Servo Mouth;
	int MouthPosition = 0;


public:
	Skalleper(uint8_t leftEyePIRPin, uint8_t rightEyePIRPin, uint8_t leftEyeLEDPin, uint8_t rightEyeLEDPin);

	unsigned long MotionDelay = 2;

	void AttachMouth(uint8_t mouthPin);
	void CloseMouth();
	void OpenMouth();

	void Cackle();

	void Wink();
	void Blink();

	void AddMotionCallback(MotionCallback callback, EyeSide eyeSide);
	void RemoveMotionCallback(MotionCallback callback, EyeSide eyeSide);

	void Tick();
	void Reset();

private:
	Chrono* Stopwatch;

	void SetMouthAngle(int angle);
};

#endif //SKALLEPER_SKALLEPER_H
