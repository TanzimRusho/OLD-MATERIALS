#include<iostream>
#include<cstdio>
#include<sstream>

static char buffer[100], b[100];

int main(){
    unsigned n;

    /*
     * Read the whole input stream
     */
    fread(buffer, 1, sizeof buffer, stdin);

    /*
     * Create input and output streams
     */
    std::istringstream ss(buffer);
    std::ostringstream sout(b);

    /*
     * Read each input from stream and divide by two
     */
	while((ss >> n) && n){
        sout << (n >> 1);
        sout << "\n";
	}
	std::cout << sout.str();

	return 0;
}
