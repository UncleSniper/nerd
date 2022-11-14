#include <new>

#include "die.hpp"
#include "blobs.hpp"
#include "StaticTrie.hpp"

using std::size_t;
using std::bad_alloc;

namespace nerd {
namespace base {

	// ======== BlobModuleRegistrar ========

	BlobModuleRegistrar::BlobModuleRegistrar(const char* name) : name(name) {
		registerBlobModule(name);
	}

	// ======== BlobRegistrationOutOfMemoryDieMessage ========

	class BlobRegistrationOutOfMemoryDieMessage : public DieMessage {

	  private:
		const char *const moduleName;

	  public:
		BlobRegistrationOutOfMemoryDieMessage(const char*);

		virtual void emitMessage(DieSink&);

	};

	BlobRegistrationOutOfMemoryDieMessage::BlobRegistrationOutOfMemoryDieMessage(const char* moduleName)
			: moduleName(moduleName) {}

	void BlobRegistrationOutOfMemoryDieMessage::emitMessage(DieSink& sink) {
		sink.putMessage("Failed to register blob module '");
		sink.putMessage(moduleName);
		sink.putMessage("': Out of memory");
	}

	// ======== BlobRegistrationDuplicateDieMessage ========

	class BlobRegistrationDuplicateDieMessage : public DieMessage {

	  private:
		const char *const moduleName;

	  public:
		BlobRegistrationDuplicateDieMessage(const char*);

		virtual void emitMessage(DieSink&);

	};

	BlobRegistrationDuplicateDieMessage::BlobRegistrationDuplicateDieMessage(const char* moduleName)
			: moduleName(moduleName) {}

	void BlobRegistrationDuplicateDieMessage::emitMessage(DieSink& sink) {
		sink.putMessage("Failed to register blob module '");
		sink.putMessage(moduleName);
		sink.putMessage("': Already registered");
	}

	// ======== functions ========

	typedef StaticTrie<const char*, bool, static_cast<size_t>(0u)> BlobModuleTrie;

	static BlobModuleTrie* blobModuleTrie = nullptr;

	NERD_BASE_API void registerBlobModule(const char* name) {
		try {
			if(!blobModuleTrie)
				blobModuleTrie = new BlobModuleTrie(*new StringStaticTrieKey);
			if(!blobModuleTrie->put(name, true)) {
				BlobRegistrationDuplicateDieMessage dieMessage(name);
				die(dieMessage);
			}
		}
		catch(const bad_alloc&) {
			BlobRegistrationOutOfMemoryDieMessage dieMessage(name);
			die(dieMessage);
		}
	}

	NERD_BASE_API bool hasBlobModule(const char* name) {
		if(!blobModuleTrie)
			return false;
		return !!blobModuleTrie->get(name);
	}

}}
