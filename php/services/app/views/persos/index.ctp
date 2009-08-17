<div class="persos index">
<h2><?php __('Liste des personnels');?></h2>
<p>
<?php
echo $paginator->counter(array(
'format' => __('Page %page% of %pages%, showing %current% records out of %count% total, starting on record %start%, ending on %end%', true)
));
?></p>
<table cellpadding="0" cellspacing="0">
<tr>
	<th><?php echo $paginator->sort('id');?></th>
	<th><?php echo $paginator->sort('initiales');?></th>
	<th><?php echo $paginator->sort('nom');?></th>
	<th><?php echo $paginator->sort('prenom');?></th>
	<th><?php echo $paginator->sort('statut_id');?></th>
	<th><?php echo $paginator->sort('permanent');?></th>
	<th>H Cours</th>
	<th>H Td</th>
	<th>H Tp</th>
	<th>&nbsp;</th>
	<th>H Tot</th>
	<th>H Eq_Td</th>  
	<th class="actions"><?php __('Actions');?></th>
</tr>
<?php
$i = 0;
foreach ($persos as $perso):
	$class = null;
	if ($i++ % 2 == 0) {
		$class = ' class="altrow"';
	}
?>
	<tr<?php echo $class;?>>
		<td><?php echo $perso['Perso']['id']; ?></td>
		<td><?php echo $html->link($perso['Perso']['initiales'], array('action'=>'view', $perso['Perso']['id'])); ?></td>
		<td><?php echo $html->link($perso['Perso']['nom'], array('action'=>'view', $perso['Perso']['id'])); ?></td>
		<td><?php echo $html->link($perso['Perso']['prenom'], array('action'=>'view', $perso['Perso']['id'])); ?></td>
		<td><?php echo $html->link($perso['Statut']['nom'], array('controller'=> 'statuts', 'action'=>'view', $perso['Statut']['id'])); ?></td>
		<td><?php echo $boolean->yes_no( $perso['Perso']['permanent'] ); ?></td>
		<td><?php echo $heures->get($perso['VuePersosBilanService'], 'h_cours'); ?></td>
		<td><?php echo $heures->get($perso['VuePersosBilanService'], 'h_td'); ?></td>
		<td><?php echo $heures->get($perso['VuePersosBilanService'], 'h_tp'); ?></td>
		<td>&nbsp;</td>
		<td><?php echo $heures->h_tot($perso['VuePersosBilanService']); ?></td>
		<td><?php echo $heures->h_eq_td($perso['VuePersosBilanService']); ?></td>
		<td class="actions">
			<?php echo $html->link(__('View', true), array('action'=>'view', $perso['Perso']['id'])); ?>
			<?php echo $html->link(__('Edit', true), array('action'=>'edit', $perso['Perso']['id'])); ?>
			<?php echo $html->link(__('Delete', true), array('action'=>'delete', $perso['Perso']['id']), null, sprintf(__('Are you sure you want to delete # %s?', true), $perso['Perso']['id'])); ?>
		</td>
	</tr>
<?php endforeach; ?>
</table>
</div>
<div class="paging">
	<?php echo $paginator->prev('<< '.__('previous', true), array(), null, array('class'=>'disabled'));?>
 | 	<?php echo $paginator->numbers();?>
	<?php echo $paginator->next(__('next', true).' >>', array(), null, array('class'=>'disabled'));?>
</div>
<div class="actions">
	<ul>
		<li><?php echo $html->link(__('Nouveau Perso', true), array('action'=>'add')); ?></li>
	</ul>
	<ul>
		<li><?php echo $html->link(__('Lister Statuts', true), array('controller'=> 'statuts', 'action'=>'index')); ?> </li>
		<li><?php echo $html->link(__('Nouveau Statut', true), array('controller'=> 'statuts', 'action'=>'add')); ?> </li>
	</ul>
	<ul>
		<li><?php echo $html->link(__('Lister les occupations', true), array('controller'=> 'matieres_persos', 'action'=>'index')); ?> </li>
		<li><?php echo $html->link(__('Nouvelle occupation', true), array('controller'=> 'matieres_persos', 'action'=>'add')); ?> </li>
	</ul>
	<ul>
		<li><?php echo $html->link(__('Bilan de service des personnels', true), array('controller'=> 'vue_persos_bilan_services', 'action'=>'index')); ?> </li>
	</ul>
</div>
