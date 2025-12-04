COMPILER = clang++
CXXFLAGS = -std=c++17 -Wall

day%: bin/day% | bin
	@true

bin/day%: 2025/day%/main.cpp
	$(COMPILER) $(CXXFLAGS) -o $@ $<

bin:
	mkdir -p bin

clean:
	rm -rf bin

.PRECIOUS: bin/day%
.PHONY: clean
