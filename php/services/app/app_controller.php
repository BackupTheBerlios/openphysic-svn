<?php
class AppController extends Controller {
	var $components = array('Auth', 'Session');
	
	function beforeFilter() {
		$this->Auth->allow(''); // ToFix
		
		$this->Auth->loginAction = array('controller'=>'users','action'=>'login');
		
		$id = $this->Auth->user('id');
		$this->set('loggedIn', $id);
		$this->User =& ClassRegistry::init('User');
		$this->User->recursive = 0;
		$user = $this->User->read(null, $id);
		$this->set('user', $user);		
	}
}
?>