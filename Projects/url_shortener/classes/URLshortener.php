<?php 
session_start();
require_once('DBConnection.php');
Class URLshortener extends DBConnection{
    static $logout;
    public function __construct(){
		parent::__construct();
	}
	public function __destruct(){
		parent::__destruct();
	}

    public function shorten(){
        extract($_POST);
        $data = " url_redirect = '{$url}' ";
        $codeString = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        $codeString.= "abcdefghijklmnopqrstuvwxyz";
        $codeString.= "0123456789";
        while(true):
            $codeString = str_repeat($codeString,rand(9,99));
            $shuf_string = str_shuffle($codeString);
            $code = substr($shuf_string,0,10);
            $chk = $this->conn->query("SELECT * FROM `url_list` where `code` = '{$code}'")->num_rows;
            if($chk <= 0)
                break;
        endwhile;
        $data .= ", `code` = '{$code}' ";
        $save = $this->conn->query("INSERT INTO `url_list` set {$data}");
        if($save){
            $resp['status'] = 'success';
            $resp['code'] = $code;
            $resp['metas'] = json_decode($this->get_url_data($url));
        }else{
            $resp['status'] = 'failed';
            $resp['err_'] = $this->conn->error;
        }
        return json_encode($resp);
    }

    function get_url_data($url){
        $curl = curl_init();
        curl_setopt($curl, CURLOPT_HEADER, 0); 
        curl_setopt($curl, CURLOPT_RETURNTRANSFER, 1); 
        curl_setopt($curl, CURLOPT_URL, $url); 
        curl_setopt($curl, CURLOPT_FOLLOWLOCATION, 1); 

        $resp = curl_exec($curl);
        curl_close($curl);

        $DOM = new DOMDocument();
        @$DOM->loadHTML($resp);
        
        $data = array();
        $data['title'] = $DOM->getElementsByTagName('title')->item(0)->nodeValue;

        $metaNodes = $DOM->getElementsByTagName('meta');

        for ($i = 0 ; $i < $metaNodes->length; $i++){
            $mdata = $metaNodes->item($i);
            if($mdata->getAttribute('name') !== null){
                $data[strtolower($mdata->getAttribute('name'))] = $mdata->getAttribute('content');
            }
            if($mdata->getAttribute('property') !== null){
                $data[strtolower($mdata->getAttribute('property'))] = $mdata->getAttribute('content');
            }
        }

            // echo "<pre>";
            // var_dump($data);
            // echo "</pre>";
            return json_encode($data);
    }
    function load_redirect($code = ""){
        if(empty($code)){
            return "<h2>Link Do not Exist.</h2>";
        }else{
            $get = $this->conn->query("SELECT * FROM `url_list` where `code` = '{$code}' ");
            if($get->num_rows > 0){
                $linkData = $get->fetch_assoc();
                
                $update = $this->conn->query("UPDATE `url_list` set `last_browsed` = from_unixtime('".time()."'), `redirects` = `redirects` + 1   where code = '{$code}' ");
                if($update){
                    header('location:'.$linkData['url_redirect']);
                }
                
            }else{
                return "<h2>Link Do not Exist.</h2>";
            }
        }
    }
    function login(){
        extract($_POST);
        $pass = 'f865b53623b121fd34ee5426c792e5c33af8c227';
        if(sha1($password) == $pass){
            $_SESSION['admin_login'] = true;
            $resp['status']='success';
        }else{
            $resp['status']='failed';
        }
        return json_encode($resp);
    }
    public static function logout(){
        session_destroy();
        header('location:./');
    }
    function list_urls(){
        $qry = $this->conn->query("SELECT * FROM `url_list` order by date(last_browsed) desc");
        $data = array();
        while($row= $qry->fetch_assoc()){
            $data[] = $row;
        }
        return json_encode($data);
    }
    function delete_url(){
        extract($_POST);
        $delete = $this->conn->query("DELETE FROM `url_list` where `code` = '{$code}'");
        if($delete){
            $resp['status'] = "success";
        }else{
            $resp['status'] = "failed";
            $resp['err'] = $this->conn->error;

        }
        return json_encode($resp);
    }
    
}
$short = new URLshortener();
$action = !isset($_GET['a']) ? 'none' : strtolower($_GET['a']);
switch ($action) {
	case 'shorten':
		echo $short->shorten();
	break;
  
    case 'get_url':
        $url = $_POST['url'];
		echo $short->get_url_data($url);
	break;
    case 'redirect':
        $code = $_GET['code'];
		echo $short->load_redirect($code);
	break;
    case 'login':
		echo $short->login();
	break;
    case 'logout':
		echo $short->logout();
	break;
    case 'list_urls':
		echo $short->list_urls();
	break;
    case 'delete_url':
		echo $short->delete_url();
	break;
	default:
		// echo $sysset->index();
		break;
}