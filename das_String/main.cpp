// THIS FILE IS FOR TESTING OF SPECTORSTRING.H
//
// TODO LIST
// + Look at what functions we need for basic usage of this and add them.
// + Look at what overloads would be useful for effective use
// + Optimize everything (this will be here forever probably)
#include "das_string.h"
#include <cstdio>

int main()
{
    // two test strings
    String stringA = { "Hello World!", 12 };
    String stringB = { "Hello World!", 12 };

    printf("CONCATINATION WITH + TEST\n\n");
    String helloworldtwiceA = stringA + stringB;
    String helloworldtwiceB = stringA + "Hello World!";
    String helloworldtwiceC = "Hello World!" + stringA;

    //TODO(dustin): look at how get it to look at .string without having to put
    //it for printing
    if(helloworldtwiceA.length == 24) printf("\tA %s\n", helloworldtwiceA.string);
    if(helloworldtwiceB.length == 24) printf("\tB %s\n", helloworldtwiceB.string);
    if(helloworldtwiceC.length == 24) printf("\tC %s\n", helloworldtwiceC.string);
    // ------------------------------------------------------------------------
    String copyTestA = copyString(stringA);
    String copyTestB = copyString("Hello World!");
    String copyTestC = {(char*)calloc((stringA.length +1), sizeof(char)) \
                       , 12};
    copyString(stringA, copyTestC);

    printf("\nCOPY FUNCTION TEST\n\n");
    if(copyTestA.length == 12) printf("\tA %s\n", copyTestA.string);
    if(copyTestB.length == 12) printf("\tB %s\n", copyTestB.string);
    if(copyTestC.length == 12) printf("\tC %s\n", copyTestC.string);
    // ------------------------------------------------------------------------
    String equalsTestA = copyString("Equals Test");
    String equalsTestB = copyString("Equals Test");
    String equalsTestD; equalsTestD = "D Equals Test Passed";

    printf("\nEQUALS(==) FUNCTION TEST\n\n");
    if(equalsTestA == equalsTestB)   printf("\tA Equals Test Passed\n");
    if(equalsTestA == "Equals Test") printf("\tB Equals Test Passed\n");
    if("Equals Test" == equalsTestA) printf("\tC Equals Test Passed\n");
    printf("\t%s\n", equalsTestD.string);
    // ------------------------------------------------------------------------
    String arrayindextestA = copyString("A [] overload test Passed");
    String arrayindextestB = copyString("B [] overload test Passed");

    printf("\n[] OVERLOAD TEST\n\n");
    printf("\t%c [] overload test Passed\n", arrayindextestA[0]);
    printf("\t%c [] overload test Passed\n", arrayindextestB[0]);
    // ------------------------------------------------------------------------
    String basicSplitstringA = copyString("A Split string test Passed, Passed");
    String basicSplitstringB =
        splitString("B Split string test Passed, Passed", ',');
    basicSplitstringA = splitString(basicSplitstringA, ',');
    String basicSplitstringC = {(char*)calloc((26+1), sizeof(char)) \
                       , 26};
    splitString(copyString("C Split string test Passed, Passed"), ',', basicSplitstringC);

    printf("\nBASIC SPLIT STRING TEST\n\n");
    printf("\t%s\n", basicSplitstringA.string);
    printf("\t%s\n", basicSplitstringB.string);
    printf("\t%s\n\n", basicSplitstringC.string);
    // ------------------------------------------------------------------------
    return 0;
}
