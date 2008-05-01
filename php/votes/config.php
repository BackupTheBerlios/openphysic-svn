<?php

require_once('vote.php');
//global $votes;
//$votes=new Vote();
$_SESSION['votes'] = serialize(new Vote());

?>
