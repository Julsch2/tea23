#include <fmt/chrono.h>
#include <fmt/format.h>

#include "config.h"


void foo();


int globalVar = 1;
int globalVar0 = 0;
static int staticGlobal = 55; 
const int constGlobal = 1000;
int globalNoVal;




int main(int argc, char **argv) {

    /**
     * The {fmt} lib is a cross platform library for printing and formatting text
     * it is much more convenient than std::cout and printf
     * More info at https://fmt.dev/latest/api.html
     */
    
    int localVar = 2;
    const int ConstlocalVar = 2;
    static int StaticlocalVar = 2;
    
    
    int* heapVar = new int(3);
    
    
    fmt::print("Hello, {}!\n", tea::PROJECT_NAME);


    fmt::println("Adresse von globalVar {}", fmt::ptr(&globalVar));
    fmt::println("Wert von globalVar {}", globalVar);

    fmt::println("Adresse von globalVar0 {}", fmt::ptr(&globalVar0));
    fmt::println("Wert von globalVar0 {}", globalVar0);

    fmt::println("Adresse von staticGlobal {}", fmt::ptr(&staticGlobal));
    fmt::println("Wert von staticGlobal {}", staticGlobal);

    fmt::println("Adresse von constGlobal {}", fmt::ptr(&constGlobal));
    fmt::println("Wert von constGlobal {}", constGlobal);

    fmt::println("Adresse von globalNoVal {}", fmt::ptr(&globalNoVal));
    fmt::println("Wert von globalNoVal {}", globalNoVal);




    fmt::println("Adresse von localVar {}", fmt::ptr(&localVar));
    fmt::println("Wert von localVar {}", localVar);
    
    fmt::println("Adresse von ConstlocalVar {}", fmt::ptr(&ConstlocalVar));
    fmt::println("Wert von ConstlocalVar {}", ConstlocalVar);

    fmt::println("Adresse von StaticlocalVar {}", fmt::ptr(&StaticlocalVar));
    fmt::println("Wert von StaticlocalVar {}", StaticlocalVar);


    fmt::println("Adresse von heapVar {}", fmt::ptr(&heapVar));
    fmt::println("Wert von heapVar {}", *heapVar);

    foo();
    fmt::println("Adresse von foo {}", fmt::ptr(foo));
    


    /* INSERT YOUR CODE HERE */

    return 0; /* exit gracefully*/
}


void foo(){
    fmt::print("Hello from foo!\\n");

}