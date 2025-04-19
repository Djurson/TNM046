#include <iostream>
#include <cstdio>

int main(int argc, char* argv[]) {
    std::cout << "Hello World from <iostream>!\n";    // cout is the console
    fprintf(stdout, "Hello World from <cstdio>!\n");  // stdout is also the console
    printf("Hello again from <cstdio>!\n");           // printf() sends to stdout
}
