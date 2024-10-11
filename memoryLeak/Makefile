ifeq ($(OS), Windows_NT)
	CATCH=2>NUL || VER>NUL
else
	CATCH=2>/dev/null ; true
endif

build:  
	-afl-clang-fast -fsanitize=fuzzer,address -o leak leak.c


run:
	-rm -r input_corpus $(CATCH)
	-mkdir input_corpus
	-echo "" > input_corpus/empty_seed
	-afl-fuzz -i input_corpus -o output_corpus -- ./leak