using System;


class Animal
{
    public void Eat()
    {
        Console.WriteLine("Animal is eating");
    }
}

class Dog : Animal 
{
    public void Bark()
    {
        Console.WriteLine("Dog is barking");
    }
}


interface IRun
{
    void Run();
}

interface ISwim
{
    void Swim();
}

class Dolphin : Animal, IRun, ISwim 
{
    public void Run()
    {
        Console.WriteLine("Dolphin is running");
    }

    public void Swim()
    {
        Console.WriteLine("Dolphin is swimming");
    }
}


class Puppy : Dog 
{
    public void Play()
    {
        Console.WriteLine("Puppy is playing");
    }
}


class Cat : Animal 
{
    public void Meow()
    {
        Console.WriteLine("Cat is meowing");
    }
}

class Program
{
    static void Main()
    {
        Console.WriteLine("Single Inheritance:");
        Dog dog = new Dog();
        dog.Eat();  
        dog.Bark(); 

        Console.WriteLine("\nMultiple Inheritance:");
        Dolphin dolphin = new Dolphin();
        dolphin.Eat();  
        dolphin.Run();  
        dolphin.Swim(); 

        Console.WriteLine("\nMultilevel Inheritance:");
        Puppy puppy = new Puppy();
        puppy.Eat();  
        puppy.Bark(); 
        puppy.Play(); 

        Console.WriteLine("\nHierarchical Inheritance:");
        Cat cat = new Cat();
        cat.Eat();  
        cat.Meow(); 
    }
}