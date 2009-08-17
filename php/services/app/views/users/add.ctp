<div class="users form">
<?php echo $form->create('User');?>
	<fieldset>
 		<legend><?php __('S\'inscrire');?></legend>
	<?php
		echo $form->input('username', array('label'=>__('Nom d\'utilisateur', true)));
		echo $form->input('password', array('type'=>'password', 'label'=>__('Mot de passe', true)));
		echo $form->input('password2', array('type'=>'password', 'label'=>__('Confirmation du mot de passe', true)));
		echo $form->input('group_id');
		echo $form->input('perso_id');
		echo $form->input('role');
	?>
	</fieldset>
<?php echo $form->end(__('Submit', true));?>
</div>
<div class="actions">
	<ul>
		<li><?php echo $html->link(__('List Users', true), array('action'=>'index'));?></li>
		<li><?php echo $html->link(__('List Groups', true), array('controller'=> 'groups', 'action'=>'index')); ?> </li>
		<li><?php echo $html->link(__('New Group', true), array('controller'=> 'groups', 'action'=>'add')); ?> </li>
	</ul>
</div>
