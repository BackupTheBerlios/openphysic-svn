<div class="filieres view">
<h2><?php  __('Bilan pour une filière');?></h2>
	<dl><?php $i = 0; $class = ' class="altrow"';?>
		<dt<?php if ($i % 2 == 0) echo $class;?>><?php __('Id'); ?></dt>
		<dd<?php if ($i++ % 2 == 0) echo $class;?>>
			<?php echo $filiere['Filiere']['id']; ?>
			&nbsp;
		</dd>
		<dt<?php if ($i % 2 == 0) echo $class;?>><?php __('Name'); ?></dt>
		<dd<?php if ($i++ % 2 == 0) echo $class;?>>
			<?php echo $filiere['Filiere']['name']; ?>
			&nbsp;
		</dd>
		<dt<?php if ($i % 2 == 0) echo $class;?>><?php __('Nb Gr Td'); ?></dt>
		<dd<?php if ($i++ % 2 == 0) echo $class;?>>
			<?php echo $filiere['Filiere']['nb_gr_td']; ?>
			&nbsp;
		</dd>
		<dt<?php if ($i % 2 == 0) echo $class;?>><?php __('Nb Gr Tp'); ?></dt>
		<dd<?php if ($i++ % 2 == 0) echo $class;?>>
			<?php echo $filiere['Filiere']['nb_gr_tp']; ?>
			&nbsp;
		</dd>
	</dl>
</div>
<div class="actions">
	<ul>
		<li><?php echo $html->link(__('Editer Filière', true), array('action'=>'edit', $filiere['Filiere']['id'])); ?> </li>
		<li><?php echo $html->link(__('Lister Filières', true), array('action'=>'index')); ?> </li>
		<li><?php echo $html->link(__('Nouvelle Filière', true), array('action'=>'add')); ?> </li>
		<li><?php echo $html->link(__('Supprimer Filière', true), array('action'=>'delete', $filiere['Filiere']['id']), null, sprintf(__('Are you sure you want to delete # %s?', true), $filiere['Filiere']['id'])); ?> </li>
	</ul>
	<ul>
		<li><?php echo $html->link(__('Bilan des besoins par filière', true), array('controller'=> 'vue_filieres_total_besoins', 'action'=>'index')); ?> </li>	
	</ul>

</div>
<div class="related">
	<h3><?php __('Matières enseignées dans la filière');?></h3>
	<h4><?php __('Volume horaire par groupe'); ?></h4>
	<?php if (!empty($filiere['Matiere'])):?>
	<table cellpadding = "0" cellspacing = "0">
	<tr>
		<th><?php __('Id'); ?></th>
		<th><?php __('Name'); ?></th>
		<th><?php __('H Cours'); ?></th>
		<th><?php __('H Td'); ?></th>
		<th><?php __('H Tp'); ?></th>
		<th><?php __('Commentaire'); ?></th>
		<th class="actions"><?php __('Actions');?></th>
	</tr>
	<?php
		$i = 0;
		foreach ($filiere['Matiere'] as $matiere):
			$class = null;
			if ($i++ % 2 == 0) {
				$class = ' class="altrow"';
			}
		?>		
		<tr<?php echo $class;?>>
			<td><?php echo $matiere['id'];?></td>
			<td><?php
				echo $html->link($matiere['name'], array('controller'=> 'matieres', 'action'=>'view', $matiere['id']));
			?></td>
			<td><?php echo $matiere['h_cours'];?></td>
			<td><?php echo $matiere['h_td'];?></td>
			<td><?php echo $matiere['h_tp'];?></td>
			<td><?php echo $matiere['commentaire'];?></td>
			<td class="actions">
				<?php echo $html->link(__('View', true), array('controller'=> 'matieres', 'action'=>'view', $matiere['id'])); ?>
				<?php echo $html->link(__('Edit', true), array('controller'=> 'matieres', 'action'=>'edit', $matiere['id'])); ?>
				<?php echo $html->link(__('Delete', true), array('controller'=> 'matieres', 'action'=>'delete', $matiere['id']), null, sprintf(__('Are you sure you want to delete # %s?', true), $matiere['id'])); ?>
			</td>
		</tr>
	<?php endforeach; ?>
	</table>
	<?php endif; ?>

	<div class="actions">
		<ul>
			<li><?php echo $html->link(__('Nouvelle Matière', true), array('controller'=> 'matieres', 'action'=>'add', 'filiere'=>$filiere['Filiere']['id'] ));?> </li>
			<li><?php echo $html->link(__('Lister Matières', true), array('controller'=> 'matieres', 'action'=>'index')); ?> </li>
		</ul>
	</div>

	<h4><?php __('Volume horaire pour l\'ensemble des groupes'); ?></h4>
	<?php if (!empty($filiere['Matiere'])):?>
	<table cellpadding = "0" cellspacing = "0">

	<tr>
		<th><?php __('Id'); ?></th>
		<th><?php __('Name'); ?></th>
		<th><?php __('H Cours'); ?></th>
		<th><?php __('H Td'); ?></th>
		<th><?php __('H Tp'); ?></th>
		<th>&nbsp;</th>
		<th><?php __('H Tot'); ?></th>
		<th><?php __('H Eq Td'); ?></th>		
		<th class="actions"><?php __('Actions');?></th>
	</tr>

	<?php
		$i = 0;
		foreach ($filiere['Matiere'] as $matiere):
			$class = null;
			if ($i++ % 2 == 0) {
				$class = ' class="altrow"';
			}
		?>
		<tr<?php echo $class;?>>
			<td>&nbsp;</td>
			<td>&nbsp;</td>
			<td><?php echo $matiere['VueMatieresTotalBesoin']['h_cours'];?></td>
			<td><?php echo $matiere['VueMatieresTotalBesoin']['h_td'];?></td>
			<td><?php echo $matiere['VueMatieresTotalBesoin']['h_tp'];?></td>
			<td>à&nbsp;attribuer</td>
			<td><?php echo $heures->h_tot($matiere['VueMatieresTotalBesoin']); ?></td>
			<td><?php echo $heures->h_eq_td($matiere['VueMatieresTotalBesoin']); ?></td>
			<td>&nbsp;</td>
		</tr>
		<tr<?php echo $class;?>>
			<td><?php echo $matiere['id'];?></td>
			<td><?php
				echo $html->link($matiere['name'], array('controller'=> 'matieres', 'action'=>'view', $matiere['id']));
			?></td>
			<td><?php echo $heures->get($matiere['VueMatieresComblesBesoin'], 'h_cours'); ?></td>
			<td><?php echo $heures->get($matiere['VueMatieresComblesBesoin'], 'h_td'); ?></td>
			<td><?php echo $heures->get($matiere['VueMatieresComblesBesoin'], 'h_tp'); ?></td>
			<td>attribué</td>
			<td><?php echo $heures->h_tot($heures->get($matiere['VueMatieresComblesBesoin'])); ?></td>
			<td><?php echo $heures->h_eq_td($heures->get($matiere['VueMatieresComblesBesoin'])); ?></td>
			<td class="actions">
				<?php echo $html->link(__('View', true), array('controller'=> 'matieres', 'action'=>'view', $matiere['id'])); ?>
				<?php echo $html->link(__('Edit', true), array('controller'=> 'matieres', 'action'=>'edit', $matiere['id'])); ?>
				<?php echo $html->link(__('Delete', true), array('controller'=> 'matieres', 'action'=>'delete', $matiere['id']), null, sprintf(__('Are you sure you want to delete # %s?', true), $matiere['id'])); ?>
			</td>
		</tr>
		<tr<?php echo $class;?>>
			<td>&nbsp;</td>
			<td>&nbsp;</td>
			<td <?php echo $couleurs->heures_restantes($matiere['VueMatieresRestantsBesoin']['h_cours']); ?>><?php echo $matiere['VueMatieresRestantsBesoin']['h_cours'];?></td>
			<td <?php echo $couleurs->heures_restantes($matiere['VueMatieresRestantsBesoin']['h_td']); ?>><?php echo $matiere['VueMatieresRestantsBesoin']['h_td'];?></td>
			<td <?php echo $couleurs->heures_restantes($matiere['VueMatieresRestantsBesoin']['h_tp']); ?>><?php echo $matiere['VueMatieresRestantsBesoin']['h_tp'];?></td>
			<td>restant</td>
			<td><?php echo $heures->h_tot($matiere['VueMatieresRestantsBesoin']); ?></td>
			<td><?php echo $heures->h_eq_td($matiere['VueMatieresRestantsBesoin']); ?></td>
			<td>&nbsp;</td>
		</tr>
	<?php endforeach; ?>
	</table>
	<?php endif; ?>
</div>

<div class="vol_horaire_total">
<h3>Volume horaire pour l'ensemble de la filière</h3>
		<table cellpadding = "0" cellspacing = "0">
		<tr>
			<th>&nbsp;</th>
			<th>H Cours</th>
			<th>H Td</th>
			<th>H Tp</th>
			<th>&nbsp;</th>
			<th>H Tot</th>
			<th>H Eq_Td</th>  
		</tr>
		<tr class="altrow">
			<th>à effectuer</th>
			<td><?php echo $heures->get($filiere['VueFilieresTotalBesoin'], 'h_cours'); ?></td>
			<td><?php echo $heures->get($filiere['VueFilieresTotalBesoin'], 'h_td'); ?></td>
			<td><?php echo $heures->get($filiere['VueFilieresTotalBesoin'], 'h_tp'); ?></td>
			<td>&nbsp;</td>
			<td><?php echo $heures->h_tot($filiere['VueFilieresTotalBesoin']); ?></td>
			<td><?php echo $heures->h_eq_td($filiere['VueFilieresTotalBesoin']); ?></td>
		</tr>
		<tr>
			<th>attribué</th>
			<td><?php echo $heures->get($filiere['VueFilieresComblesBesoin'], 'h_cours'); ?></td>
			<td><?php echo $heures->get($filiere['VueFilieresComblesBesoin'], 'h_td'); ?></td>
			<td><?php echo $heures->get($filiere['VueFilieresComblesBesoin'], 'h_tp'); ?></td>
			<td>&nbsp;</td>
			<td><?php echo $heures->h_tot($filiere['VueFilieresComblesBesoin']); ?></td>
			<td><?php echo $heures->h_eq_td($filiere['VueFilieresComblesBesoin']); ?></td>
		</tr>
		<tr class="altrow">
			<th>restant</th>
			<td><?php echo $heures->get($filiere['VueFilieresRestantsBesoin'], 'h_cours'); ?></td>
			<td><?php echo $heures->get($filiere['VueFilieresRestantsBesoin'], 'h_td'); ?></td>
			<td><?php echo $heures->get($filiere['VueFilieresRestantsBesoin'], 'h_tp'); ?></td>
			<td>&nbsp;</td>
			<td><?php echo $heures->h_tot($filiere['VueFilieresRestantsBesoin']); ?></td>
			<td><?php echo $heures->h_eq_td($filiere['VueFilieresRestantsBesoin']); ?></td>
		</tr>
		</table>

</div>