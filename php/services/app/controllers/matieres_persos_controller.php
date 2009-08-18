<?php
class MatieresPersosController extends AppController {

	var $name = 'MatieresPersos';
	var $helpers = array('Html', 'Form');

	var $components = array('Auth', 'Session');

	function index() {
		$this->MatieresPerso->recursive = 0;
		$this->set('matieresPersos', $this->paginate());
	}

	function view($id = null) {		
		if (!$id) {
			$this->Session->setFlash(__('Occupation Invalide', true));
			$this->redirect(array('action'=>'index'));
		}
		$this->set('matieresPerso', $this->MatieresPerso->read(null, $id));
		
		//debug($this->MatieresPerso->vol_horaire_attribue($this->MatieresPerso->data['Matiere']['id']));

	}

	function add() {	
		if (!empty($this->data)) {
			$this->MatieresPerso->create();
			if ($this->MatieresPerso->save($this->data)) {
				$this->Session->setFlash(__('The MatieresPerso has been saved', true));
				
				
				//debug($this->data);
				
				//$this->redirect(array('action'=>'index'));
				
				$this->redirect(array('controller'=>'matieres', 'action'=>'view', $this->data['MatieresPerso']['matiere_id']));
				
				//$this->redirect($this->referer());

				/*
				if (isset($this->passedArgs['perso'])) {
					$this->redirect(array('controller'=>'persos', 'action'=>'view'), $this->passedArgs['perso']);
				}
		
				if (isset($this->passedArgs['matiere'])) {
					$this->redirect(array('controller'=>'matieres', 'action'=>'view'), $this->passedArgs['matiere']);				
				}
				*/
				
				
				//$this->referer()
			} else {
				$this->Session->setFlash(__('The MatieresPerso could not be saved. Please, try again.', true));
			}
		
		}
		
		if (isset($this->passedArgs['perso'])) {
			//echo 'perso='.$this->passedArgs['perso'].'<br/>';
			//$conditionsPersos='id='.$this->passedArgs['perso'];
			$this->data['MatieresPerso']['perso_id']=$this->passedArgs['perso'];
		}
		
		if (isset($this->passedArgs['matiere'])) {
			//echo 'matiere='.$this->passedArgs['matiere'].'<br/>';
			//$conditionsMatieres=$conditionsMatieres.' and '.'id='.$this->passedArgs['matiere'];
			$this->data['MatieresPerso']['matiere_id']=$this->passedArgs['matiere'];			
		}
		
		$this->data['MatieresPerso']['h_cours']=0;
		$this->data['MatieresPerso']['h_td']=0;
		$this->data['MatieresPerso']['h_tp']=0;
		
		$conditionsMatieres='';
		if (isset($this->passedArgs['filiere'])) {
			//echo 'filiere='.$this->passedArgs['filiere'].'<br/>';
			$conditionsMatieres='filiere_id='.$this->passedArgs['filiere'];
		}

		
		//$this->data=$this->MatieresPerso->create();
		//debug($this->data);
		
		//$this->MatieresPerso->_schema['h_cours']=14;
		//$this->data=$this->MatieresPerso;
		
		//$this->data=array('h_cours'=>14);
				
		//$matieres = $this->MatieresPerso->Matiere->find('list');
		$persos = $this->MatieresPerso->Perso->find('list');
		//$persos = $this->MatieresPerso->Perso->find('all', array('recursive'=>-1) );
		$matieres = $this->MatieresPerso->Matiere->find('list', array('conditions'=>$conditionsMatieres) );
		$this->set(compact('persos', 'matieres'));
		
		//debug($this->MatieresPerso);
		
		//$this->redirect(array('action'=>'index'));
	}

	function edit($id = null) {
		if (!$id && empty($this->data)) {
			$this->Session->setFlash(__('Occupation Invalide', true));
			$this->redirect(array('action'=>'index'));
		}
		if (!empty($this->data)) {
			if ($this->MatieresPerso->save($this->data)) {
				$this->Session->setFlash(__('The MatieresPerso has been saved', true));
				//$this->redirect(array('action'=>'index'));
				$this->redirect(array('controller'=>'matieres', 'action'=>'view', $this->data['MatieresPerso']['matiere_id']));
			} else {
				$this->Session->setFlash(__('The MatieresPerso could not be saved. Please, try again.', true));
			}
		}
		if (empty($this->data)) {
			$this->data = $this->MatieresPerso->read(null, $id);
		}
		$persos = $this->MatieresPerso->Perso->find('list');
		//$persos = $this->MatieresPerso->Perso->find('all', array('recursive'=>-1) );
		$matieres = $this->MatieresPerso->Matiere->find('list');
		$this->set(compact('persos','matieres'));
	}

	function delete($id = null) {
		if (!$id) {
			$this->Session->setFlash(__('Invalid id for MatieresPerso', true));
			$this->redirect(array('action'=>'index'));
		}
		if ($this->MatieresPerso->del($id)) {
			$this->Session->setFlash(__('MatieresPerso deleted', true));
			
			//$this->redirect(array('action'=>'index'));
			
			//$this->redirect(array('controller'=>'matiere', 'action'=>'index', ... ));
			
			$this->redirect($this->referer());

		}
	}

}
?>