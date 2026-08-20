#include "Saver.h"
#include <format>
#include <fstream>
#include <stdexcept>

Saver::Saver(const std::wstring& p, const std::wstring& e) : _path(p) {
	auto extentionName = e;
	if (e[0] == L'.') extentionName = e.substr(1, e.size() - 1);
	size_t offset = this->_path.find_last_of(L".");
	this->_path.resize(offset + 1);
	this->_path += extentionName;
}

void Saver::Save(std::span<uint8_t> b) {
	std::ofstream f(this->_path, std::ofstream::binary);
	if (f.is_open() == false) throw std::runtime_error(std::format("Unable to open/create the save file."));
	f.write(reinterpret_cast<char*>(b.data()), b.size());
	if (f.fail()) throw std::runtime_error("Unable to write the save file.");
}
