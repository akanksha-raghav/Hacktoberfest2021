<?php 

ob_start();
session_start();
require_once('./classes/DBConnection.php');
$db = new DBConnection();

$page = isset($_GET['p']) ? $_GET['p'] : "home";
ob_end_flush();

?>
<!DOCTYPE html>
<html lang="en">
<style>
    /* canvas {
        height: 250px !important
    } */
    
    table th,
    table td {
        padding: 3px !important
    }
</style>

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>URL Shortener Admin</title>
    <?php include('./header.php') ?>
</head>

<body class=''>
    <main>
    <nav class="navbar navbar-expand-lg navbar-dark bg-dark w-100 border-bottom border-light mb-2" id="top-nav">
        <a class="navbar-brand" href="./admin.php">URL Shortener Admin</a>
        <button class="navbar-toggler" type="button" data-toggle="collapse" data-target="#nav-menu" aria-controls="nav-menu" aria-expanded="false" aria-label="Toggle navigation">
        <span class="navbar-toggler-icon"></span>
    </button>

        <div class="collapse navbar-collapse" id="nav-menu">
            <ul class="navbar-nav mr-auto">
                <li class="nav-item nav-forms">
                    <a class="nav-link" href="./index.html" target="_blank"><i class="fa fa-window-maximize"></i> Website</a>
                </li>
                <li class="nav-item nav-forms">
                    <a class="nav-link" href="./logout.php"><i class="fa fa-sign-out-alt"></i> Sign out</a>
                </li>
        </div>
    </nav>
    <div class="container-fluid">
        <?php include("./".$page.".php") ?>
    </div>
    <?php if(!isset($_SESSION['admin_login']) || (isset($_SESSION['admin_login']) && $_SESSION['admin_login']==false) ): ?>
        <div id="login-dialog" title="Please enter admin password">
            <form action="" id="login">
                <input type="password" class="form form-control" required name="password">
            </form>
        </div>
    <?php endif; ?>
    </main>

</body>
<script>
    $(function(){
        var page = "<?php echo $page ?>";

        $('#nav-menu').find(".nav-item.nav-"+page).addClass("active")
        if($('#login-dialog').length > 0){
            $('#login-dialog').dialog({
                dialogClass: "no-close login-dialog",
                buttons:[
                    {
                        text:"Login",
                        icon:"fa fa-sign-in",
                        click:function(){
                            $('#login').submit()
                        }
                        
                    }
                ],
                open:function(){
                    $("body").addClass("dialog-backdrop")
                }
            });
            $('.login-dialog button').addClass("btn btn-default border")
        }
        
    })
</script>
</html>