using System;

// Define the interface for arithmetic operations
interface ICalculator
{
    int Add(int a, int b);
    int Subtract(int a, int b);
    int Multiply(int a, int b);
    double Divide(int a, int b);
}

// Implement the interface in a class
class Calculator : ICalculator
{
    public int Add(int a, int b)
    {
        return a + b;
    }

    public int Subtract(int a, int b)
    {
        return a - b;
    }

    public int Multiply(int a, int b)
    {
        return a * b;
    }

    public double Divide(int a, int b)
    {
        if (b == 0)
        {
            Console.WriteLine("Error: Division by zero!");
            return 0;
        }
        return (double)a / b;
    }
}

class Program
{
    static void Main()
    {
        // Create instance of Calculator
        ICalculator calc = new Calculator();

        // Test numbers
        int num1 = 10;
        int num2 = 5;

        // Perform and display arithmetic operations
        Console.WriteLine($"Numbers: {num1} and {num2}");
        Console.WriteLine($"Addition: {calc.Add(num1, num2)}");
        Console.WriteLine($"Subtraction: {calc.Subtract(num1, num2)}");
        Console.WriteLine($"Multiplication: {calc.Multiply(num1, num2)}");
        Console.WriteLine($"Division: {calc.Divide(num1, num2)}");
    }
}