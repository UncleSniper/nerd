MODS=base

.PHONY: all clean new
.SILENT:

all:
	for mod in $(MODS); do $(MAKE) -C "$$mod" all; done

clean:
	for mod in $(MODS); do $(MAKE) -C "$$mod" clean; done

new: clean all
