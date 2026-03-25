#pragma once
#pragma once
#include "Car.h"

class Volvo : public Car
{
public:
	Volvo();
	float get_speed() override;
	float get_weather_avg_speed(Weather w = Weather::Sunny) override;
};