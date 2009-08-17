<?php
class FilieresController extends AppController {

	var $name = 'Filieres';
	var $helpers = array('Html', 'Form', 'Couleurs', 'Heures');
	
	var $components = array('Auth', 'Session');

	function index() {
		//debug($this->Auth->user());
		
		//if (!empty($this->data) && $this->Auth->user('id')) {
		$this->Filiere->recursive = 0;
		$this->set('filieres', $this->paginate());
		//}
	}

	function view($id = null) {
		if (!$id) {
			$this->Session->setFlash(__('Invalid Filiere.', true));
			$this->redirect(array('action'=>'index'));
		}
		$this->Filiere->recursive = 2;
		$this->set('filiere', $this->Filiere->read(null, $id));
		
		
		/* === Volume horaire total === */
		//$this->Matiere =& ClassRegistry::init('Matiere');
		//$this->Matiere->get_vol_horaire_a_attribuer();
		
		$this->set('vol_horaire_total',
       		array(
       			'h_cours' => 'x h_cours',
       			'h_td' => 'x h_td',
       			'h_tp' => 'x h_tp',
       			'h_tot' => 'x h_tot',
       			'h_eq_td' => 'x h_eq_td'        			
       			)
       	);
		
	}

	function add() {
		if (!empty($this->data)) {
			$this->Filiere->create();
			if ($this->Filiere->save($this->data)) {
				$this->Session->setFlash(__('The Filiere has been saved', true));
				$this->redirect(array('action'=>'index'));
			} else {
				$this->Session->setFlash(__('The Filiere could not be saved. Please, try again.', true));
			}
		}
	}

	function edit($id = null) {
		if (!$id && empty($this->data)) {
			$this->Session->setFlash(__('Invalid Filiere', true));
			$this->redirect(array('action'=>'index'));
		}
		if (!empty($this->data)) {
			if ($this->Filiere->save($this->data)) {
				$this->Session->setFlash(__('The Filiere has been saved', true));
				$this->redirect(array('action'=>'index'));
			} else {
				$this->Session->setFlash(__('The Filiere could not be saved. Please, try again.', true));
			}
		}
		if (empty($this->data)) {
			$this->data = $this->Filiere->read(null, $id);
		}
	}

	function delete($id = null) {
		if (!$id) {
			$this->Session->setFlash(__('Invalid id for Filiere', true));
			$this->redirect(array('action'=>'index'));
		}
		if ($this->Filiere->del($id)) {
			$this->Session->setFlash(__('Filiere deleted', true));
			$this->redirect(array('action'=>'index'));
		}
	}

}
?>