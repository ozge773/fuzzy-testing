ifeq ($(OS), Windows_NT)
	CATCH=2>NUL || VER>NUL
else
	CATCH=2>/dev/null ; true
endif

build: 
	-git clone https://github.com/AFLplusplus/AFLplusplus
	-gcc -shared -o bits-flip.so bits-flip.c -fPIC -I AFLplusplus/include/
	-rm -r AFLplusplus