#pragma once
#include "Car.h"

class RangeRover : public Car
{
public:
	RangeRover();
	float get_speed() override;
	float get_weather_avg_speed(Weather w = Weather::Sunny) override;
};
