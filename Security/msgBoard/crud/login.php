<?php
session_start();

include_once ('conn.php');
header("refresh:2;url=../index.php");

?>
<title>PHP留言板</title>

<head>
    <link rel="stylesheet" type="text/css" href="../css.css" />
</head>

<?php
if ('' == $_POST[name] || '' == $_POST[password]) {
    echo "请输入用户名密码";
    exit;
}
$username = $_POST['name'];
$password = $_POST['password'];
$username = htmlspecialchars(addslashes($username), ENT_QUOTES, UTF - 8);
$password = htmlspecialchars(addslashes($password), ENT_QUOTES, UTF - 8);

$query = mysql_query("SELECT uuid,permission FROM T_USER_LOGIN WHERE username='$username' and password='$password' limit 1", $mysql);
if ($result = mysql_fetch_array($query)) {

    //存入session
    $_SESSION['username'] = $username;
    $_SESSION['uuid'] = $result['uuid'];
    $_SESSION['userflag'] = $result['permission'];
    if ($_SESSION['userflag'] == 1 or $_SESSION['userflag'] == 2) {
        echo '欢迎回来';
        echo $_SESSION['username'];
        echo "<br/>";
        echo "正在跳转。。。";
    } else {
        echo "无权限";
    }

} else {
    echo "错误的用户名或者密码";
}
?>