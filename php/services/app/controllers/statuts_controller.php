<?php
class StatutsController extends AppController {

	var $name = 'Statuts';
	var $helpers = array('Html', 'Form', 'Boolean');

	var $components = array('Auth', 'Session');

	function index() {
		$this->Statut->recursive = 0;
		$this->set('statuts', $this->paginate());
	}

	function view($id = null) {
		if (!$id) {
			$this->Session->setFlash(__('Invalid Statut.', true));
			$this->redirect(array('action'=>'index'));
		}
		$this->set('statut', $this->Statut->read(null, $id));
	}

	function add() {
		if (!empty($this->data)) {
			$this->Statut->create();
			if ($this->Statut->save($this->data)) {
				$this->Session->setFlash(__('The Statut has been saved', true));
				$this->redirect(array('action'=>'index'));
			} else {
				$this->Session->setFlash(__('The Statut could not be saved. Please, try again.', true));
			}
		}
	}

	function edit($id = null) {
		if (!$id && empty($this->data)) {
			$this->Session->setFlash(__('Invalid Statut', true));
			$this->redirect(array('action'=>'index'));
		}
		if (!empty($this->data)) {
			if ($this->Statut->save($this->data)) {
				$this->Session->setFlash(__('The Statut has been saved', true));
				$this->redirect(array('action'=>'index'));
			} else {
				$this->Session->setFlash(__('The Statut could not be saved. Please, try again.', true));
			}
		}
		if (empty($this->data)) {
			$this->data = $this->Statut->read(null, $id);
		}
	}

	function delete($id = null) {
		if (!$id) {
			$this->Session->setFlash(__('Invalid id for Statut', true));
			$this->redirect(array('action'=>'index'));
		}
		if ($this->Statut->del($id)) {
			$this->Session->setFlash(__('Statut deleted', true));
			$this->redirect(array('action'=>'index'));
		}
	}

}
?>