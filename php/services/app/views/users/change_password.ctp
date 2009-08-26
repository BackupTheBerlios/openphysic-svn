<div class="users form">

<?php echo $form->create('User');?>
	<fieldset>
 		<legend><?php __('Modifiez le mot de passe');?></legend>


	<dl><?php $i = 0; $class = ' class="altrow"';?>
		<dt<?php if ($i % 2 == 0) echo $class;?>><?php __("Id"); ?></dt>
		<dd<?php if ($i++ % 2 == 0) echo $class;?>>
			<?php echo $user['User']['id']; ?>
			&nbsp;
		</dd>

		<dt<?php if ($i % 2 == 0) echo $class;?>><?php __("Nom d'utilisateur"); ?></dt>
		<dd<?php if ($i++ % 2 == 0) echo $class;?>>
			<?php echo $html->link($user['User']['username'], array('controller'=>'users', 'action'=>'view', $user['User']['id'])); ?>
			&nbsp;
		</dd>

	<?php
	
		echo $form->input('password', array('type'=>'password', 'label'=>__('Mot de passe', true)));
		echo $form->input('password2', array('type'=>'password', 'label'=>__('Confirmer le mot de passe', true)));
	?>

		<dt<?php if ($i % 2 == 0) echo $class;?>><?php __("Groupe"); ?></dt>
		<dd<?php if ($i++ % 2 == 0) echo $class;?>>
			<?php echo $html->link($user['Group']['name'], array('controller'=>'groups', 'action'=>'view', $user['Group']['id'])); ?>
			&nbsp;
		</dd>
	
	</dl>

	</fieldset>
<?php echo $form->end(__('Submit',true));?>
</div>

