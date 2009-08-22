<?php
class VueMatieresTotalBesoin extends AppModel {

	var $name = 'VueMatieresTotalBesoin';

	//The Associations below have been created with all possible keys, those that are not needed can be removed
	/*
	var $belongsTo = array(
		'Matiere' => array(
			'className' => 'Matiere',
			'foreignKey' => 'matiere_id',
			'conditions' => '',
			'fields' => '',
			'order' => ''
		)
	);
	*/
	
	var $hasOne = array('Matiere');

	/*
	var $_schema = array(
		'id' => array(
			'type' => 'integer',
			'null' => '',
			'default' => 0,
			'length' => 10
				),
		'matiere_id' => array(
			'type' => 'string',
			'null' => '',
			'default' => 0,
			'length' => 10
				),
		'h_cours' => array(
			'type' => 'float',
			'null' => '',
			'default' => 0,
			'length' => ''
				),
		'h_td' => array(
			'type' => 'float',
			'null' => '',
			'default' => 0,
			'length' => ''
				),
		'h_tp' => array(
			'type' => 'float',
			'null' => '',
			'default' => 0,
			'length' => ''
				),
	);
	*/

}
?>