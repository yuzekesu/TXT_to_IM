#pragma once
#include "Coordinate.h"
#include <cstdint>
#include <fstream>
#include <string>
#include <tuple>
#include <vector>

class Loader {
public:
	Loader(std::wstring);
	std::tuple <std::vector<Coordinate>, std::vector<uint32_t>> Load();
private:
	std::wifstream _file;
};

