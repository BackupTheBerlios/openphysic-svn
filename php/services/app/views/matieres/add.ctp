<div class="matieres form">
<?php echo $form->create('Matiere');?>
	<fieldset>
 		<legend><?php __('Ajouter Matiere');?></legend>
	<?php
		echo $form->input('filiere_id');
		echo $form->input('name');
		echo $form->input('h_cours');
		echo $form->input('h_td');
		echo $form->input('h_tp');
		echo $form->input('commentaire');
	?>
	</fieldset>
<?php echo $form->end(__('Submit', true));?>
</div>
<div class="actions">
	<ul>
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
