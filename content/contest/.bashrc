alias c='g++ -Wall -Wconversion -Wfatal-errors -g -std=c++14 \
	-fsanitize=undefined,address'
export ASAN_OPTIONS=detect_leaks=0
