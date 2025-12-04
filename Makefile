COMPILER = clang++
CXXFLAGS = -std=c++17 -Wall -fsanitize=undefined

bin:
	mkdir -p bin

clean:
	rm -rf bin

# make 25-1, make run-25-1, make test-25-1
.SECONDEXPANSION:
%: bin/$$*
	@true

bin/%: 20$$(word 1,$$(subst -, ,$$*))/day$$(word 2,$$(subst -, ,$$*))/main.cpp | bin
	$(COMPILER) $(CXXFLAGS) -o $@ $<

run-%: bin/$$*
	cat 20$(word 1,$(subst -, ,$*))/day$(word 2,$(subst -, ,$*))/input | ./bin/$*

test-%: bin/$$*
	cat 20$(word 1,$(subst -, ,$*))/day$(word 2,$(subst -, ,$*))/test | ./bin/$*

.PRECIOUS: bin/%
.PHONY: build clean
