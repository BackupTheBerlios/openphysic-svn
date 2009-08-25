<div class="users form">
<?php echo $form->create('User');?>
	<fieldset>
 		<legend><?php __('Modifiez le mot de passe');?></legend>


	<dl><?php $i = 0; $class = ' class="altrow"';?>
		<dt<?php if ($i % 2 == 0) echo $class;?>><?php __("Id"); ?></dt>
		<dd<?php if ($i++ % 2 == 0) echo $class;?>>
			<?php echo $this->data['User']['id']; ?>
			&nbsp;
		</dd>

		<dt<?php if ($i % 2 == 0) echo $class;?>><?php __("Nom d'utilisateur"); ?></dt>
		<dd<?php if ($i++ % 2 == 0) echo $class;?>>
			<?php echo $this->data['User']['username']; ?>
			&nbsp;
		</dd>

	<?php
	
		echo $form->input('password', array('type'=>'password', 'label'=>__('Mot de passe', true)));
		echo $form->input('password2', array('type'=>'password', 'label'=>__('Confirmer le mot de passe', true)));
	?>

		<dt<?php if ($i % 2 == 0) echo $class;?>><?php __("Groupe"); ?></dt>
		<dd<?php if ($i++ % 2 == 0) echo $class;?>>
			<?php echo $this->data['Group']['name']; ?>
			&nbsp;
		</dd>
	
	</dl>

	</fieldset>
<?php echo $form->end(__('Submit',true));?>
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
