//
//  Eye.cpp
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
#include "Eye.h"

Eye::Eye(uint8_t pirPin, uint8_t ledPin)
{
	this->PIRPin = pirPin;
	this->PIRState = LOW;

	pinMode(this->PIRPin, INPUT);

	this->LEDPin = ledPin;
	pinMode(this->LEDPin, OUTPUT);

	digitalWrite(this->LEDPin, HIGH);
}

bool Eye::CheckMotion()
{
	int val = digitalRead(this->PIRPin);  // read input value
	if (val == HIGH)
	{
		if (this->PIRState == LOW)
		{
			if (!this->Callbacks.empty())
			{
				for (MotionCallback callback : this->Callbacks)
				{
					callback(true);
				}
			}

			this->PIRState = HIGH;
		}
		return true;
	}
	else
	{
		if (this->PIRState == HIGH)
		{
			if (!this->Callbacks.empty())
			{
				for (MotionCallback callback : this->Callbacks)
				{
					callback(false);
				}
			}

			this->PIRState = LOW;
		}
		return false;
	}
}

void Eye::AddCallback(MotionCallback callback)
{
	this->Callbacks.push_back(callback);
}

void Eye::RemoveCallback(MotionCallback callback)
{
	this->Callbacks.erase(remove(this->Callbacks.begin(), this->Callbacks.end(), callback), this->Callbacks.end());
}

void Eye::Blink()
{
	Close();
	delay(300);
	Open();
}

void Eye::Open()
{
	digitalWrite(this->LEDPin, HIGH);
}

void Eye::Close()
{
	digitalWrite(this->LEDPin, LOW);
}
