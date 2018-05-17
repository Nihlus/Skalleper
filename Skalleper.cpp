//
//  Skalleper.cpp
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

#include <Arduino.h>
#include "Skalleper.h"

Skalleper::Skalleper(uint8_t leftEyePIRPin, uint8_t rightEyePIRPin, uint8_t leftEyeLEDPin, uint8_t rightEyeLEDPin)
{
	this->LeftEye = new Eye(leftEyePIRPin, leftEyeLEDPin);
	this->RightEye = new Eye(rightEyePIRPin, rightEyeLEDPin);

	this->Stopwatch = new Chrono();
}

void Skalleper::CloseMouth()
{
	SetMouthAngle(90);
}

void Skalleper::OpenMouth()
{
	SetMouthAngle(40);
}

void Skalleper::AttachMouth(uint8_t mouthPin)
{
	this->Mouth.attach(mouthPin);
}

void Skalleper::AddMotionCallback(MotionCallback callback, EyeSide eyeSide)
{
	switch (eyeSide)
	{
		case EyeSide::Left:
		{
			LeftEye->AddCallback(callback);
			break;
		}
		case EyeSide::Right:
		{
			RightEye->AddCallback(callback);
			break;
		}
	}
}

void Skalleper::RemoveMotionCallback(MotionCallback callback, EyeSide eyeSide)
{
	switch (eyeSide)
	{
		case EyeSide::Left:
		{
			LeftEye->RemoveCallback(callback);
			break;
		}
		case EyeSide::Right:
		{
			RightEye->RemoveCallback(callback);
			break;
		}
	}
}

void Skalleper::Tick()
{
	this->Stopwatch->restart();

	this->LeftEye->CheckMotion();
	this->RightEye->CheckMotion();

	unsigned long millis = this->Stopwatch->elapsed();

	if (Serial.available())
	{
		long command = Serial.parseInt();
		switch (command)
		{
			case 1:
			{
				Cackle();
				break;
			}
			default:
			{
				break;
			}
		}
	}
}

void Skalleper::SetMouthAngle(int angle)
{
	if (angle <= 90)
	{
		angle = static_cast<int>(map(angle, 0, 90, 0, 180));
	}

	this->Mouth.write(angle);
}

void Skalleper::Cackle()
{
	for (int i = 0; i < 7; ++i)
	{
		OpenMouth();
		delay(125);
		CloseMouth();
		delay(150);
	}
}

void Skalleper::Reset()
{
	CloseMouth();
}

void Skalleper::Wink()
{
	this->RightEye->Blink();
}

void Skalleper::Blink()
{
	this->RightEye->Close();
	this->LeftEye->Close();
	delay(300);
	this->RightEye->Open();
	this->LeftEye->Close();
}

