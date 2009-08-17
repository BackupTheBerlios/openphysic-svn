<div class="matieres form">
<?php echo $form->create('Matiere');?>
	<fieldset>
 		<legend><?php __('Editer Matiere');?></legend>
	<?php
		echo $form->input('id');
		echo $form->input('name');
		echo $form->input('h_cours');
		echo $form->input('h_td');
		echo $form->input('h_tp');
		echo $form->input('filiere_id');
		echo $form->input('commentaire');
	?>
	</fieldset>
<?php echo $form->end('Submit');?>
</div>
<div class="actions">
	<ul>
		<li><?php echo $html->link(__('Supprimer', true), array('action'=>'delete', $form->value('Matiere.id')), null, sprintf(__('Are you sure you want to delete # %s?', true), $form->value('Matiere.id'))); ?></li>
		<li><?php echo $html->link(__('Lister Matieres', true), array('action'=>'index'));?></li>
	</ul>
	<ul>
		<li><?php echo $html->link(__('Lister Filieres', true), array('controller'=> 'filieres', 'action'=>'index')); ?> </li>
		<li><?php echo $html->link(__('Nouvelle Filiere', true), array('controller'=> 'filieres', 'action'=>'add')); ?> </li>
	</ul>
	<ul>
		<li><?php echo $html->link(__('Lister Occupations', true), array('controller'=> 'matieres_persos', 'action'=>'index')); ?> </li>
		<li><?php echo $html->link(__('Nouvelle Occupation', true), array('controller'=> 'matieres_persos', 'action'=>'add')); ?> </li>
	</ul>
</div>
