#include "Volvo.h"


Volvo::Volvo() {
	this->fuel_capacity = 60;
	this->fuel_consumption = 7.2f;
	this->avg_s_sunny = this->get_weather_avg_speed(Weather::Sunny);
	this->avg_s_rain = this->get_weather_avg_speed(Weather::Rain);
	this->avg_s_snow = this->get_weather_avg_speed(Weather::Snow);
	this->name = "Volvo";
}

float Volvo::get_speed() {
	return 110.0f;
}

float Volvo::get_weather_avg_speed(Weather w) {
	if (w == Weather::Sunny)
		return get_speed();
	else if (w == Weather::Rain)
		return get_speed() * 0.9f;
	else
		return get_speed() * 0.75f;
}