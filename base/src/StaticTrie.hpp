#ifndef NERD_BASE_STATICTRIE_HPP
#define NERD_BASE_STATICTRIE_HPP

#include <cstddef>
#include <cstring>

#include "api.hpp"
#include "DeleteArray.hpp"

namespace nerd {
namespace base {

	template<typename KeyT>
	class StaticTrieKey {

	  public:
		StaticTrieKey() {}

		virtual std::size_t getBufferSize(const KeyT&) = 0;
		virtual void serializeKey(const KeyT&, unsigned char*) = 0;

	};

	template<typename KeyT, typename ValueT>
	class StaticTrieBase {

	  public:
		typedef KeyT Key;
		typedef ValueT Value;
		typedef StaticTrieKey<KeyT> KeyTraits;

	  protected:
		struct Node {

			bool hasValue;
			Value value;
			Node* children[16];

			Node() : hasValue(false) {
				memset(children, 0, sizeof(children));
			}

		};

	  protected:
		KeyTraits* keyTraits;
		Node* root;

	  protected:
		bool putBuffer(const Key& key, unsigned char* buffer, std::size_t byteCount, const Value& value) {
			if(!root)
				root = new Node;
			keyTraits->serializeKey(key, buffer);
			Node *currentNode = root, *newNode;
			for(std::size_t byteIndex = static_cast<std::size_t>(0u); byteIndex < byteCount; ++byteIndex) {
				for(int low = 0; low < 2; ++low) {
					unsigned byte = static_cast<unsigned>(buffer[byteIndex]);
					unsigned nibble = low ? byte & 0xFu : byte >> 4;
					newNode = currentNode->children[nibble];
					if(!newNode) {
						newNode = new Node;
						currentNode->children[nibble] = newNode;
					}
					currentNode = newNode;
				}
			}
			if(currentNode->hasValue)
				return false;
			currentNode->value = value;
			currentNode->hasValue = true;
			return true;
		}

		Node* getNodeBuffer(const Key& key, unsigned char* buffer, std::size_t byteCount) const {
			if(!root)
				return nullptr;
			keyTraits->serializeKey(key, buffer);
			Node* currentNode = root;
			for(std::size_t byteIndex = static_cast<std::size_t>(0u); byteIndex < byteCount; ++byteIndex) {
				for(int low = 0; low < 2; ++low) {
					unsigned byte = static_cast<unsigned>(buffer[byteIndex]);
					unsigned nibble = low ? byte & 0xFu : byte >> 4;
					currentNode = currentNode->children[nibble];
					if(!currentNode)
						return nullptr;
				}
			}
			return currentNode->hasValue ? currentNode : nullptr;
		}

		virtual Node* getNode(const Key&) const = 0;

	  public:
		StaticTrieBase(KeyTraits& keyTraits) : keyTraits(&keyTraits), root(nullptr) {}

		Value* get(const Key& key) {
			Node* node = getNode(key);
			return node ? &node->value : nullptr;
		}

		const Value* get(const Key& key) const {
			Node* node = getNode(key);
			return node ? &node->value : nullptr;
		}

	};

	template<typename KeyT, typename ValueT, std::size_t StaticBufferSize>
	class StaticTrie : public StaticTrieBase<KeyT, ValueT> {

	  private:
		typedef typename StaticTrieBase<KeyT, ValueT>::Node Node;
		typedef typename StaticTrieBase<KeyT, ValueT>::KeyTraits KeyTraits;

	  protected:
		virtual Node* getNode(const KeyT& key) const {
			unsigned char buffer[StaticBufferSize];
			return this->getNodeBuffer(key, buffer, StaticBufferSize);
		}

	  public:
		StaticTrie(KeyTraits& keyTraits) : StaticTrieBase<KeyT, ValueT>(keyTraits) {}

		bool put(const KeyT& key, const ValueT& value) {
			unsigned char buffer[StaticBufferSize];
			return this->putBuffer(key, buffer, StaticBufferSize, value);
		}

	};

	template<typename KeyT, typename ValueT>
	class StaticTrie<KeyT, ValueT, static_cast<std::size_t>(0u)> : public StaticTrieBase<KeyT, ValueT> {

	  private:
		typedef typename StaticTrieBase<KeyT, ValueT>::Node Node;
		typedef typename StaticTrieBase<KeyT, ValueT>::KeyTraits KeyTraits;

	  protected:
		virtual Node* getNode(const KeyT& key) const {
			std::size_t byteCount = this->keyTraits->getBufferSize(key);
			DeleteArray<unsigned char> buffer = byteCount ? new unsigned char[byteCount] : nullptr;
			return this->getNodeBuffer(key, *buffer, byteCount);
		}

	  public:
		StaticTrie(KeyTraits& keyTraits) : StaticTrieBase<KeyT, ValueT>(keyTraits) {}

		bool put(const KeyT& key, const ValueT& value) {
			std::size_t byteCount = this->keyTraits->getBufferSize(key);
			DeleteArray<unsigned char> buffer = byteCount ? new unsigned char[byteCount] : nullptr;
			return this->putBuffer(key, *buffer, byteCount, value);
		}

	};

	class NERD_BASE_API StringStaticTrieKey : public StaticTrieKey<const char*> {

	  public:
		StringStaticTrieKey();

		virtual std::size_t getBufferSize(const char *const&);
		virtual void serializeKey(const char *const&, unsigned char*);

	};

}}

#endif /* NERD_BASE_STATICTRIE_HPP */
