crypto: crypto.cc
	g++ -std=c++14 -o crypto crypto.cc

install: crypto
	mv crypto /usr/bin

uninstall:
	rm /usr/bin/crypto
