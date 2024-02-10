#include <stdio.h>
#include <math.h>

#define finalAmount 167083.85

#define initialAmount 142184.85

#define interestRateDecimal 0.0328

#define numYears 5

int main(int argc, char *argv[])
{
    printf("The expected amount is %lf.\n", finalAmount);
    /*
     * compound interest formula = P(1 +r/n)^nt
     * 142184.85(1+.328)^5
     */

    /*
     * Mohan version
     */
    float multiplier = initialAmount * (powf((1 + interestRateDecimal), numYears));
    printf("Matt's version is: %f.\n", multiplier);

    /*
     * Jerifans version
     */
    double end = initialAmount * (pow((1 + interestRateDecimal), 5));
    printf("Jerifans's version is: %lf.\n", end);

    /*
     * Linda's version
     */
    float base = 1 + interestRateDecimal;
    float mult2 = 1 + interestRateDecimal;
    for (int i = 0; i < numYears - 1; i++)
    {
        base = base * mult2;
    }
    float final = initialAmount * base;
    printf("Linda's version: %f. \n", final);

    /*
     * Jeff's version
     */
    double base1 = 1 + interestRateDecimal;
    double mult21 = 1 + interestRateDecimal;
    for (int i = 0; i < numYears - 1; i++)
    {
        base1 = base1 * mult21;
    }
    double final1 = initialAmount * base1;
    printf("Jeff's version: %f. \n", final1);

    printf("My final observation is that each method gets relatively close, \nyet with different decimal precisions.\n");
    printf("Using a float or double in both methods created the same value. \nThe method didn't matter, but the double had the most precisions.\n");
    printf("Powf wasn't as accurate as pow, \nand the loops tended to be more precise.\n");
}