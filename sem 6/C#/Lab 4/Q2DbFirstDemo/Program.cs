using System;
using System.Linq;
using Q2DbFirstDemo; // <-- Add this line! Replace with your actual namespace if different

namespace Q2DbFirstDemo
{
    class Program
    {
        static void Main(string[] args)
        {
            using (var db = new StudentDBEntities1())
            {
                var students = db.Students.ToList();

                Console.WriteLine("List of Students:");
                foreach (var student in students)
                {
                    Console.WriteLine($"ID: {student.StudentId}, Name: {student.Name}, Age: {student.Age}");
                }
            }

            Console.WriteLine("Press any key to exit...");
            Console.ReadKey();
        }
    }
}
