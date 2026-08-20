#include "Loader.h"
#include <format>
#include <limits>
#include <sstream>
#include <stdexcept>

Loader::Loader(std::wstring path) : _file{ path } {
	if (_file.is_open() == false) throw std::runtime_error("Unable to open the .txt");
}

std::tuple <std::vector<Coordinate>, std::vector<uint32_t>> Loader::Load() {
	std::vector<Coordinate> vertices;
	unsigned lineCounter = 0;
	wchar_t buffer[500];
	auto& f = this->_file;

	// parse the vertices.
	// 1. get the line.
	// 2. split to words.
	// 3. take the first three words and convert them to float.
	for (unsigned long long i = 0; i < std::numeric_limits<unsigned long long>::max(); ++i) {
		// 1
		f.getline(buffer, sizeof(buffer) / sizeof(buffer[0]));
		++lineCounter;
		if (f.eof()) throw std::runtime_error(std::format("No indices detected at the line {} in the .txt", lineCounter));
		if (f.fail()) throw std::runtime_error(std::format("Containing to many characters at the line {}. Maximum characters allowed is {}.", lineCounter, sizeof(buffer) / sizeof(buffer[0])));
		// 2 & 3
		std::wistringstream stream{ buffer };
		std::wstring word;
		unsigned loopCounter = 0;
		unsigned floatCounter = 0;
		std::vector<float> tempFloatVector;
		while (stream >> word) {
			tempFloatVector.push_back(std::stof(word));
			++floatCounter;
			++loopCounter;
			if (floatCounter == 3) break;
		}
		if (loopCounter == 0) break;
		if (tempFloatVector.size() != 3) throw std::runtime_error(std::format("Wrong format for the float numbers at the line {} in the .txt", lineCounter));
		// the size of the vector here is exactly three.
		vertices.push_back({ .x = tempFloatVector[0], .y = tempFloatVector[1], .z = tempFloatVector[2] });
	}

	// parse the indices.
	// 1. get the line.
	// 2. split to words.
	// 3. convert them to uint32_t.
	std::vector<uint32_t> indices;
	for (unsigned long long i = 0; i < std::numeric_limits<unsigned long long>::max(); ++i) {
		// 1
		f.getline(buffer, sizeof(buffer) / sizeof(buffer[0]));
		++lineCounter;
		if (f.eof()) break;
		if (f.fail()) throw std::runtime_error(std::format("Containing to many characters at the line {}. Maximum characters allowed is {}.", lineCounter, sizeof(buffer) / sizeof(buffer[0])));
		// 2 & 3
		std::wistringstream stream{ buffer };
		std::wstring word;
		while (stream >> word) {
			try {
				indices.push_back(static_cast<uint32_t>(std::stol(word)));
			}
			catch (...) {
				// let it be ;)
			}
		}
	}
	return { std::move(vertices), std::move(indices) };
}
