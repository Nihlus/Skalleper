//
//  Eye.h
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

#ifndef SKALLEPER_EYE_H
#define SKALLEPER_EYE_H

#include "StandardCplusplus.h"
#include <vector>

typedef void (*MotionCallback)(bool);

using namespace std;

class Eye
{
	uint8_t Pin;
	int State;
	vector<MotionCallback> Callbacks;

public:
	explicit Eye(uint8_t pin);
	bool CheckMotion();
	void AddCallback(MotionCallback callback);
	void RemoveCallback(MotionCallback callback);
};

#endif //SKALLEPER_EYE_H
