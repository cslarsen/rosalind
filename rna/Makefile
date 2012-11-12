PROGRAM = r2
CXX = /usr/local-gcc/bin/gcc
TARGETS = $(PROGRAM)
CXXFLAGS = -W -Wall -O3 -march=corei7

run: all
	@echo --- `date` | tee output
	@bash -c "time ./$(PROGRAM) < input" 2>&1 | tee -a output
	@echo --- `date` | tee -a output

all: $(TARGETS)

clean:
	rm -f $(TARGETS) output
