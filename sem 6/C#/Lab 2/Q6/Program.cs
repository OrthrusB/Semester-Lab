using System;

// User-defined exception for insufficient balance
class InsufficientBalanceException : Exception
{
    public InsufficientBalanceException(string message) : base(message)
    {
    }
}

class Program
{
    static void Main()
    {
        try
        {
            // Read balance and withdraw amount from user
            Console.Write("Enter current balance: ");
            double balance = Convert.ToDouble(Console.ReadLine());

            Console.Write("Enter withdraw amount: ");
            double withdrawAmount = Convert.ToDouble(Console.ReadLine());

            // Check if balance is sufficient
            if (balance >= withdrawAmount)
            {
                double remainingBalance = balance - withdrawAmount;
                Console.WriteLine($"Withdrawal successful! Remaining balance: {remainingBalance}");
            }
            else
            {
                throw new InsufficientBalanceException("Error: Insufficient balance for withdrawal!");
            }
        }
        catch (InsufficientBalanceException ex)
        {
            Console.WriteLine(ex.Message);
        }
        catch (FormatException)
        {
            Console.WriteLine("Error: Please enter valid numeric values!");
        }
    }
}