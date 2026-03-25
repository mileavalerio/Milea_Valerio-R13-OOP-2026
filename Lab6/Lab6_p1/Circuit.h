#pragma once
#include "Car.h"

class Circuit {
private:
	unsigned int circuit_len, index;
	Weather w;
	Car* cars[100] = { nullptr };
	float time[100] = { 0.0f };
	bool finished[100] = { false };
public:
	Circuit();
	~Circuit();
	void SetLength(unsigned int len);
	void SetWeather(Weather conditions);
	void AddCar(Car *car);
	void Race();
	void ShowFinalRanks();
	void ShowWhoDidNotFinish();
};