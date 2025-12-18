namespace StateManagementDemo.Models
{
    public class UserPreference
    {
        public int Id { get; set; }
        public string UserId { get; set; } = "User1";
        public string Theme { get; set; } = "Light";
        public DateTime LastUpdated { get; set; }
    }
}