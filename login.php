<?php
session_start();

// Database configuration
$servername = "localhost";
$dbname = "uttkarsh";
$dbusername = "root";
$dbpassword = "";

// Create connection
$conn = new mysqli($servername, $dbusername, $dbpassword, $dbname);

// Check connection
if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}

// Get the form input
$username = $_POST['username'];
$password = $_POST['password'];

// Prevent SQL injection
$username = $conn->real_escape_string($username);
$password = $conn->real_escape_string($password);

// Query to check if the user exists in the database
$sql = "SELECT * FROM users WHERE username='$username' AND password='$password'";
$result = $conn->query($sql);

if ($result->num_rows > 0) {
    // Successful login
    $_SESSION['username'] = $username;
    echo "Login successful. Welcome, " . $username . "!";
} else {
    // Unsuccessful login
    echo "Login unsuccessful. Invalid username or password.";
}

$conn->close();
?>
