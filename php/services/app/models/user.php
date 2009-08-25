<?php
class User extends AppModel {
	var $name = 'User';
	
	//var $belongsTo = array('Group');
	var $belongsTo = array('Group', 'Perso');
	
	//var $hasOne = array('Perso');
}
?>