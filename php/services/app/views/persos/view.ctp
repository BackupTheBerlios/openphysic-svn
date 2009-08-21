<div class="persos view">
<h2><?php  __('Bilan de service prévisionnel d\'un personnel');?></h2>
	<dl><?php $i = 0; $class = ' class="altrow"';?>
		<dt<?php if ($i % 2 == 0) echo $class;?>><?php __('Id'); ?></dt>
		<dd<?php if ($i++ % 2 == 0) echo $class;?>>
			<?php echo $perso['Perso']['id']; ?>
			&nbsp;
		</dd>
		<dt<?php if ($i % 2 == 0) echo $class;?>><?php __('Initiales'); ?></dt>
		<dd<?php if ($i++ % 2 == 0) echo $class;?>>
			<?php echo $perso['Perso']['initiales']; ?>
			&nbsp;
		</dd>
		<dt<?php if ($i % 2 == 0) echo $class;?>><?php __('Nom'); ?></dt>
		<dd<?php if ($i++ % 2 == 0) echo $class;?>>
			<?php echo $perso['Perso']['nom']; ?>
			&nbsp;
		</dd>
		<dt<?php if ($i % 2 == 0) echo $class;?>><?php __('Prenom'); ?></dt>
		<dd<?php if ($i++ % 2 == 0) echo $class;?>>
			<?php echo $perso['Perso']['prenom']; ?>
			&nbsp;
		</dd>
		<dt<?php if ($i % 2 == 0) echo $class;?>><?php __('Statut'); ?></dt>
		<dd<?php if ($i++ % 2 == 0) echo $class;?>>
			<?php echo $html->link($perso['Statut']['nom'], array('controller'=> 'statuts', 'action'=>'view', $perso['Statut']['id'])); ?>
			&nbsp;
		</dd>
		<dt<?php if ($i % 2 == 0) echo $class;?>><?php __('Permanent'); ?></dt>
		<dd<?php if ($i++ % 2 == 0) echo $class;?>>
			<?php echo $boolean->yes_no( $perso['Perso']['permanent'] ); ?>
			&nbsp;
		</dd>
	</dl>
</div>
<div class="actions">
	<ul>
		<li><?php echo $html->link(__('Editer Perso', true), array('action'=>'edit', $perso['Perso']['id'])); ?> </li>
		<li><?php echo $html->link(__('Lister Persos', true), array('action'=>'index')); ?> </li>
		<li><?php echo $html->link(__('Nouveau Perso', true), array('action'=>'add')); ?> </li>
		<li><?php echo $html->link(__('Supprimer Perso', true), array('action'=>'delete', $perso['Perso']['id']), null, sprintf(__('Are you sure you want to delete # %s?', true), $perso['Perso']['id'])); ?> </li>
	</ul>
	<ul>
		<li><?php echo $html->link(__('Lister Statuts', true), array('controller'=> 'statuts', 'action'=>'index')); ?> </li>
		<li><?php echo $html->link(__('Nouveau Statut', true), array('controller'=> 'statuts', 'action'=>'add')); ?> </li>
	</ul>
</div>
<div class="related">
	<h3><?php __('Service de ce personnel');?></h3>
	<?php if (!empty($matieres_persos)):?>
	<table cellpadding = "0" cellspacing = "0">
	<tr>
		<th><?php __('Id'); ?></th>
		<th><?php __('Filière'); ?></th>		
		<th><?php __('Matière'); ?></th>
		<th width="8%"><?php __('H Cours'); ?></th>
		<th width="8%"><?php __('H Td'); ?></th>
		<th width="8%"><?php __('H Tp'); ?></th>
		<th class="actions"><?php __('Actions');?></th>
	</tr>
	<?php
		$i = 0;
		foreach ($matieres_persos as $matierePerso):
			$class = null;
			if ($i++ % 2 == 0) {
				$class = ' class="altrow"';
			}
		?>
		<tr<?php echo $class;?>>
			<td><?php echo $matierePerso['MatieresPerso']['id'];?></td>
			<td><?php echo $html->link($filieres[$matierePerso['Matiere']['filiere_id']], array('controller'=>'filieres', 'action'=>'view', $matierePerso['Matiere']['filiere_id'])); ?></td>
			<td><?php echo $html->link($matierePerso['Matiere']['name'], array('controller'=>'matieres', 'action'=>'view', $matierePerso['Matiere']['id'])); ?></td>
			<td><?php echo $matierePerso['MatieresPerso']['h_cours'];?></td>
			<td><?php echo $matierePerso['MatieresPerso']['h_td'];?></td>
			<td><?php echo $matierePerso['MatieresPerso']['h_tp'];?></td>
			<td class="actions">
				<?php echo $html->link(__('View', true), array('controller'=> 'matieres_persos', 'action'=>'view', $matierePerso['MatieresPerso']['id'])); ?>
				<?php echo $html->link(__('Edit', true), array('controller'=> 'matieres_persos', 'action'=>'edit', $matierePerso['MatieresPerso']['id'])); ?>
				<?php echo $html->link(__('Delete', true), array('controller'=> 'matieres_persos', 'action'=>'delete', $matierePerso['MatieresPerso']['id']), null, sprintf(__('Are you sure you want to delete # %s?', true), $matierePerso['MatieresPerso']['id'])); ?>
			</td>
		</tr>
	<?php endforeach; ?>
	</table>
<?php endif; ?>

	<div class="actions">
		<ul>
			<li><?php echo $html->link(__('Nouvelle Occupation', true), array('controller'=> 'matieres_persos', 'action'=>'add', 'perso' => $perso['Perso']['id']));?> </li>
		</ul>
	</div>
</div>

<div class="vol_horaire_total">
<h3>Volume horaire total</h3>
		<table cellpadding = "0" cellspacing = "0">
		<tr>
			<th width="16%">&nbsp;</th>
			<th width="16%">H Cours</th>
			<th width="16%">H Td</th>
			<th width="16%">H Tp</th>
			<th>&nbsp;</th>
			<th width="16%">H Tot</th>
			<th width="16%">H Eq_Td</th>  
		</tr>
		<tr>
			<th>attribué</th>
			<td><?php echo $heures->get($vol_horaire_total, 'h_cours'); ?></td>
			<td><?php echo $heures->get($vol_horaire_total, 'h_td'); ?></td>
			<td><?php echo $heures->get($vol_horaire_total, 'h_tp'); ?></td>
			<td>&nbsp;</td>
			<td><?php echo $heures->h_tot($vol_horaire_total); ?></td>
			<td><?php echo $heures->h_eq_td($vol_horaire_total); ?></td>
		</tr>
		</table>

<!--
<dl>
	<dt>H Cours</dt>
	<dd><?php echo $vol_horaire_total['h_cours']; ?>&nbsp;</dd>
	
	<dt>H Td</dt>
	<dd><?php echo $vol_horaire_total['h_td']; ?>&nbsp;</dd>

	<dt>H Tp</dt>
	<dd><?php echo $vol_horaire_total['h_tp']; ?>&nbsp;</dd>
	
	<br/>

	<dt>H Tot</dt>
	<dd><?php echo $vol_horaire_total['h_tot']; ?>&nbsp;</dd>
	
	<dt>H Eq_Td</dt>  
	<dd><?php echo $vol_horaire_total['h_eq_td']; ?>&nbsp;</dd>
</dl>
-->

</div>