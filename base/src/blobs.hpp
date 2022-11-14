#ifndef NERD_BASE_BLOBS_HPP
#define NERD_BASE_BLOBS_HPP

// This file semi-shamelessly semi-ripped-off from RedEngine RedStrain

#include "api.hpp"

namespace nerd {
namespace base {

	NERD_BASE_API void registerBlobModule(const char*);
	NERD_BASE_API bool hasBlobModule(const char*);

	class NERD_BASE_API BlobModuleRegistrar {

	  private:
		const char *const name;

	  public:
		BlobModuleRegistrar(const char*);

		inline const char* getName() const {
			return name;
		}

	};

}}

#endif /* NERD_BASE_BLOBS_HPP */
