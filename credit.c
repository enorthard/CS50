#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    long credit, test1, test2;
    // Ask user for credit card number
    do
    {
        credit = get_long("Credit card #?\n");
    }
    while (credit <= 0);
    // Test checksum
    int n1, n2, nsum, nproduct;
    nsum = 0;
    nproduct = 0;
    test1 = credit;
    test2 = credit;
    // Starting with second to last digit, multiply each by 2
    // Add those products digits
    // Add the sum to the sum of digits not multiplied
    // Then, check if last digit in sum is 0
    while (test1 > 0)
    {
        n1 = test1 % 10;
        nsum += n1;
        test1 -= n1;
        test1 /= 10;
        n2 = test1 % 10;
        test1 -= n2;
        test1 /= 10;
        if ((n2 * 2) > 9)
        {
            nproduct += (n2 * 2) % 10;
            nproduct += ((n2 * 2) - ((n2 * 2) % 10)) / 10;
        }
        else 
        {
            nproduct += (n2 * 2);
        }
    }
    // Check company
    // Check length
    if ((nsum + nproduct) % 10 == 0)
    {
        bool amex, mastercard, visa;
        
        amex = (test2 >= 340000000000000 && test2 < 350000000000000) || 
               (test2 >= 370000000000000 && test2 < 380000000000000);
        
        mastercard = (test2 >= 5100000000000000 && test2 < 5600000000000000);
        
        visa = (test2 >= 4000000000000 && test2 < 5000000000000) ||
               (test2 >= 4000000000000000 && test2 < 5000000000000000);
        
        if (amex)
        {
            printf("AMEX\n");
        }
        else if (mastercard)
        {
            printf("MASTERCARD\n");
        }  
        else if (visa)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n"); 
        }  
        
    } 
    // Invalid card
    else 
    {
        printf("INVALID\n");
    }
}
