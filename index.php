<?php
//set default values
$name = '';
$email = '';
$phone = '';
$message = 'Enter some data and click on the Submit button.';

//process
$action = filter_input(INPUT_POST, 'action');

switch ($action) {
    case 'process_data':
        $name = filter_input(INPUT_POST, 'name');
        $email = filter_input(INPUT_POST, 'email');
        $phone = filter_input(INPUT_POST, 'phone');

        //trim the spaces from the start and end of string
        $name = trim($name);
        $email = trim($email);
        $phone = trim($phone);

        //validate name
        if(empty($name)){
            $message = 'You must enter a name.';
            break;
        }

        //captitalize first letters

        $name = strtolower($name);
        $name = ucwords($name);

        //get first name only
        $i =strpos($name, '');
        if ($i === false){
            $first_name = $name;
        } else{
            $first_name = substr($name, 0, $i);
        }

        //validate and format email

        if (empty($email)){
            $message = 'You must enter an eamil.';
            break;
        } elseif(strpos($email, '@') === false){
            $message = 'Your email address must contain and @ symbol.';
            break;
        } elseif (strpos($email, '.') === false){
            $message = 'Your email must contain a period.';
            break;
        }

        //validate and format phone
        $phone = str_replace('-','', $phone);
        $phone = str_replace('.','', $phone);
        $phone = str_replace('(','', $phone);
        $phone = str_replace(')','', $phone);
        $phone = str_replace(' ','', $phone);

        if(strlen($phone) < 7){
            $message = 'Phone numbers must have 7 characters';
            break;
        }
        if(strlen($phone) == 7){
            $part1 = substr($phone, 0, 3);
            $part2 = substr($phone, 3);
            $phone = $part1 . '-' . $part2;
        } else{
                $part1 = substr($phone, 0, 3);
                $part2 = substr($phone, 3, 3);
                $part3 = substr($phone, 6);
                $phone = $part1 . '-' . $part2 . '-' . $part3;
        }

        //format the message
        $message =
        "Hello $first_name,\n\n".
        "Thank you for entering this data:\n\n". 
        "Name: $name\n". 
        "Email: $email\n". 
        "Phone: $phone\n";

        break;
    }
include 'string_tester.php';
?>