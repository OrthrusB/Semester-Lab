using System;

public class Student
{
    
    public int Id { get; set; }
    public string Name { get; set; }

    // Constructor
    public Student(int id, string name)
    {
        Id = id;
        Name = name;
    }

    // Method to display student information
    public void DisplayInfo()
    {
        Console.WriteLine($"Student ID: {Id}");
        Console.WriteLine($"Student Name: {Name}");
    }
}

class Program
{
    static void Main(string[] args)
    {
        // Create a new Student object
        Student student = new Student(1, "Ram");

        // Display student information
        student.DisplayInfo();

        // Keep console window open
        Console.WriteLine("\nPress any key to exit...");
        Console.ReadKey();
    }
}