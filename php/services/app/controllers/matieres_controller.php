<?php
class MatieresController extends AppController {

	var $name = 'Matieres';
	var $helpers = array('Html', 'Form', 'Couleurs', 'Heures');

	var $components = array('Auth', 'Session');

	function index() {
		$this->Matiere->recursive = 0;
		$this->set('matieres', $this->paginate());
	}
	
	function view($id = null) {
		//echo $this->Matiere->test($id);
	
		if (!$id) {
			$this->Session->setFlash(__('Invalid Matiere.', true));
			$this->redirect(array('action'=>'index'));
		}
		$this->Matiere->recursive=0;
		$matiere = $this->Matiere->read(null, $id);
		//debug($matiere);
		$this->set('matiere', $matiere);

		$this->MatieresPerso =& ClassRegistry::init('MatieresPerso');
		$matieres_persos = $this->MatieresPerso->findByMatiere($id);
		//debug($matieres_persos);
		$this->set('matieres_persos', $matieres_persos);
		
        
		/* === Volume horaire total === */
		//$todo = array('h_cours'=>'ToDo', 'h_td'=>'ToDo', 'h_tp'=>'ToDo');	
		/* = Volume à attribuer = */		
		$vol_h_a_attribuer = $this->Matiere->get_vol_horaire_a_attribuer($id);
		/* = Volume attribue */
		$vol_h_attribue = $this->Matiere->get_vol_horaire_attribue($id);
		/* = Volume restant */
		$vol_h_restant=$this->Matiere->get_vol_horaire_restant($id);		
		
				
		$this->set('vol_horaire_total',
			array(
       			'a_effectuer'=>array(
       				'h_cours' => $vol_h_a_attribuer['h_cours'],
       				'h_td' => $vol_h_a_attribuer['h_td'],
       				'h_tp' => $vol_h_a_attribuer['h_tp'],
       				),
       			'attribue'=>array(
       				'h_cours' => $vol_h_attribue['h_cours'],
       				'h_td' => $vol_h_attribue['h_td'],
       				'h_tp' => $vol_h_attribue['h_tp'],
       				),
       			'restant'=>array(
       				'h_cours' => $vol_h_restant['h_cours'],
       				'h_td' => $vol_h_restant['h_td'],
       				'h_tp' => $vol_h_restant['h_tp'],
       				)
       			)
       	);
	}

	function add() {
		if (!empty($this->data)) {
			$this->Matiere->create();
			if ($this->Matiere->save($this->data)) {
				$this->Session->setFlash(__('The Matiere has been saved', true));
				$this->redirect(array('action'=>'index'));
			} else {
				$this->Session->setFlash(__('The Matiere could not be saved. Please, try again.', true));
			}
		}
		
		if (isset($this->passedArgs['filiere'])) {
			$this->data['Matiere']['filiere_id']=$this->passedArgs['filiere'];
		}
		
		
		$filieres = $this->Matiere->Filiere->find('list');
		$this->set(compact('filieres'));
	}

	function edit($id = null) {
		if (!$id && empty($this->data)) {
			$this->Session->setFlash(__('Invalid Matiere', true));
			$this->redirect(array('action'=>'index'));
		}
		if (!empty($this->data)) {
			if ($this->Matiere->save($this->data)) {
				$this->Session->setFlash(__('The Matiere has been saved', true));
				$this->redirect(array('action'=>'index'));
			} else {
				$this->Session->setFlash(__('The Matiere could not be saved. Please, try again.', true));
			}
		}
		if (empty($this->data)) {
			$this->data = $this->Matiere->read(null, $id);
		}
		$filieres = $this->Matiere->Filiere->find('list');
		$this->set(compact('filieres'));
	}

	function delete($id = null) {
		if (!$id) {
			$this->Session->setFlash(__('Invalid id for Matiere', true));
			$this->redirect(array('action'=>'index'));
		}
		if ($this->Matiere->del($id)) {
			$this->Session->setFlash(__('Matiere deleted', true));
			$this->redirect(array('action'=>'index'));
		}
	}
	
	/* ====== */
	/*
	function besoins_totaux() {
		$this->Matiere->recursive = 0;
		$this->set('matieres', $this->Matiere->find('list'));
    }
    */
    
    
    /*
    function test() {
    	//debug("the test");
    	debug($this->Matiere->test());
    }
	*/
}
?>