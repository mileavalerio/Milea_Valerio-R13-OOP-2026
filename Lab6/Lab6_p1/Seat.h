#pragma once
#include "Car.h"

class Seat : public Car
{
public:
	Seat();
	float get_speed() override;
	float get_weather_avg_speed(Weather w = Weather::Sunny) override;
};