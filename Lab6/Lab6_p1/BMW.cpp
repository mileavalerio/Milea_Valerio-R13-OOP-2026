#include "BMW.h"


BMW::BMW() {
	this->fuel_capacity = 59;
	this->fuel_consumption = 6.5f;
	this->avg_s_sunny = this->get_weather_avg_speed(Weather::Sunny);
	this->avg_s_rain = this->get_weather_avg_speed(Weather::Rain);
	this->avg_s_snow = this->get_weather_avg_speed(Weather::Snow);
	this->name = "BMW";
}

float BMW::get_speed() {
	return 120.0f;
}

float BMW::get_weather_avg_speed(Weather w) {
	if (w == Weather::Sunny)
		return get_speed();
	else if (w == Weather::Rain)
		return get_speed() * 0.85f;
	else
		return get_speed() * 0.65f;
}