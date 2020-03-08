CC = g++
option = -g -I ./
all:

install:

tar:

test: WordTest NumberBigTest helper
	$(CC) $(option) test/build/*.o build/*.o test/start_test/start_test.cpp -o test/build/start_test
	./test/build/start_test

WordTest: Word test/Word/*
	for f in test/Word/*.cpp ; do\
		realf=`basename -s .cpp $$f`; \
		$(CC) $(option) -c $$f -o test/build/$(addsuffix .o,$$realf); \
	done

Word: src/Word/*

NumberBigTest: NumberBig test/NumberBig/*
	for f in test/NumberBig/*.cpp ; do \
		realf=`basename -s .cpp $$f`; \
		$(CC) $(option) -c $$f -o test/build/$(addsuffix .o,$$realf); \
	done

NumberBig: src/NumberBig/*
	for f in src/NumberBig/*.cpp ; do \
		realf=`basename -s .cpp $$f`; \
		$(CC) $(option) -c $$f -o build/$(addsuffix .o,$$realf); \
	done 

helper: src/helper/*
	for f in src/helper/*.cpp ; do \
		realf=`basename -s .cpp $$f`; \
		$(CC) $(option) -c $$f -o build/$(addsuffix .o,$$realf); \
	done 


.PHONY:clean

clean:
	rm -f test/build/*
	rm -f build/*
