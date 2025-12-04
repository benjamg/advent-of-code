COMPILER = clang++
CXXFLAGS = -std=c++17 -Wall -fsanitize=undefined

day%: bin/day% | bin
	@true

bin/day%: 2025/day%/main.cpp
	$(COMPILER) $(CXXFLAGS) -o $@ $<

bin:
	mkdir -p bin

clean:
	rm -rf bin

test-day%: bin/day%
	cat 2025/day$*/test | ./bin/day$*

run-day%: bin/day%
	cat 2025/day$*/input | ./bin/day$*

.PRECIOUS: bin/day%
.PHONY: build clean
