<?php
class AppController extends Controller {
	var $components = array('Auth', 'Session');
	
	function beforeFilter() {
		$this->Auth->allow(''); // ToFix
		
		//debug("beforeFilter");
		//exit();
		
		$this->Auth->loginAction = array('controller'=>'users','action'=>'login');
		
		//$this->Auth->recursive = 0;
		//$loggeduser = $this->Auth->user();

		$id = $this->Auth->user('id');
		$this->set('loggedIn', $id);

		//debug($this->Auth);

		$this->User =& ClassRegistry::init('User');
		$this->User->recursive = 0;
		$loggeduser = $this->User->read(null, $id);

		//$this->LoggedUser =& ClassRegistry::init('User');
		//$this->LoggedUser->recursive = 0;
		//$loggeduser = $this->LoggedUser->read(null, $id);

		$this->set('loggeduser', $loggeduser);		
	}
}
?>
