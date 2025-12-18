using System;
using System.Linq;

class Program
{
    static void Main(string[] args)
    {
        // Prompt user for input string
        Console.WriteLine("Enter a string:");
        string input = Console.ReadLine();

        // Use LINQ to group characters and count their frequency
        var charFrequency = input
            .GroupBy(c => c)
            .Select(g => new { Character = g.Key, Frequency = g.Count() })
            .OrderBy(x => x.Character);

        // Display the results
        Console.WriteLine("\nCharacter frequencies:");
        foreach (var item in charFrequency)
        {
            Console.WriteLine($"Character '{item.Character}' appears {item.Frequency} time(s)");
        }
    }
}