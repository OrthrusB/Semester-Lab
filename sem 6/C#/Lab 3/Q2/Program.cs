using System;
using System.Linq;

class Program
{
    static void Main(string[] args)
    {
        // Sample input string
        string input = "My Name is Babin Rana";

        // Use LINQ to find uppercase letters
        var upperCaseLetters = input.Where(char.IsUpper).ToList();

        // Display the result
        Console.WriteLine($"Uppercase letters in '{input}':");
        if (upperCaseLetters.Any())
        {
            Console.WriteLine(string.Join(", ", upperCaseLetters));
            Console.WriteLine($"Total uppercase letters: {upperCaseLetters.Count}");
        }
        else
        {
            Console.WriteLine("No uppercase letters found.");
        }
    }
}