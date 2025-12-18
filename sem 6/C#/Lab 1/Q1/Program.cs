using System;

class AddDigits
{
    public AddDigits(int a, int b)
    {
        Console.WriteLine($"Sum of {a} and {b} is: {a + b}");
    }

    static void Main()
    {
        Console.Write("Enter first digit: ");
        int digit1 = int.Parse(Console.ReadLine());

        Console.Write("Enter second digit: ");
        int digit2 = int.Parse(Console.ReadLine());

        new AddDigits(digit1, digit2);
    }
}