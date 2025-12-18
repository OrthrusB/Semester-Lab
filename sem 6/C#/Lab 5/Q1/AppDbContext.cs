using Q1.Models; // Adjust to Q1 if Person.cs is in Q1 namespace
using System.Collections.Generic;
using System.Data.Entity;
using System.Runtime.Remoting.Contexts;

namespace Q1.Data
{
    public class AppDbContext : DbContext
    {
        public DbSet<Person> People { get; set; }

        public AppDbContext() : base("name=AppDbContext")
        {
        }
    }
}