#pragma once

#include <utility>

struct PairHash {
	inline std::size_t operator()(const std::pair<int, int> &v) const {
		return v.first * 8000 + v.second;
	}
};