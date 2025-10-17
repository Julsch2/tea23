#include <fmt/chrono.h>
#include <fmt/format.h>

#include "config.h"


void changeValueByParameter(int value){
    value = 99;
}

void changeValueByPointer(int* ptr){
    *ptr = 99;
}



int main(int argc, char **argv) {

    /**
     * The {fmt} lib is a cross platform library for printing and formatting text
     * it is much more convenient than std::cout and printf
     * More info at https://fmt.dev/latest/api.html
     */
    
    int i = 0;
    
    
    fmt::print("Hello, {}!\n", tea::PROJECT_NAME);
    fmt::print("Anzahl an Argumenten {}!\n", argc);

    for (i = 0; i < argc; i++) {
        fmt::print("Argument[{}] = {}\n", i, argv[i]);
    }

    int foo = 10;
    int* ptr = &foo;


    *ptr = 42;
    int bar = 4711;
    ptr = &bar;
    *ptr = foo;

    fmt::print("Wert{} \n ", bar);


    /* INSERT YOUR CODE HERE */


    double* Pi = new double (3.1415);
    fmt::println ("Double ist: {}, mit der Adresse: {}", *Pi, fmt::ptr(Pi));
    delete(Pi);

    int y = -85;

    fmt::println("Wert von Y vor der Funktion: {}",y );
    changeValueByParameter(y);
    fmt::println("Wert von Y nach der Funktion mit Parameter: {}",y );
    changeValueByPointer(&y);
    fmt::println("Wert von Y nach der Funktion mit Zeiger: {}",y );
    

    return 0; /* exit gracefully*/
}
