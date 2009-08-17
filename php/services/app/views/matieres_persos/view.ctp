<div class="matieresPersos view">
<h2><?php  __('Occupation');?></h2>
	<dl><?php $i = 0; $class = ' class="altrow"';?>
		<dt<?php if ($i % 2 == 0) echo $class;?>><?php __('Id'); ?></dt>
		<dd<?php if ($i++ % 2 == 0) echo $class;?>>
			<?php echo $matieresPerso['MatieresPerso']['id']; ?>
			&nbsp;
		</dd>
		<dt<?php if ($i % 2 == 0) echo $class;?>><?php __('Perso'); ?></dt>
		<dd<?php if ($i++ % 2 == 0) echo $class;?>>
			<?php echo $html->link($matieresPerso['Perso']['initiales'], array('controller'=> 'persos', 'action'=>'view', $matieresPerso['Perso']['id'])); ?>
			&nbsp;
		</dd>
		<dt<?php if ($i % 2 == 0) echo $class;?>><?php __('Matiere'); ?></dt>
		<dd<?php if ($i++ % 2 == 0) echo $class;?>>
			<?php echo $html->link($matieresPerso['Matiere']['name'], array('controller'=> 'matieres', 'action'=>'view', $matieresPerso['Matiere']['id'])); ?>
			&nbsp;
		</dd>
		<dt<?php if ($i % 2 == 0) echo $class;?>><?php __('H Cours'); ?></dt>
		<dd<?php if ($i++ % 2 == 0) echo $class;?>>
			<?php echo $matieresPerso['MatieresPerso']['h_cours']; ?>
			&nbsp;
		</dd>
		<dt<?php if ($i % 2 == 0) echo $class;?>><?php __('H Td'); ?></dt>
		<dd<?php if ($i++ % 2 == 0) echo $class;?>>
			<?php echo $matieresPerso['MatieresPerso']['h_td']; ?>
			&nbsp;
		</dd>
		<dt<?php if ($i % 2 == 0) echo $class;?>><?php __('H Tp'); ?></dt>
		<dd<?php if ($i++ % 2 == 0) echo $class;?>>
			<?php echo $matieresPerso['MatieresPerso']['h_tp']; ?>
			&nbsp;
		</dd>
	</dl>
</div>
<div class="actions">
	<ul>
		<li><?php echo $html->link(__('Editer Occupation', true), array('action'=>'edit', $matieresPerso['MatieresPerso']['id'])); ?> </li>
		<li><?php echo $html->link(__('Lister Occupations', true), array('action'=>'index')); ?> </li>
		<li><?php echo $html->link(__('Nouvelle Occupation', true), array('action'=>'add')); ?> </li>
		<li><?php echo $html->link(__('Supprimer Occupation', true), array('action'=>'delete', $matieresPerso['MatieresPerso']['id']), null, sprintf(__('Are you sure you want to delete # %s?', true), $matieresPerso['MatieresPerso']['id'])); ?> </li>
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
