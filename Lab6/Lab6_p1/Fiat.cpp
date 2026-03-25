#include "Fiat.h"


Fiat::Fiat() {
	this->fuel_capacity = 45;
	this->fuel_consumption = 5.5f;
	this->avg_s_sunny = this->get_weather_avg_speed(Weather::Sunny);
	this->avg_s_rain = this->get_weather_avg_speed(Weather::Rain);
	this->avg_s_snow = this->get_weather_avg_speed(Weather::Snow);
	this->name = "Fiat";
}

float Fiat::get_speed() {
	return 90.0f;
}

float Fiat::get_weather_avg_speed(Weather w) {
	if (w == Weather::Sunny)
		return get_speed();
	else if (w == Weather::Rain)
		return get_speed() * 0.8f;
	else
		return get_speed() * 0.6f;

}