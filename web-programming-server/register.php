<?php
// Include config file
require_once "config.php";
 
// Define variables and initialize with empty values
$username = $email = $radio1 = $radio2 = "";
$username_err = $email_err = $radio1_err = $radio2_err = "";
 
// Processing form data when form is submitted
if($_SERVER["REQUEST_METHOD"] == "POST"){
 
    // Prepare a select statement
    $sql = "SELECT id FROM users WHERE email = ?";
        
    if($stmt = mysqli_prepare($link, $sql)){
        // Bind variables to the prepared statement as parameters
        mysqli_stmt_bind_param($stmt, "s", $param_email);
    
        // Set parameters
        $param_email = trim($_POST["email"]);
    
        // Attempt to execute the prepared statement
        if(mysqli_stmt_execute($stmt)){
            /* store result */
            mysqli_stmt_store_result($stmt);
        
            if(mysqli_stmt_num_rows($stmt) == 1){
                $email_err = "This email is already taken.";
            }else{
                $email = trim($_POST["email"]);
            }
        } else{
            echo "Oops! Something went wrong. Please try again later.";
        }

        // Close statement
        mysqli_stmt_close($stmt);
    }

    // Validate username
    if(empty(trim($_POST["username"]))){
        $username_err = "Please enter a name.";
    } else{
        $username = trim($_POST["username"]);
    }
    
    
    //Validate Radio1
    if(empty(trim($_POST["radio1"]))){
        $radio1_err = "Please choose an option.";     
    } else{
        $radio1 = trim($_POST["radio1"]);
    }

    //Validate Radio2
    if(empty(trim($_POST["radio2"]))){
        $radio2_err = "Please choose an option.";     
    } else{
        $radio2 = trim($_POST["radio2"]);
    }

    // Check input errors before inserting in database
    if(empty($username_err) && empty($email_err) && empty($radio1_err) && empty($radio2_err)){
        
        // Prepare an insert statement
        $sql = "INSERT INTO users (username, email, radio1, radio2) VALUES (?, ?, ?, ?)";
         
        if($stmt = mysqli_prepare($link, $sql)){
            // Bind variables to the prepared statement as parameters
            mysqli_stmt_bind_param($stmt, "ssss", $param_username, $param_email, $param_r1, $param_r2);
            
            // Set parameters
            $param_username = $username;
            $param_email = $email;
            $param_r1 = $radio1;
            $param_r2 = $radio2;
            
            // Attempt to execute the prepared statement
            if(mysqli_stmt_execute($stmt)){
                echo "Successful.";
            } else{
                echo "Oops! Something went wrong. Please try again later.";
            }

            // Close statement
            mysqli_stmt_close($stmt);
        }
    }
    
    // Close connection
    mysqli_close($link);
}
?>
 
<!DOCTYPE html>>
<head>
    <meta charset="UTF-8">
    <title>iis20001</title>
    <link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.5.2/css/bootstrap.min.css">
    <style>
        body{ font: 16px sans-serif; }
        .form{
            padding: 20px; 
            float: center; 
            margin: auto;
            width: 360px;
            border-style: outset;
            padding-bottom: 75px;
        }   
        button{
            color: #fff !important;
            text-decoration: none;
            background: #ed3330;
            padding: 20px;
            border-radius: 5px;
            display: inline-block;
            border: none;
            transition: all 0.4s ease 0s;
        }
        button:hover {
            background: #434343;
            letter-spacing: 1px;
            -webkit-box-shadow: 0px 5px 40px -10px rgba(0,0,0,0.57);
            -moz-box-shadow: 0px 5px 40px -10px rgba(0,0,0,0.57);
            box-shadow: 5px 40px -10px rgba(0,0,0,0.57);
            transition: all 0.4s ease 0s;
        }

        input[name="radio1"] {
             /* Change width and height */
            width:1em;
            height:1em;
            float: right;
        }

        input[name="radio2"] {
             /* Change width and height */
            width:1em;
            height:1em;
            float: right;
        }
    </style>
</head>
<body>
    <div class="form">
        <h2>Έρευνα για την Εταιρεία BioJam</h2>
        <p>Συμπληρώστε παρακαλώ τα παρακάτω στοιχεία</p>
        <form action="<?php echo htmlspecialchars($_SERVER["PHP_SELF"]); ?>" method="post">
            <div class="form-group">
                <label><strong>Ονοματεπώνυμο</strong></label>
                <input type="text" name="username" class="form-control <?php echo (!empty($username_err)) ? 'is-invalid' : ''; ?>" value="<?php echo $username; ?>">
                <span class="invalid-feedback"><?php echo $username_err; ?></span>
            </div>    
            <div class="form-group">
                <label><strong>Email</strong></label>
                <input type="email" name="email"  class="form-control <?php echo (!empty($email_err)) ? 'is-invalid' : ''; ?>" value="<?php echo $email; ?>">
                <span class="invalid-feedback"><?php echo $email_err; ?></span>
            </div>
            <br>
            <div class="question">
            <label><strong>Which of the following skills is your strongest?</strong></label>
            <div class="question-answer">
                <div>
                    <input type="radio" value="Financial" id="radio_01" name="radio1" class="form-control <?php echo (!empty($radio1_err)) ? 'is-invalid' : ''; ?>" value="<?php echo $radio1; ?>"/>
                    <label for="radio_01" class="radio"><span>Financial/analytical</span></label>
                </div>
                <div>
                    <input type="radio" value="Communication" id="radio_02" name="radio1" class="form-control <?php echo (!empty($radio1_err)) ? 'is-invalid' : ''; ?>" value="<?php echo $radio1; ?>"/>
                    <label for="radio_02" class="radio"><span>Communication</span></label>
                </div>
                <div>
                    <input type="radio" value="Sales" id="radio_03" name="radio1" class="form-control <?php echo (!empty($radio1_err)) ? 'is-invalid' : ''; ?>" value="<?php echo $radio1; ?>"/>
                    <label for="radio_03" class="radio"><span>Sales</span></label>
                </div>
                <div>
                    <input type="radio" value="Technical" id="radio_04" name="radio1" class="form-control <?php echo (!empty($radio1_err)) ? 'is-invalid' : ''; ?>" value="<?php echo $radio1; ?>"/>
                    <label for="radio_04" class="radio"><span>Technical</span></label>
                </div>
                <div>
                    <input type="radio" value="Creative" id="radio_05" name="radio1" class="form-control <?php echo (!empty($radio1_err)) ? 'is-invalid' : ''; ?>" value="<?php echo $radio1; ?>"/>
                    <label for="radio_05" class="radio"><span>Creative</span></label>
                </div>
                </div>
            </div>
            <br>
            <div class="question">
                <label><strong>Do you prefer to work with?</strong></label>
                <div class="question-answer">
                    <div>
                        <input type="radio" value="large" id="radio_09" name="radio2" class="form-control <?php echo (!empty($radio2_err)) ? 'is-invalid' : ''; ?>" value="<?php echo $radio2; ?>"/>
                        <label for="radio_09" class="radio"><span>A large group of people</span></label>
                    </div>
                    <div>
                        <input type="radio" value="small" id="radio_010" name="radio2" class="form-control <?php echo (!empty($radio2_err)) ? 'is-invalid' : ''; ?>" value="<?php echo $radio2; ?>"/>
                        <label for="radio_010" class="radio"><span>A small group of people</span></label>
                    </div>
                    <div>
                        <input type="radio" value="alone" id="radio_011" name="radio2" class="form-control <?php echo (!empty($radio2_err)) ? 'is-invalid' : ''; ?>" value="<?php echo $radio2; ?>"/>
                        <label for="radio_011" class="radio"><span>Alone</span></label>
                    </div>
                </div>
            </div>
            <div class="form-group">
                <input type="submit" class="btn btn-primary" value="Submit" style='float: right;'>
            </div>
            <br>
        </form>
    </div>    
    <button style=" margin-left: 46%; margin-top: 1%;" onclick="location.href = 'createDB.php';"> Create Database </button>
    <br>
    <button style="margin-left: 47%; margin-top: 1%;" onclick="location.href = 'showDB.php';"> Show Data </button>
</body>
</html>