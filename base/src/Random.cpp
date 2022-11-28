// This file shamelessly ripped off from RedEngine RedStrain

#include "Random.hpp"
#include "DeleteArray.hpp"

namespace nerd {
namespace base {

	Random::Random() {}

	Random::Random(const Random&) {}

	Random::~Random() {}

	void Random::seedFrom(Random& entropy) {
		MemorySize size = getSeedSize();
		if(!size) {
			seed(nullptr);
			return;
		}
		DeleteArray<char> buffer(new char[size]);
		entropy.randomBytes(*buffer, size);
		seed(*buffer);
	}

}}
