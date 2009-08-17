<div class="matieresPersos form">
<?php echo $form->create('MatieresPerso');?>
	<fieldset>
 		<legend><?php __('Ajouter Occupation');?></legend>
	<?php
		echo $form->input('perso_id');
		echo $form->input('matiere_id');
		echo $form->input('h_cours');
		echo $form->input('h_td');
		echo $form->input('h_tp');
	?>
	</fieldset>
<?php echo $form->end('Submit');?>
</div>
<div class="actions">
	<ul>
		<li><?php echo $html->link(__('Lister Occupations', true), array('action'=>'index'));?></li>
	</ul>
	<ul>
		<li><?php echo $html->link(__('Lister Persos', true), array('controller'=> 'persos', 'action'=>'index')); ?> </li>
		<li><?php echo $html->link(__('Nouveau Perso', true), array('controller'=> 'persos', 'action'=>'add')); ?> </li>
	</ul>
	<ul>
		<li><?php echo $html->link(__('Lister Matieres', true), array('controller'=> 'matieres', 'action'=>'index')); ?> </li>
		<li><?php echo $html->link(__('Nouvelle Matiere', true), array('controller'=> 'matieres', 'action'=>'add')); ?> </li>
	</ul>
</div>
