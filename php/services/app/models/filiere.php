<?php
class Filiere extends AppModel {

	var $name = 'Filiere';
	
	//var $displayField = 'nom';
		
	var $order='Filiere.name ASC';
		
	var $hasMany = array('Matiere' =>
		array('className'    => 'Matiere',
			'conditions'   => null,
			'order'        => 'h_cours DESC, h_td DESC, h_tp DESC, name ASC',
			'foreignKey'   => 'filiere_id'
		)
	);
			
	var $hasOne = array('VueFilieresTotalBesoin', 'VueFilieresComblesBesoin', 'VueFilieresRestantsBesoin');
		
	var $validate = array( 'name'=>'alphaNumeric', 'nb_gr_td'=>'decimal', 'nb_gr_tp'=>'decimal' );
		
	/*
	function isAuthorized($user, $controller, $action) {
		if ($user['User']['role'] == 'admin') {
			return true;
		} else {
			return false;
		}
	}
	*/
}
?>