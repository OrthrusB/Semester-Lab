using System;

class Program
{
    // Define a delegate for adding two digits
    delegate int AddDelegate(int a, int b);

    static void Main()
    {
        // Create delegate instance pointing to Add method
        AddDelegate addNumbers = Add;

        // Call delegate to add two digits
        int num1 = 5;
        int num2 = 3;
        int result = addNumbers(num1, num2);

        // Display result
        Console.WriteLine($"Sum of {num1} and {num2} is: {result}");
    }

    // Method to add two digits
    static int Add(int a, int b)
    {
        return a + b;
    }
}