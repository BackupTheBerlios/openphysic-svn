<?php
class Perso extends AppModel {
	var $name = 'Perso';
		
	var $displayField = 'initiales';
	//var $displayField = 'nom';
		
	var $order='Perso.permanent DESC, Perso.nom ASC, Perso.prenom ASC';
				
	var $belongsTo = array('Statut' =>
		array('className'    => 'Statut',
			'conditions'   => '',
			'order'        => '',
			'foreignKey'   => 'statut_id'
			)
	);

	var $hasMany = array('MatieresPerso' =>
		array('className'    => 'MatieresPerso',
			'conditions'   => '',
			'order'        => 'h_cours DESC, h_td DESC, h_tp DESC',
			'foreignKey'   => 'perso_id',
			//'joinTable' => 'Matieres' 
		)
	);
	
	//var $hasOne = array('User');
	
	//var $hasAndBelongsToMany = array('Matieres');
	
	var $hasOne = array('VuePersosBilanService');
	
	var $validate = array( 'initiales'=>'alphaNumeric', 'nom'=>'alphaNumeric', 'prenom'=>'alphaNumeric' );
	
	function getBilanService($id='all') {
		return $this->getBilanServiceWithSqlView($id);
	}
	
	function getBilanServiceWithSqlView($id='all') {
		//  Méthode 1 : à l'aide d'une vue SQL dans la base
		$this->VuePersosBilanServices =& ClassRegistry::init('VuePersosBilanServices');
		$this->VuePersosBilanServices->recursive=-1;
		if($id=='all' or $id==null) {
			$temp = $this->VuePersosBilanServices->find('all');
			return $temp;
		} else {
			$temp = $this->VuePersosBilanServices->read(null, $id);
			return $temp['VuePersosBilanServices'];
		}
	}
		
	function getBilanServiceWithLoop($id='all') {
		//  Méthode 2 : à l'aide d'une d'une boucle
		//ToDo

		if($id=='all' or $id==null) {
			return "ToDo";		
		} else {
			return "ToDo";
		}
	}

	function getBilanServiceWithSqlQuery($id='all') {
		//  Méthode 3 : à l'aide d'une requête SQL directe
		$prefix = $this->tablePrefix;
		if($id=='all' or $id==null) {
			$sql = "SELECT perso_id AS id, perso_id, SUM( h_cours ) AS h_cours, SUM( h_td ) AS h_td, SUM( h_tp ) AS h_tp FROM {$prefix}matieres_persos GROUP BY perso_id";
			$result = $this->query($sql);
			// ToDo
			return $result;
        } else {
        	// ToFix : use Sanitize to avoid SQL injection
			$sql = "SELECT perso_id AS id, perso_id, SUM( h_cours ) AS h_cours, SUM( h_td ) AS h_td, SUM( h_tp ) AS h_tp FROM {$prefix}matieres_persos WHERE perso_id=$id GROUP BY perso_id LIMIT 1";
			$result = $this->query($sql);
			$result = Set::merge($result[0]["{$prefix}matieres_persos"], $result[0][0]);
			return $result;
		}
	}
}
?>