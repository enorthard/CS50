#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Initialize Variables
    int height;
    int hashes;
    int spaces;
    // Prompt user for height
    do
    {
        height = get_int("Height?\n");
    }
    // If height is not an integer between 1 and 8, return to step 1
    while (height < 0 || height > 8);
    // When in the correct parameters
    for (int i = 1; i <= height; i++)
    {
        // Add spaces
        for (spaces = (height - i); spaces > 0; spaces--)
        {
            printf(" ");
        }
        // Add hashes
        for (hashes = 1; i >= hashes; hashes++)
        {
            printf("#");
        }
        // Make new line
        printf("\n");
    }
    // Return
    return 0;
}
    
  

