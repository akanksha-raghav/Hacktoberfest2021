<?php
ob_start();
$code = isset($_GET['c']) ? $_GET['c'] : '';
$url = "http://localhost/url_shortener/classes/URLshortener.php?a=redirect&code=".$code;
$ch = curl_init();
curl_setopt($ch, CURLOPT_HEADER, 0); 
curl_setopt($ch, CURLOPT_RETURNTRANSFER, 1); 
curl_setopt($ch, CURLOPT_URL, $url); 
curl_setopt($ch, CURLOPT_FOLLOWLOCATION, 1); 
if(!curl_errno($ch)){
echo "<style>html{display:none}</style>";
echo curl_exec($ch);
}
$data = curl_getinfo($ch);
ob_end_flush();
echo "<script>location.replace('".$data['url']."');</script>";
curl_close($ch);

