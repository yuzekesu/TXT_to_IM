#pragma once
#include <cstdint>
#include <span>
#include <string>

class Saver {
public:
	Saver() = delete;
	Saver(const std::wstring& path, const std::wstring& extention);
	void Save(std::span<uint8_t>);
private:
	std::wstring _path;
};

