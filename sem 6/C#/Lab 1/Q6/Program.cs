using System;


interface ILength
{
    double Length { get; set; }
}


interface IWidth
{
    double Width { get; set; }
}


class Rectangle : ILength, IWidth
{
    public double Length { get; set; }
    public double Width { get; set; }

    public double CalculateArea()
    {
        return Length * Width;
    }
}

class Program
{
    static void Main()
    {
        Rectangle rect = new Rectangle();
        rect.Length = 5;
        rect.Width = 3;
        Console.WriteLine($"Area of Rectangle: {rect.CalculateArea()}");
    }
}