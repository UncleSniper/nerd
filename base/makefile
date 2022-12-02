CXX=g++
LD=$(CXX)
RM=rm -rf
MKDIR=mkdir -p

NS=base
MACRO_NS=BASE
SO=libnerd-$(NS).so
SRC=$(shell find src -type f '(' -name '*.cpp' -or -name '*.cxx' ')')
HDR=$(shell find src -type f '(' -name '*.hpp' -or -name '*.hxx' ')')
OBJ=$(subst src/,bin/,$(SRC:.cpp=.o))
TS_HDR=src/build_timestamp.hpp

WARN_FLAGS=-Wall -Wextra -pedantic
CXXFLAGS=-std=c++17 -fPIC -DPIC -g $(WARN_FLAGS)
LDFLAGS=-shared -Wl,-soname,$(SO) -g

.SILENT:
.PHONY: all clean new timestamp

all: $(SO)

clean:
	echo '[base]      clean'
	$(RM) bin $(SO)

new: clean all

timestamp:
	echo '[base]      gen     $(subst src/,,$(TS_HDR))'
	echo "#define NERD_MOD_$(MACRO_NS)_STATIC_VERSION_MAJOR $$(date +'%Y%m%d')u" >$(TS_HDR)
	echo "#define NERD_MOD_$(MACRO_NS)_STATIC_VERSION_MINOR $$(date +'%H%M%S' | sed 's/^0*//')u" >>$(TS_HDR)

$(SO): $(OBJ)
	echo '[base]      link    $(SO)'
	$(LD) $(LDFLAGS) $(OBJ) -o$(SO)

bin/%.o: src/%.cpp
	echo '[base]      compile $(subst src/,,$<)'
	$(MKDIR) $(dir $@)
	$(CXX) -c $(CXXFLAGS) $< -o$@

bin/modinfo.o: timestamp
