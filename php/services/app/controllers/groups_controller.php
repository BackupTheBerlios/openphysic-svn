<?php
class GroupsController extends AppController {

	var $name = 'Groups';
	var $helpers = array('Html', 'Form', 'Password');
	var $components = array('Auth', 'Session');

	function index() {
		$this->Group->recursive = 0;
		$this->set('groups', $this->paginate());
	}

	function view($id = null) {
		if (!$id) {
			$this->Session->setFlash(__('Groupe invalide', true));
			$this->redirect(array('action'=>'index'));
		}
		$this->set('group', $this->Group->read(null, $id));
	}

	function add() {
		if (!empty($this->data)) {
			$this->Group->create();
			if ($this->Group->save($this->data)) {
				$this->Session->setFlash(__('Le groupe a été sauvegardé', true));
				$this->redirect(array('action'=>'index'));
			} else {
				$this->Session->setFlash(__('Le groupe n\'a pas pu être sauvegardé. Veuillez réessayer, merci.', true));
			}
		}
	}

	function edit($id = null) {
		if (!$id && empty($this->data)) {
			$this->Session->setFlash(__('Groupe invalide', true));
			$this->redirect(array('action'=>'index'));
		}
		if (!empty($this->data)) {
			if ($this->Group->save($this->data)) {
				$this->Session->setFlash(__('Le groupe a été sauvegardé', true));
				$this->redirect(array('action'=>'index'));
			} else {
				$this->Session->setFlash(__('Le groupe n\'a pas pu être sauvegardé. Veuillez réessayer, merci.', true));
			}
		}
		if (empty($this->data)) {
			$this->data = $this->Group->read(null, $id);
		}
	}

	function delete($id = null) {
		if (!$id) {
			$this->Session->setFlash(__('Groupe invalide', true));
			$this->redirect(array('action'=>'index'));
		}
		if ($this->Group->del($id)) {
			$this->Session->setFlash(__('Groupe supprimé', true));
			$this->redirect(array('action'=>'index'));
		}
	}

}
?>