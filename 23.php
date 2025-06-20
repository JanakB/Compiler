<!DOCTYPE html>
<html lang="en">
<head>
    <title>Php Class</title>
</head>
<body>
   <?php
   class Student {
    private $age;
    private $name;

    function __construct($age,$name){
       $this->age = $age;
       $this->name = $name; 

    }

    function printDetails(){
        echo "<h2>Hi I am $this->name and I am $this->age years old.";
    }
   }

   $rmb = new Student(21,"Rabindra");
   $rmb->printDetails();
   ?>
</body>
</html>