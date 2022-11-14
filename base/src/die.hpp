#ifndef NERD_BASE_DIE_HPP
#define NERD_BASE_DIE_HPP

#include <cstddef>

#include "api.hpp"

namespace nerd {
namespace base {

	class NERD_BASE_API DieSink {

	  public:
		DieSink();
		virtual ~DieSink();

		void putMessage(const char*);

		virtual void beginMessage() = 0;
		virtual void putMessage(const char*, std::size_t) = 0;
		virtual void nextMessage() = 0;
		virtual void endMessage() = 0;

	};

	class NERD_BASE_API StderrDieSink : public DieSink {

	  public:
		StderrDieSink();

		virtual void beginMessage();
		virtual void putMessage(const char*, std::size_t);
		virtual void nextMessage();
		virtual void endMessage();

	};

	class NERD_BASE_API DieMessage {

	  public:
		DieMessage();
		virtual ~DieMessage();

		virtual void emitMessage(DieSink&) = 0;

	};

	class NERD_BASE_API StringDieMessage : public DieMessage {

	  private:
		const char *const message;

	  public:
		StringDieMessage(const char*);

		inline const char* getMessage() {
			return message;
		}

		virtual void emitMessage(DieSink&);

	};

	NERD_BASE_API extern DieSink* dieSink;

	NERD_BASE_API [[noreturn]] void die(DieMessage&);
	NERD_BASE_API [[noreturn]] void die(const char*);

}}

#endif /* NERD_BASE_DIE_HPP */
