ifeq ($(OS), Windows_NT)
	CATCH=2>NUL || VER>NUL
else
	CATCH=2>/dev/null ; true
endif

build:  
	-afl-clang-fast++ -fsanitize=address,undefined -o wolframroesler_example main.cpp


run:
	-rm -r input_corpus $(CATCH)
	-mkdir input_corpus
	-echo "Hello world" > input_corpus/empty_seed
	-afl-fuzz -p explore -i input_corpus -o output_corpus -- ./wolframroesler_example