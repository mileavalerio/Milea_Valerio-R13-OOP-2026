#include "Circuit.h"
#include <iostream>
#include <iomanip>

Circuit::Circuit() {
	circuit_len = 200;
	index = 0;
	w = Weather::Sunny;
}

Circuit::~Circuit() {
	for (unsigned int i = 0; i < index; i++) {
		delete cars[i];
	}
}

void Circuit::SetLength(unsigned int len) {

	this->circuit_len = len;
}

void Circuit::SetWeather(Weather conditions) {

	this->w = conditions;
}

void Circuit::AddCar(Car* car) {
	if (index > 99)
		return;
	cars[index++] = car;
}

void Circuit::Race() {
	for (unsigned int i = 0; i < index; i++) {
		float autonomy = (float)((float)cars[i]->get_fuel_capacity() / cars[i]->get_fuel_consumption()) * 100;
		if (autonomy >= this->circuit_len) {
			finished[i] = true;
		}
		else finished[i] = false;
		time[i] = (float) this->circuit_len / cars[i]->get_weather_avg_speed(this->w);
	}

	bool swapped;
	unsigned int n = index;
	do {
		swapped = false;
		for (int i = 0; i < n - 1; i++) {
			if (time[i] > time[i + 1]) {
				float temp = time[i];
				time[i] = time[i + 1];
				time[i + 1] = temp;

				Car* tmp = cars[i];
				cars[i] = cars[i + 1];
				cars[i + 1] = tmp;

				bool tempFin = finished[i];
				finished[i] = finished[i + 1];
				finished[i + 1] = tempFin;

				swapped = true;
			}
		}
		n--;
	} while (swapped);
}

void Circuit::ShowFinalRanks() {
	for (unsigned int i = 0; i < index; i++) {
		if(finished[i])
			std::cout << cars[i]->get_name() << " has finished in the race in " << std::fixed << std::setprecision(2) << time[i]<<" hours."<<std::endl;
	}
}

void Circuit::ShowWhoDidNotFinish() {
	for (unsigned int i = 0; i < index; i++) {
		if (!finished[i])
			std::cout << cars[i]->get_name() << " has't finished the race."<<std::endl;
	}
}