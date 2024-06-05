<?php
// Database connection details
$servername = "localhost";
$username = "root";
$password = "";
$dbname = "user";

// Create connection
$conn = new mysqli($servername, $username, $password, $dbname);

// Check connection
if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $first_name = $conn->real_escape_string($_POST['first_name']);

    // Query to search for the first name
    $sql = "SELECT last_name, address FROM users WHERE first_name='$first_name'";
    $result = $conn->query($sql);

    if ($result->num_rows > 0) {
        // Output the results
        echo "<h2>Results for '$first_name':</h2>";
        echo "<table border='1'>
                <tr>
                    <th>Last Name</th>
                    <th>Address</th>
                </tr>";
        while ($row = $result->fetch_assoc()) {
            echo "<tr>
                    <td>" . htmlspecialchars($row["last_name"]) . "</td>
                    <td>" . htmlspecialchars($row["address"]) . "</td>
                  </tr>";
        }
        echo "</table>";

        // Display the number of rows found
        echo "<p>Total records found: " . $result->num_rows . "</p>";
    } else {
        echo "<p>No results found for '$first_name'.</p>";
    }
}

$conn->close();
?>
<!DOCTYPE html>
<html>
<head>
    <title>Search Results</title>
</head>
<body>
    <a href="search.php">Go Back</a>
</body>
</html>
