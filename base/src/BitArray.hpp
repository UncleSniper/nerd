#ifndef NERD_BASE_BITARRAY_HPP
#define NERD_BASE_BITARRAY_HPP

// This file shamelessly ripped off from RedEngine RedStrain

#include <cstring>

#include "api.hpp"
#include "types.hpp"

namespace nerd {
namespace base {

	class NERD_BASE_API BitArray {

	  private:
		MemorySize size, tainted;
		unsigned* bits;

		static const MemorySize ELEMENT_BITS
				= static_cast<MemorySize>(sizeof(unsigned)) * static_cast<MemorySize>(8u);

		inline void taint(MemorySize threshold) {
			if(threshold > tainted) {
				memset(bits + tainted, 0, (threshold - tainted) * sizeof(unsigned));
				tainted = threshold;
			}
		}

	  public:
		BitArray(MemorySize);
		BitArray(const BitArray&);
		~BitArray();

		inline MemorySize getSize() const {
			return size * ELEMENT_BITS;
		}

		inline void clear() {
			tainted = static_cast<MemorySize>(0u);
		}

		bool isSet(MemorySize) const;
		void set(MemorySize);
		void unset(MemorySize);
		void set(MemorySize, bool);
		void toggle(MemorySize);
		int compare(const BitArray&) const;
		bool isClear() const;

		BitArray& operator=(const BitArray&);
		bool operator==(const BitArray&) const;
		bool operator<(const BitArray&) const;

	};

}}

#endif /* NERD_BASE_BITARRAY_HPP */
