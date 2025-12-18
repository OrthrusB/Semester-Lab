using System;
using System.Collections.Generic;
using System.Linq;

class Program
{
    static void Main(string[] args)
    {
        // Create a list of student marks
        List<int> studentMarks = new List<int> { 85, 92, 78, 95, 88, 65, 90, 72, 84, 60 };

        // Use LINQ to count students with marks > 80
        int count = studentMarks.Count(mark => mark > 80);

        // Display the result
        Console.WriteLine($"Number of students with marks greater than 80: {count}");

        // Optional: Display the marks that are greater than 80
        var highMarks = studentMarks.Where(mark => mark > 80).ToList();
        Console.WriteLine("Marks greater than 80:");
        highMarks.ForEach(mark => Console.WriteLine(mark));
    }
}