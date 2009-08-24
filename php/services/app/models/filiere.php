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
		
	var $validate = array( 'name' => 'alphaNumeric',
		'nb_gr_td' => array( 'rule' => array('custom', '/^[0-9]*$/') ), // ToFix integer <> decimal <> numeric ???
		'nb_gr_tp' => array( 'rule' => array('custom', '/^[0-9]*$/') )
	); // , 
		
	/*
	function isAuthorized($user, $controller, $action) {
		if ($user['User']['role'] == 'admin') {
			return true;
		} else {
			return false;
		}
	}
	*/
	
	
	/*=============================
	 = Volume horaire à attribuer =
	 =============================*/
	function get_vol_horaire_a_attribuer($id=null) {
		return array('h_cours'=>'ToDo', 'h_td'=>'ToDo', 'h_tp'=>'ToDo');
	}


	/*=========================
	 = Volume horaire restant =
	 =========================*/
    function get_vol_horaire_restant($id=null) {
		return array('h_cours'=>'ToDo', 'h_td'=>'ToDo', 'h_tp'=>'ToDo');
	}

	
	/*==========================
	 = Volume horaire attribué =
	 ==========================*/
	 
	function get_vol_horaire_attribue($id=null) {
		return array('h_cours'=>'ToDo', 'h_td'=>'ToDo', 'h_tp'=>'ToDo');
	}
	
	
	/*=========================
	 = Volume horaire (bilan) =
	 =========================*/
	function get_vol_horaire($id=null) {
	 	return array(
       		'a_effectuer'=>$this->get_vol_horaire_a_attribuer($id),
       		'attribue'=>$this->get_vol_horaire_attribue($id),
       		'restant'=>$this->get_vol_horaire_restant($id)
       	);
	}


}
?>