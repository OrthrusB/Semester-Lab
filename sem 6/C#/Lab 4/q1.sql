CREATE TABLE Employee (
    EmployeeID INT PRIMARY KEY IDENTITY(1,1),
    FirstName NVARCHAR(50),
    LastName NVARCHAR(50),
    Department NVARCHAR(50),
    Salary DECIMAL(10,2)
);

INSERT INTO Employee (FirstName, LastName, Department, Salary)
VALUES 
    ('Babin', 'Rana', 'IT', 75000.00),
    ('Rajan', 'Bohara', 'HR', 65000.00),
    ('Sudip', 'Tharu', 'Sales', 70000.00),
    ('MD', NULL, 'Management', 80000.00); 