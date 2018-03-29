crypto: crypto.cc crypto.hh
	g++ -std=c++14 -o crypto crypto.cc

install:
	mv crypto /usr/bin

uninstall:
	rm /usr/bin/crypto
