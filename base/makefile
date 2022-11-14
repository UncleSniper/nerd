CXX=g++
LD=$(CXX)
RM=rm -rf
MKDIR=mkdir -p

NS=base
SO=libnerd-$(NS).so
SRC=$(shell find src -type f '(' -name '*.cpp' -or -name '*.cxx' ')')
HDR=$(shell find src -type f '(' -name '*.hpp' -or -name '*.hxx' ')')
OBJ=$(subst src/,bin/,$(SRC:.cpp=.o))

WARN_FLAGS=-Wall -Wextra -pedantic
CXXFLAGS=-fPIC -DPIC -g $(WARN_FLAGS)
LDFLAGS=-shared -Wl,-soname,$(SO) -g

.SILENT:
.PHONY: all clean new

all: $(SO)

clean:
	echo '[base]      clean'
	$(RM) bin $(SO)

new: clean all

$(SO): $(OBJ)
	echo '[base]      link    $(SO)'
	$(LD) $(LDFLAGS) $(OBJ) -o$(SO)

bin/%.o: src/%.cpp
	echo '[base]      compile $(subst src/,,$<)'
	$(MKDIR) $(dir $@)
	$(CXX) -c $(CXXFLAGS) $< -o$@
