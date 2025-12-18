using Microsoft.AspNetCore.Mvc;
using Q2.Models;
using Q2.Data;

namespace Q2.Controllers
{
    public class InterestController : Controller
    {
        private readonly AppDbContext _context;

        public InterestController(AppDbContext context)
        {
            _context = context;
        }

        public IActionResult Index()
        {
            return View();
        }

        [HttpPost]
        public IActionResult Calculate(InterestCalculation model)
        {
            if (ModelState.IsValid)
            {
                model.SimpleInterest = (model.Amount * model.Rate * model.Time) / 100;
                _context.InterestCalculations.Add(model);
                _context.SaveChanges();
                return RedirectToAction("Result", new { id = model.Id });
            }
            return View("Index", model);
        }

        public IActionResult Result(int id)
        {
            var calculation = _context.InterestCalculations.Find(id);
            return View(calculation);
        }
    }
}