using System;


class Animal
{
    public virtual void Sound()
    {
        Console.WriteLine("Some sound");
    }
}


class Dog : Animal
{
    public override void Sound()
    {
        Console.WriteLine("Woof!");
    }
}

class Program
{
    static void Main()
    {
        Animal myAnimal = new Animal();
        Animal myDog = new Dog();

        myAnimal.Sound(); 
        myDog.Sound();    // Prints "Woof!"
    }
}