#pragma once
#include "Weather.h"

class Car {
protected:
	unsigned int fuel_capacity = 0;
	float fuel_consumption = 0.0f, avg_s_rain = 0.0f, avg_s_snow = 0.0f, avg_s_sunny = 0.0f;
	const char* name = nullptr;
public:
	virtual ~Car() = default;
	virtual float get_speed() = 0;
	virtual const char* get_name() {
		return name;
	}
	virtual float get_fuel_consumption() {
		return fuel_consumption;
	};
	virtual unsigned int get_fuel_capacity() {
		return fuel_capacity;
	};
	virtual float get_weather_avg_speed(Weather w = Weather::Sunny) = 0;
};
