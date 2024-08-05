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
                <input type="text" name="username">
            </div>    
            <div class="form-group">
                <label><strong>Email</strong></label>
                <br>
                <input type="email" name="email" >
            </div>
            <br>
            <div class="question">
            <label><strong>Which of the following skills is your strongest?</strong></label>
            <div class="question-answer">
                <div>
                    <input type="radio" value="Financial" id="radio_01" name="radio1" />
                    <label for="radio_01" class="radio"><span>Financial/analytical</span></label>
                </div>
                <div>
                    <input type="radio" value="Communication" id="radio_02" name="radio1" />
                    <label for="radio_02" class="radio"><span>Communication</span></label>
                </div>
                <div>
                    <input type="radio" value="Sales" id="radio_03" name="radio1" />
                    <label for="radio_03" class="radio"><span>Sales</span></label>
                </div>
                <div>
                    <input type="radio" value="Technical" id="radio_04" name="radio1" />
                    <label for="radio_04" class="radio"><span>Technical</span></label>
                </div>
                <div>
                    <input type="radio" value="Creative" id="radio_05" name="radio1"/>
                    <label for="radio_05" class="radio"><span>Creative</span></label>
                </div>
                </div>
            </div>
            <br>
            <div class="question">
                <label><strong>Do you prefer to work with?</strong></label>
                <div class="question-answer">
                    <div>
                        <input type="radio" value="large" id="radio_09" name="radio2" />
                        <label for="radio_09" class="radio"><span>A large group of people</span></label>
                    </div>
                    <div>
                        <input type="radio" value="small" id="radio_010" name="radio2" />
                        <label for="radio_010" class="radio"><span>A small group of people</span></label>
                    </div>
                    <div>
                        <input type="radio" value="alone" id="radio_011" name="radio2" />
                        <label for="radio_011" class="radio"><span>Alone</span></label>
                    </div>
                </div>
            </div>
            <div class="form-group">
                <input type="submit" class="btn btn-primary" value="Submit" style='float: right;' onclick="window.alert('You have to create DB first.');">
            </div>
            <br>
        </form>
    </div>    
    <button style=" margin-left: 46%; margin-top: 1%;" onclick="location.href = 'createDB.php';"> Create Database </button>
    <br>
    <button style="margin-left: 47%; margin-top: 1%;" onclick="window.alert('You have to create DB first.');"> Show Data </button>
</body>
</html>