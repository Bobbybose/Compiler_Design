binaries = hello math loop array

# Try with -O0 as well
CFLAGS = -O1

# Don't remove intermediates
.PRECIOUS: %.ll %.s

all: $(binaries)

clean:
	-rm $(binaries) $(binaries:%=%.ll) $(binaries:%=%.s)

%.ll: %.c
	clang $(CFLAGS) -emit-llvm -S $< -o $@

# Need to generate position-independent code on Linux x86-64
%.s: %.ll
	llc --relocation-model=pic $< -o $@

%: %.s
	gcc $< -o $@

# Disable built-in implicit rules, so we don't go straight from .c to binary
%: %.c

%.s: %.c
