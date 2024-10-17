#include "matrix_operations.h"
#include "input_validation.h"
#include "constants.h"

int main()
{
    while (true)
    {
        displaymenu();
        std::string choice = getChoice();
        getMatrixOperation(choice);
    }
    return 0;
}