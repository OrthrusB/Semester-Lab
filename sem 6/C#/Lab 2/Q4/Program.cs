using System;
using System.Collections.Generic;

class Program
{
    static void Main()
    {
        // Create a generic List to store numbers
        List<int> numbers = new List<int>();

        // Add numbers 1 to 10 to the List
        for (int i = 1; i <= 10; i++)
        {
            numbers.Add(i);
        }

        // Print all numbers in the List
        Console.WriteLine("Numbers from 1 to 10:");
        foreach (int num in numbers)
        {
            Console.WriteLine(num);
        }
    }
}