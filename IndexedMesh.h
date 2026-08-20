#pragma once
#include "Coordinate.h"
#include "Loader.h"
#include <cstdint>
#include <vector>

class IndexedMesh {
public:
	IndexedMesh(Loader&);
	std::vector<uint8_t> Binary();
private:
	std::vector<Coordinate> _vertices;
	std::vector<unsigned> _indices;
};

