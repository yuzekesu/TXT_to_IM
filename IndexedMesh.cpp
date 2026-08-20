#include "IndexedMesh.h"

IndexedMesh::IndexedMesh(Loader& p) {
	auto [v, i] = p.Load();
	this->_vertices = std::move(v);
	this->_indices = std::move(i);
}

std::vector<uint8_t> IndexedMesh::Binary() {
	std::vector<uint8_t> binary;
	struct Header { uint64_t sizeOfVertices, sizeOfIndices; };
	Header h{
		.sizeOfVertices = this->_vertices.size(),
		.sizeOfIndices = this->_indices.size()
	};
	size_t byteSizeVertices = this->_vertices.size() * sizeof(decltype(this->_vertices)::value_type);
	size_t byteSizeIndices = this->_indices.size() * sizeof(decltype(this->_indices)::value_type);
	binary.resize(sizeof(h) + byteSizeVertices + byteSizeIndices);

	// header part.
	memcpy(binary.data(), &h, sizeof(h));
	// _vertices part.
	memcpy(binary.data() + sizeof(h), this->_vertices.data(), byteSizeVertices);
	// _indices part.
	memcpy(binary.data() + sizeof(h) + byteSizeVertices, this->_indices.data(), byteSizeIndices);
	return binary;
}
