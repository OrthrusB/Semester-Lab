using Q1.Models;
using System.Data.Entity.Migrations;

namespace Q1.Migrations
{
    internal sealed class Configuration : DbMigrationsConfiguration<Q1.Data.AppDbContext>
    {
        public Configuration()
        {
            AutomaticMigrationsEnabled = false;
        }

        protected override void Seed(Q1.Data.AppDbContext context)
        {
            context.People.AddOrUpdate(
                p => p.Id,
                new Person { Id = 1, Name = "Ram", Age = 30 },
                new Person { Id = 2, Name = "Shyam", Age = 25 },
                new Person { Id = 3, Name = "Hari", Age = 35 }
            );
        }
    }
}