using System;
using System.Data;
using System.Data.SqlClient;

namespace AdoNetDemo
{
    class Program
    {
        // Connection string for local server
        private static string connectionString = "Server=.;Database=EmployeeDB;Trusted_Connection=True;";

        static void Main(string[] args)
        {
            Console.WriteLine(" Connected Architecture ");
            ConnectedDemo();

            Console.WriteLine("\nDisconnected Architecture");
            DisconnectedDemo();

            Console.ReadLine();
        }

        static void ConnectedDemo()
        {
            using (SqlConnection connection = new SqlConnection(connectionString))
            {
                try
                {
                    connection.Open();
                    // Read data
                    string query = "SELECT * FROM Employee";
                    SqlCommand command = new SqlCommand(query, connection);
                    SqlDataReader reader = command.ExecuteReader();
                    Console.WriteLine("\nEmployee List:");
                    while (reader.Read())
                    {
                        string fullName = reader["LastName"] == DBNull.Value
                            ? reader["FirstName"].ToString()
                            : reader["FirstName"] + " " + reader["LastName"];
                        Console.WriteLine($"ID: {reader["EmployeeID"]}, Name: {fullName}");
                    }
                    reader.Close();

                    // Insert data
                    query = "INSERT INTO Employee (FirstName, LastName, Department, Salary) VALUES ('New', 'User', 'IT', 68000.00)";
                    command = new SqlCommand(query, connection);
                    int rows = command.ExecuteNonQuery();
                    Console.WriteLine($"\nInserted {rows} row(s)");
                }
                catch (Exception ex)
                {
                    Console.WriteLine($"Error: {ex.Message}");
                }
            }
        }

        static void DisconnectedDemo()
        {
            using (SqlConnection connection = new SqlConnection(connectionString))
            {
                try
                {
                    // Read data into DataSet
                    DataSet dataSet = new DataSet();
                    string query = "SELECT * FROM Employee";
                    SqlDataAdapter adapter = new SqlDataAdapter(query, connection);
                    adapter.Fill(dataSet, "Employee");
                    Console.WriteLine("\nEmployee List from DataSet:");
                    foreach (DataRow row in dataSet.Tables["Employee"].Rows)
                    {
                        string fullName = row["LastName"] == DBNull.Value
                            ? row["FirstName"].ToString()
                            : row["FirstName"] + " " + row["LastName"];
                        Console.WriteLine($"ID: {row["EmployeeID"]}, Name: {fullName}");
                    }

                    // Insert data into DataSet and update database
                    DataRow newRow = dataSet.Tables["Employee"].NewRow();
                    newRow["FirstName"] = "New";
                    newRow["LastName"] = "Person";
                    newRow["Department"] = "Finance";
                    newRow["Salary"] = 72000.00;
                    dataSet.Tables["Employee"].Rows.Add(newRow);
                    adapter.Update(dataSet, "Employee");
                    Console.WriteLine("\nAdded new employee to database");
                }
                catch (Exception ex)
                {
                    Console.WriteLine($"Error: {ex.Message}");
                }
            }
        }
    }
}