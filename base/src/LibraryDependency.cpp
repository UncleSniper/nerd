#include <cstdio>

// This file semi-shamelessly semi-ripped-off from RedEngine RedStrain

#include "die.hpp"
#include "LibraryDependency.hpp"

namespace nerd {
namespace base {

	// ======== LibraryDependencyMismatchDieMessage ========

	class LibraryDependencyMismatchDieMessage : public DieMessage {

	  private:
		const LibraryDependency& dependency;

	  public:
		LibraryDependencyMismatchDieMessage(const LibraryDependency&);

		virtual void emitMessage(DieSink&);

	};

	LibraryDependencyMismatchDieMessage::LibraryDependencyMismatchDieMessage(const LibraryDependency& dependency)
			: dependency(dependency) {}

	void LibraryDependencyMismatchDieMessage::emitMessage(DieSink& sink) {
		sink.putMessage("Component '");
		sink.putMessage(dependency.getOuterComponentName());
		sink.putMessage("' expected version '");
		// If 'unsigned' is a 64 bit quantity, it yields at most 20 decimal digits.
		char buffer[42];
		sprintf(buffer, "%u.%u", dependency.getExpectedMajor(), dependency.getExpectedMinor());
		sink.putMessage(buffer);
		sink.putMessage("-cabi-");
		sink.putMessage(LibraryDependency::formatCompilerFlavor(dependency.getExpectedCompiler()));
		sink.putMessage("' of component '");
		sink.putMessage(dependency.getInnerComponentName());
		sprintf(buffer, "%u.%u", dependency.getActualMajor(), dependency.getActualMinor());
		sink.putMessage("', but found version '");
		sink.putMessage(buffer);
		sink.putMessage("-cabi-");
		sink.putMessage(LibraryDependency::formatCompilerFlavor(dependency.getActualCompiler()));
		sink.putMessage("'.");
	}

	// ======== LibraryDependency ========

	LibraryDependency::LibraryDependency(const char* outerComponent, const char* innerComponent,
			unsigned expectedMajor, unsigned expectedMinor, CompilerFlavor expectedCompiler,
			unsigned actualMajor, unsigned actualMinor, CompilerFlavor actualCompiler)
			: outerComponent(outerComponent), innerComponent(innerComponent),
			expectedMajor(expectedMajor), expectedMinor(expectedMinor),
			actualMajor(actualMajor), actualMinor(actualMinor),
			expectedCompiler(expectedCompiler), actualCompiler(actualCompiler) {
		checkVersion();
	}

	LibraryDependency::LibraryDependency(const LibraryDependency& dependency)
			: outerComponent(dependency.outerComponent), innerComponent(dependency.innerComponent),
			expectedMajor(dependency.expectedMajor), expectedMinor(dependency.expectedMinor),
			actualMajor(dependency.actualMajor), actualMinor(dependency.actualMinor),
			expectedCompiler(dependency.expectedCompiler), actualCompiler(dependency.actualCompiler) {}

	void LibraryDependency::checkVersion() const {
		if(
			expectedMajor == actualMajor
			&& expectedMinor == actualMinor
			&& expectedCompiler == actualCompiler
		)
			return;
		LibraryDependencyMismatchDieMessage dieMessage(*this);
		die(dieMessage);
	}

	const char* LibraryDependency::formatCompilerFlavor(CompilerFlavor flavor) {
		switch(flavor) {
			case COMP_GCC:
				return "gcc";
			case COMP_MSVC:
				return "msvc";
			case COMP_UNKNOWN:
			default:
				return "unknown";
		}
	}

}}
