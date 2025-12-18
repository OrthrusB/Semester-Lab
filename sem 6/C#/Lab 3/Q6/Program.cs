using System;
using System.Collections.Generic;
using System.Linq;

class Program
{
    // Student class
    class Student
    {
        public int StudentId { get; set; }
        public string Name { get; set; }
    }

    // Course class
    class Course
    {
        public int StudentId { get; set; } 
        public string CourseName { get; set; }
    }

    static void Main(string[] args)
    {
        // Sample student data
        List<Student> students = new List<Student>
        {
            new Student { StudentId = 1, Name = "Babin" },
            new Student { StudentId = 2, Name = "Rabin" },
            new Student { StudentId = 3, Name = "Sabin" }
        };

        // Sample course data
        List<Course> courses = new List<Course>
        {
            new Course { StudentId = 1, CourseName = "Mathematics" },
            new Course { StudentId = 1, CourseName = "Physics" },
            new Course { StudentId = 2, CourseName = "Chemistry" },
            new Course { StudentId = 4, CourseName = "Biology" }
        };

        // Use LINQ to join students and courses on StudentId
        var joinedData = from student in students
                         join course in courses
                         on student.StudentId equals course.StudentId
                         select new
                         {
                             StudentName = student.Name,
                             CourseEnrolled = course.CourseName
                         };

        // Display the results
        Console.WriteLine("Student and Course Information:");
        foreach (var item in joinedData)
        {
            Console.WriteLine($"Student: {item.StudentName}, Course: {item.CourseEnrolled}");
        }
    }
}