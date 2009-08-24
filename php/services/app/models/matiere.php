<?php
class Matiere extends AppModel {

	var $name = 'Matiere';

	var $belongsTo = array('Filiere' =>
        array('className'    => 'Filiere',
			'conditions'   => '',
			'order'        => '', // Filiere.name ASC, Matiere.name ASC
			'foreignKey'   => 'filiere_id'
    	)
	);

	var $hasMany = array('MatieresPerso' =>
		array('className'    => 'MatieresPerso',
			'conditions'   => '',
			'order'        => 'h_cours DESC, h_td DESC, h_tp DESC',
			'foreignKey'   => 'matiere_id'
		)
	);

	var $hasOne = array('VueMatieresTotalBesoin', 'VueMatieresComblesBesoin', 'VueMatieresRestantsBesoin');

	var $validate = array( 'name'=>'alphaNumeric', 'h_cours'=>'numeric', 'h_td'=>'numeric', 'h_tp'=>'numeric' );

	//var $hasAndBelongsToMany = array('Perso');

	/* Bilan horaire par matiere : $id=... */
	/* Bilan horaire pour toutes les matières $id=null ou 'all' */

	
	function get_vol_horaire_a_attribuer_with_sql_view($id='all') {
		//  Méthode 1 : à l'aide d'une vue SQL dans la base

		if ($id==null or $id=='all') {
			$this->VueMatieresTotalBesoin =& ClassRegistry::init('VueMatieresTotalBesoin');
			$this->VueMatieresTotalBesoin->recursive = -1;
			$temp = $this->VueMatieresTotalBesoin->find('all');
			//debug($temp);
			return $temp;
				
		} else {
		

			$this->VueMatieresTotalBesoin =& ClassRegistry::init('VueMatieresTotalBesoin');
			$this->VueMatieresTotalBesoin->recursive = -1;
			$temp = $this->VueMatieresTotalBesoin->read(null, $id);
			return $temp['VueMatieresTotalBesoin'];

		}
	}

	function get_vol_horaire_a_attribuer_with_sql_query($id='all') {
		// Méthode 2
		$prefix = $this->tablePrefix;
		
		if ($id==null or $id=='all') {
			//  à l'aide d'une requête SQL
			$sql = "SELECT {$prefix}matieres.id AS id, {$prefix}matieres.h_cours as h_cours, {$prefix}matieres.h_td * {$prefix}filieres.nb_gr_td AS h_td, h_tp * {$prefix}filieres.nb_gr_tp AS h_tp FROM {$prefix}matieres, {$prefix}filieres WHERE {$prefix}matieres.filiere_id = {$prefix}filieres.id;";
			$temp = $this->query($sql);
			$result = array();
			foreach ( $temp as $key => $matiere ) {
				$matiere_id=$matiere['services_matieres']['id'];
				$result=Set::insert($result, $matiere_id,
					array(	'h_cours'=>$matiere['services_matieres']['h_cours'],
							'h_td'=>$matiere[0]['h_td'],
							'h_tp'=>$matiere[0]['h_tp']
							)
				);
				//debug($matiere_id);
			}
			//$result = Set::combine ($result, '{n}.services_matieres.id', '{n}.0'); // Mise en forme l'array pour avoir matiere_id comme clé
			return $result;


		} else {
			// à l'aide d'une requête read recursive et d'une boucle
			$this->recursive=0;
			$matiere = $this->read(null, $id);
			$result = array(
				'h_cours'=>$matiere['Matiere']['h_cours'],
				'h_td'=>$matiere['Matiere']['h_td']*$matiere['Filiere']['nb_gr_td'],
				'h_tp'=>$matiere['Matiere']['h_tp']*$matiere['Filiere']['nb_gr_tp']
			);
			return $result;
		}
		
	}

	function get_vol_horaire_a_attribuer_with_loop($id='all') {
		// Méthode 3
		if ($id==null or $id=='all') {
			// à l'aide d'une requête find all et d'une boucle
			$temp = $this->find('all');
			$result = array();
			foreach ( $temp as $key => $matiere ) {
				$matiere_id=$matiere['Matiere']['id'];
				$result=Set::insert($result, $matiere_id,
					array(	'h_cours'=>$matiere['Matiere']['h_cours'],
							'h_td'=>$matiere['Matiere']['h_td']*$matiere['Filiere']['nb_gr_td'],
							'h_tp'=>$matiere['Matiere']['h_tp']*$matiere['Filiere']['nb_gr_tp']
							)
						);
			}
			return $result;

		} else {
			// à l'aide d'une requête read recursive et d'une boucle
			$this->recursive=0;
			$matiere = $this->read(null, $id);
			$result = array(
				'h_cours'=>$matiere['Matiere']['h_cours'],
				'h_td'=>$matiere['Matiere']['h_td']*$matiere['Filiere']['nb_gr_td'],
				'h_tp'=>$matiere['Matiere']['h_tp']*$matiere['Filiere']['nb_gr_tp']
			);
			return $result;
		}
	}

	function get_vol_horaire_a_attribuer($id='all') {
		return $this->get_vol_horaire_a_attribuer_with_sql_view($id);
	}

	function get_vol_horaire_attribue($id='all') {
		/*  Méthode 1 : à l'aide d'une vue SQL dans la base */
		$this->VueMatieresComblesBesoin =& ClassRegistry::init('VueMatieresComblesBesoin');
		$this->VueMatieresComblesBesoin->recursive=-1;
		$temp = $this->VueMatieresComblesBesoin->read(null, $id);
		//debug($temp);
		return $temp['VueMatieresComblesBesoin'];                
	}
    
    function get_vol_horaire_restant($id='all') {
		/*  Méthode 1 : à l'aide d'une vue SQL dans la base */
		$this->VueMatieresRestantsBesoin =& ClassRegistry::init('VueMatieresRestantsBesoin');
		$this->VueMatieresRestantsBesoin->recursive=-1;
		$temp = $this->VueMatieresRestantsBesoin->read(null, $id);
		//debug($temp);
		return $temp['VueMatieresRestantsBesoin'];
	}

		/*
		function test() {
			$matieres = $this->find('all', array('recursive'=>0) );
			$matieres_tot = $matieres;
			foreach ($matieres as $matiere) {
				$matieres_tot['Matiere']['h_tp'] = $matiere['Matiere']['h_tp']*$matiere['Filiere']['nb_gr_tp'];
			}
			return $matieres_tot;
			//return "a test in model";
		}
		*/
        
}
?>