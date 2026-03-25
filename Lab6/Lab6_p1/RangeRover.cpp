#include "RangeRover.h"


RangeRover::RangeRover() {
	this->fuel_capacity = 80;
	this->fuel_consumption = 9.5f;
	this->avg_s_sunny = this->get_weather_avg_speed(Weather::Sunny);
	this->avg_s_rain = this->get_weather_avg_speed(Weather::Rain);
	this->avg_s_snow = this->get_weather_avg_speed(Weather::Snow);
	this->name = "RangeRover";
}

float RangeRover::get_speed() {
	return 115.0f;
}

float RangeRover::get_weather_avg_speed(Weather w) {
	if (w == Weather::Sunny)
		return get_speed();
	else if (w == Weather::Rain)
		return get_speed() * 0.95f;
	else
		return get_speed() * 0.8f;

}