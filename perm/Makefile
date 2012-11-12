PROGRAM = perm
CXX = /usr/local-gcc/bin/g++
TARGETS = $(PROGRAM)
CXXFLAGS = -W -Wall -O3 --std=c++11 -march=corei7 -I../include

run: all
	@echo --- `date` | tee output
	@bash -c "time ./$(PROGRAM) < input" 2>&1 | tee -a output
	@echo --- `date` | tee -a output

all: $(TARGETS)

clean:
	rm -f $(TARGETS) output
