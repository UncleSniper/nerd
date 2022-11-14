#include <cstring>
#include <cstdlib>

#include "environment.hpp"
#ifdef NERD_ENV_OS_LINUX
#include <unistd.h>
#else /* unknown OS */
#error unknown OS
#endif

#include "die.hpp"

using std::size_t;

namespace nerd {
namespace base {

	// ======== DieSink ========

	DieSink::DieSink() {}

	DieSink::~DieSink() {}

	void DieSink::putMessage(const char* message) {
		putMessage(message, strlen(message));
	}

	// ======== StderrDieSink ========

	StderrDieSink::StderrDieSink() {}

#ifdef NERD_ENV_OS_LINUX

	void StderrDieSink::beginMessage() {
		write(2, "*** Nerd PANIC: ", 16);
	}

	void StderrDieSink::putMessage(const char* message, size_t size) {
		write(2, message, size);
	}

	void StderrDieSink::nextMessage() {
		write(2, "\n                ", 17);
	}

	void StderrDieSink::endMessage() {
		write(2, "\n", 1);
	}

#else /* unknown OS */
#error unknown OS
#endif

	// ======== DieMessage ========

	DieMessage::DieMessage() {}

	DieMessage::~DieMessage() {}

	// ======== StringDieMessage ========

	StringDieMessage::StringDieMessage(const char* message) : message(message) {}

	void StringDieMessage::emitMessage(DieSink& sink) {
		sink.putMessage(message, strlen(message));
	}

	// ======== variables ========

	NERD_BASE_API DieSink* dieSink = nullptr;

	// ======== functions ========

	NERD_BASE_API [[noreturn]] void die(DieMessage& message) {
		StderrDieSink sink;
		DieSink& targetSink = dieSink ? *dieSink : sink;
		targetSink.beginMessage();
		message.emitMessage(sink);
		targetSink.endMessage();
		abort();
	}

	NERD_BASE_API [[noreturn]] void die(const char* message) {
		StringDieMessage holder(message);
		die(holder);
	}

}}
