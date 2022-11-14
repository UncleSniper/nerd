#include "StaticTrie.hpp"

using std::size_t;

namespace nerd {
namespace base {

	// ======== StringStaticTrieKey ========

	StringStaticTrieKey::StringStaticTrieKey() {}

	size_t StringStaticTrieKey::getBufferSize(const char *const& key) {
		return strlen(key);
	}

	void StringStaticTrieKey::serializeKey(const char *const& key, unsigned char* buffer) {
		strcpy(reinterpret_cast<char*>(buffer), key);
	}

}}
