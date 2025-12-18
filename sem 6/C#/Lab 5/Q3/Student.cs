using System.ComponentModel.DataAnnotations;

namespace Q3.Models
{
    public class Student
    {
        public int Id { get; set; }

        [Required(ErrorMessage = "Student Name is required.")]
        [StringLength(100, ErrorMessage = "Student Name cannot exceed 100 characters.")]
        public string Name { get; set; }

        [Required(ErrorMessage = "Course is required.")]
        [StringLength(50, ErrorMessage = "Course cannot exceed 50 characters.")]
        public string Course { get; set; }

        [Required(ErrorMessage = "Semester is required.")]
        [Range(1, 8, ErrorMessage = "Semester must be between 1 and 8.")]
        public int Semester { get; set; }
    }
}