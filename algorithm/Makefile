.PHONY: all
.PHONY: clean
.PHONY: build_out
.PHONY: readme

OUT_PREFIX := out
CC := gcc
VERSION := release
CFLAGS :=

ifeq ($(VERSION),debug)
CFLAGS += -g -DDEBUG
endif

COMMON := common.o
objects_orig := $(patsubst %.c,%.o,$(wildcard *.c))
objects := $(filter-out $(COMMON),$(objects_orig))

all: $(objects_orig) build_out
	$(foreach target,$(objects), \
	$(CC) $(CFLAGS) $(addprefix $(OUT_PREFIX)/,$(COMMON)) $(addprefix $(OUT_PREFIX)/, $(target)) -o $(addprefix $(OUT_PREFIX)/,$(basename $(target)));)


build_out:
	@mkdir -p $(OUT_PREFIX)

readme:
	@echo
	@echo "This is the study output of algorithms by faywong"
	@echo "Usage:"
	@echo "      make readme --- print this help"
	@echo "      make all    --- build all objects"
	@echo "      make VERSION=[debug/release]    --- build all objects in debug/release version"
	@echo "      make clean --- clean all the building output"
	@echo
	@echo "Any problem, please contact <philip584521@gmail.com>"
	@echo

%.o: %.c build_out
	$(CC) $(CFLAGS) -c -o $(addprefix $(OUT_PREFIX)/,$@) $<

clean:
	@rm -rf $(OUT_PREFIX)
	@rm -f *.o
	@rm -f a.out
