using System;
using System.Linq;

class Program
{
    static void Main(string[] args)
    {
        // List of cities
        string[] cities = { "ROME", "LONDON", "NAIROBI", "CALIFORNIA", "ZURICH", "NEWDELHI", "AMSTERDAM", "ABUDHABI", "PARIS" };

        // Prompt user for the specific character
        Console.WriteLine("Enter a character to find cities that start and end with it:");
        char inputChar = Console.ReadLine().ToUpper()[0];

        // Use LINQ to find cities that start and end with the specific character
        var matchingCities = cities
            .Where(city => city.StartsWith(inputChar.ToString(), StringComparison.OrdinalIgnoreCase)
                        && city.EndsWith(inputChar.ToString(), StringComparison.OrdinalIgnoreCase))
            .ToList();

        // Display the results
        Console.WriteLine($"\nCities that start and end with '{inputChar}':");
        if (matchingCities.Any())
        {
            foreach (var city in matchingCities)
            {
                Console.WriteLine(city);
            }
            Console.WriteLine($"Total matching cities: {matchingCities.Count}");
        }
        else
        {
            Console.WriteLine("No cities found that start and end with the specified character.");
        }
    }
}