<?php
class PersosController extends AppController {

	var $name = 'Persos';
	var $helpers = array('Html', 'Form', 'Heures', 'Boolean');
	
	//var $scaffold;
	var $components = array('Auth', 'Session');
	
	function index() {
		$this->Perso->recursive = 0;
		$this->set('persos', $this->paginate());
	}
	
	function vol_horaire_attribue($perso) {
		//$perso=$this->find('all', array('conditions'=>'matiere_id='.$id_matiere));
		$result=array('h_cours'=>0, 'h_td'=>0, 'h_tp'=>0);
		foreach($perso['Matieres'] as $matiere) {
			//debug($matiere_perso);
        	$result['h_cours'] = $result['h_cours'] + $matiere['MatieresPerso']['h_cours'];
        	$result['h_td'] = $result['h_td'] + $matiere['MatieresPerso']['h_td'];
        	$result['h_tp'] = $result['h_tp'] + + $matiere['MatieresPerso']['h_tp'];
		}
		return $result;
	}
        
	function view($id = null) {
		if (!$id) {
			$this->Session->setFlash(__('Invalid Perso.', true));
			$this->redirect(array('action'=>'index'));
		}		

		$this->Perso->recursive = 0;
		$perso = $this->Perso->read(null, $id);
		$this->set('perso', $perso);
		
		$this->MatieresPerso =& ClassRegistry::init('MatieresPerso');
		$matieres_persos = $this->MatieresPerso->findByPerso($id);
		//debug($matieres_persos);
		$this->set('matieres_persos', $matieres_persos);
		
        //$this->set(compact('perso', 'matieres'));

        $this->Filiere =& ClassRegistry::init('Filiere');
        $filieres = $this->Filiere->find('list');
        $this->set('filieres', $filieres);
        
 		/* === Volume horaire total === */
		$vol_horaire_attribue = $this->Perso->getBilanService($id);
				
		$this->set('vol_horaire_total',
       		array(
       			'h_cours' => $vol_horaire_attribue['h_cours'],
       			'h_td' => $vol_horaire_attribue['h_td'],
       			'h_tp' => $vol_horaire_attribue['h_tp'],
       			)
       	);
	}

	function add() {
		if (!empty($this->data)) {
			$this->Perso->create();
			if ($this->Perso->save($this->data)) {
				$this->Session->setFlash(__('The Perso has been saved', true));
				$this->redirect(array('action'=>'index'));
			} else {
				$this->Session->setFlash(__('The Perso could not be saved. Please, try again.', true));
			}
		}
		$statuts = $this->Perso->Statut->find('list');
		$this->set(compact('statuts'));
	}

	function edit($id = null) {
		if (!$id && empty($this->data)) {
			$this->Session->setFlash(__('Invalid Perso', true));
			$this->redirect(array('action'=>'index'));
		}
		if (!empty($this->data)) {
			if ($this->Perso->save($this->data)) {
				$this->Session->setFlash(__('The Perso has been saved', true));
				$this->redirect(array('action'=>'index'));
			} else {
				$this->Session->setFlash(__('The Perso could not be saved. Please, try again.', true));
			}
		}
		if (empty($this->data)) {
			$this->data = $this->Perso->read(null, $id);
		}
		$statuts = $this->Perso->Statut->find('list');
		$this->set(compact('statuts'));
	}

	function delete($id = null) {
		if (!$id) {
			$this->Session->setFlash(__('Invalid id for Perso', true));
			$this->redirect(array('action'=>'index'));
		}
		if ($this->Perso->del($id)) {
			$this->Session->setFlash(__('Perso deleted', true));
			$this->redirect(array('action'=>'index'));
		}
	}
	
	function debug() {
		//debug($this->Perso->getBilanService(16));
		//debug($this->Perso->getBilanService());
		//debug($this->Perso->getBilanService('all'));
		//debug($this->Perso->getBilanService(null));
		
		$id=16;
		debug("<h1>getBilanServiceWithSqlView($id)</h1>");
		debug($this->Perso->getBilanServiceWithSqlView($id));
		debug("<h1>getBilanServiceWithSqlQuery($id)</h1>");
		debug($this->Perso->getBilanServiceWithSqlQuery($id));
		debug("<h1>getBilanServiceWithSqlQuery($id)</h1>");
		debug($this->Perso->getBilanServiceWithLoop($id));

		debug("<h1>getBilanServiceWithSqlView('all')</h1>");
		debug($this->Perso->getBilanServiceWithSqlView('all'));
		debug("<h1>getBilanServiceWithSqlQuery('all')</h1>");
		debug($this->Perso->getBilanServiceWithSqlQuery('all'));
		debug("<h1>getBilanServiceWithLoop('all')</h1>");
		debug($this->Perso->getBilanServiceWithLoop('all'));

		//exit();
	}

}
?>