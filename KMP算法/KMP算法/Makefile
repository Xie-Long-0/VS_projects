obj = main.o kmp-algo.o

KMP.out: $(obj)
	g++ -o KMP.out $(obj)

kmp-algo.o: kmp-algo.cpp kmp-algo.h
main.o: main.cpp kmp-algo.h

.PHONY: clean
clean:
	rm -f KMP.out $(obj)

