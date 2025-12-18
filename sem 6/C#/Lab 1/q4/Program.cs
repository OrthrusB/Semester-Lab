using System;

class StudentNames
{
    private string[] names = new string[10]; 

   
    public string this[int index]
    {
        get
        {
            return names[index]; 
        }
        set
        {
            names[index] = value; 
        }
    }
}

class Program
{
    static void Main()
    {
        
        StudentNames students = new StudentNames();

        
        students[0] = "Ram";
        students[1] = "Shyam";
        students[2] = "Hari";

        
        Console.WriteLine("Student Names:");
        Console.WriteLine(students[0]); 
        Console.WriteLine(students[1]);
        Console.WriteLine(students[2]); 
    }
}