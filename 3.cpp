#include "fmt/printf.h"
int main(void)
{
fmt::print("I'd rather be {1} than {0}.\n", "right", "happy"); // Positional arguments
fmt::print("Numbers : {1:24.16e} {0:24.16e}\n", -9.8765, 2.34); // Python + printf like printing
fmt::printf("Elapsed time: %.2f seconds\n", 1.23); // printf like printing
return 0;
}
