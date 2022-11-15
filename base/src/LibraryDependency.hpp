#ifndef NERD_BASE_LIBRARYDEPENDENCY_HPP
#define NERD_BASE_LIBRARYDEPENDENCY_HPP

// This file semi-shamelessly semi-ripped-off from RedEngine RedStrain

#include "constants.hpp"

namespace nerd {
namespace base {

	class NERD_BASE_API LibraryDependency {

	  private:
		const char *const outerComponent, *const innerComponent;
		const unsigned expectedMajor, expectedMinor, actualMajor, actualMinor;
		const CompilerFlavor expectedCompiler, actualCompiler;

	  public:
		LibraryDependency(const char*, const char*,
				unsigned, unsigned, CompilerFlavor, unsigned, unsigned, CompilerFlavor);
		LibraryDependency(const LibraryDependency&);

		inline const char* getOuterComponentName() const {
			return outerComponent;
		}

		inline const char* getInnerComponentName() const {
			return innerComponent;
		}

		inline unsigned getExpectedMajor() const {
			return expectedMajor;
		}

		inline unsigned getExpectedMinor() const {
			return expectedMinor;
		}

		inline CompilerFlavor getExpectedCompiler() const {
			return expectedCompiler;
		}

		inline unsigned getActualMajor() const {
			return actualMajor;
		}

		inline unsigned getActualMinor() const {
			return actualMinor;
		}

		inline CompilerFlavor getActualCompiler() const {
			return actualCompiler;
		}

		void checkVersion() const;

		static const char* formatCompilerFlavor(CompilerFlavor);

	};

}}

#if defined(NERD_ENV_COMPILER_GNU)
#define NERD_BASE_BUILD_COMPILER ::nerd::base::COMP_GCC
#elif defined(NERD_ENV_COMPILER_MSVC)
#define NERD_BASE_BUILD_COMPILER ::nerd::base::COMP_MSVC
#else /* unknown compiler */
#define NERD_BASE_BUILD_COMPILER ::nerd::base::COMP_UNKNOWN
#endif /* build compiler switch */

#define NERD_DECLARE_MODULE_VERSION(exportMacro) \
	exportMacro extern const unsigned dynamicVersionMajor; \
	exportMacro extern const unsigned dynamicVersionMinor; \
	exportMacro extern const ::nerd::base::CompilerFlavor dynamicVersionCompiler;

#define NERD_DEFINE_MODULE_VERSION(versionMacroPrefix) \
	extern const unsigned dynamicVersionMajor = versionMacroPrefix ## _STATIC_VERSION_MAJOR; \
	extern const unsigned dynamicVersionMinor = versionMacroPrefix ## _STATIC_VERSION_MINOR; \
	extern const ::nerd::base::CompilerFlavor dynamicVersionCompiler = NERD_BASE_BUILD_COMPILER;

#define NERD_DEPEND_MODULE(varName, outerName, innerName, versionMacroPrefix, innerNamespace) \
	static ::nerd::base::LibraryDependency dependOn ## varName( \
		#outerName, #innerName, \
		versionMacroPrefix ## _STATIC_VERSION_MAJOR, \
		versionMacroPrefix ## _STATIC_VERSION_MINOR, \
		NERD_BASE_BUILD_COMPILER, \
		innerNamespace::dynamicVersionMajor, \
		innerNamespace::dynamicVersionMinor, \
		innerNamespace::dynamicVersionCompiler \
	);

#endif /* NERD_BASE_LIBRARYDEPENDENCY_HPP */
