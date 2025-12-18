using Microsoft.EntityFrameworkCore;
using Q2.Models;

namespace Q2.Data
{
    public class AppDbContext : DbContext
    {
        public DbSet<InterestCalculation> InterestCalculations { get; set; }

        public AppDbContext(DbContextOptions<AppDbContext> options) : base(options)
        {
        }
    }
}