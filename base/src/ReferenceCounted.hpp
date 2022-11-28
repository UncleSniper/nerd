#ifndef NERD_BASE_REFERENCECOUNTED_HPP
#define NERD_BASE_REFERENCECOUNTED_HPP

// This file semi-shamelessly semi-ripped-off from RedEngine RedStrain

#include "api.hpp"
#include "types.hpp"

namespace nerd {
namespace base {

	class NERD_BASE_API ReferenceCounted {

	  private:
		MemorySize refcount;

	  protected:
		ReferenceCounted(const ReferenceCounted&);

	  public:
		ReferenceCounted();
		virtual ~ReferenceCounted();

		inline void ref() {
			++refcount;
		}

		inline void unref() {
			if(!--refcount)
				delete this;
		}

		inline MemorySize getReferenceCount() const {
			return refcount;
		}

	};

}}

#endif /* NERD_BASE_REFERENCECOUNTED_HPP */
