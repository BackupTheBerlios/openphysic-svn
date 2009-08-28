<?php
class UsersController extends AppController {

	var $name = 'Users';
	var $helpers = array('Html', 'Form', 'Password', 'People');
	var $components = array('Auth', 'Session');
	
	/*
	function beforeFilter() {
        // Login failed. Invalid username or password.
		//$this->Auth->loginError = 'Connexion échouée. Nom d\'utilisateur ou mot de passe incorrect.';
		// You are not authorized to access that location.
		//$this->Auth->authError = 'Vous n\'&ecirc;tes pas autorisé à accéder à cette page.';

		//$this->Auth->allow('*','about');

		//$this->Auth->allow('login');
		
		$this->Auth->allow('login', 'logout');

		$this->Auth->loginRedirect = array('controller' => 'filieres', 'action' => 'index');
		//$this->Auth->loginRedirect = array('controller' => 'persos', 'action' => 'view', 16); // vers fiche de service
		
		$this->Auth->logoutRedirect  = array('controller' => 'users', 'action' => 'login');
		

	}
	*/

	function login() {
		
		//$this->set('my_password',$this->Auth->password("admin"));
		//$this->set('my_password',$this->Auth->password($this->data['User']['password']));
		
		//$this->redirect($this->Auth->login());
	}
	
	function logout() {
		$this->Session->setFlash('Au revoir !'); 

		//$this->Session->delete('User');
		//$this->Session->destroy();

		$this->redirect($this->Auth->logout());
	}
	
	/* fonction pour calculer le hash d'un mot de passe */
	/* attention le hash dépend du sel défini dans app/config/core.php */
	/* http://localhost:8888/services/users/pwd/ */
	/* admin/admin user/user */
	/*
	function pwd($p=null) {
		debug($this->Auth->password($p));
	}
	*/

	function index() {
		$this->User->recursive = 0;
		$this->set('users', $this->paginate());
	}

	function view($id = null) {
		if (!$id) {
			$this->Session->setFlash(__('Utilisateur invalide.', true));
			$this->redirect(array('action'=>'index'));
		}
		$this->User->recursive = 0;
		$user=$this->User->read(null, $id);
		$this->set('user', $user);
	}

	function add() {
		if (!empty($this->data)) {
			if ( $this->data['User']['password']==$this->Auth->password($this->data['User']['password2']) ) {
				$this->User->create();
				if ($this->User->save($this->data)) {
					$this->Session->setFlash(__('L\'utilisateur a été sauvegardé', true));
					$this->redirect(array('action'=>'index'));
				} else {
					$this->Session->setFlash(__('L\'utilisateur n\'a pas pu être sauvegardé. Veuillez réessayer, merci.', true));
				}
			} else {
				$this->Session->setFlash(__('Le mot de passe n\'a pas été confirmé correctement.', true));
				$this->data['User']['password'] = '';
				$this->data['User']['password2'] = '';
			}
		} else {
			$this->data['User']['perso_id'] = 0;
		}
		
		$groups = $this->User->Group->find('list');
		$this->set(compact('groups'));
	}
	
	function edit($id = null) {
		if (!$id && empty($this->data)) {
			$this->Session->setFlash(__('Utilisateur invalide.', true));
			$this->redirect(array('action'=>'index'));
		}
		if (!empty($this->data)) {
			if ( $this->data['User']['password']==$this->Auth->password($this->data['User']['password2']) ) {
				if ($this->User->save($this->data)) {
					$this->Session->setFlash(__('L\'utilisateur a été sauvegardé', true));
					$this->redirect(array('action'=>'view', $id));
				} else {
					$this->Session->setFlash(__('L\'utilisateur n\'a pas pu être sauvegardé. Veuillez réessayer, merci.', true));
				}
			} else {
				$this->Session->setFlash(__('Le mot de passe n\'a pas été confirmé correctement.', true));
				$this->redirect(array('action'=>'edit', $id));
			}
		}
		if (empty($this->data)) {
			$this->data = $this->User->read(null, $id);
		}

		$this->data['User']['password'] = '';
		$this->data['User']['password2'] = '';
		
		$groups = $this->User->Group->find('list');
		$this->set(compact('groups'));
	}
	
	function change_password($id = null) { // attention il faut préciser dans la vue $form->create('User', array('action' => 'change_password'))
		if (!$id && empty($this->data)) {
			$this->Session->setFlash(__('Utilisateur invalide.', true));
			$this->redirect(array('action'=>'index'));
		}
		if (!empty($this->data)) {
			if ( $this->data['User']['password']==$this->data['User']['password2'] ) {
				$this->data['User']['password'] = Security::hash($this->data['User']['password'], null, true);
				if ($this->User->save($this->data)) {
					$this->Session->setFlash(__('Le mot de passe utilisateur a été sauvegardé', true));
					$this->redirect(array('action'=>'view', $id));
				} else {
					$this->Session->setFlash(__('Le mot de passe n\'a pas pu être sauvegardé. Veuillez réessayer, merci.', true));
				}
			} else {
				$this->Session->setFlash(__('Le mot de passe n\'a pas été confirmé correctement.', true));
				$this->redirect(array('action'=>'change_password', $id));
			}
		}
		if (empty($this->data)) {
			$this->data = $this->User->read(null, $id);
		}

		$this->data['User']['password'] = '';
		$this->data['User']['password2'] = '';
		
		$groups = $this->User->Group->find('list');
		$this->set(compact('groups'));
	}

	function delete($id = null) {
		if (!$id) {
			$this->Session->setFlash(__('Utilisateur invalide.', true));
			$this->redirect(array('action'=>'index'));
		}
		if ($this->User->del($id)) {
			$this->Session->setFlash(__('Utilisateur supprimé', true));
			$this->redirect(array('action'=>'index'));
		}
	}
	
	function reset_password($id = null) {
		if (!$id) {
			$this->Session->setFlash(__('Utilisateur invalide.', true));
			$this->redirect(array('action'=>'index'));
		}
		$this->User->recursive = -1;
		$user=$this->User->read(null, $id);
		
		$password='123';
		$user['User']['password']=$password;
		$user=$this->Auth->hashPasswords($user); // necessite un champ username et un champ password pour que la 'magie' de CakePHP fonctionne
		
		//$user['User']['password'] = Security::hash('123', null, true);

		if ( $this->User->save($user) ) {
			$this->Session->setFlash(__(sprintf("Mot de passe initialisé à '%s'. Merci de le modifier.", $password), true));
		} else {
			$this->Session->setFlash(__('zLe mot de passe n\'a pas été modifié', true));		
		}

		$this->redirect(array('action'=>'view', $id));		
	}

}
?>