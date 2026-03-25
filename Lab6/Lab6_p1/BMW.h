#pragma once
#include "Car.h"

class BMW : public Car
{
public:
	BMW();
	float get_speed() override;
	float get_weather_avg_speed(Weather w = Weather::Sunny) override;
};