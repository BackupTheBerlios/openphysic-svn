<div class="statuts form">
<?php echo $form->create('Statut');?>
	<fieldset>
 		<legend><?php __('Editer Statut');?></legend>
	<?php
		echo $form->input('id');
		echo $form->input('nom');
		echo $form->input('h_statut');
		echo $form->input('h_sup_max');
	?>
	</fieldset>
<?php echo $form->end('Submit');?>
</div>
<div class="actions">
	<ul>
		<li><?php echo $html->link(__('Supprimer', true), array('action'=>'delete', $form->value('Statut.id')), null, sprintf(__('Are you sure you want to delete # %s?', true), $form->value('Statut.id'))); ?></li>
		<li><?php echo $html->link(__('Lister Statuts', true), array('action'=>'index'));?></li>
	</ul>
	<ul>
		<li><?php echo $html->link(__('Lister Persos', true), array('controller'=> 'persos', 'action'=>'index')); ?> </li>
		<li><?php echo $html->link(__('Nouveau Perso', true), array('controller'=> 'persos', 'action'=>'add')); ?> </li>
	</ul>
</div>
