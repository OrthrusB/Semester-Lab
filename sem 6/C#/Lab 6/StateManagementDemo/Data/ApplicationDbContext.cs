using Microsoft.EntityFrameworkCore;
using StateManagementDemo.Models;

namespace StateManagementDemo.Data
{
    public class ApplicationDbContext : DbContext
    {
        public ApplicationDbContext(DbContextOptions<ApplicationDbContext> options)
            : base(options) { }

        public DbSet<UserPreference> UserPreferences { get; set; } = null!;
    }
}