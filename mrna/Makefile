PROGRAM = mrna
CXX = /usr/local-gcc/bin/g++
TARGETS = $(PROGRAM)
CXXFLAGS = -W -Wall -O3 --std=c++11 -march=corei7 -I../include

run: all
	@echo --- `date`
	@bash -c "time ./$(PROGRAM) < input | tee output" 2>&1
	@echo --- `date`

all: $(TARGETS)

clean:
	rm -f $(TARGETS) output
