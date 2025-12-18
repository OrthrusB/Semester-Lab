using System;
using System.Collections.Generic;

class Program
{
    static void Main()
    {
        // Create a Dictionary to store CustomerId and CustomerName
        Dictionary<int, string> customers = new Dictionary<int, string>();

        // Add sample customer data
        customers.Add(101, "Babin Rana");
        customers.Add(102, "Ram Hari");
        customers.Add(103, "Sita Gita");
        customers.Add(104, "Luv Kush");

        // Print all customers
        Console.WriteLine("Customer List:");
        Console.WriteLine("CustomerId\tCustomerName");
        Console.WriteLine("-------------------------");

        foreach (var customer in customers)
        {
            Console.WriteLine($"{customer.Key}\t\t{customer.Value}");
        }
    }
}