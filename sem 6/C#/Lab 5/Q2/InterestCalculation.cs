namespace Q2.Models
{
    public class InterestCalculation
    {
        public int Id { get; set; } // Primary key
        public decimal Amount { get; set; }
        public decimal Rate { get; set; } // Interest rate (e.g., 5 for 5%)
        public int Time { get; set; } // Time in years
        public decimal SimpleInterest { get; set; } // Calculated interest
    }
}