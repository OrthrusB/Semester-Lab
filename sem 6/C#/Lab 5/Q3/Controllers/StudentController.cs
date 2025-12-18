using Microsoft.AspNetCore.Mvc;
using Q3.Models;
using Q3.Data;

namespace Q3.Controllers
{
    public class StudentController : Controller
    {
        private readonly AppDbContext _context;

        public StudentController(AppDbContext context)
        {
            _context = context;
        }

        public IActionResult Index()
        {
            return View();
        }

        [HttpPost]
        public IActionResult Display(Student model)
        {
            if (ModelState.IsValid)
            {
                _context.Students.Add(model);
                _context.SaveChanges();
                return RedirectToAction("Details", new { id = model.Id });
            }
            return View("Index", model);
        }

        public IActionResult Details(int id)
        {
            var student = _context.Students.Find(id);
            return View(student);
        }
    }
}