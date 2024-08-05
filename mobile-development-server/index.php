
<!DOCTYPE html>
<html>
<head>
<title>ΕΣΑΚΕ</title>
<meta charset="UTF-8">
<meta name="viewport" content="width=device-width, initial-scale=1">
<link href="https://cdn.jsdelivr.net/npm/bootstrap@5.1.3/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-1BmE4kWBq78iYhFldvKuhfTAU6auU8tT94WrHftjDbrCEXSU1oBoqyl2QvZ6jIW3" crossorigin="anonymous">
</head>
<body>
    <div class="p-5 mb-4 bg-light rounded-3">
      <div class="container-fluid py-5">
            <h1 class="display-3 fw-bold">ΕΣΑΚΕ</h1>
            <p class="col-md-3 fs-4">Basketball management service.</p>
      </div>
    </div>
    <?php
        include 'mysql_handler.php';
        $client = new MySQLHandler('localhost', 'MyUserAdmin', 'Ur3*3$fasE234o4', 3036);
        $client->setConnection();
        createDbFunction('esakedb',$client);
    ?>
    <div class="container">
        <div class="row gx-5">
            <div class="col-sm-4">
                <h5> ΔΗΜΙΟΥΡΓΙΑ ΟΜΑΔΑΣ </h5>
                <br>
                <form action="" method="post">
                    Name: <input type="text" name="Name"><br>
                    City: <input type="text" name="City"><br>
                    Logo: <input type="file" name="Logo" id="picture" /><br>
                    <button type="submit" name="submit_team">Add team</button>
                </form>
            </div>
            <div class="col-sm-4">
                <h5> ΔΗΜΙΟΥΡΓΙΑ ΤΟΥΡΝΟΥΑ </h5>
                <br>
                <form action="" method="post">
                    Name: <input type="text" name="Name"><br>
                    Team: <input type="text" name="Team"><br>
                    <button type="submit" name="submit_tournament">Add tournament</button>
                </form>
            </div>
            <div class="col-sm-4">
                <h5> ΔΗΜΙΟΥΡΓΙΑ ΠΑΙΚΤΗ </h5>
                <br>
                <form action="" method="post">
                    Name: <input type="text" name="name"><br>
                    Position: <input type="text" name="position"><br>
                    Team: <input type="text" name="team"><br>
                    Photo: <input type="file" name="picture" id="picture" /><br>
                    <button type="submit" name="submit_player">Add player</button>
                </form>
            </div>
        </div>
    </div>
</body>

