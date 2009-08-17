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

	function get_vol_horaire_a_attribuer($id=null) {
		if ($id==null or $id=='all') {

			/*  Méthode 1 : à l'aide d'une vue SQL dans la base */
			$this->VueMatieresTotalBesoin =& ClassRegistry::init('VueMatieresTotalBesoin');
			$this->VueMatieresTotalBesoin->recursive = 0;
			$temp = $this->VueMatieresTotalBesoin->find('all');
			//debug($temp);
			return $temp;
				
		} else {
			
        	/*  Méthode 1 : à l'aide d'une vue SQL dans la base */
			$this->VueMatieresTotalBesoin =& ClassRegistry::init('VueMatieresTotalBesoin');
			$this->VueMatieresTotalBesoin->recursive = -1;
			$temp = $this->VueMatieresTotalBesoin->read(null, $id);
			return $temp['VueMatieresTotalBesoin'];

	        /*  Méthode 2 : à l'aide d'une requête read recursive et d'une boucle */
    	   	/*
			$this->recursive=0;
			$matiere = $this->read(null, $id);
			$result = array(
				'h_cours'=>$matiere['Matiere']['h_cours'],
				'h_td'=>$matiere['Matiere']['h_td']*$matiere['Filiere']['nb_gr_td'],
	        	'h_tp'=>$matiere['Matiere']['h_tp']*$matiere['Filiere']['nb_gr_tp']
	        );
			return $result;
			*/
			
			/* Méthode 3 : à l'aide d'une requête find all et d'une boucle */			
			}
        }

        function get_vol_horaire_attribue($id=null) {
			/*  Méthode 1 : à l'aide d'une vue SQL dans la base */
			$this->VueMatieresComblesBesoin =& ClassRegistry::init('VueMatieresComblesBesoin');
			$this->VueMatieresComblesBesoin->recursive=-1;
			$temp = $this->VueMatieresComblesBesoin->read(null, $id);
			//debug($temp);
			return $temp['VueMatieresComblesBesoin'];                
        }        
        
        function get_vol_horaire_restant($id=null) {
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