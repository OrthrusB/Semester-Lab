using System;

class Program
{
    static void Main(string[] args)
    {
        // Initialize an array
        int[] numbers = { 1, 2, 3, 4, 5 };

        // Display original array
        Console.WriteLine("Original Array:");
        foreach (int num in numbers)
        {
            Console.Write(num + " ");
        }

        // Reverse the array
        Array.Reverse(numbers);

        // Display reversed array
        Console.WriteLine("\n\nReversed Array:");
        foreach (int num in numbers)
        {
            Console.Write(num + " ");
        }

        // Keep console window open
        Console.WriteLine("\n\nPress any key to exit...");
        Console.ReadKey();
    }
}