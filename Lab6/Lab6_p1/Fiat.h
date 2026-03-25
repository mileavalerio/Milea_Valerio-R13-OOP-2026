#pragma once
#include "Car.h"

class Fiat : public Car
{
public:
	Fiat();
	float get_speed() override;
	float get_weather_avg_speed(Weather w = Weather::Sunny) override;
};