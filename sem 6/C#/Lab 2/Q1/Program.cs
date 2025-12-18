using System;

class Program
{
    static void Main()
    {
        // Declare a string
        string originalString = "Hello";
        Console.WriteLine("Original string: " + originalString);

        // Attemptთ Attempt to modify string
        string modifiedString = originalString;
        modifiedString = modifiedString + ", World!";

        // Display results
        Console.WriteLine("Original string after 'modification': " + originalString);
        Console.WriteLine("Modified string: " + modifiedString);

        // Show memory difference to prove immutability
        Console.WriteLine("\nMemory reference of originalString: " + ReferenceEquals(originalString, modifiedString));
    }
}