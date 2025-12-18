using System;
using System.Linq;
using Q1.Data;
using Q1.Models;

namespace Q1
{
    class Program
    {
        static void Main(string[] args)
        {
            using (var context = new AppDbContext())
            {
                var people = context.People.ToList();
                Console.WriteLine("People in the database:");
                foreach (var person in people)
                {
                    Console.WriteLine($"ID: {person.Id}, Name: {person.Name}, Age: {person.Age}");
                }
            }
            Console.WriteLine("Press any key to exit...");
            Console.ReadKey();
        }
    }
}