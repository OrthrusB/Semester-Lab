using System;
using System.Linq;

class Program
{
    static void Main(string[] args)
    {
        // Sample array of numbers
        int[] numbers = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

        // Use LINQ to calculate squares
        var squares = numbers.Select(n => new { Number = n, Square = n * n });

        // Display the results
        Console.WriteLine("Number and their squares:");
        foreach (var item in squares)
        {
            Console.WriteLine($"Square of Number {item.Number} is {item.Square}");
        }
    }
}