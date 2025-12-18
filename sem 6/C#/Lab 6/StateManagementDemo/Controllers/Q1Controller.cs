using Microsoft.AspNetCore.Mvc;
using StateManagementDemo.Data;
using StateManagementDemo.Models;

namespace StateManagementDemo.Controllers
{
    public class Q1Controller : Controller
    {
        private readonly ApplicationDbContext _db;

        public Q1Controller(ApplicationDbContext db) => _db = db;

        public IActionResult QueryStringDemo(string msg = "Default") { ViewBag.Msg = msg; return View(); }

        public IActionResult HiddenFieldDemo() => View();

        [HttpPost]
        public IActionResult HiddenFieldDemo(string hiddenValue)
        {
            ViewBag.Result = $"Hidden = {hiddenValue}";
            return View();
        }

        public IActionResult CookieDemo()
        {
            Response.Cookies.Append("Q1Cookie", "Cookie123", new CookieOptions
            {
                Expires = DateTimeOffset.Now.AddDays(1),
                HttpOnly = true,
                Secure = true
            });
            ViewBag.Cookie = Request.Cookies["Q1Cookie"] ?? "none";
            return View();
        }

        public IActionResult SessionDemo()
        {
            HttpContext.Session.SetString("Q1Session", "Session123");
            ViewBag.Session = HttpContext.Session.GetString("Q1Session");
            return View();
        }

        public IActionResult TempDataDemo()
        {
            TempData["Flash"] = "One-time message!";
            return RedirectToAction("TempDataResult");
        }

        public IActionResult TempDataResult() => View();

        public IActionResult DatabaseDemo()
        {
            var p = new UserPreference { UserId = "User1", Theme = "Dark", LastUpdated = DateTime.UtcNow };
            _db.UserPreferences.Add(p);
            _db.SaveChanges();
            ViewBag.SavedId = p.Id;
            return View();
        }

        public IActionResult LoadFromDb()
        {
            var p = _db.UserPreferences
                .OrderByDescending(x => x.LastUpdated)
                .FirstOrDefault(x => x.UserId == "User1");
            ViewBag.Theme = p?.Theme ?? "—";
            ViewBag.Updated = p?.LastUpdated.ToString("g") ?? "—";
            return View("DatabaseDemo");
        }
    }
}