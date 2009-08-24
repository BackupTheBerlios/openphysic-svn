<div class="users form">
<?php echo $form->create('User');?>
	<fieldset>
 		<legend><?php __('Editer un utilisateur');?></legend>
	<?php
		echo $form->input('id');
		echo $form->input('username', array('label'=>__('Username', true)));
		echo $form->input('password', array('type'=>'password', 'label'=>__('Password', true)));
		echo $form->input('password2', array('type'=>'password', 'label'=>__('Confirm password', true)));
		echo $form->input('group_id');
		echo $form->input('perso_id');
		echo $form->input('role');
	?>
	</fieldset>
<?php echo $form->end('Submit');?>
</div>
<div class="actions">
	<ul>
		<li><?php echo $html->link(__('Supprimer', true), array('action'=>'delete', $form->value('User.id')), null, sprintf(__('Êtes-vous sûr de vouloir supprimer l\'utilisateur # %s ?', true), $form->value('User.id'))); ?></li>
		<li><?php echo $html->link(__('Lister les utilisateurs', true), array('action'=>'index'));?></li>
	</ul>
	<ul>
		<li><?php echo $html->link(__('Lister les groupes d\'utilisateurs', true), array('controller'=> 'groups', 'action'=>'index')); ?> </li>
		<li><?php echo $html->link(__('Nouveau groupe d\'utilisateurs', true), array('controller'=> 'groups', 'action'=>'add')); ?> </li>
	</ul>
</div>
